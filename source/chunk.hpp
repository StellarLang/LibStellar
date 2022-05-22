#pragma once

#include <vector>
#include <cstdint>

#include "value.hpp"

namespace stellar {
    enum OpCode {
        OP_RETURN = 0x00,
        OP_CONSTANT = 0x01,
    };

    class Chunk {
    public:
        void writeInstruction(OpCode instruction, int line);
        void writeByte(uint8_t byte, int line);
        void writeConstant(const Value& value, int line);
        size_t addConstant(const Value& value);

        std::vector<uint8_t> getCode();
        std::vector<Value> getConstants();
        std::vector<int> getLines();

        void disassemble(const std::string& name);
    private:
        size_t disassembleInstruction(size_t offset);
        size_t constantInstruction(const std::string& name, size_t offset);

        std::vector<uint8_t> code;
        std::vector<Value> constants;
        std::vector<int> lines;
    };
}
