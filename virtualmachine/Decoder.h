//
//  Decoder.h
//  virtualmachine
//
//  Created by Jem Tucker on 17/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include <cstdint>

#ifndef __virtualmachine__Decoder__
#define __virtualmachine__Decoder__

typedef struct {
    char s = 0;
    char i = 0;
    char code = 0;
    char cond = 0;
    char reg_d = 0;
    char reg_n = 0;
    char reg_m = 0;
    char reg_s = 0;
    char imm_val = 0;
    char imm_rot = 0;
    char carry = 0;
} DecodedOperation;

class Decoder {
public:
    DecodedOperation decode(uint32_t instr);
};

#endif /* defined(__virtualmachine__Decoder__) */
