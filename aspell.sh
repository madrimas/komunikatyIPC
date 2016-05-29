#!/bin/bash
./wrzuc
wiadomosc="$(./wyrzuc | aspell -l pl_PL -a | tail -c 3)"
pomocnicza="*"
if [ "$wiadomosc" = "$pomocnicza" ]
	then
		echo "Wyraz istnieje w slowniku jezyka polskiego"
	else 
		echo "Wyraz nie istnieje w slowniku jezyka polskiego"
fi
