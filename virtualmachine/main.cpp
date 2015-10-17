//
//  main.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 10/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <string>

#include "VirtualMachine.h"
#include "Assembler.h"

int main(int argc, const char * argv[]) {
    
    VirtualMachine vm;
    
    std::vector<int> instructions = { 0xF064, 0x1100, 0x2221, 0x0000 };
    
//    vm.run(instructions);
//    
//    Assembler ass;
//    auto byte_code = ass.assemble("MOV r2 r3");
//    
//    for (auto itr = byte_code.begin(); itr != byte_code.end(); itr++) {
//        printf("%04x \n", *itr);
//    }
//    
//    vm.run(byte_code);
//    
    return 0;
}
