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
#define ID_SIZE size_of_attr(row, id)
#define USERNAME_SIZE size_of_attr(row, username)
#define EMAIL_SIZE size_of_attr(row, email)
#define ID_OFFSET 0
#define USERNAME_OFFSET ID_OFFSET + ID_SIZE
#define EMAIL_OFFSET USERNAME_OFFSET + USERNAME_SIZE
#define ROW_SIZE EMAIL_OFFSET + EMAIL_SIZE

void serialize_row(row *src, void *dst);
void deserialize_row(void *src, row *dst);

#endif
