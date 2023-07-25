#include "utils.h"

parser_error_t _find_section(FILE *stream, const char *section, char *buffer, size_t bufsize) {
    char line[LINE_LEN];
    bool found = false;
    size_t result_len = 0;

    memset(buffer, 0, sizeof(buffer) - 1);

    while ((fgets(line, LINE_LEN, stream) != NULL)) {
        if (isupper(line[0]) && found) {
            break;
        }

        if (found) {
            size_t line_len = strlen(line);
            if ((result_len + line_len) < bufsize) {
                strcat(buffer, line);
                result_len += line_len;
            } else {
                break;
            }
        }

        if (strstr(line, section)) {
            strcat(buffer, line); // maybe that needs a check...
            found = true;
        }
    }
    
    if (strlen(buffer) > 0) {
        return E_PARSER_SUCCESS;
    }

    return E_PARSER_SECTION_NOT_FOUND;
}
