//
//  Parser.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Parser.h"

#include "Instruction.h"

#include <iostream>
#include <string>

namespace assembler {

Parser::Parser() {
    instruction_codes[ vm::Instruction::MN_AND ] = vm::Instruction::OP_AND;
    instruction_codes[ vm::Instruction::MN_EOR ] = vm::Instruction::OP_EOR;
    instruction_codes[ vm::Instruction::MN_SUB ] = vm::Instruction::OP_SUB;
    instruction_codes[ vm::Instruction::MN_RSB ] = vm::Instruction::OP_RSB;
    instruction_codes[ vm::Instruction::MN_ADD ] = vm::Instruction::OP_ADD;
    instruction_codes[ vm::Instruction::MN_ADC ] = vm::Instruction::OP_ADC;
    instruction_codes[ vm::Instruction::MN_SBC ] = vm::Instruction::OP_SBC;
    instruction_codes[ vm::Instruction::MN_RSC ] = vm::Instruction::OP_RSC;
    instruction_codes[ vm::Instruction::MN_TST ] = vm::Instruction::OP_TST;
    instruction_codes[ vm::Instruction::MN_TEQ ] = vm::Instruction::OP_TEQ;
    instruction_codes[ vm::Instruction::MN_CMP ] = vm::Instruction::OP_CMP;
    instruction_codes[ vm::Instruction::MN_CMN ] = vm::Instruction::OP_CMN;
    instruction_codes[ vm::Instruction::MN_ORR ] = vm::Instruction::OP_ORR;
    instruction_codes[ vm::Instruction::MN_MOV ] = vm::Instruction::OP_MOV;
    instruction_codes[ vm::Instruction::MN_BIC ] = vm::Instruction::OP_BIC;
    instruction_codes[ vm::Instruction::MN_MVN ] = vm::Instruction::OP_MVN;

    condition_codes[ vm::Instruction::MN_EQ ] = vm::Instruction::CND_EQ;
    condition_codes[ vm::Instruction::MN_NE ] = vm::Instruction::CND_NE;
    condition_codes[ vm::Instruction::MN_HS ] = vm::Instruction::CND_HS;
    condition_codes[ vm::Instruction::MN_LO ] = vm::Instruction::CND_LO;
    condition_codes[ vm::Instruction::MN_MI ] = vm::Instruction::CND_MI;
    condition_codes[ vm::Instruction::MN_PL ] = vm::Instruction::CND_PL;
    condition_codes[ vm::Instruction::MN_VS ] = vm::Instruction::CND_VS;
    condition_codes[ vm::Instruction::MN_VC ] = vm::Instruction::CND_VC;
    condition_codes[ vm::Instruction::MN_HI ] = vm::Instruction::CND_HI;
    condition_codes[ vm::Instruction::MN_LS ] = vm::Instruction::CND_LS;
    condition_codes[ vm::Instruction::MN_GE ] = vm::Instruction::CND_GE;
    condition_codes[ vm::Instruction::MN_LT ] = vm::Instruction::CND_LT;
    condition_codes[ vm::Instruction::MN_GT ] = vm::Instruction::CND_GT;
    condition_codes[ vm::Instruction::MN_LE ] = vm::Instruction::CND_LE;
    condition_codes[ vm::Instruction::MN_AL ] = vm::Instruction::CND_AL;
    condition_codes[ vm::Instruction::MN_NV ] = vm::Instruction::CND_NV;
}

InstructionModel Parser::parse(TokenisedInstruction instruction) {
    InstructionModel model;

    model.s = parse_s(instruction);
    model.code = parse_operation_code(instruction);
    model.cond = parse_condition_code(instruction);
    model.reg_d = parse_reg_d(instruction);
    model.reg_n = parse_reg_n(instruction);

    parse_arg_c(instruction, &model);

    return model;
}

void Parser::parse_arg_c(TokenisedInstruction instruction, InstructionModel *result_model) {
    if (instruction.arg_c.size() > 1 && instruction.arg_c.substr(0, 1) == "R") {
        result_model->reg_m = std::stoi(instruction.arg_c.substr(1));
        result_model->reg_s = 0x00;
    } else if (instruction.arg_c.size() > 2 && instruction.arg_c.substr(0, 2) == "0x") {
        std::size_t i = 2;
        result_model->i = 0x01;
        result_model->imm_val = std::stoi(instruction.arg_c, &i, 16);
        result_model->imm_rot = 0x00;
    } else if (instruction.arg_c.size() > 1 && instruction.arg_c.substr(0, 1) == "#") {
        result_model->i = 0x01;
        result_model->imm_val = std::stoi(instruction.arg_c.substr(1));
        result_model->imm_rot = 0x00;
    }
}

const uint8_t Parser::parse_s(TokenisedInstruction instruction) {
    if (instruction.s == "S") {
        return 0x01;
    } else {
        return 0x00;
    }
}

const uint8_t Parser::parse_reg_string(std::string string) {
    if (string.size() > 1) {
        return std::stoi(string.substr(1));
    } else {
        return 0x00;
    }
}

const uint8_t Parser::parse_reg_d(TokenisedInstruction instruction) {
    return parse_reg_string(instruction.arg_a);
}

const uint8_t Parser::parse_reg_n(TokenisedInstruction instruction) {
    return parse_reg_string(instruction.arg_b);
}

const uint8_t Parser::parse_operation_code(TokenisedInstruction instruction) {
    if (instruction_codes.count(instruction.operation) > 0) {
        return instruction_codes.at(instruction.operation);
    } else {
        return 0x00;
    }
}

const uint8_t Parser::parse_condition_code(TokenisedInstruction instruction) {
    if (condition_codes.count(instruction.condition) > 0) {
        return condition_codes.at(instruction.condition);
    } else {
        return 0x00;
    }
}

}
