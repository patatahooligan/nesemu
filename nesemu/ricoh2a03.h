#pragma once

#include "stdafx.h"

class Ricoh2A03 {
	private:
		// A bunch of useful enums for readability of interal workings

		// Referring to bits of the P flag register
		enum class Flag {
			Carry = 0,
			Zero = 1,
			Interrupt = 2,
			Decimal = 3,
			S1 = 4,
			S2 = 5,
			Overflow = 6,
			Negative = 7
		};

		// Possibly useless as code is getting refactored. Keep until design is finalized.
		enum class instruction_name {
			ADC, AND, ASL, BCC, BCS, BEQ, BIT, BMI, BNE, BPL, BRK, BVC, BVS, CLC,
			CLD, CLI ,CLV, CMP, CPX, CPY, DEC, DEX, DEY, EOR, INC, INX, INY, JMP,
			JSR, LDA, LDX, LDY, LSR, NOP, ORA, PHA, PHP, PLA, PLP, ROL, ROR, RTI,
			RTS, SBC, SEC, SED, SEI, STA, STX, STY ,TAX, TAY, TSX, TXA, TXS, TYA,

			// Unofficial op-code
			AHX, ALR, ANC, ARR, AXS, DCP, ISC, LAS, LAX, RLA, RRA, SAX, SHX, SHY, SLO, SRE, STP, TAS, XAA
		};

		enum class addressing_mode {
			zero_x, zero_y, abs_x, abs_y, ind_x, ind_y,
			accumulator, immediate, zero, abs, relative, indirect,
			implicit
		};

		// Aliases for the register and Ram types
		// The underlying type needs to be in 2-complement representation
		// and it must be valid to alias one with the other.
		using byte_t = int8_t;
		using ubyte_t = uint8_t;

		struct {
			uint16_t PC;
			ubyte_t
				SP = 0xFD,
				P = 0x34,
				A = 0,
				X = 0,
				Y = 0;
		} Register;

		ubyte_t ram[2048];

		addressing_mode get_addressing(const ubyte_t opcode);

		void process_next_instruction();

		void set_flag(Flag flag, bool value);

		bool get_flag(Flag flag);
};
