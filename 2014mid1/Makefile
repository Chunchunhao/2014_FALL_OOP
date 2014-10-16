CXX=clang++
FLAGS=-std=c++11 -stdlib=libc++ -Weverything
TAR=CircleClient
all:
		$(CXX) $(FLAGS) $(TAR).cpp Circle.cpp -o $(TAR)
		
clean:
	  rm -fr build/*
		rm -rf *.o $(TAR)

test: 
	  $(CXX) $(FLAGS) src/test.cpp -o build/test.bin -Isrc/
		 
.PHONY: all clean test
