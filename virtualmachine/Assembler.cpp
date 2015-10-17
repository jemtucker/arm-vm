//
//  Assembler.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 10/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Assembler.h"

#include <sstream>

std::vector<int> Assembler::assemble(std::string code) {
    std::istringstream ss(code);
    std::vector<std::string> lines;
    
    while (!ss.eof()) {
        std::string line;
        getline(ss, line, '\n');
        lines.push_back(line);
    }
    
    std::vector<int> instructions;
    
    for (auto iter = lines.begin(); iter != lines.end(); iter++) {
        m_instr = 0;
        m_reg1 = 0;
        m_reg2 = 0;
        m_reg3 = 0;
        m_immediate = 0;
        
        auto tokens = tokenize(*iter);
        
        for (int i = 1; i < tokens.size(); i++) {
            parse_data(tokens[i], i);
        }
        
        m_instr = m_instr << 12;
        m_reg1  = m_reg1  <<  8;
        m_reg2  = m_reg2  <<  4;
        
        instructions.push_back( m_instr | m_reg1 | m_reg2 | m_reg3 | m_immediate );
    }
    
    return instructions;
}

void Assembler::parse_data(std::string token, int nib) {
    char first = *token.begin();
    
    switch (first) {
        case 'r':
            if (!m_reg1) m_reg1 = stoi(token.substr(1));
            else if (!m_reg2) m_reg2 = stoi(token.substr(1));
            else m_reg3 = stoi(token.substr(1));
            break;
        case '#':
            m_immediate = stoi(token.substr(1));
            break;
        case '0':
            m_immediate = stoi(token.substr(1));
        default:
            break;
    }
}

// TODO use boost
std::vector<std::string> Assembler::tokenize(std::string string) {
    std::vector<std::string> tokens;
    std::istringstream ss(string);
    while (!ss.eof()) {
        std::string token;
        getline(ss, token, ' ');
        tokens.push_back(token);
    }
    return tokens;
}