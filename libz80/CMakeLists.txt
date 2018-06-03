add_library(z80-replicant STATIC
	cpu.h
	opcodes.h
	opcodes.c
	types.h
)

target_include_directories(z80-replicant PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


