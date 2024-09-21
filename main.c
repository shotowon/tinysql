#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "repl.h"

int main() {
	input_buf* buf = new_input_buf();
	
	while(1) {
		print_prompt();
		if(read_input(buf)) {
			close_input_buf(buf);
			return EXIT_FAILURE;
		}

		if (!strcmp(buf->buf, ".exit")) {
			close_input_buf(buf);
			return EXIT_SUCCESS;
		} else {
			printf("error: unrecognized command - '%s'\n", buf->buf);
		}
	}
}
