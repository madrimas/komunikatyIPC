#!/bin/bash
if [ $# != 0 ]
	then
		if [ $1 = '1' ]
			then
				./wrzuc
				./wyrzuc
		elif [ $1 = '2' ]
			then
				./aspell.sh
		elif [ $1 = '3' ]
			then
				./ipcmd.sh
		elif [ $1 = '4' ]
			then
				./IPC.sh .
		elif [ $1 = '5' ]
			then
				make
		else
			echo -e "Nie ma takiej opcji.\n"
			echo -e "Info:\n Jako parametr podaj:\n 1 -> Uruchom kolejkowanie\n 2 -> Uruchom aspell\n 3 -> Pobierz ipcmd i skompiluj\n 4 -> Uruchom kolejkowanie IPC\n 5 -> Skompiluj kolejkowanie"
		fi
else
	echo -e "Info:\n Jako parametr podaj:\n 1 -> Uruchom kolejkowanie\n 2 -> Uruchom aspell\n 3 -> Pobierz ipcmd i skompiluj\n 4 -> Uruchom kolejkowanie IPC\n 5 -> Skompiluj kolejkowanie"
fi
