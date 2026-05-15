CC=gcc
CFLAGS=-Iinclude -Wall -Wextra

SRC=src/main.c src/auth.c src/course.c src/utils.c src/storage.c
OUT=lms

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

clean:
	rm -f $(OUT)
