/* vim: set ts=8 sw=8 tw=0 noet : */
#ifndef COLOR_H

#define COLOR_H

#include <stdarg.h>
#include <string.h>
#include "user.h"

int printfclr(enum colors color, char * fstring, ...);
int vprintfclr(enum colors color, char * fstring, va_list arg);
int printfusr(struct user_s * user, char * fstring, ...);

#endif /* end of include guard: COLOR_H */
