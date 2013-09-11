CC=c++
CFLAGS=-std=c++11 -stdlib=libc++

test: 
	$(CC) CppUnitLite/Main.cpp \
										 CppUnitLite/Failure.cpp \
										 CppUnitLite/Test.cpp \
										 CppUnitLite/TestRegistry.cpp \
										 CppUnitLite/TestResult.cpp \
										 CppUnitLite/CODECTest.cpp \
										 Bitmap.h \ 
										 CodecLibrary.cpp \ 
										 WindowsBitmapDecoder.cpp \ 
										 WindowsBitmapEncoder.cpp \ 
										 WindowsBitmapHeader.cpp \
										 BitmapIterator.cpp \
										 DoubleWord.cpp \
										 Word.cpp \ 
	./run_tests
