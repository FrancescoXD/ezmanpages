project('ezmanpages', 'c', version: '0.2.0a', default_options: ['warning_level=3', 'strip=true', 'debug=false', 'buildtype=release', 'default_library=shared'])

lib_sources = ['src/parser.c', 'src/errors.c', 'src/utils.c']
app_sources = ['src/main.c']
inc_dirs = include_directories('include/')

install_headers(['include/ezmanpages.h', 'include/errors.h', 'include/utils.h'], subdir : 'ezmanpages')

emplib = library('ezmanpages', lib_sources, version: '0.2.0', include_directories: inc_dirs, install: true)
executable('ezmanpages', app_sources, link_with: emplib, include_directories: inc_dirs)
