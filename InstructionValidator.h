#pragma once
#include "Instruction.h"
#include <stdexcept>

class InstructionValidator {
public:
    
    bool isValid(const Instruction& inst) {
        int op = inst.getOpcode();
        
        if (op < 1 || op > 12) {
            return false;
        }
        return true;
    }

    
    std::string getErrorMessage(const Instruction& inst) {
        if (!isValid(inst)) {
            return "Error: Invalid Opcode detected!";
        }
        return "Instruction is valid.";
    }
};