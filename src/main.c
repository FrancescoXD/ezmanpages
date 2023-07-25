#include "parser.h"

#define BUFFER_SIZE 4096

void check_ret(parser_error_t ret) {
    if (ret != E_PARSER_SUCCESS) {
        // perror() like function
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
    ret = ezmanpages_init(&ezmanpages, "popen", 3, "SYNOPSIS");
    fprintf(stdout, "ezmanpages struct:\n%s %s %s\n", ezmanpages.name, ezmanpages.page, ezmanpages.section);
    check_ret(ret);

    // Use those functions to change the `ezmanpages_t` structure
    ezmanpages_set_name(&ezmanpages, "mv");
    ezmanpages_set_page(&ezmanpages, 1);
    ezmanpages_set_section(&ezmanpages, "DESCRIPTION");
    fprintf(stdout, "ezmanpages struct:\n%s %s %s\n", ezmanpages.name, ezmanpages.page, ezmanpages.section);

    // Now parse the man page
    char result[BUFFER_SIZE];
    ret = ezmanpages_parse(ezmanpages, result);
    check_ret(ret);

    // Print the results
    fprintf(stdout, "%s", result);

    return 0;
}
