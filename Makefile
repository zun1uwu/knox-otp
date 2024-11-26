CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic

all: knox

knox: knox.c
	${CC} $< -o $@

clean:
	rm -rf knox