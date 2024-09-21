#include "metacommand.h"
#include "string.h"

meta_command_result do_meta_command(char *meta_command) {
	if (!strcmp(meta_command, ".exit")) {
		return META_COMMAND_EXIT;
	} 

	return META_COMMAND_UNRECOGNIZED_COMMAND;
}
