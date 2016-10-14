objects = main.o src.o
cc      = g++
main   : $(objects)
	$(cc) -o main $(objects)

main.o : main.cc Sales_data.h
	$(cc) -c main.cc -std=c++11
src.o   : Sales_data.h
	$(cc) -c src.cc   -std=c++11
clean: 
	rm -f *.o