#ifndef __EZMANPARSER_H__
#define __EZMANPARSER_H__

#include <stdio.h>
#include <string.h>

#include "errors.h"

#define MAX_NAME_LEN 64
#define MAX_PAGE_LEN 2
#define MAX_SECTION_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char page[MAX_PAGE_LEN];
    char section[MAX_SECTION_LEN];
} man_parser_t;

parser_error_t ezmanparser_init(man_parser_t *man_parser, const char *name, int page, const char *section);
parser_error_t ezmanparser_set_name(man_parser_t *man_parser, const char *name);
parser_error_t ezmanparser_set_page(man_parser_t *man_parser, int page);
parser_error_t ezmanparser_set_section(man_parser_t *man_parser, const char *section);
parser_error_t _find_section(const char *section);

#endif
