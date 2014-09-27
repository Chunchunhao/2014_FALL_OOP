CXX=clang++
FLAGS=-std=c++11 -stdlib=libc++ -Weverything
TAR=hw2-2
all:
		$(CXX) $(FLAGS) $(TAR).cpp -o $(TAR)
		
clean:
	  rm -fr build/*
		rm -rf *.o $(TAR)

test: 
	  $(CXX) $(FLAGS) src/test.cpp -o build/test.bin -Isrc/
		 
.PHONY: all clean test
