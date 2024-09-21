#ifndef STMT_H
#define STMT_H

typedef enum {
	STMT_INSERT,
	STMT_SELECT
} stmt_type;

typedef struct {
	stmt_type type;
} stmt;

#endif
