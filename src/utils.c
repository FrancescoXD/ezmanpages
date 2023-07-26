#include "utils.h"

parser_error_t _find_section(FILE *stream, const char *section, char *buffer, size_t bufsize) {
#ifdef PARSER_SAFE
    if (!(stream && section && *section && buffer && *buffer && bufsize)) {
        return E_PARSER_INVALID_PARAM;
    }
#endif

    char line[LINE_LEN];
    bool found = false;
    size_t result_len = strlen(buffer);
    char *next;

    while ((fgets(line, LINE_LEN, stream) != NULL)) {
        if (isupper(line[0]) && found) {
            break;
        }

        if (found) {
            size_t line_len = strlen(line);
            if ((result_len + line_len) < bufsize) {
                next = stpcpy(next, line);
                result_len += line_len;
            } else {
                return E_PARSER_TRUNC;
            }
        }

        if (strstr(line, section)) {
            next = stpcpy(buffer, line);
            found = true;
        }
    }
    
    if (strlen(buffer) > 0) {
        return E_PARSER_SUCCESS;
    }

    return E_PARSER_SECTION_NOT_FOUND;
}
