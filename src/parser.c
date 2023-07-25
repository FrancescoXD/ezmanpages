#include "ezmanpages.h"
#include "utils.h"

parser_error_t ezmanpages_init(ezmanpages_t *ezmanpages, const char *name, int page, const char *section) {
    strncpy(ezmanpages->name, name, MAX_NAME_LEN);
    ezmanpages->name[MAX_NAME_LEN - 1] = '\0';
    
    int page_ret = snprintf(ezmanpages->page, MAX_PAGE_LEN, "%d", page);
    if (page_ret < 0) {
        return E_PARSER_INIT_FAILED;
    }
    
    strncpy(ezmanpages->section, section, MAX_SECTION_LEN);
    ezmanpages->section[MAX_SECTION_LEN - 1] = '\0';

    return E_PARSER_SUCCESS;
}

parser_error_t ezmanpages_set_name(ezmanpages_t *ezmanpages, const char *name) {
    strncpy(ezmanpages->name, name, MAX_NAME_LEN);
    ezmanpages->name[MAX_NAME_LEN - 1] = '\0';

    return E_PARSER_SUCCESS;
}

parser_error_t ezmanpages_set_page(ezmanpages_t *ezmanpages, int page) {
    int page_ret = snprintf(ezmanpages->page, MAX_PAGE_LEN, "%d", page);
    if (page_ret < 0) {
        return E_PARSER_INIT_FAILED;
    }

    return E_PARSER_SUCCESS;
}

parser_error_t ezmanpages_set_section(ezmanpages_t *ezmanpages, const char *section) {
    strncpy(ezmanpages->section, section, MAX_SECTION_LEN);
    ezmanpages->section[MAX_SECTION_LEN - 1] = '\0';

    return E_PARSER_SUCCESS;
}

parser_error_t ezmanpages_parse(ezmanpages_t ezmanpages, char *buffer) {
    char cmd[MAX_CMD_LEN];
    int ret = snprintf(cmd, MAX_CMD_LEN, "bash -c 'man %s %s | col -b'", ezmanpages.page, ezmanpages.name);
    if (ret < 0) {
        return E_PARSER_ERROR;
    }

    FILE *stream = popen(cmd, "r");
    if (stream == NULL) {
        return E_PARSER_ERROR;
    }

    parser_error_t ret_code = _find_section(stream, ezmanpages.section, buffer);

    ret = pclose(stream);
    if (ret == -1) {
        return E_PARSER_ERROR;
    }

    return ret_code;
}
