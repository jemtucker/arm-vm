//
//  Lexer.h
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__Lexer__
#define __virtualmachine__Lexer__

#include <string>
#include <vector>

namespace assembler {
    
typedef struct {
    std::string operation;
    std::string condition;
    std::string s;
    std::string arg_a;
    std::string arg_b;
    std::string arg_c;
} TokenisedInstruction;

class Lexer {
    const std::string extract_partial_token(std::vector<std::string> tokens, int token_index, int start, int length);
    const std::string extract_single_token(std::vector<std::string> tokens, int token_index);
    
    const std::string tokens_to_operation(std::vector<std::string> token);
    const std::string tokens_to_condition(std::vector<std::string> token);
    const std::string tokens_to_arg_a(std::vector<std::string> token);
    const std::string tokens_to_arg_b(std::vector<std::string> token);
    const std::string tokens_to_arg_c(std::vector<std::string> token);
    const std::string tokens_to_s(std::vector<std::string> token);
    
public:
    const TokenisedInstruction tokenize(std::string line);
};
    
} // namespace assembler

#endif /* defined(__virtualmachine__Lexer__) */
