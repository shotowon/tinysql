#ifndef ROW_H
#define ROW_H

#include <stdint.h>

#include "gears.h"

// for now table will be hardcoded
// columns:
// id: integer
// username: varchar(32)
// email: varchar(255)

#define COL_USERNAME_LENGTH 32
#define COL_EMAIL_LENGTH 255

typedef struct {
	uint32_t id;
	char username[COL_USERNAME_LENGTH];
	char email[COL_EMAIL_LENGTH];
} row;

// representation of a row
static const uint32_t ID_SIZE = size_of_attr(row, id);
static const uint32_t USERNAME_SIZE = size_of_attr(row, username);
static const uint32_t EMAIL_SIZE = size_of_attr(row, email);
static const uint32_t ID_OFFSET = 0;
static const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
static const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
static const uint32_t ROW_SIZE = EMAIL_OFFSET + EMAIL_SIZE;

void serialize_row(row *src, void *dst);
void deserialize_row(void *src, row *dst);

#endif
