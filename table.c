#include "table.h"

#include <stdio.h>
#include <stdlib.h>

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

void* row_slot(table *t, uint32_t row_num) {
	uint32_t page_num = row_num / ROWS_PER_PAGE;
	void *page = t->pages[page_num];
	if (page == NULL) {
		page = t->pages[page_num] = malloc(PAGE_SIZE);
	}
	
	uint32_t row_offset = row_num % ROWS_PER_PAGE;
	uint32_t byte_offset = row_offset * ROW_SIZE;
	return page + byte_offset;
}
