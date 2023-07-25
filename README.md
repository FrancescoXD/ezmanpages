# ezmanpages (v0.2.0a)
A simple man pages parser written in C

## Requirements
- meson
- ninja

## How to build
``` bash
$ meson setup build
$ cd build
$ ninja
$ ./ezmanpages
```

## How to install
```bash
$ cd build
$ meson install
$ sudo ldconfig # reload cache
```

### Example
A very basic example without error handling:
```c
#include <ezmanpages/ezmanpages.h>
#include <stdio.h>

int main(void) {
    ezmanpages_t parser;
    ezmanpages_init(&parser, "free", 3, "SYNOPSIS");
    char buffer[4096];
    ezmanpages_parse(parser, buffer);
    fprintf(stdout, "%s", buffer);

    return 0;
}
```
To compile it just run: `gcc file.c -lezmanpages`!

### TODO
- Parse files instead of the command (/usr/share/man)
- Write mine implementation of `col`
