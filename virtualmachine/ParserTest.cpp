//
//  ParserTest.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include <gtest/gtest.h>

#include "Parser.h"

class ParserTest: public ::testing::Test {
protected:
    assembler::Parser parser;
};

TEST_F(ParserTest, ParsesANDInstructions) {
    assembler::TokenisedInstruction instr = {
        "ADD",
        "",
        "",
        "",
        "",
        ""
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x00, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x04, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x00, result.imm_val);
}