//
//  Parser.h
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__Parser__
#define __virtualmachine__Parser__

#include "Lexer.h"

#include <map>

namespace assembler {
    
typedef struct {
    uint8_t s = 0x00;
    uint8_t i = 0x00;
    uint8_t code = 0x00;
    uint8_t cond = 0x00;
    uint8_t reg_d = 0x00;
    uint8_t reg_n = 0x00;
    uint8_t reg_m = 0x00;
    uint8_t reg_s = 0x00;
    uint8_t imm_val = 0x00;
    uint8_t imm_rot = 0x00;
} InstructionModel;
    
class Parser {
    std::map<std::string, char> instruction_codes;
    std::map<std::string, char> condition_codes;
    
    void parse_arg_c(TokenisedInstruction instruction, InstructionModel *result_model);
    
    const uint8_t parse_reg_string(std::string string);
    const uint8_t parse_s(TokenisedInstruction instruction);
    const uint8_t parse_reg_d(TokenisedInstruction instruction);
    const uint8_t parse_reg_n(TokenisedInstruction instruction);
    const uint8_t parse_operation_code(TokenisedInstruction instruction);
    const uint8_t parse_condition_code(TokenisedInstruction instruction);
    
public:
    Parser();
    
    InstructionModel parse(TokenisedInstruction instruction);
};
    
}

#endif /* defined(__virtualmachine__Parser__) */
