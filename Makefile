SDL2INC=include/
SDL2LIB=lib/x64/
MIMEKINC=src/mimek/

mimek: src/main.cpp
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
			src/mimek/Utils.cpp \
			src/mimek/Color.cpp \
			src/mimek/mimek.cpp	\
			src/main.cpp \
			shell32.lib	\
			User32.lib	\
			/link	\
				/LIBPATH:"$(SDL2LIB)"	\
				SDL2.lib SDL2main.lib
				
clean:
	@del *.obj *.exe *.ilk *.pdb *.dll *.lib *~

scanlinefillalgorithm: test/ScanlineFillAlgorithm.cpp
	@cp lib\x64\SDL2.dll .
	@cl /W4 /sdl /nologo \
		/std:c++20 \
		/Zi \
		/EHsc \
		/I$(SDL2INC) \
		/I$(MIMEKINC) \
		/Fescanlinefillalgorithm.exe \
		test/ScanlineFillAlgorithm.cpp \
		shell32.lib \
		User32.lib \
		/link \
		  /LIBPATH:"$(SDL2LIB)" \
			SDL2.lib SDL2main.lib

test_rdtscp: test/rdtscpPerformanceCounter.cpp
	@ml64 /c /Fo rdtscp.obj \
		test/rdtscp.asm
	@lib rdtscp.obj \
		/OUT:rdstcp.lib
	@cl /W4 /nologo \
		/std:c++20 \
		/Zi \
		/EHsc \
		/FerdtscpPerformanceCounter.exe \
		test/rdtscpPerformanceCounter.cpp \
		rdstcp.lib

test_query_performance_frequency: test/QueryPerformanceFrequency.cpp
	@cl /W4 /nologo \
		/std:c++20 \
		/Zi \
		/EHsc \
		/FeQueryPerformanceFrequency.exe \
		test/QueryPerformanceFrequency.cpp

test_rdmsr: test/rdmsrInline.cpp
	@ml64 /c /Fo rdmsr.obj \
		test/rdmsr.asm
	@lib rdmsr.obj \
		/OUT:rdmsr.lib
	@cl /W4 /nologo \
		/std:c++20 \
		/Zi \
		/EHsc \
		/Ferdmsr.exe \
		test/rdmsrInline.cpp \
		rdmsr.lib

