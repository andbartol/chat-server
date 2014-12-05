#ifndef LOG_H

#define LOG_H

#include <stdarg.h>
#include <stdio.h>

#define	LOG_PATH_DEFAULT "log_file"

void log_file(const char* format, ...);

#endif /* end of include guard: LOG_H */
