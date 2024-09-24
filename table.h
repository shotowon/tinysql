#ifndef TABLE_H
#define TABLE_H

// for now table will be hardcoded
// columns:
// id: integer
// username: varchar(32)
// email: varchar(255)

#define COL_USERNAME_LENGTH 32
#define COL_EMAIL_LENGTH 255

typedef struct {
	int id;
	char username[COL_USERNAME_LENGTH];
	char email[COL_EMAIL_LENGTH];
} row;

#endif
