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
    static const std::string AND;
    static const std::string EOR;
    static const std::string SUB;
    static const std::string RSB;
    static const std::string ADD;
    static const std::string ADC;
    static const std::string SBC;
    static const std::string RSC;
    static const std::string TST;
    static const std::string TEQ;
    static const std::string CMP;
    static const std::string CMN;
    static const std::string ORR;
    static const std::string MOV;
    static const std::string BIC;
    static const std::string MVN;
    
    static const std::string EQ;
    static const std::string NE;
    static const std::string HS;
    static const std::string LO;
    static const std::string MI;
    static const std::string PL;
    static const std::string VS;
    static const std::string VC;
    static const std::string HI;
    static const std::string LS;
    static const std::string GE;
    static const std::string LT;
    static const std::string GT;
    static const std::string LE;
    static const std::string AL;
    static const std::string NV;
    
public:
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
