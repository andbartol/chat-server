/* vim: set ts=8 sw=8 tw=0 noet : */
/*
 * \file auth.c
 * \author Andrea Bartolucci
 */
/*
 * Functions to authenticate users
 */
#include "auth.h"

#define	MAX_LINE_LEN 256

gint authcompare(gconstpointer, gconstpointer);

/*
 * ! \fn readusers
 * \brief Reads the file with usernames
 * The file is like this:
 * USER SHA1 NUMCOLOR
 * \param path path to the file
 * \param auth output linked list (user_s)
 * \return 0 if couldn't read file, 1 otherwise
 */
int readusers(const char* path, GSList** auth) {
	*auth = NULL;
	FILE* f;
	if ((f = fopen(path, "r")) == NULL) {
		perror("Users file");
		return 0;
	}

	char buffer[MAX_LINE_LEN];

	while (!feof(f)) {
		if (fgets(buffer, MAX_LINE_LEN, f)) {
			struct user_s* a = (struct user_s*) malloc(sizeof(struct user_s));
			if (!a) {
				perror("malloc");
				continue;
			}
			sscanf(buffer, "%s %s %d\n", a->name, a->sha1, &a->color);
			*auth = g_slist_append(*auth, a);
		}
	}

	fclose(f);

	return 1;
}

/*
 * Checks if the user_s is compatible with the user
 */
gint authcompare(gconstpointer auth, gconstpointer user) {
	if (strcmp(((struct user_s*)auth)->name, ((struct user_s*)user)->name))
		return 1;
	if (strcmp(((struct user_s*)auth)->sha1, ((struct user_s*)user)->sha1))
		return 1;
	return 0;
}

/*
 * Checks if the user is present in the linked list
 * ut: User to authenticate
 * auth: Linked list of user_s
 * returns 0 if authentication failed, 1 otherwise
 */
int autenticate_user(struct user_s* ut, GSList* auth) {
	GSList* ufound = g_slist_find_custom(auth, ut, (GCompareFunc)authcompare);
	if (!ufound)
		return 0;
	return 1;
}
