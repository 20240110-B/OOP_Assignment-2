#pragma once
#include "Instruction.h"
#include <string>

class InstructionDecoder {
public:
    
    Instruction decode(std::string rawInstruction) {
        return Instruction(rawInstruction);
    }
};