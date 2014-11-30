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

struct auth_s {
	char name[NAME_MAX_LEN];
	char sha1[SHA_DIGEST_LENGTH+1];
};

int readusers(const char*, GSList**);
int autenticate_user(struct user_s*, GSList*);

#endif /* end of include guard: AUTH_H */
