CC=g++

test: 
	$(CC) -o run_tests CppUnitLite/Main.cpp \
										 CppUnitLite/Failure.cpp \
										 CppUnitLite/Test.cpp \
										 CppUnitLite/TestRegistry.cpp \
										 CppUnitLite/TestResult.cpp \
										 CODECTest.cpp
	
	./run_tests
