#pragma once

#include "stdafx.h"

class Ricoh2A03 {
	private:
		struct {
			uint16_t PC;
			uint8_t
				SP = 0xFD,
				P = 0x34,
				A = 0,
				X = 0,
				Y = 0;
		} Register;

		uint8_t ram[2048];

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

		instruction_name get_instruction(const uint8_t opcode);

		addressing_mode get_addressing(const uint8_t opcode);

		void process_next_instruction();
};
