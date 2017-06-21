#include "stdafx.h"

#include "ricoh2a03.h"

Ricoh2A03::instruction_name Ricoh2A03::get_instruction(const uint8_t opcode) {
	switch (opcode) {
		case 0x00:
			return instruction_name::BRK;
		case 0x01: case 0x05: case 0x09: case 0x0D: case 0x11: case 0x15: case 0x19: case 0x1D:
			return instruction_name::ORA;
		case 0x02: case 0x12: case 0x22: case 0x32: case 0x42: case 0x52: case 0x62: case 0x72:
		case 0x92: case 0xB2: case 0xD2: case 0xF2:
			return instruction_name::STP;
		case 0x03: case 0x07: case 0x0F: case 0x13: case 0x17: case 0x1B: case 0x1F:
			return instruction_name::SLO;
		case 0x06: case 0x0A: case 0x0E: case 0x16: case 0x1E:
			return instruction_name::ASL;
		case 0x08:
			return instruction_name::PHP;
		case 0x0B: case 0x2B:
			return instruction_name::ANC;
		case 0x10:
			return instruction_name::BPL;
		case 0x18:
			return instruction_name::CLC;
		case 0x20:
			return instruction_name::JSR;
		case 0x21: case 0x25: case 0x29: case 0x2D: case 0x31: case 0x35: case 0x39: case 0x3D:
			return instruction_name::AND;
		case 0x23: case 0x27: case 0x2F: case 0x33: case 0x37: case 0x3B: case 0x3F:
			return instruction_name::RLA;
		case 0x24: case 0x2C:
			return instruction_name::BIT;
		case 0x26: case 0x2A: case 0x2E: case 0x36: case 0x3E:
			return instruction_name::ROL;
		case 0x28:
			return instruction_name::PLP;
		case 0x30:
			return instruction_name::BMI;
		case 0x38:
			return instruction_name::SEC;
		case 0x40:
			return instruction_name::RTI;
		case 0x41: case 0x45: case 0x49: case 0x4D: case 0x51: case 0x55: case 0x59: case 0x5D:
			return instruction_name::EOR;
		case 0x43: case 0x47: case 0x4F: case 0x53: case 0x57: case 0x5B: case 0x5F:
			return instruction_name::SRE;
		case 0x46: case 0x4A: case 0x4E: case 0x56: case 0x5E:
			return instruction_name::LSR;
		case 0x48:
			return instruction_name::PHA;
		case 0x4B:
			return instruction_name::ALR;
		case 0x4C: case 0x6C:
			return instruction_name::JMP;
		case 0x50:
			return instruction_name::BVC;
		case 0x58:
			return instruction_name::CLI;
		case 0x60:
			return instruction_name::RTS;
		case 0x61: case 0x65: case 0x69: case 0x6D: case 0x71: case 0x75: case 0x79: case 0x7D:
			return instruction_name::ADC;
		case 0x63: case 0x67: case 0x6F: case 0x73: case 0x77: case 0x7B: case 0x7F:
			return instruction_name::RRA;
		case 0x66: case 0x6A: case 0x6E: case 0x76: case 0x7E:
			return instruction_name::ROR;
		case 0x68:
			return instruction_name::PLA;
		case 0x6B:
			return instruction_name::ARR;
		case 0x70:
			return instruction_name::BVS;
		case 0x78:
			return instruction_name::SEI;
		case 0x81: case 0x85: case 0x8D: case 0x91: case 0x95: case 0x99: case 0x9D:
			return instruction_name::STA;
		case 0x83: case 0x87: case 0x8F: case 0x97:
			return instruction_name::SAX;
		case 0x84: case 0x8C: case 0x94:
			return instruction_name::STY;
		case 0x86: case 0x8E: case 0x96:
			return instruction_name::STX;
		case 0x88:
			return instruction_name::DEY;
		case 0x8A:
			return instruction_name::TXA;
		case 0x8B:
			return instruction_name::XAA;
		case 0x90:
			return instruction_name::BCC;
		case 0x93: case 0x9F:
			return instruction_name::AHX;
		case 0x98:
			return instruction_name::TYA;
		case 0x9A:
			return instruction_name::TXS;
		case 0x9B:
			return instruction_name::TAS;
		case 0x9C:
			return instruction_name::SHY;
		case 0x9E:
			return instruction_name::SHX;
		case 0xA0: case 0xA4: case 0xAC: case 0xB4: case 0xBC:
			return instruction_name::LDY;
		case 0xA1: case 0xA5: case 0xA9: case 0xAD: case 0xB1: case 0xB5: case 0xB9: case 0xBD:
			return instruction_name::LDA;
		case 0xA2: case 0xA6: case 0xAE: case 0xB6: case 0xBE:
			return instruction_name::LDX;
		case 0xA3: case 0xA7: case 0xAB: case 0xAF: case 0xB3: case 0xB7: case 0xBF:
			return instruction_name::LAX;
		case 0xA8:
			return instruction_name::TAY;
		case 0xAA:
			return instruction_name::TAX;
		case 0xB0:
			return instruction_name::BCS;
		case 0xB8:
			return instruction_name::CLV;
		case 0xBA:
			return instruction_name::TSX;
		case 0xBB:
			return instruction_name::LAS;
		case 0xC0: case 0xC4: case 0xCC:
			return instruction_name::CPY;
		case 0xC1: case 0xC5: case 0xC9: case 0xCD: case 0xD1: case 0xD5: case 0xD9: case 0xDD:
			return instruction_name::CMP;
		case 0xC3: case 0xC7: case 0xCF: case 0xD3: case 0xD7: case 0xDB: case 0xDF:
			return instruction_name::DCP;
		case 0xC6: case 0xCE: case 0xD6: case 0xDE:
			return instruction_name::DEC;
		case 0xC8:
			return instruction_name::INY;
		case 0xCA:
			return instruction_name::DEX;
		case 0xCB:
			return instruction_name::AXS;
		case 0xD0:
			return instruction_name::BNE;
		case 0xD8:
			return instruction_name::CLD;
		case 0xE0: case 0xE4: case 0xEC:
			return instruction_name::CPX;
		case 0xE1: case 0xE5: case 0xE9: case 0xED: case 0xF1: case 0xF5: case 0xF9: case 0xFD:
			return instruction_name::SBC;
		case 0xE3: case 0xE7: case 0xEF: case 0xF3: case 0xF7: case 0xFB: case 0xFF:
			return instruction_name::ISC;
		case 0xE6: case 0xEE: case 0xF6: case 0xFE:
			return instruction_name::INC;
		case 0xE8:
			return instruction_name::INX;
		case 0xEB:
			return instruction_name::SBC;
		case 0xF0:
			return instruction_name::BEQ;
		case 0x04: case 0x0C: case 0x14: case 0x1A: case 0x1C: case 0x34: case 0x3A: case 0x3C:
		case 0x44: case 0x54: case 0x5A: case 0x5C: case 0x64: case 0x74: case 0x7A: case 0x7C:
		case 0x80: case 0x82: case 0x89: case 0xC2: case 0xD4: case 0xDA: case 0xDC: case 0xE2:
		case 0xEA: case 0xF4: case 0xFA: case 0xFC:
			return instruction_name::NOP;
	}
	throw std::runtime_error(std::string("Unprocessed opcode : ") + std::to_string(opcode) + "\n");
}

Ricoh2A03::addressing_mode Ricoh2A03::get_addressing(const uint8_t opcode) {
	switch (opcode % 0x20) {
		case 0x00:
			// In lieu of an else statement, it uses the following cases. Do NOT add a break after the if statement!
			if (opcode == 0x20)
				return addressing_mode::abs;
		case 0x02:
			if (opcode < 0x80)
				return addressing_mode::implicit;
			else
				return addressing_mode::immediate;

		case 0x01: case 0x03:
			return addressing_mode::ind_x;

		case 0x04: case 0x05: case 0x06: case 0x07:
			return addressing_mode::zero;
			
		case 0x08: case 0x0A: case 0x12: case 0x18: case 0x1A:
			return addressing_mode::implicit;

		case 0x09: case 0x0B:
			return addressing_mode::immediate;

		case 0x0C:
			// In lieu of an else statement, it uses the following cases. Do NOT add a break after the if statement!
			if (opcode == 0x6C)
				return addressing_mode::indirect;
		case 0x0D: case 0x0E: case 0x0F:
			return addressing_mode::abs;

		case 0x10:
			return addressing_mode::relative;

		case 0x11: case 0x13:
			return addressing_mode::ind_y;

		case 0x16: 	case 0x17:
			if (opcode > 0x79 && opcode < 0xC0)
				return addressing_mode::zero_y;
		case 0x14: 	case 0x15:
			return addressing_mode::zero_x;

		case 0x19: case 0x1B:
			return addressing_mode::abs_y;

		case 0x1E: 	case 0x1F:
			if (opcode > 0x79 && opcode < 0xC0)
				return addressing_mode::abs_y;
		case 0x1C: 	case 0x1D:
			return addressing_mode::abs_x;
	}
	throw std::runtime_error(std::string("Unprocessed opcode : ") + std::to_string(opcode) + "\n");
}

void Ricoh2A03::process_next_instruction() {
	instruction_name instruction = get_instruction(ram[Register.PC]);
	addressing_mode addressing = get_addressing(ram[Register.PC]);;

	// TODO: figure out the best way to handle 16-bit arguments
	uint8_t argument = ram[Register.PC + 1];
	uint8_t value;
	switch (addressing) {
		case addressing_mode::zero_x:
			value = ram[(Register.X + argument) % 256];
			break;
		case addressing_mode::zero_y:
			value = ram[(Register.Y + argument) % 256];
			break;
		case addressing_mode::zero:
			value = ram[argument % 256];
			break;
		// TODO: add the rest here
	}
}