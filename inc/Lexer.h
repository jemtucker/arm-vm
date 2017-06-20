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
    std::string extract_partial_token(const std::vector<std::string>& tokens, int token_index, int start, int length);
    std::string extract_single_token(const std::vector<std::string>& tokens, int token_index);

    std::string tokens_to_operation(const std::vector<std::string>& token);
    std::string tokens_to_condition(const std::vector<std::string>& token);
    std::string tokens_to_arg_a(const std::vector<std::string>& token);
    std::string tokens_to_arg_b(const std::vector<std::string>& token);
    std::string tokens_to_arg_c(const std::vector<std::string>& token);
    std::string tokens_to_s(const std::vector<std::string>& token);

public:
    TokenisedInstruction tokenize(const std::string& line);
};

} // namespace assembler

#endif /* defined(__virtualmachine__Lexer__) */
