#include "errors.h"

struct _parser_error_desc parser_error_desc[] = {
    { E_PARSER_SUCCESS, "No error" },
    { E_PARSER_NAME_NOT_FOUND, "Program not found in man pages" },
    { E_PARSER_PAGE_NOT_FOUND, "Page not found in man pages" },
    { E_PARSER_SECTION_NOT_FOUND, "Section not found in man pages" },
    { E_PARSER_INIT_FAILED, "Unable to init the ezmanpages_t struct" },
    { E_PARSER_ERROR, "General error" }
};

void ezmanpages_perror(const char *msg, parser_error_t error) {
    fprintf(stderr, "%s: %s\n", msg, parser_error_desc[error * -1].message);
}
