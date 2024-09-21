build: *.c
	clang -o tinysql -Wall -Werror *.c

run: tinysql
	./tinysql
