/* vim: set ts=8 sw=8 tw=0 noet : */
/*
 * Functions to authenticate users
 */
#ifndef AUTH_H

#define AUTH_H

#include "user.h"
#include <glib.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readusers(const char*, GSList**);
int autenticate_user(struct user_s*, GSList*);

#endif /* end of include guard: AUTH_H */
