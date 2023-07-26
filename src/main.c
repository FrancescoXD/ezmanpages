#include "ezmanpages.h"
// Use this instead
//#include <ezmanpages/ezmanpages.h>

#define BUFFER_SIZE 1024

void check_ret(parser_error_t ret) {
    switch (ret) {
        case E_PARSER_SUCCESS:
            break;
        case E_PARSER_TRUNC:
            ezmanpages_perror("[info]", ret);
            break;
        default:
            ezmanpages_perror("[error] parser error", ret);
            exit(EXIT_FAILURE);
    }
}

int main(void) {
    // Return code to check errors
    parser_error_t ret;

    // Define the `ezmanpages_t` struct
    ezmanpages_t ezmanpages;

    // Init the ezmanpages
    ret = ezmanpages_init(&ezmanpages, "mv", 1, "SYNOPSIS");
    fprintf(stdout, "ezmanpages struct:\n%s %s %s\n", ezmanpages.name, ezmanpages.page, ezmanpages.section);
    check_ret(ret);

    // Use those functions to change the `ezmanpages_t` structure
    ezmanpages_set_name(&ezmanpages, "free");
    ezmanpages_set_page(&ezmanpages, 3);
    ezmanpages_set_section(&ezmanpages, "DESCRIPTION");
    fprintf(stdout, "ezmanpages struct:\n%s %s %s\n", ezmanpages.name, ezmanpages.page, ezmanpages.section);

    // Now parse the man page
    char result[BUFFER_SIZE];
    ret = ezmanpages_parse(ezmanpages, result, BUFFER_SIZE);
    check_ret(ret);

    // Print the results
    fprintf(stdout, "%s", result);

    return 0;
}
