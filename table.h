#ifndef TABLE_H
#define TABLE_H

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
const uint32_t id_size = size_of_attr(row, id);
const uint32_t username_size = size_of_attr(row, username);
const uint32_t email_size = size_of_attr(row, email);
const uint32_t id_offset = 0;
const uint32_t username_offset = id_offset + id_size;
const uint32_t email_offset = username_offset + username_size;
const uint32_t row_size = email_offset + email_size;

#endif
