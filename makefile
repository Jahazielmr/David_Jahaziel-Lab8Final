in: Main.o Real.o Racional.o Radical.o 
	g++ Main.o Real.o Racional.o Radical.o -o Main

Main.o: Main.cpp Real.h Racional.h Radical.h
	g++ -c Main.cpp

Real.o: Real.cpp Real.h
	g++ -c Real.cpp 

Racional.o:  Racional.h Racional.cpp Real.h
	g++ -c Racional.cpp 

Radical.o:  Radical.h Radical.cpp Real.h
	g++ -c Radical.cpp 

clean: 
	rm -f *.0 *.main
