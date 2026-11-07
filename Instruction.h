#pragma once
#include <string>
#include <stdexcept>

class Instruction {
private:
    std::string raw;
    int opcode;
    int r;
    int s;
    int t;
    int x;
    int y;

public:
    
    Instruction(std::string rawCode) {
        raw = rawCode;
        if (raw.length() < 4) {
            throw std::invalid_argument("Invalid instruction length");
        }
        
        opcode = std::stoi(raw.substr(0, 1), 0, 16);
        r = std::stoi(raw.substr(1, 1), 0, 16);
        s = std::stoi(raw.substr(2, 1), 0, 16);
        t = std::stoi(raw.substr(3, 1), 0, 16);
        x = std::stoi(raw.substr(2, 2), 0, 16); 
        y = std::stoi(raw.substr(3, 1), 0, 16);
    }

    int getOpcode() const { return opcode; }
    int getR() const { return r; }
    int getS() const { return s; }
    int getT() const { return t; }
    int getXY() const { return x; }
    int getY() const { return y; }
    std::string getRaw() const { return raw; }
};