//
//  Instruction.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Instruction.h"

namespace vm {

const std::string Instruction::MN_AND = "AND";
const std::string Instruction::MN_EOR = "EOR";
const std::string Instruction::MN_SUB = "SUB";
const std::string Instruction::MN_RSB = "RSB";
const std::string Instruction::MN_ADD = "ADD";
const std::string Instruction::MN_ADC = "ADC";
const std::string Instruction::MN_SBC = "SBC";
const std::string Instruction::MN_RSC = "RSC";
const std::string Instruction::MN_TST = "TST";
const std::string Instruction::MN_TEQ = "TEQ";
const std::string Instruction::MN_CMP = "CMP";
const std::string Instruction::MN_CMN = "CMN";
const std::string Instruction::MN_ORR = "ORR";
const std::string Instruction::MN_MOV = "MOV";
const std::string Instruction::MN_BIC = "BIC";
const std::string Instruction::MN_MVN = "MVN";

const std::string Instruction::MN_EQ = "EQ";
const std::string Instruction::MN_NE = "NE";
const std::string Instruction::MN_HS = "HS";
const std::string Instruction::MN_LO = "LO";
const std::string Instruction::MN_MI = "MI";
const std::string Instruction::MN_PL = "PL";
const std::string Instruction::MN_VS = "VS";
const std::string Instruction::MN_VC = "VC";
const std::string Instruction::MN_HI = "HI";
const std::string Instruction::MN_LS = "LS";
const std::string Instruction::MN_GE = "GE";
const std::string Instruction::MN_LT = "LT";
const std::string Instruction::MN_GT = "GT";
const std::string Instruction::MN_LE = "LE";
const std::string Instruction::MN_AL = "AL";
const std::string Instruction::MN_NV = "NV";
    
const char Instruction::OP_AND;
const char Instruction::OP_EOR;
const char Instruction::OP_SUB;
const char Instruction::OP_RSB;
const char Instruction::OP_ADD;
const char Instruction::OP_ADC;
const char Instruction::OP_SBC;
const char Instruction::OP_RSC;
const char Instruction::OP_TST;
const char Instruction::OP_TEQ;
const char Instruction::OP_CMP;
const char Instruction::OP_CMN;
const char Instruction::OP_ORR;
const char Instruction::OP_MOV;
const char Instruction::OP_BIC;
const char Instruction::OP_MVN;
    
const char Instruction::CND_EQ;
const char Instruction::CND_NE;
const char Instruction::CND_HS;
const char Instruction::CND_LO;
const char Instruction::CND_MI;
const char Instruction::CND_PL;
const char Instruction::CND_VS;
const char Instruction::CND_VC;
const char Instruction::CND_HI;
const char Instruction::CND_LS;
const char Instruction::CND_GE;
const char Instruction::CND_LT;
const char Instruction::CND_GT;
const char Instruction::CND_LE;
const char Instruction::CND_AL;
const char Instruction::CND_NV;

} // namespace vm