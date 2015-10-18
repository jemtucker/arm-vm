//
//  Assembler.h
//  virtualmachine
//
//  Created by Jem Tucker on 10/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__Assembler__
#define __virtualmachine__Assembler__

#include <vector>

#include "Lexer.h"
#include "Parser.h"

namespace assembler {
    
class Assembler {
    Parser m_parser;
    Lexer  m_lexer;
    
    std::vector<std::string> code_into_lines(std::string code);
    
public:
    int assemble_model(InstructionModel model);
    std::vector<int> assemble(std::string code);
};
    
} // namespace assembler

#endif /* defined(__virtualmachine__Assembler__) */
