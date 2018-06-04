#include "cpu.h"
#include "opcodes.h"
#include <stdio.h>

int main() {
	struct cpu_t cpu;
	cpu.main.bc.WORD = 0x1234;
	cpu.main.bc.WORD++
	printf("%x\n", cpu.main.bc.WORD);

	ejecutar_tabla(2);

	return 0;
}