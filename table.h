#ifndef TABLE_H
#define TABLE_H
#include "row.h"
#include "stmt.h"

#include <stdint.h>

#define MAX_PAGES (uint32_t)100
#define PAGE_SIZE (uint32_t) 4096
#define ROWS_PER_PAGE (uint32_t)(PAGE_SIZE / ROW_SIZE)
#define TABLE_MAX_ROWS (uint32_t)(ROWS_PER_PAGE * MAX_PAGES)

typedef enum {
	EXECUTE_SUCCESS,
	EXECUTE_TABLE_FULL,
} execute_result;

typedef struct {
	uint32_t rows;
	void* pages[MAX_PAGES];
} table;

void execute_stmt(stmt*);

#endif
