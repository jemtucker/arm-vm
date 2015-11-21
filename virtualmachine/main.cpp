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
    assembler::Assembler ass;
    vm::VirtualMachine vm;
    vm.set_debug(true);
    
    auto instr = ass.assemble("MOV R1 #9");
    
    vm.run(instr);
    
    return 0;
}
