/* vim: set ts=8 sw=8 tw=0 noet : */
#include "../src/auth.h"
#include "../src/user.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

START_TEST(test_auth_work)
{
	GSList *auths = NULL, *it = NULL;

	ck_assert_msg(readusers("users.txt", &auths) == 1, "Couldn't read file");

	struct user_s u;
	strcpy(u.name, "andrea");
	strcpy(u.sha1, "12345678901234567890");

	/*ck_assert_msg(autenticate_user(&u, auths) != 0, "auth didn't worked");*/
	autenticate_user(&u, auths);

	strcpy(u.sha1, "10345678901234567890");

	/*ck_assert_msg(autenticate_user(&u, auths) == 0, "auth worked");*/
	autenticate_user(&u, auths);

	g_slist_free(auths);
}
END_TEST

Suite * auth_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Auth");

	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_auth_work);
	suite_add_tcase(s, tc_core);

	return s;
}

int main()
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = auth_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
