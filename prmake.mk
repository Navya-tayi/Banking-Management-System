a.exe: bank_of_pes.o services.o 
	gcc bank_of_pes.o services.o
bank_of_pes.o: bank_of_pes.c prhead2.h
	gcc -c bank_of_pes.c
services.o: services.c prhead2.h
	gcc -c services.c
