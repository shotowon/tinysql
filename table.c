#include <string.h>

#include "table.h"

void serialize_row(row *src, void *dst) {
	memcpy(dst + ID_OFFSET, &(src->id), ID_SIZE);
	memcpy(dst + USERNAME_OFFSET, &(src->username), USERNAME_SIZE);
	memcpy(dst + EMAIL_OFFSET, &(src->email), EMAIL_SIZE);
}
