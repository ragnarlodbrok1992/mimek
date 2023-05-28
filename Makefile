SDL2INC=include/
SDL2LIB=lib/x64/
MIMEKINC=src/mimek/

mimek.exe: src/main.cpp
	@cp lib\x64\SDL2.dll .
	@cl	/W4 /sdl /nologo 	\
			/std:c++20 \
			/Zi	\
			/EHsc	\
			/I$(SDL2INC) \
			/I$(MIMEKINC)	\
			/Femimek.exe \
			src/mimek/Render.cpp \
			src/mimek/Input.cpp \
			src/mimek/UIelements.cpp \
			src/mimek/mimek.cpp	\
			src/main.cpp \
			shell32.lib	\
			User32.lib	\
			/link	\
				/LIBPATH:"$(SDL2LIB)"	\
				SDL2.lib SDL2main.lib
				
clean:
	@del *.obj *.exe *.ilk *.pdb *.dll *~

