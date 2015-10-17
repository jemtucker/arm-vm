//
//  VirtualMachine.h
//  virtualmachine
//
//  Created by Jem Tucker on 10/10/2015.
//  Copyright (c) 2015 Jem Tucker. All rights reserved.
//

#ifndef __virtualmachine__VirtualMachine__
#define __virtualmachine__VirtualMachine__

#include <vector>

#define NUM_REGS 16

#define REG_SP 15
#define REG_LR 15
#define REG_PC 15

typedef struct {
    uint32_t instruction;
    uint32_t condition;
    uint32_t reg_dest;
    uint32_t reg_n;
    uint32_t reg_m;
    uint32_t reg_m_shift;
    uint32_t imm;
    uint32_t imm_shift;
} Operation;

class Decoder;


class VirtualMachine {
    std::vector<uint32_t> m_registers = std::vector<uint32_t>( NUM_REGS );
    
    bool m_running = true;
    
    uint32_t *m_reg_sp = &m_registers[ REG_SP ];
    uint32_t *m_reg_lr = &m_registers[ REG_LR ];
    uint32_t *m_reg_pc = &m_registers[ REG_PC ];
    
    uint32_t m_reg_cpsr = 0;
    
    // Instruction parts
    uint32_t m_op_code = 0;
    uint32_t m_cond = 0;
    uint32_t m_s = 0;
    uint32_t m_i = 0;
    uint32_t m_op_reg_d = 0;
    uint32_t m_op_reg_n = 0;
    uint32_t m_op_reg_m = 0;
    uint32_t m_op_reg_s = 0;
    uint32_t m_imm_val = 0;
    uint32_t m_imm_rot = 0;
    uint32_t m_carry = 0;
    
    Decoder decoder;
    
    uint32_t fetch(std::vector<uint32_t> instructions);
    
    void decode(uint32_t instruction);
    void execute();
    
public:
    uint32_t run(std::vector<uint32_t> instructions);
    void show_registers();
};
    


#endif /* defined(__virtualmachine__VirtualMachine__) */
