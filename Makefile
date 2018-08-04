all:
	c++ libspurdoxx.cpp -std=c++11 -Os -Wall -c -fpic
	c++ -shared -o libspurdoxx.so libspurdoxx.o

install:
	#You'll probably want to run this as root.
	#Tested to work for Arch Linux
	cp libspurdoxx.so /usr/lib
	cp libspurdoxx.hpp /usr/include/Pr0Wolf29/

clean:
	rm *.so *.o
