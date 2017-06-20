//
//  Assembler.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 10/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Assembler.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

namespace {

std::vector<std::string> split_string(const std::string& str, const std::string& delims) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    size_t last = 0;

    do
    {
        // Find next delimiter
        pos = str.find_first_of(delims, pos);
        if (pos == std::string::npos) {
            tokens.push_back(str.substr(last));
        } else if (pos > last) {
            const auto len = (pos++ - last);
            tokens.push_back(str.substr(last, len));
        } else {
            ++pos;
        }

        last = pos;
    } while (pos != std::string::npos);

    return tokens;
}

}

namespace assembler {

std::vector<uint32_t> Assembler::assemble(const std::string& code) {
    // Normalise the code into uppercase, this is all the parser can handle
    std::string upper_case = code;
    std::transform(
        code.begin(),
        code.end(),
        upper_case.begin(),
        ::toupper
    );

    std::vector<uint32_t> result;

    auto lines = code_into_lines(upper_case);

    for (auto iter = lines.begin(); iter != lines.end(); iter++) {
        auto tokens = m_lexer.tokenize(*iter);
        auto model = m_parser.parse(tokens);
        uint32_t byte_code = assemble_model(model);
        result.push_back(byte_code);
    }

    return result;
}

uint32_t Assembler::assemble_model(const InstructionModel& model) {
    uint32_t condition = model.cond << 28;
    uint32_t operation = model.code << 21;
    uint32_t reg_n = model.reg_n << 16;
    uint32_t reg_d = model.reg_d << 12;
    uint32_t i = model.i << 25;
    uint32_t s = model.s << 20;

    uint32_t operand_2 = model.reg_m | (model.reg_s << 4);

    if (i) {
        operand_2 = model.imm_val | (model.imm_rot << 8);
    }

    return condition | i | operation | s | reg_n | reg_d | operand_2;
}

std::vector<std::string> Assembler::code_into_lines(const std::string& code) {
    return split_string(code, "\n");
}

}
