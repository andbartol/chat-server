/* vim: set ts=8 sw=8 tw=0 noet : */
#ifndef USER_H

#define USER_H

#include "auth.h"
#include <glib.h>
#include <openssl/sha.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define	NAME_MAX_LEN 20

struct user_s {
	char name[NAME_MAX_LEN];
	char sha1[SHA_DIGEST_LENGTH+1];
};

#endif /* end of include guard: USER_H */
