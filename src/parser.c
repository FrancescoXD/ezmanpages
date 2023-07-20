#include "parser.h"

parser_error_t ezmanparser_init(man_parser_t *man_parser, const char *name, int page, const char *section) {
    strncpy(man_parser->name, name, strlen(man_parser->name));
    
    int page_ret = snprintf(man_parser->page, strlen(man_parser->page), "%d", page);
    if (page_ret < 0) {
        return E_PARSER_INIT_FAILED;
    }
    
    strncpy(man_parser->section, section, strlen(man_parser->section));

    return E_PARSER_SUCCESS;
}

parser_error_t ezmanparser_set_name(man_parser_t *man_parser, const char *name) {
    strncpy(man_parser->name, name, strlen(man_parser->name));

    return E_PARSER_SUCCESS;
}

parser_error_t ezmanparser_set_page(man_parser_t *man_parser, int page) {
    int page_ret = snprintf(man_parser->page, strlen(man_parser->page), "%d", page);
    if (page_ret < 0) {
        return E_PARSER_INIT_FAILED;
    }

    return E_PARSER_SUCCESS;
}

parser_error_t ezmanparser_set_section(man_parser_t *man_parser, const char *section) {
    strncpy(man_parser->section, section, strlen(man_parser->section));

    return E_PARSER_SUCCESS;
}

parser_error_t _find_section(const char *section) {
    printf("%s", section);
    
    return E_PARSER_SUCCESS;
}
