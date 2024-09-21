#include "repl.h"

#include <stdlib.h>

input_buf* new_input_buf() {
	input_buf *buf = malloc(sizeof(input_buf));
	buf->buf = NULL, buf->buf_len = 0, buf->input_len = 0;

	return buf;
}

void close_input_buf(input_buf* buf) {
	free(buf->buf);
	free(buf);
}
