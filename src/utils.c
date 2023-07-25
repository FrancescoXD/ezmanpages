#include "utils.h"

parser_error_t _find_section(FILE *stream, const char *section, char *buffer) {
    char line[LINE_LEN];
    bool found = false;
    size_t result_len = 0;

    memset(buffer, 0, sizeof(buffer) - 1);

    while ((fgets(line, LINE_LEN, stream) != NULL)) {
        //_removenewline(line);
        if (isupper(line[0]) && found) {
            //printf("found an upper char: %s", line);
            break;
        }

        if (found) {
            size_t line_len = strlen(line);
            if (result_len + line_len < 4096) {
                strcat(buffer, line);
                result_len += line_len;
                //printf("%s", line);
            } else {
                break;
            }
        }

        if (strstr(line, section)) {
            //_dbprint("section found!");
            strcat(buffer, line); // maybe that needs a check...
            //fprintf(stdout, "%s", line);
            found = true;
        }
    }
    
    if (strlen(buffer) > 0) {
        return E_PARSER_SUCCESS;
    }

    return E_PARSER_SECTION_NOT_FOUND;
}

void _dbprint(const char *text) {
    fprintf(stdout, "[debug] %s\n", text);
}

void _removenewline(char *text) {
    int len = strlen(text);
    if (text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}
