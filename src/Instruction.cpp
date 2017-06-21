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

} // namespace vm
