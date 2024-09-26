#ifndef TABLE_H
#define TABLE_H
#include "row.h"
#include "stmt.h"

#include <stdint.h>

#define MAX_PAGES (uint32_t)100
static const uint32_t PAGE_SIZE = 4096;
static const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
static const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * MAX_PAGES;

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
