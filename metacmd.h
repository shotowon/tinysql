#ifndef META_CMD_H
#define META_CMD_H

typedef enum {
	META_CMD_EXIT,
	META_CMD_UNRECOGNIZED_CMD
} meta_cmd_result;

meta_cmd_result do_meta_cmd(char *meta_cmd);

#endif
