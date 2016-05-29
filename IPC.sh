#!/bin/bash
if [ $# != 0 ]
	then
		if [ $1 = '.' ]
			then
				path='./ipcmd/bin/ipcmd'

		fi
		x=$($path msgget)
		echo "Podaj wiadomosc do zakolejkowania:"
		read wpisz
		$path msgsnd -q $x $wpisz
		echo "Wiadomosc z kolejki to:"
		$path msgrcv -q $x
		echo

else
	echo "Podaj sciezke do ipcmd. Jezeli Twoja sciezka to ./ipcmd/bin/ipcmd (domyslna) to wpisz . "
fi
