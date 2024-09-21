#include <stdlib.h>
#include "repl.h"

int main() {
	if (repl()) return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
