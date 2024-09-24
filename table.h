#ifndef TABLE_H
#define TABLE_H
#include "row.h"

#include <stdint.h>

static const uint32_t PAGE_SIZE = 4096;
static const uint32_t MAX_PAGES = 100;
static const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
static const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * MAX_PAGES;

typedef struct {
	uint32_t rows;
	void *pages[MAX_PAGES];
} table;

#endif
