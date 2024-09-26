#ifndef TABLE_H
#define TABLE_H
#include "row.h"
#include "stmt.h"

#include <stdint.h>
#include <stddef.h>

#define MAX_PAGES (uint32_t)100
#define PAGE_SIZE (uint32_t) 4096
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

table* table_new();
void free_table(table*);

execute_result execute_insert(table*, stmt *s);
execute_result execute_select(table*, stmt *s);
execute_result execute_stmt(table*, stmt *s);

void* row_slot(table*, uint32_t row_num);

#endif
