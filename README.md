[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/XpvI6cTa)
# CHIP-8 Emulator - CMSC 411 Spring 2025

# Semester Project

# First Checkpoint: Saturday, March 29th by 11:59:00 PM EDT

# Due Date: Saturday, May 3rd by 11:59:00 PM EDT

## Changelog

- March 13: Added more information about compiling with the SDL-based UI.
- March 12: Added SDL-based Project UI and information on it and two more resource links.
- February 26: Initial Revision 

# Introduction
In this project, you will be implementing an emulator for a virtual machine called the CHIP-8. You will be responsible for implementing code to load CHIP-8 programs, interpret the instructions of the virtual machine, update the state of the virtual machine, generate graphics, and handle input from the user. Upon doing so, you will be able to play actual games designed for this virtual machine on your own computer in order to test out its functionality.

This project is to be completed individually. No group work is allowed on the project. You may discuss concepts behind the project with your classmates, however you are not allowed to directly collaborate on the assignment. You will turn in your project on GitHub, so please sign up for a GitHub account at your earliest convenience if you do not have one already. Please ensure that your UMBC email account is listed on the account (it does not have to be the primary email and your GitHub account username need not match your UMBC one).

## Project Requirements

You are to design and implement an emulator for the CHIP-8 virtual machine. Your project must be implemented either in the C or C++ programming language.

Your CHIP-8 emulator must implement all instructions of the original CHIP-8, as well as features such as input and video/sound output. Accuracy is important to ensure that programs written for the CHIP-8 work correctly in your emulator.

The instructor will provide a simple user interface for the emulator that will take in input from the user and provide it to your code by way of a C function. In addition, there will be functions that your code must implement that the user interface will call such as one to do one frame of emulation. The instructor's user interface will also be responsible for loading the program into the emulator and will provide an interface to read/write memory for the emulator.

The sample interface is available here. This interface provides the entire user interface and interaction code, as well as the implementation of sound support for your emulator. Everyone is expected to use this code, and during grading an unmodified version of this code will be used to bootstrap everyone's emulator by the TA.

You must implement the following functions in order to use this interface:

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
