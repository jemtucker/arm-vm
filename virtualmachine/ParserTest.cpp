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

TEST_F(ParserTest, ParsesOperationInstructions) {
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

TEST_F(ParserTest, ParsesConditions) {
    assembler::TokenisedInstruction instr = {
        "",
        "NE",
        "",
        "",
        "",
        ""
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x00, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x01, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x00, result.imm_val);
}

TEST_F(ParserTest, ParsesTheSFlag) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "S",
        "",
        "",
        ""
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x00, result.i);
    EXPECT_EQ(0x01, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x00, result.imm_val);
}

TEST_F(ParserTest, ParsesTheDestinationRegister) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "",
        "R1",
        "",
        ""
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x00, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x01, result.reg_d);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x00, result.imm_val);
}

TEST_F(ParserTest, ParsesTheFirstOpRegister) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "",
        "",
        "R3",
        ""
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x00, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x03, result.reg_n);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x00, result.imm_val);
}

TEST_F(ParserTest, ParsesTheSecondOpAsARegister) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "",
        "",
        "",
        "R15"
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x00, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x0F, result.reg_m);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x00, result.imm_val);
}

TEST_F(ParserTest, ParsesTheSecondOpAsAnImmVal) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "",
        "",
        "",
        "#9"
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x01, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x09, result.imm_val);
}

TEST_F(ParserTest, ParsesTheSecondOpAsAnImmValFromHex) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "",
        "",
        "",
        "0x0F"
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x01, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x0F, result.imm_val);
}

TEST_F(ParserTest, Parses8BitImmVal) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "",
        "",
        "",
        "#100"
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x01, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x64, result.imm_val);
}

TEST_F(ParserTest, Parses8BitImmValFromHex) {
    assembler::TokenisedInstruction instr = {
        "",
        "",
        "",
        "",
        "",
        "0x65"
    };
    
    auto result = parser.parse(instr);
    
    EXPECT_EQ(0x01, result.i);
    EXPECT_EQ(0x00, result.s);
    EXPECT_EQ(0x00, result.code);
    EXPECT_EQ(0x00, result.cond);
    EXPECT_EQ(0x00, result.reg_d);
    EXPECT_EQ(0x00, result.reg_n);
    EXPECT_EQ(0x00, result.reg_m);
    EXPECT_EQ(0x00, result.reg_s);
    EXPECT_EQ(0x00, result.imm_rot);
    EXPECT_EQ(0x65, result.imm_val);
}





