#include "parser.h"

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

parser_error_t _find_section(const char *section) {
    printf("%s", section);

    return E_PARSER_SUCCESS;
}
