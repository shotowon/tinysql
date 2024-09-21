#ifndef STMT_H
#define STMT_H

typedef enum {
	PREPARE_SUCCESS, 
	PREPARE_UNRECOGNIZED_STMT
} prepare_stmt_result;

typedef enum {
	STMT_INSERT,
	STMT_SELECT
} stmt_type;

typedef struct {
	stmt_type type;
} stmt;

prepare_stmt_result prepare_stmt(char *stmt_str, stmt *s);

void execute_stmt(stmt*);

#endif
