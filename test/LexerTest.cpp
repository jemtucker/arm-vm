//
//  LexerTest.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Lexer.h"

#include <gtest/gtest.h>


class LexerTest: public ::testing::Test {
protected:
    assembler::Lexer lexer;
};

TEST_F(LexerTest, TokenizesLinesSplitWithCommas) {
    std::string line = "ADD R1,R2,R3";
    auto result = lexer.tokenize(line);
    
    EXPECT_EQ("ADD", result.operation);
    EXPECT_EQ("", result.condition);
    EXPECT_EQ("R1", result.arg_a);
    EXPECT_EQ("R2", result.arg_b);
    EXPECT_EQ("R3", result.arg_c);
    EXPECT_EQ("", result.s);
}

TEST_F(LexerTest, TokenizesLinesSplitWithSpace) {
    std::string line = "ADD R1, R2, R3";
    auto result = lexer.tokenize(line);
    
    EXPECT_EQ("ADD", result.operation);
    EXPECT_EQ("", result.condition);
    EXPECT_EQ("R1", result.arg_a);
    EXPECT_EQ("R2", result.arg_b);
    EXPECT_EQ("R3", result.arg_c);
    EXPECT_EQ("", result.s);
}

TEST_F(LexerTest, ExtractsConditions) {
    std::string line = "ADDGT R1,R2,R3";
    auto result = lexer.tokenize(line);
    
    EXPECT_EQ("ADD", result.operation);
    EXPECT_EQ("GT", result.condition);
    EXPECT_EQ("R1", result.arg_a);
    EXPECT_EQ("R2", result.arg_b);
    EXPECT_EQ("R3", result.arg_c);
    EXPECT_EQ("", result.s);
}

TEST_F(LexerTest, ExtractsConditionsAndTheSFlag) {
    std::string line = "ADDGTS R1,R2,R3";
    auto result = lexer.tokenize(line);
    
    EXPECT_EQ("ADD", result.operation);
    EXPECT_EQ("GT", result.condition);
    EXPECT_EQ("R1", result.arg_a);
    EXPECT_EQ("R2", result.arg_b);
    EXPECT_EQ("R3", result.arg_c);
    EXPECT_EQ("S", result.s);
}

TEST_F(LexerTest, ExtractsTheSFlagWithNoCondidtion) {
    std::string line = "ADDS R1,R2,R3";
    auto result = lexer.tokenize(line);
    
    EXPECT_EQ("ADD", result.operation);
    EXPECT_EQ("", result.condition);
    EXPECT_EQ("R1", result.arg_a);
    EXPECT_EQ("R2", result.arg_b);
    EXPECT_EQ("R3", result.arg_c);
    EXPECT_EQ("S", result.s);
}
