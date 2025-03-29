#include <stdint.h>
#include "mychip8.h"

// basic emulator state
static uint8_t V[16];        // registers V0 to VF
static uint16_t I;           // index register
static uint16_t pc = 0x200;  // program counter starts at 0x200

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

        case 0x6000:
            // 6XNN - set Vx = NN
            V[x] = nn;
            break;

        case 0x7000:
            // 7XNN - Vx += NN
            V[x] += nn;
            break;

        case 0xA000:
            // ANNN - set I = NNN
            I = nnn;
            break;

        case 0xD000:
            // DXYN - draw sprite
            V[0xF] = chip8_draw_sprite(I, V[x], V[y], n);
            break;

        default:
            // not handled yet
            break;
    }
}       
