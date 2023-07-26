#ifndef __EZMANPAGES_ERRORS_H__
#define __EZMANPAGES_ERRORS_H__

#include <stdio.h>
#include <stdlib.h>

enum _parser_error {
    E_PARSER_SUCCESS = 0,
    E_PARSER_NAME_NOT_FOUND = -1,
    E_PARSER_PAGE_NOT_FOUND = -2,
    E_PARSER_SECTION_NOT_FOUND = -3,
    E_PARSER_INIT_FAILED = -4,
    E_PARSER_MAN_ERROR = -5,
    E_PARSER_INVALID_PARAM = -6,
    E_PARSER_TRUNC = -7,
    E_PARSER_ERROR = -8
};

typedef enum _parser_error parser_error_t;

struct _parser_error_desc {
    int code;
    const char *message;
};

typedef struct _parser_error_desc parser_error_desc_t;

extern struct _parser_error_desc parser_error_desc[];

void ezmanpages_perror(const char *msg, parser_error_t error);

#endif
