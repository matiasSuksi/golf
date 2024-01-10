golf:
	gcc -std=c99 golf.c -o golf -L/home/matiass/raylib/src/ -I/home/matiass/raylib/src/ -lraylib -lglfw -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm -f golf

build: clean golf

default: build
