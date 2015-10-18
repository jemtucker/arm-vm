//
//  AssemblerTest.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include <gtest/gtest.h>
#include "Assembler.h"

class AssemblerTest: public ::testing::Test {
protected:
    assembler::Assembler assembler;
};

TEST_F(AssemblerTest, AssemblesTheIFlag) {
    assembler::InstructionModel instr;
    
    instr.i = 0x01;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x02000000, result);
}

TEST_F(AssemblerTest, AssemblesTheSFlag) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x01;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x00100000, result);
}

TEST_F(AssemblerTest, AssemblesTheCondition) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x00;
    instr.cond = 0x01;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x10000000, result);
}

TEST_F(AssemblerTest, AssemblesTheOpCode) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x01;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x00200000, result);
}

TEST_F(AssemblerTest, AssemblesTheRegisterN) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x01;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x00010000, result);
}

TEST_F(AssemblerTest, AssemblesTheDestinationRegister) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x01;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x00001000, result);
}

TEST_F(AssemblerTest, DoesNotAssembleRegMIfIIsOne) {
    assembler::InstructionModel instr;
    
    instr.i = 0x01;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x01;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x02000000, result);
}

TEST_F(AssemblerTest, AssemblesRegMIfIIsZero) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x01;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x00000001, result);
}

TEST_F(AssemblerTest, AssemblesRegSIfIIsZero) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x01;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x00000010, result);
}

TEST_F(AssemblerTest, DoesNotAssembleImmIfIIsZero) {
    assembler::InstructionModel instr;
    
    instr.i = 0x00;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x32;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x00000000, result);
}

TEST_F(AssemblerTest, AssemblesImmIfIIsOne) {
    assembler::InstructionModel instr;
    
    instr.i = 0x01;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x01;
    instr.imm_rot = 0x00;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x02000001, result);
}

TEST_F(AssemblerTest, AssemblesRotIfIIsOne) {
    assembler::InstructionModel instr;
    
    instr.i = 0x01;
    instr.s = 0x00;
    instr.cond = 0x00;
    instr.code = 0x00;
    instr.reg_n = 0x00;
    instr.reg_d = 0x00;
    instr.reg_m = 0x00;
    instr.reg_s = 0x00;
    instr.imm_val = 0x00;
    instr.imm_rot = 0x01;
    
    auto result = assembler.assemble_model(instr);
    
    EXPECT_EQ(0x02000100, result);
}