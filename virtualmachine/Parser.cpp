//
//  Parser.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Parser.h"

#include "Instruction.h"

namespace assembler {
    
const std::map<std::string, char> Parser::instruction_operations = {
    {vm::Instruction::MN_AND, vm::Instruction::OP_AND},
    {vm::Instruction::MN_EOR, vm::Instruction::OP_EOR},
    {vm::Instruction::MN_SUB, vm::Instruction::OP_SUB},
    {vm::Instruction::MN_RSB, vm::Instruction::OP_RSB},
    {vm::Instruction::MN_ADD, vm::Instruction::OP_ADD},
    {vm::Instruction::MN_ADC, vm::Instruction::OP_ADC},
    {vm::Instruction::MN_SBC, vm::Instruction::OP_SBC},
    {vm::Instruction::MN_RSC, vm::Instruction::OP_RSC},
    {vm::Instruction::MN_TST, vm::Instruction::OP_TST},
    {vm::Instruction::MN_TEQ, vm::Instruction::OP_TEQ},
    {vm::Instruction::MN_CMP, vm::Instruction::OP_CMP},
    {vm::Instruction::MN_CMN, vm::Instruction::OP_CMN},
    {vm::Instruction::MN_ORR, vm::Instruction::OP_ORR},
    {vm::Instruction::MN_MOV, vm::Instruction::OP_MOV},
    {vm::Instruction::MN_BIC, vm::Instruction::OP_BIC},
    {vm::Instruction::MN_MVN, vm::Instruction::OP_MVN}
};
    
InstructionModel Parser::parse(TokenisedInstruction instruction) {
    InstructionModel model;
    
    model.code = parse_operation_code(instruction);
    
    return model;
}
    
const char Parser::parse_operation_code(TokenisedInstruction instruction) {
    if (instruction_operations.find(instruction.operation) != instruction_operations.end()) {
        return instruction_operations.at(instruction.operation);
    } else {
        return 0x00;
    }
}
    
}