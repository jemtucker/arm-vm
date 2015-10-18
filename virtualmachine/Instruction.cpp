//
//  Instruction.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include "Instruction.h"

namespace vm {

const std::string Instruction::AND = "AND";
const std::string Instruction::EOR = "EOR";
const std::string Instruction::SUB = "SUB";
const std::string Instruction::RSB = "RSB";
const std::string Instruction::ADD = "ADD";
const std::string Instruction::ADC = "ADC";
const std::string Instruction::SBC = "SBC";
const std::string Instruction::RSC = "RSC";
const std::string Instruction::TST = "TST";
const std::string Instruction::TEQ = "TEQ";
const std::string Instruction::CMP = "CMP";
const std::string Instruction::CMN = "CMN";
const std::string Instruction::ORR = "ORR";
const std::string Instruction::MOV = "MOV";
const std::string Instruction::BIC = "BIC";
const std::string Instruction::MVN = "MVN";

const std::string Instruction::EQ = "EQ";
const std::string Instruction::NE = "NE";
const std::string Instruction::HS = "HS";
const std::string Instruction::LO = "LO";
const std::string Instruction::MI = "MI";
const std::string Instruction::PL = "PL";
const std::string Instruction::VS = "VS";
const std::string Instruction::VC = "VC";
const std::string Instruction::HI = "HI";
const std::string Instruction::LS = "LS";
const std::string Instruction::GE = "GE";
const std::string Instruction::LT = "LT";
const std::string Instruction::GT = "GT";
const std::string Instruction::LE = "LE";
const std::string Instruction::AL = "AL";
const std::string Instruction::NV = "NV";

} // namespace vm