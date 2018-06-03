#include "opcodes.h"

/*
Extrae los trozos de un opcode a partir del opcode tal cual que
se haya sacado de la memoria. Aplica una serie de máscaras de
bit para sacar el resultado.

-No probado.

@param opcode - opcode leído de memoria
@param opstruct - estructura donde se volcan los datos
*/
void extract_opcode(char opcode, struct opcode_t* opstruct) {
	opstruct -> x = (opcode & 0xC0) >> 6;
	opstruct -> y = (opcode & 0x38) >> 3;
	opstruct -> z = (opcode & 0x07);

	opstruct -> p = opstruct -> y >> 1;
	opstruct -> q = opstruct -> y & 1;
}

void execute_opcode(struct cpu_t* cpu) {
	//Extraer opcode
	struct opsctruct opdata;
	byte opcode = cpu -> mem[cpu -> pc.WORD++]:
	extract_opcode(opcode, &opdata);


	//Procesar opcode
	if (z == 0) {
		execute_table0(cpu, &opdata);
	}
	else if (z == 1) {
		execute_table1(cpu, &opdata);
	}
	else if (z == 2) {
		execute_table2(cpu, &opdata);
	}

	//Otras tareas
}