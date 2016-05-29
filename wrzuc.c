#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>

struct temp
{
    long typ;
    char zawartosc[69];
};

int main(int argc, char* argv[])
{
	key_t klucz;
	int rozmiar, ID_wiadomosc;
	struct temp wiadomosc;
	
	if ((klucz = ftok("./wrzuc", 69)) == -1)
	{
		perror("ftok nie podolal");
		exit(1);
	}
	
	if ((ID_wiadomosc = msgget(klucz, 0666 | IPC_CREAT)) == -1)
	{
		perror("mssget nie podolal");
		exit(1);
	}
	
	wiadomosc.typ = 1;
	printf("Podaj wiadomosc do zakolejkowania: ");
	scanf("%s", wiadomosc.zawartosc);
	rozmiar = sizeof wiadomosc.zawartosc;
	
	if ((msgsnd(ID_wiadomosc, &wiadomosc, rozmiar, IPC_NOWAIT)) == -1)
	{
		perror("msgsnd nie wyslal wiadomosci");
		exit(1);
	}
	
	return 0;
}
