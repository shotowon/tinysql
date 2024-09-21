#include "metacmd.h"
#include "string.h"

meta_cmd_result do_meta_command(char *meta_command) {
	if (!strcmp(meta_command, ".exit")) {
		return META_CMD_EXIT;
	} 

	return META_CMD_UNRECOGNIZED_CMD;
}
