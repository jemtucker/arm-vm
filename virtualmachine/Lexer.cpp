//
//  Lexer.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Lexer.h"

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

namespace assembler {
    
const TokenisedInstruction Lexer::tokenize(std::string line) {
    std::vector<std::string> lexed_tokens;
    
    boost::split(lexed_tokens, line, boost::is_any_of(", "), boost::token_compress_on);
    
    TokenisedInstruction instr;
    
    instr.operation = tokens_to_operation(lexed_tokens);
    instr.condition = tokens_to_condition(lexed_tokens);
    instr.arg_a     = tokens_to_arg_a(lexed_tokens);
    instr.arg_b     = tokens_to_arg_b(lexed_tokens);
    instr.arg_c     = tokens_to_arg_c(lexed_tokens);
    instr.s         = tokens_to_s(lexed_tokens);
    
    return instr;
}
    
const std::string Lexer::extract_partial_token(std::vector<std::string> tokens, int token_index, int start, int length) {
    int token_min_len = start + length;
    
    if (tokens.size() > token_index && tokens[token_index].size() >= token_min_len) {
        return tokens[token_index].substr(start, length);
    }
    
    return "";
}

const std::string Lexer::extract_single_token(std::vector<std::string> tokens, int token_index) {
    if (tokens.size() > token_index) {
        return tokens[token_index];
    }
    return "";
}

const std::string Lexer::tokens_to_operation(std::vector<std::string> tokens) {
    return extract_partial_token(tokens, 0, 0, 3);
}

const std::string Lexer::tokens_to_condition(std::vector<std::string> tokens) {
    return extract_partial_token(tokens, 0, 3, 2);
}

const std::string Lexer::tokens_to_arg_a(std::vector<std::string> tokens) {
    return extract_single_token(tokens, 1);
}

const std::string Lexer::tokens_to_arg_b(std::vector<std::string> tokens) {
    return extract_single_token(tokens, 2);
}

const std::string Lexer::tokens_to_arg_c(std::vector<std::string> tokens) {
    return extract_single_token(tokens, 3);
}

const std::string Lexer::tokens_to_s(std::vector<std::string> tokens) {
    if (tokens_to_condition(tokens) != "") {
        return extract_partial_token(tokens, 0, 5, 1);
    } else {
        return extract_partial_token(tokens, 0, 3, 1);
    }
}
   
    
} // namespace assembler