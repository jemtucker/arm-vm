//
//  Instruction.h
//  virtualmachine
//
//  Created by Jem Tucker on 18/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__Instruction__
#define __virtualmachine__Instruction__

#include <string>

namespace vm {

class Instruction {
public:
    static const std::string MN_AND;
    static const std::string MN_EOR;
    static const std::string MN_SUB;
    static const std::string MN_RSB;
    static const std::string MN_ADD;
    static const std::string MN_ADC;
    static const std::string MN_SBC;
    static const std::string MN_RSC;
    static const std::string MN_TST;
    static const std::string MN_TEQ;
    static const std::string MN_CMP;
    static const std::string MN_CMN;
    static const std::string MN_ORR;
    static const std::string MN_MOV;
    static const std::string MN_BIC;
    static const std::string MN_MVN;
    
    static const std::string MN_EQ;
    static const std::string MN_NE;
    static const std::string MN_HS;
    static const std::string MN_LO;
    static const std::string MN_MI;
    static const std::string MN_PL;
    static const std::string MN_VS;
    static const std::string MN_VC;
    static const std::string MN_HI;
    static const std::string MN_LS;
    static const std::string MN_GE;
    static const std::string MN_LT;
    static const std::string MN_GT;
    static const std::string MN_LE;
    static const std::string MN_AL;
    static const std::string MN_NV;
    
    static const char OP_AND = 0x00;
    static const char OP_EOR = 0x01;
    static const char OP_SUB = 0x02;
    static const char OP_RSB = 0x03;
    static const char OP_ADD = 0x04;
    static const char OP_ADC = 0x05;
    static const char OP_SBC = 0x06;
    static const char OP_RSC = 0x07;
    static const char OP_TST = 0x08;
    static const char OP_TEQ = 0x09;
    static const char OP_CMP = 0x0A;
    static const char OP_CMN = 0x0B;
    static const char OP_ORR = 0x0C;
    static const char OP_MOV = 0x0D;
    static const char OP_BIC = 0x0E;
    static const char OP_MVN = 0x0F;
    
    static const char CND_EQ = 0x00;
    static const char CND_NE = 0x01;
    static const char CND_HS = 0x02;
    static const char CND_LO = 0x03;
    static const char CND_MI = 0x04;
    static const char CND_PL = 0x05;
    static const char CND_VS = 0x06;
    static const char CND_VC = 0x07;
    static const char CND_HI = 0x08;
    static const char CND_LS = 0x09;
    static const char CND_GE = 0x0A;
    static const char CND_LT = 0x0B;
    static const char CND_GT = 0x0C;
    static const char CND_LE = 0x0D;
    static const char CND_AL = 0x0E;
    static const char CND_NV = 0x0F;

};
    
} // namespace vm
#endif /* defined(__virtualmachine__Instruction__) */
