#z80/src
add_executable(z80
	main.c
)

target_link_libraries(z80 libz80-r)

install(TARGETS z80 DESTINATION bin)
