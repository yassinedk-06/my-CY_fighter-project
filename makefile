all: exec

main.o: main.c menu.h structure.h combat.h choix.h computer.h
	gcc -c main.c -o main.o

menu.o: menu.c structure.h choix.h combat.h
	gcc -c menu.c -o menu.o

structure.o: structure.c structure.h
	gcc -c structure.c -o structure.o

choix.o: choix.c structure.h choix.h
	gcc -c choix.c -o choix.o

combat.o: combat.c structure.h choix.h menu.h combat.h computer.h
	gcc -c combat.c -o combat.o

computer.o: computer.c computer.h structure.h combat.h
	gcc -c computer.c -o computer.o

exec: main.o menu.o combat.o choix.o structure.o computer.o
	gcc main.o menu.o combat.o choix.o structure.o computer.o -o exec

clean:
	rm -f *.o
	rm -f exec
