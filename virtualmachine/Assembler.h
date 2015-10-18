//
//  Assembler.h
//  virtualmachine
//
//  Created by Jem Tucker on 10/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__Assembler__
#define __virtualmachine__Assembler__

#include <map>
#include <string>
#include <vector>

namespace assembler {

class Assembler {
    
    
public:
    std::vector<int> assemble(std::string code);
};
    
} // namespace assembler

#endif /* defined(__virtualmachine__Assembler__) */
