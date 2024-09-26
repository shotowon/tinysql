#include "table.h"
#include <stdio.h>

execute_result execute_stmt(table *t, stmt *s) {
	switch(s->type) {
		case(STMT_INSERT):
		printf("INSERT\n");
		break;
		case(STMT_SELECT):
		printf("SELECT\n");
		break;
	}
	return EXECUTE_SUCCESS;
}

execute_result execute_insert(table *t, stmt *s) {
	if (t->rows >= TABLE_MAX_ROWS) {

	}
	return EXECUTE_SUCCESS;
}

execute_result execute_select(table *t, stmt *s) {
	return EXECUTE_SUCCESS;
}
