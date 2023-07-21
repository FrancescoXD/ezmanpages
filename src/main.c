#include "parser.h"

int main(void) {
    // Return code to check errors
    parser_error_t ret;

    // Define the `ezmanpages_t` struct
    ezmanpages_t ezmanpages;

    // Init the ezmanpages
    ret = ezmanpages_init(&ezmanpages, "popen", 3, "NAME");
    fprintf(stdout, "ezmanpages struct:\n%s %s %s\n", ezmanpages.name, ezmanpages.page, ezmanpages.section);
    if (ret != E_PARSER_SUCCESS) {
        // perror() like function
        ezmanpages_perror("[error] parser error", ret);
        exit(EXIT_FAILURE);
    }

    // Use those functions to change the `ezmanpages_t` structure
    ezmanpages_set_name(&ezmanpages, "mv");
    ezmanpages_set_page(&ezmanpages, 1);
    ezmanpages_set_section(&ezmanpages, "SYNOPSIS");

    fprintf(stdout, "ezmanpages struct:\n%s %s %s\n", ezmanpages.name, ezmanpages.page, ezmanpages.section);

    return 0;
}
