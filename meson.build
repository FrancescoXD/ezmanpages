project('ezmanpages', 'c', version: '0.1.1a', default_options: ['warning_level=3', 'strip=true', 'debug=false', 'buildtype=release'])

sources = ['src/main.c', 'src/parser.c', 'src/errors.c']
inc_dirs = include_directories('./include/')

executable('ezmanpages', sources, include_directories: inc_dirs)
