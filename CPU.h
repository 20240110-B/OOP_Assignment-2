#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.h"
#include "InstructionDecoder.h"
#include "InstructionValidator.h"

class CPU {
private:
    int registers[16]; 
    int pc;           
    std::vector<std::string> memory; 
    
    InstructionDecoder decoder;
    InstructionValidator validator;

public:
    CPU() {
        pc = 0;
       
        for (int i = 0; i < 16; ++i) {
            registers[i] = 0;
        }
        memory.resize(256, "0000"); 
    }

    
    void loadProgram(const std::vector<std::string>& programCode) {
        for (size_t i = 0; i < programCode.size() && i < memory.size(); ++i) {
            memory[i] = programCode[i];
        }
    }

   
    void step() {
        if (pc >= memory.size()) return;

        
        std::string rawInst = memory[pc];
        pc++; 

        try {
          
            Instruction inst = decoder.decode(rawInst);

          
            if (!validator.isValid(inst)) {
                std::cout << validator.getErrorMessage(inst) << " at PC: " << pc - 1 << std::endl;
                return;
            }

            std::cout << "Successfully executed instruction: " << inst.getRaw() 
                      << " with Opcode: " << inst.getOpcode() << std::endl;

        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }

   
    int getRegister(int index) const {
        if (index >= 0 && index < 16) return registers[index];
        return 0;
    }

  
    void setRegister(int index, int value) {
        if (index >= 0 && index < 16) {
            registers[index] = value;
        }
    }
};