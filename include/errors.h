#ifndef __EZMANPARSER_ERRORS_H__
#define __EZMANPARSER_ERRORS_H__

#include <stdlib.h>

enum _parser_error {
    E_PARSER_SUCCESS = 0,
    E_PARSER_NAME_NOT_FOUND = -1,
    E_PARSER_PAGE_NOT_FOUND = -2,
    E_PARSER_SECTION_NOT_FOUND = -3,
    E_PARSER_INIT_FAILED = -4,
    E_PARSER_ERROR = -99
};

typedef enum _parser_error parser_error_t;

struct _parser_error_desc {
    int code;
    const char *message;
} parser_error_desc[] = {
    { E_PARSER_SUCCESS, "No error" },
    { E_PARSER_NAME_NOT_FOUND, "Program not found in man pages" },
    { E_PARSER_PAGE_NOT_FOUND, "Page not found in man pages" },
    { E_PARSER_SECTION_NOT_FOUND, "Section not found in man pages" },
    { E_PARSER_INIT_FAILED, "Unable to init the man_parser_t struct" },
    { E_PARSER_ERROR, "General error" }
};

#endif
