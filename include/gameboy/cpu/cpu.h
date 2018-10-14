#ifndef INCLUDE_GAMEBOY_CPU_CPU_H_
#define INCLUDE_GAMEBOY_CPU_CPU_H_

/* Cpu word */
typedef uint8_t CPU_WORD;

/* Registers */
enum
{
   REG_A, REG_F, REG_AF,
   REG_B, REG_C, REG_BC,
   REG_D, REG_E, REG_DE,
   REG_H, REG_L, REG_HL,
   REG_SP,
   REG_PC
};

/******************************************************************************
*
*        [CLASS] Gameboy CPU (Cpu)
*
*  [ABSTRACTION] www.pastraiser.com/cpu/gameboy/gameboy_opcodes.html
*                Emulates the Gameboy's CPU, which is similar to the intel Z80.
*                Reads opcodes and operands, and performs the corresponding
*                instruction. GB cpu is 8bit, but supports 16bit registers
*                by composing two adjacent 8bit registers.
*
*                Registers:
*                | A | F |
*                | B | C |
*                | D | E |
*                | H | L |
*                |   SP  |
*                |   PC  |
*                A,F,B,C,D,E,H,L are 8 bit registers
*                SP,PC are 16 bit registers
*                BC, DE, HL can be used as 16bit registers
*
*                [TODO] Instruction layout:
*
*
*******************************************************************************/
class Cpu
{
public:
   void execInstr(CPU_WORD opcode, void *operands);
private:
   // [TODO] Instructions, how is instr layed out?
   void nop();      // x00
   void ld();
   /* Registers */
   uint16_t mRegAF;
   uint16_t mRegBC;
   uint16_t mRegDE;
   uint16_t mRegHL;
   uint16_t mRegSP;
   uint16_t mRegPC;
};

#endif /* INCLUDE_GAMEBOY_CPU_CPU_H_ */
