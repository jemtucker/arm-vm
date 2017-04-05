//
//  VirtualMachineTest.cpp
//  virtualmachine
//
//  Created by Jem Tucker on 24/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#include <gtest/gtest.h>
#include "VirtualMachine.h"
#include "Assembler.h"

class VirtualMachineTest: public ::testing::Test {
protected:
    vm::VirtualMachine vm;
};

TEST_F(VirtualMachineTest, StoresValuesInRegisters) {
    // TODO
}
