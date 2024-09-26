#include "table.h"

#include <stdio.h>
#include <stdlib.h>

execute_result execute_stmt(table *t, stmt *s) {
	switch(s->type) {
		case(STMT_INSERT):
			return execute_insert(t, s);
		case(STMT_SELECT):
			return execute_select(t, s);
	}

	return EXECUTE_SUCCESS;
}

execute_result execute_insert(table *t, stmt *s) {
	if (t->rows >= TABLE_MAX_ROWS) {
		return EXECUTE_TABLE_FULL;
	}
	
	row *row_to_insert = &(s->row_to_insert);
	serialize_row(row_to_insert, row_slot(t, t->rows));
	t->rows++;

	return EXECUTE_SUCCESS;
}

execute_result execute_select(table *t, stmt *s) {
	row row;
	
	for (uint32_t i = 0; i < t->rows; i++) {
		deserialize_row(row_slot(t, i), &row);
		print_row(&row);
	}

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
