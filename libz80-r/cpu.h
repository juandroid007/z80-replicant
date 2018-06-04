#include "types.h"

#ifndef CPU_H_
#define CPU_H_

//Flags del procesador
enum flag_t {
	FLAGS_S = 0x80, //Sign flag
	FLAGS_Z = 0x40, //Zero flag
	FLAGS_5 = 0x20, //5-flag (reserved)
	FLAGS_H = 0x10, //Half carry flag
	FLAGS_3 = 0x08, //3-flag (reserved)
	FLAGS_P = 0x04, //Parity/Overflow flag
	FLAGS_N = 0x02, //DAA flag
	FLAGS_C = 0x01  //Carry flag
};

/*
Estructura de registro. A través de esta estructura de 16 bits se
puede acceder a un registro virtual de 16 bits, o a los dos
registros de los que se compone simultáneamente.

Ejemplo: con un union register_t, se puede acceder a BC con
bc.WORD, a B con bc.BYTES.H, y a C con bc.BYTES.L.
*/
union register_t {
	word WORD;

	struct {
		byte L, H;
	} BYTES;
};

/*
Banco de registros. El Z80 tiene varios bancos de registros y
para cada banco tiene ocho registros de 8 bits que virtualmente
pueden agruparse en 4 registros virtuales de 16 bits.
*/
struct bank_t {
	union register_t
		bc,
		de,
		hl,
		af;
	/*byte a, f;
	byte b, c;
	byte d, e;
	byte h, l;*/
};

struct cpu_t {
	word mem[0x10000];			//Memory

	struct bank_t main;			//Main Register bank_t
	struct bank_t alternate;	//Alternate register bank

	union register_t pc;		//Program counter
	union register_t sp; 		//Stack pointer
	union register_t ix; 		//Index X
	union register_t iy; 		//Index Y
	byte i; 					//Interruptor vector
	byte r; 					//Memory Refresh

	int tstates;				//T-State counter
};

#endif