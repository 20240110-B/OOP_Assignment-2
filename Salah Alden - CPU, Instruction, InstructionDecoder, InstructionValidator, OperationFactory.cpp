#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// 1. Instruction Class
class Instruction {
private:
    std::string raw;
    int opcode, r, s, t, x, y;

public:
    Instruction(std::string rawCode) {
        raw = rawCode;
        if (raw.length() < 4) return;
        opcode = std::stoi(raw.substr(0, 1), nullptr, 16);
        r      = std::stoi(raw.substr(1, 1), nullptr, 16);
        s      = std::stoi(raw.substr(2, 1), nullptr, 16);
        t      = std::stoi(raw.substr(3, 1), nullptr, 16);
        x      = std::stoi(raw.substr(2, 2), nullptr, 16); 
        y      = std::stoi(raw.substr(3, 1), nullptr, 16);
    }

    int getOpcode() const { return opcode; }
    int getR() const { return r; }
    int getS() const { return s; }
    int getT() const { return t; }
    int getXY() const { return x; }
    int getY() const { return y; }
    std::string getRaw() const { return raw; }
};

// 2. InstructionDecoder Class
class InstructionDecoder {
public:
    Instruction decode(std::string rawInstruction) {
        return Instruction(rawInstruction);
    }
};

// 3. InstructionValidator Class
class InstructionValidator {
public:
    bool isValid(const Instruction& inst) {
        int op = inst.getOpcode();
        if (op < 1 || op > 12) return false;
        return true;
    }
};

class CPU;

// 4. OperationFactory Class
class OperationFactory {
public:
    static void executeOperation(const Instruction& inst, CPU& cpu) {
        int op = inst.getOpcode();
        switch (op) {
            case 1: break;
            case 2: break;
            case 3: break;
            case 4: break;
            default: break;
        }
    }
};

// 5. CPU Class
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
        for (int i = 0; i < 16; ++i) registers[i] = 0;
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

        Instruction inst = decoder.decode(rawInst);
        if (!validator.isValid(inst)) {
            std::cout << "Invalid Opcode at PC: " << pc - 1 << std::endl;
            return;
        }

        OperationFactory::executeOperation(inst, *this);
        std::cout << "Executed: " << inst.getRaw() << std::endl;
    }
};