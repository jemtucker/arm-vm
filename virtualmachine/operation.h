//
//  operation.h
//  virtualmachine
//
//  Created by Jem Tucker on 12/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef virtualmachine_operation_h
#define virtualmachine_operation_h

/**
 *
 * Structure of bits
 *
 *   3                   2                   1                   0
 * 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 *  cond  |   |i|op_code|s| reg_n | reg_d |        operand_2
 *
 */

// Conditions (first 4 bits)

#define EQ 0x0
#define NE 0x1
#define HS 0x2
#define LO 0x3
#define MI 0x4
#define PL 0x5
#define VS 0x6
#define VC 0x7
#define HI 0x8
#define LS 0x9
#define GE 0xa
#define LT 0xb
#define GT 0xc
#define LE 0xd
#define AL 0xe
#define NV 0xf

// Data Processing Instructions

#define AND 0x0
#define EOR 0x1
#define SUB 0x2
#define RSB 0x3
#define ADD 0x4
#define ADC 0x5
#define SBC 0x6
#define RSC 0x7
#define TST 0x8
#define TEQ 0x9
#define CMP 0xa
#define CMN 0xb
#define ORR 0xc
#define MOV 0xd
#define BIC 0xe
#define MVN 0xf

#endif
