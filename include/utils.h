#ifndef __EZMANPAGES_UTILS_H__
#define __EZMANPAGES_UTILS_H__

#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "errors.h"

#define LINE_LEN 100
#define MAX_CMD_LEN 64

parser_error_t _find_section(FILE *stream, const char *section, char *buffer, size_t bufsize);

#endif
