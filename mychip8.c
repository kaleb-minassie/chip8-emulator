#include <stdint.h>
#include "mychip8.h"

// basic emulator state
static uint8_t V[16];        // registers V0 to VF
static uint16_t I;           // index register
static uint16_t pc = 0x200;  // program counter starts at 0x200
static uint16_t stack[16];  // stack for subroutine calls
static uint8_t sp = 0;      // stack pointer


void chip8_execute_instruction(void) {
    // grab the opcode (2 bytes)
    uint16_t opcode = (chip8_mem_read(pc) << 8) | chip8_mem_read(pc + 1);
    uint8_t x = (opcode >> 8) & 0xF;
    uint8_t y = (opcode >> 4) & 0xF;
    uint8_t n = opcode & 0xF;
    uint8_t nn = opcode & 0xFF;
    uint16_t nnn = opcode & 0x0FFF;

    pc += 2; // move to next instruction by default

    switch (opcode & 0xF000) {
        case 0x0000:
            if (opcode == 0x00E0) {
                // 00E0 - clear screen
                chip8_clear_frame();
            }
            break;

        case 0x1000:
            // 1NNN - jump to address
            pc = nnn;
            break;
        
        case 0x3000:
        // 3XNN - skip next if Vx == NN
        if (V[x] == nn) pc += 2;
        break;

        case 0x4000:
        // 4XNN - skip next if Vx != NN
        if (V[x] != nn) pc += 2;
        break;

        case 0x5000:
        if ((opcode & 0x000F) == 0x0) {
            // 5XY0 - skip next if Vx == Vy
            if (V[x] == V[y]) pc += 2;
        }
        break;
        
        case 0x6000:
            // 6XNN - set Vx = NN
            V[x] = nn;
            break;

        case 0x7000:
            // 7XNN - Vx += NN
            V[x] += nn;
            break;
        case 0x8000:
    switch (opcode & 0x000F) {
        case 0x0:
            // 8XY0 - set Vx = Vy
            V[x] = V[y];
            break;
        case 0x1:
            // 8XY1 - Vx = Vx OR Vy
            V[x] |= V[y];
            break;
        case 0x2:
            // 8XY2 - Vx = Vx AND Vy
            V[x] &= V[y];
            break;
        case 0x3:
            // 8XY3 - Vx = Vx XOR Vy
            V[x] ^= V[y];
            break;
        case 0x4:
            // 8XY4 - Vx += Vy (with carry)
            if (V[y] > (0xFF - V[x])) V[0xF] = 1;
            else V[0xF] = 0;
            V[x] += V[y];
            break;
        default:
            // not handled yet
            break;
    }
    break;
        
        case 0x9000:
        if ((opcode & 0x000F) == 0x0) {
            // 9XY0 - skip next if Vx != Vy
            if (V[x] != V[y]) pc += 2;
        }
        break;
        
        case 0xA000:
            // ANNN - set I = NNN
            I = nnn;
            break;

        case 0xD000:
            // DXYN - draw sprite
            V[0xF] = chip8_draw_sprite(I, V[x], V[y], n);
            break;
        
        case 0xF000:
        switch (opcode & 0x00FF) {
            case 0x07:
                // FX07 - Vx = delay timer
                V[x] = chip8_register_read(CHIP8_REG_DT);
                break;
            case 0x15:
                // FX15 - set delay timer = Vx
                chip8_register_write(CHIP8_REG_DT, V[x]);
                break;
            case 0x18:
                // FX18 - set sound timer = Vx
                chip8_register_write(CHIP8_REG_ST, V[x]);
                break;
            default:
                // not handled yet
                break;
        }
        break;

        default:
            // not handled yet
            break;
    }
}       

void chip8_init(void) {
    // todo: initialize chip8 state
}

void chip8_shutdown(void) {
    // todo: clean up emulator
}

void chip8_reset(void) {
      // clear all V registers
       for (int i = 0; i < 16; i++) {
        V[i] = 0;
    }

    // reset index and program counter
    I = 0;
    pc = 0x200;

    // clear memory and reload ROM
    chip8_mem_reset();
}
