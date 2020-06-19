all: install clean

install:
	cp src/*.cpp .
	cp inc/*.h .
	clang++ -std=c++11 -lncurses -o Chsee *.cpp


uninstall:
	rm -rf Chess

clean:
	rm -rf *.cpp
	rm -rf *.h
	rm -rf *.o

reinstall: uninstall install clean