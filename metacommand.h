#ifndef META_COMMAND_H
#define META_COMMAND_H

typedef enum {
	META_COMMAND_EXIT,
	META_COMMAND_UNRECOGNIZED_COMMAND
} meta_command_result;

meta_command_result do_meta_command(char *meta_command);

#endif
