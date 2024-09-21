#include "repl.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

input_buf* new_input_buf() {
	input_buf *buf = malloc(sizeof(input_buf));
	buf->buf = NULL, buf->buf_len = 0, buf->input_len = 0;

	return buf;
}

void close_input_buf(input_buf* buf) {
	free(buf->buf);
	free(buf);
}

int read_input(input_buf *buf) {
	ssize_t bytes = getline(&(buf->buf), &(buf->buf_len), stdin);
	
	if(bytes <= 0) {
		printf("error: reading input\n");
		return 1;
	}
	
	buf->input_len = bytes - 1; // ignore newline
	buf->buf[buf->input_len] = 0;
	return 0;	
}

void print_prompt() {
	printf("db > ");
}

int repl() {
	input_buf* buf = new_input_buf();
	
	while(1) {
		print_prompt();
		if(read_input(buf)) {
			close_input_buf(buf);
			return 1;
		}

		if (!strcmp(buf->buf, ".exit")) {
			repl_exit(buf);
			return 0;
		} else {
			printf("error: unrecognized command - '%s'\n", buf->buf);
		}
	}
}

void repl_exit(input_buf *buf) { close_input_buf(buf); }
