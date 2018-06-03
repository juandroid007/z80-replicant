#z80/libz80
add_library(libz80-r STATIC
	cpu.h
	opcodes.h
	opcodes.c
	types.h
)

target_include_directories(z80-replicant PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
