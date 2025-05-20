@echo off
if not exist bin mkdir bin
if not exist obj mkdir obj

gcc -I./include -Wall -Wextra -c src/main.c -o obj/main.o
gcc -I./include -Wall -Wextra -c src/menu.c -o obj/menu.o
gcc obj/main.o obj/menu.o -o bin/rpg.exe

echo Compilacao concluida!
echo Para executar o jogo, digite: bin\rpg.exe 