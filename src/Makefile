# test : test.cpp Aquarium.o Bestiole.o Milieu.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o PersoMultiple.o 
# 	g++ -Wall -std=c++11 -o test test.cpp Aquarium.o Bestiole.o Milieu.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o PersoMultiple.o  -I . -lX11 -lpthread

main : main.cpp Aquarium.o Bestiole.o Milieu.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o PersoMultiple.o 
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o PersoMultiple.o  -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Gregaire.o : Gregaire.h IComportement.h Gregaire.cpp
	g++ -Wall -std=c++11  -c Gregaire.cpp -I .

Kamikaze.o : Kamikaze.h IComportement.h Kamikaze.cpp
	g++ -Wall -std=c++11  -c Kamikaze.cpp -I .

Peureuse.o : Peureuse.h IComportement.h Peureuse.cpp
	g++ -Wall -std=c++11  -c Peureuse.cpp -I .

Prevoyante.o : Prevoyante.h IComportement.h Prevoyante.cpp
	g++ -Wall -std=c++11  -c Prevoyante.cpp -I .

PersoMultiple.o : PersoMultiple.h IComportement.h PersoMultiple.cpp
	g++ -Wall -std=c++11  -c PersoMultiple.cpp -I .

clean:
	rm -rf *.o main test