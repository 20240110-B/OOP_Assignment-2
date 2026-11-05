// Vole Machine - Memory, RegisterFile, Screen and Machine parts
// NOTE: Machine uses the ALU and CPU classes, so those must be defined
// above Machine (they are in vole.cpp) for this file to compile.
#include <iostream>
#include <string>
using namespace std;

// Number -> hex text. Example: toHex(10, 2) gives "0A"
string toHex(int value, int digits) {
    string chars = "0123456789ABCDEF", text = "";
    for (int i = 0; i < digits; i++) {
        text = chars[value % 16] + text;
        value = value / 16;
    }
    return text;
}

// ---------------- Memory: 256 cells ----------------
class Memory {
    int cells[256] = {0};
public:
    int read(int address) { return cells[address % 256]; }
    void write(int address, int value) { cells[address % 256] = value & 255; }

    void display() {
        cout << "\nMemory:\n     0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n";
        for (int row = 0; row < 16; row++) {
            cout << toHex(row, 1) << "0 | ";
            for (int col = 0; col < 16; col++)
                cout << toHex(cells[row * 16 + col], 2) << " ";
            cout << "\n";
        }
    }
};

// ---------------- RegisterFile: R0 to RF ----------------
class RegisterFile {
    int regs[16] = {0};
public:
    int get(int index) { return regs[index]; }
    void set(int index, int value) { regs[index] = value & 255; }

    void display() {
        cout << "\nRegisters:\n";
        for (int i = 0; i < 16; i++) {
            cout << "R" << toHex(i, 1) << "=" << toHex(regs[i], 2) << "  ";
            if (i == 7) cout << "\n";
        }
        cout << "\n";
    }
};

// ---------------- Screen ----------------
class Screen {
    string text = "";
public:
    void print(int value) { text += toHex(value, 2) + " "; }
    void clear() { text = ""; }
    void display() { cout << "\nScreen: " << text << "\n"; }
};

// ---------------- (ALU and CPU classes go here) ----------------

// ---------------- Machine: owns all the parts ----------------
class Machine {
    Memory memory;
    RegisterFile regs;
    Screen screen;
    ALU alu;
    CPU cpu;
public:
    Memory& getMemory()       { return memory; }
    RegisterFile& getRegisters() { return regs; }
    Screen& getScreen()       { return screen; }
    CPU& getCPU()             { return cpu; }

    void step() { cpu.step(memory, regs, screen, alu); }

    void displayState() {
        cout << "\nPC = " << toHex(cpu.getPC(), 2) << "    IR = " << cpu.getIR() << "\n";
        memory.display();
        regs.display();
        screen.display();
    }
};

