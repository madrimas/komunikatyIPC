#!/bin/bash
if [ $# != 0 ]
	then
		if [ $1 = '.' ]
			then
				path='./ipcmd/bin/ipcmd'

		fi
		wiadomosc=$($path msgget)
		echo "Podaj wiadomosc do zakolejkowania:"
		read x
		$path msgsnd -q $wiadomosc $x
		echo "Wiadomosc z kolejki to:"
		$path msgrcv -q $wiadomosc
		echo

else
	echo "Podaj sciezke do ipcmd. Jezeli Twoja sciezka to ./ipcmd/bin/ipcmd (domyslna) to wpisz . "
fi
