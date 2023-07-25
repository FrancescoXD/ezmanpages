#ifndef __EZMANPAGES_H__
#define __EZMANPAGES_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "errors.h"

#define MAX_NAME_LEN 64
#define MAX_PAGE_LEN 2
#define MAX_SECTION_LEN 20

#define MAX_CMD_LEN 64

struct _ezmanpages {
    char name[MAX_NAME_LEN];
    char page[MAX_PAGE_LEN];
    char section[MAX_SECTION_LEN];
};

typedef struct _ezmanpages ezmanpages_t;

parser_error_t ezmanpages_init(ezmanpages_t *ezmanpages, const char *name, int page, const char *section);
parser_error_t ezmanpages_set_name(ezmanpages_t *ezmanpages, const char *name);
parser_error_t ezmanpages_set_page(ezmanpages_t *ezmanpages, int page);
parser_error_t ezmanpages_set_section(ezmanpages_t *ezmanpages, const char *section);
parser_error_t ezmanpages_parse(ezmanpages_t ezmanpages, char *buffer);

#endif
