all:ProyectoIntegrador_v3
make:ProyectoIntegrador_v3

mainEnigma.o: main\mainEnigma.c main\menus.h
	gcc -Wall -ansi -pedantic -c main\mainEnigma.c -o mainEnigma.o
	
menus.o: main\menus.c main\menus.h auxiliar\auxiliar.h
	gcc -Wall -ansi -pedantic -c main\menus.c -o menus.o
	
auxiliar.o: auxiliar\auxiliar.c auxiliar\auxiliar.h
	gcc -Wall -ansi -pedantic -c auxiliar\auxiliar.c -o auxiliar.o
	
interfaz.o: maquina\interfaz.c maquina\interfaz.h auxiliar\auxiliar.h maquina\enigma.h auxiliar\punto.h
	gcc -Wall -ansi -pedantic -c maquina\interfaz.c -o interfaz.o
	
libroClaves.o: libroClaves\libroClaves.c libroClaves\libroClaves.h auxiliar\auxiliar.h config\config.h
	gcc -Wall -ansi -pedantic -c libroClaves\libroClaves.c -o libroClaves.o
	
cifrado.o: maquina\cifrado.c maquina\cifrado.h auxiliar\auxiliar.h maquina\rotores.h maquina\enigma.h config\config.h  auxiliar\punto.h
	gcc -Wall -ansi -pedantic -c maquina\cifrado.c -o cifrado.o
	
reflector.o: maquina\reflector.c maquina\reflector.h
	gcc -Wall -ansi -pedantic -c maquina\reflector.c -o reflector.o
	
rotores.o: maquina\rotores.c maquina\rotores.h config\config.h auxiliar\auxiliar.h
	gcc -Wall -ansi -pedantic -c maquina\rotores.c -o rotores.o
	
stecker.o: maquina\stecker.c maquina\stecker.h
	gcc -Wall -ansi -pedantic -c maquina\stecker.c -o stecker.o
	
config.o: config\config.c config\config.h auxiliar\auxiliar.h maquina\reflector.h maquina\rotores.h
	gcc -Wall -ansi -pedantic -c config\config.c -o config.o

enigma.o: maquina\enigma.c maquina\enigma.h auxiliar\auxiliar.h config\config.h maquina\rotores.h maquina\reflector.h
	gcc -Wall -ansi -pedantic -c maquina\enigma.c -o enigma.o
	
ProyectoIntegrador_v3: mainEnigma.o menus.o interfaz.o libroClaves.o auxiliar.o cifrado.o reflector.o rotores.o stecker.o config.o enigma.o
	gcc -Wall -pedantic -ansi mainEnigma.o menus.o interfaz.o libroClaves.o auxiliar.o cifrado.o reflector.o rotores.o stecker.o config.o enigma.o -o ProyectoIntegrador_v3

clean:
	del *.o *.exe