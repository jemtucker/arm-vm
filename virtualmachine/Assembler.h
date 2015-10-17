//
//  Assembler.h
//  virtualmachine
//
//  Created by Jem Tucker on 10/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__Assembler__
#define __virtualmachine__Assembler__

#include <map>
#include <string>
#include <vector>

#include "operation.h"

class Assembler {
    const std::map<std::string, int> m_opcodes = std::map<std::string, int> {
        { "AND", 0x0 },
        { "EOR", 0x1 },
        { "SUB", 0x2 },
        { "RSB", 0x3 },
        { "ADD", 0x4 },
        { "ADC", 0x5 },
        { "SBC", 0x6 },
        { "RSC", 0x7 },
        { "TST", 0x8 },
        { "TEQ", 0x9 },
        { "CMP", 0xA },
        { "CMN", 0xB },
        { "ORR", 0xC },
        { "MOV", 0xD },
        { "BIC", 0xE },
        { "MVN", 0xF }
    };
    
    const std::map<std::string, int> m_conditions = std::map<std::string, int> {
        { "AND", 0x0 },
        { "EOR", 0x1 },
        { "SUB", 0x2 },
        { "RSB", 0x3 },
        { "ADD", 0x4 },
        { "ADC", 0x5 },
        { "SBC", 0x6 },
        { "RSC", 0x7 },
        { "TST", 0x8 },
        { "TEQ", 0x9 },
        { "CMP", 0xA },
        { "CMN", 0xB },
        { "ORR", 0xC },
        { "MOV", 0xD },
        { "BIC", 0xE },
        { "MVN", 0xF }
    };
    
    int m_instr = 0;
    int m_reg1 = 0;
    int m_reg2 = 0;
    int m_reg3 = 0;
    int m_immediate = 0;
    
    std::vector<std::string> tokenize(std::string string);
    void parse_data(std::string token, int pos);
    
public:
    std::vector<int> assemble(std::string code);
};

#endif /* defined(__virtualmachine__Assembler__) */
