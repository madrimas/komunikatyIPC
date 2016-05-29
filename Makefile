all: wrzuc wyrzuc

wrzuc: wrzuc.c
	gcc -o wrzuc wrzuc.c
wyrzuc: wyrzuc.c
	gcc -o wyrzuc wyrzuc.c
