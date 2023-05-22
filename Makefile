SDL2INC=include/
SDL2LIB=lib/x64/

mimek.exe: src/main.cpp
	@cl	/W4 /sdl /nologo  			\
			/wd4100									\
			/Zi											\
			/I$(SDL2INC)						\
			/Femimek.exe						\
			src/main.cpp						\
			shell32.lib							\
			/link										\
				/LIBPATH:"$(SDL2LIB)"	\
				/SUBSYSTEM:WINDOWS		\
				SDL2.lib SDL2main.lib
				
clean:
	@del *.obj *.exe *.ilk *.pdb *.dll *~

