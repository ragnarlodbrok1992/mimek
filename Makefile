SDL2INC=include/
SDL2LIB=lib/x64/
MIMEKINC=src/mimek/

mimek.exe: src/main.cpp
	@cl	/W4 /sdl /nologo  			\
			/std:c++20							\
			/Zi											\
			/EHsc										\
			/I$(SDL2INC)						\
			/I$(MIMEKINC) 					\
			/Femimek.exe						\
			src/main.cpp						\
			src/mimek/mimek.cpp			\
			shell32.lib							\
			User32.lib							\
			/link										\
				/LIBPATH:"$(SDL2LIB)"	\
				SDL2.lib SDL2main.lib
				
clean:
	@del *.obj *.exe *.ilk *.pdb *.dll *~

