//
//  Parser.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Parser.h"

#include <iostream>

#include "Instruction.h"

namespace assembler {
   
Parser::Parser() {
    instruction_operations[ vm::Instruction::MN_AND ] = vm::Instruction::OP_AND;
    instruction_operations[ vm::Instruction::MN_EOR ] = vm::Instruction::OP_EOR;
    instruction_operations[ vm::Instruction::MN_SUB ] = vm::Instruction::OP_SUB;
    instruction_operations[ vm::Instruction::MN_RSB ] = vm::Instruction::OP_RSB;
    instruction_operations[ vm::Instruction::MN_ADD ] = vm::Instruction::OP_ADD;
    instruction_operations[ vm::Instruction::MN_ADC ] = vm::Instruction::OP_ADC;
    instruction_operations[ vm::Instruction::MN_SBC ] = vm::Instruction::OP_SBC;
    instruction_operations[ vm::Instruction::MN_RSC ] = vm::Instruction::OP_RSC;
    instruction_operations[ vm::Instruction::MN_TST ] = vm::Instruction::OP_TST;
    instruction_operations[ vm::Instruction::MN_TEQ ] = vm::Instruction::OP_TEQ;
    instruction_operations[ vm::Instruction::MN_CMP ] = vm::Instruction::OP_CMP;
    instruction_operations[ vm::Instruction::MN_CMN ] = vm::Instruction::OP_CMN;
    instruction_operations[ vm::Instruction::MN_ORR ] = vm::Instruction::OP_ORR;
    instruction_operations[ vm::Instruction::MN_MOV ] = vm::Instruction::OP_MOV;
    instruction_operations[ vm::Instruction::MN_BIC ] = vm::Instruction::OP_BIC;
    instruction_operations[ vm::Instruction::MN_MVN ] = vm::Instruction::OP_MVN;
}
    
InstructionModel Parser::parse(TokenisedInstruction instruction) {
    InstructionModel model;
    
    model.code = parse_operation_code(instruction);
    
    return model;
}
    
const char Parser::parse_operation_code(TokenisedInstruction instruction) {
    if (instruction_operations.count(instruction.operation) > 0) {
        return instruction_operations.at(instruction.operation);
    } else {
        return 0x00;
    }
}
    
}