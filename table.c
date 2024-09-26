#include "table.h"
#include <stdio.h>

void execute_stmt(stmt *s) {
	switch(s->type) {
		case(STMT_INSERT):
		printf("INSERT\n");
		break;
		case(STMT_SELECT):
		printf("SELECT\n");
		break;
	}
}
