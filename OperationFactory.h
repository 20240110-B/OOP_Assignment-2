#pragma once
#include <memory>
#include <stdexcept>
#include "Instruction.h"

class OperationFactory {
public:
   
    static void executeOperation(const Instruction& inst, class CPU& cpu) {
        int op = inst.getOpcode();
        
      
        switch (op) {
            case 1:
              
                break;
            case 2:
                
                break;
            default:
                throw std::runtime_error("Unsupported or Invalid Opcode in OperationFactory");
        }
    }
};