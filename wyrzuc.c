#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <time.h>

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
	
	time_t weekend;
    struct tm * test;
    time(&weekend);
    test=localtime(&weekend);
    
    if ( (test->tm_wday == 0) || (test->tm_wday == 5) || (test->tm_wday == 6) )
    {
		if ( (klucz = ftok("./wrzuc", 69)) == -1 )
		{
			perror("ftok nie podlal");
			exit(1);
		}	
		if ( (ID_wiadomosc = msgget(klucz, 0666 | IPC_CREAT)) == -1 )
		{
			perror("mssget nie podolal");
			exit(1);
		}
		rozmiar = sizeof wiadomosc.zawartosc;
		if ( (msgrcv(ID_wiadomosc, &wiadomosc, rozmiar, 1, IPC_NOWAIT)) == -1 )
		{
			perror("msgrcv nie odebral wiadomosci");
			exit(1);
		}
		int bool = 0;
		if ( ( ( (int)wiadomosc.zawartosc[0] > 64 && (int)wiadomosc.zawartosc[0] < 91) || ( (int)wiadomosc.zawartosc[0] > 96 && (int)wiadomosc.zawartosc[0] < 123) ) )
		{
			bool = 1;
		}
		if (bool)
		{
			int i = 0;
			while (wiadomosc.zawartosc[i] != '\0')
			{
				if ( ( (int)wiadomosc.zawartosc[i] > 33 && (int)wiadomosc.zawartosc[i] < 127 ) )
				{
					bool = 1;
				}
				else
				{
					bool = 0;
				}
					i=i+1;
			}
		}
		
		if (bool)
		{
			printf("Wiadomosc z kolejki: %s\n", wiadomosc.zawartosc);
		}
		else
			printf("Przeslana wiadomosc nie jest prawidlowa.\n");
	}
	else
		printf("Nie ma weekendu a wiec nie moge podac wiadomosci z kolejki.\n");
	
	return 0;
}
