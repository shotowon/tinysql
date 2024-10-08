#ifndef REPL_H
#define REPL_H
#include <stddef.h>

typedef struct {
	char *buf;
	size_t buf_len;
	size_t input_len;
} input_buf;

// creates new input buffer with null values for each field
input_buf* new_input_buf();

// frees memory of input_buf
void close_input_buf(input_buf*);

// reading input into input buffer
int read_input(input_buf*);

void print_prompt();

int repl();
void repl_exit(input_buf* buf);

#endif
