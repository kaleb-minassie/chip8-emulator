[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/XpvI6cTa)
# CHIP-8 Emulator - CMSC 411 Spring 2025

# Semester Project

# First Checkpoint: Saturday, March 29th by 11:59:00 PM EDT

# Due Date: Saturday, May 3rd by 11:59:00 PM EDT

## Current Status

- Opcode implementation: 10 opcodes implememented
- SDL basecode added
- `mychip8.c` file created for core emulator logic

## Progress

- Implement full CHIP-8 fetch-decode-execute cycle
- Accurately emulate all 35 CHIP-8 opcodes
- Load and run CHIP-8 ROMs with proper input/output handling

## Project Description

A simple CHIP-8 emulator written in C that can run classic CHIP-8 games using SDL for graphics, input, and sound.

Functions to implement in order to use this interface:

- void chip8_init(void) — Initialize anything your emulator requires initialized on startup. This function may be empty if you do not require any initialization on startup,     but it must be provided.
- void chip8_shutdown(void) — Clean up anything your emulator requirese to be cleaned up on shut down. This function may be empty if it is not required in your design, but 
   it must be provided.
- void chip8_reset(void) — Reset the state of your CHIP-8 Emulation code, including resetting any CPU registers, clearing the stack, etc. The program counter must be       
  initialized to 0x200, the i register to 0, and the stack pointer to 0. The general-purpose (Vx) registers must be cleared to 0.
- void chip8_execute_instruction(void) — Execute a single CHIP-8 instruction from the current location of the program counter.
  
In addition, the following functions are provided by the interface for your use as you see fit to use them:
- uint8_t chip8_mem_read(uint16_t addr) — Read a byte of memory from the specified address, returning it.
- void chip8_mem_write(uint16_t addr, uint8_t val) — Write the specified value to the address specified in memory.
- uint8_t chip8_register_read(uint8_t reg) — Read the current value of the specified register, returning it. The controls are at registers 0-15, the DT timer at 16, and the    ST timer at 17.
- void chip8_register_write(uint8_t reg, uint8_t val) — Write a value to the specified register. Only registers 16 and 17 (DT and ST) are valid. Writes to any other register 
  will be ignored.
- void chip8_clear_frame(void) — Clear all pixels from the framebuffer, resetting all pixels to black.
- void chip8_mem_clear(void) — Clear all memory to 0.
- void chip8_mem_reset(void) — Clear all memory to 0, reset internal registers, and reload the current ROM. This is meant to be called as part of your void chip8_reset(void) 
  function after you have initialized the CPU registers.
- int chip8_draw_sprite(uint16_t addr, uint8_t x, uint8_t y, uint8_t height) — Draw a sprite from the specified location in memory to the x and y coordinates provided, with    the specified height. Returns 1 if there was a collision with an already drawn pixel, 0 otherwise.

Controls are mapped in the interface to the keypad controls of the CHIP-8 in the following way:

      1 2 3 4
      q w e r
      a s d f
      z c v b

In the normal key layout, the controls are specified as they were on the COSMAC VIP system:

      1 2 3 C
      4 5 6 D
      7 8 9 E
      A 0 B F

An alternate key layout is provided for ROMs designed for the DREAM 6800 and ETI-660 computers if you come across any. In those systems, the control layout is this one that might seem more customary:

      0 1 2 3
      4 5 6 7
      8 9 A B
      C D E F

The example roms provided in the link in this document use the standard COSMAC VIP key layout. To use the other layout, provide the -k flag to the program before the name of the rom to load.

To compile with the provided SDL UI, you will need to install the SDL library and its development tools on your system. On Debian/Ubuntu/Pop!_OS Linux distributions, you will need to install at least the build-essential and libsdl1.2-dev packages with apt. On other Linux distributions, you will need to install similar packages (for instance, on Fedora you should look for the sdl12-compat-devel package, plus your normal compiler setup). On Windows, if you install MinGW-w64 and MSYS2, you can use the built-in pacman package tool to install either mingw-64-SDL or mingw-w64-sdl12-compat to build the code. On macOS, you can use MacPorts to install the sdl12-compat package, or you can try to build SDL 2.x and the compatibility library from source (or, set up a VM running Ubuntu, and follow the directions above).

You should then be able to use a command line such as the following to build the code (assuming you leave the filename as is and your code is in a file named mychip8.c):

```bash
gcc -o chip8 sdl-basecode.c mychip8.c -lSDL -lm

```
This should result in a program called chip8 being built.

## First Checkpoint

By the First Checkpoint data above, you must have the following implemented in your code:

          - Basic fetch/execute cycle
          - Implementation of at least 10 out the 35 opcodes of CHIP-8
          
The code implementing all of this must be in your GitHub repository by the date/time listed above. In addition, you must have at least three non-trivial commits made on separate days to your repository by this time.

## Resources Used

- [CHIP-8 Documentation GitHub](https://github.com/trapexit/chip-8_documentation)
- [Wikipedia: CHIP-8](https://en.wikipedia.org/wiki/CHIP-8)
- [Guide by Tobias V. Langhoff](https://tobiasvl.github.io/blog/write-a-chip-8-emulator/#google_vignette)
