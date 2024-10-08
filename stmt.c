#include "stmt.h"
#include "string.h"

prepare_stmt_result prepare_stmt(char *stmt_str, stmt *s) {
	if (!strcmp(stmt_str, "insert")) {
		s->type = STMT_INSERT;
		return PREPARE_SUCCESS;
	}

	if (!strcmp(stmt_str, "select")) {
		s->type = STMT_SELECT;
		return PREPARE_SUCCESS;
	}

	return PREPARE_UNRECOGNIZED_STMT;
}
