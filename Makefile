all: clean compile_debug

CPP      = 	g++.exe
GCC      = 	gcc.exe
WINDRES  = 	windres.exe
OBJ      = 	main.o
LINKOBJ  = 	main.o
SRC		 = 	src\\main.cpp															\
			src\\Control.cpp														\
			src\\Shape.cpp															\
			src\\Circle.cpp															\
			src\\CharacterUnit.cpp													\
			src\\Character.cpp

LIBSPATH = 	-L"C:/Dev-Cpp/MinGW64/lib" 												\
			-L"C:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/lib" 							\
			-L"C:/library/cpp/opencv-2.4.13.4/build/bin"

LIBS	 =  -l"libopencv_calib3d2413"     \
			-l"libopencv_contrib2413"     \
			-l"libopencv_core2413"        \
			-l"libopencv_features2d2413"  \
			-l"libopencv_flann2413"       \
			-l"libopencv_gpu2413"         \
			-l"libopencv_highgui2413"     \
			-l"libopencv_imgproc2413"     \
			-l"libopencv_legacy2413"      \
			-l"libopencv_ml2413"          \
			-l"libopencv_nonfree2413"     \
			-l"libopencv_objdetect2413"   \
			-l"libopencv_ocl2413"         \
			-l"libopencv_photo2413"       \
			-l"libopencv_stitching2413"   \
			-l"libopencv_superres2413"    \
			-l"libopencv_video2413"       \
			-l"libopencv_videostab2413"   \
			-l"opencv_ffmpeg2413_64"      

INCS     = 	-I"C:/Dev-Cpp/MinGW64/include" 											\
			-I"C:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" 						\
			-I"C:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include"			
			
CXXINCS  = 	-I"C:/Dev-Cpp/MinGW64/include" 											\
			-I"C:/Dev-Cpp/MinGW64/x86_64-w64-mingw32/include" 						\
			-I"C:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include" 		\
			-I"C:/Dev-Cpp/MinGW64/lib/gcc/x86_64-w64-mingw32/4.9.2/include/cpp"		\
			-I"C:/library/cpp/opencv-2.4.13.4/include"								\
			-I"C:/library/cpp/opencv-2.4.13.4/include/opencv"						\
			-I"C:/library/cpp/opencv-2.4.13.4/include/opencv2"						\
			-I"C:/library/cpp/opencv-2.4.13.4/build"		 						\
			-I"C:/library/cpp/opencv-2.4.13.4/build/opencv2"						\
			-I"C:/library/cpp/opencv-2.4.13.4/modules"								\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/core/include"					\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/flann/include"				\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/imgproc/include"				\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/photo/include"				\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/features2d/include"			\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/video/include"				\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/objdetect/include"			\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/calib3d/include"				\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/ml/include"					\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/highgui/include"				\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/highgui/include/opencv2"		\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/contrib/include"				\
			-I"C:/library/cpp/opencv-2.4.13.4/modules/legacy/include"
			
OUT      = 	bin\\main.exe
CXXFLAGS = 	$(CXXINCS) 
CFLAGS   = 	$(INCS) 
CCFLAGS  =  $(CXXFLAGS)
RM       = 	rm.exe -f

FLAGS	 = $(CXXFLAGS)

clean:
	@cls

compile_debug: 
	@$(GCC) -g -O0 -Wall -Wextra $(SRC) -o $(OUT) $(CXXFLAGS) -lstdc++ -std=c++11 $(LIBSPATH) $(LIBS)

compile: 
	@$(GCC) -Wall $(SRC) -o $(OUT) $(CXXFLAGS) -lstdc++ -std=c++11 $(LIBSPATH) $(LIBS)


run:
	@echo "Application started"
	@$(OUT)
	@echo "Application ended"