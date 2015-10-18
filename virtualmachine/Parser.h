//
//  Parser.h
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__Parser__
#define __virtualmachine__Parser__

#include "Instruction.h"
#include "Lexer.h"

#include <map>

namespace assembler {
    
typedef struct {
    char s = 0;
    char i = 0;
    char code = 0;
    char cond = 0;
    char reg_d = 0;
    char reg_n = 0;
    char reg_m = 0;
    char reg_s = 0;
    char imm_val = 0;
    char imm_rot = 0;
} InstructionModel;
    
class Parser {
    static const std::map<std::string, char> instruction_operations;
    
    const char parse_operation_code(TokenisedInstruction instruction);
    const char parse_condition_code(TokenisedInstruction instruction);
    
public:
    InstructionModel parse(TokenisedInstruction instruction);
};
    
}

#endif /* defined(__virtualmachine__Parser__) */
