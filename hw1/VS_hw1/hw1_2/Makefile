CXX=clang++
FLAGS=-std=c++11 -stdlib=libc++ -Weverything
all:
		$(CXX) $(FLAGS) hw1-2.cpp -o hw1-2
		
clean:
	  rm -fr build/*
		rm -rf *.o hw1-2

test: 
	  $(CXX) $(FLAGS) src/test.cpp -o build/test.bin -Isrc/
		 
.PHONY: all clean tes
