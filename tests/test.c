/* vim: set ts=8 sw=8 tw=0 noet : */
#include "../src/auth.h"
#include "../src/user.h"
#include "../src/color.h"
#include <stdio.h>
#include <stdlib.h>
#include <check.h>

GSList *auths;

void setup();
void teardown();

START_TEST(test_auth_work)
{
	GSList *it = NULL;

	struct user_s u;
	strcpy(u.name, "andrea");
	strcpy(u.sha1, "12345678901234567890");

	ck_assert_msg(autenticate_user(&u, auths) != 0, "auth didn't worked");
	/*autenticate_user(&u, auths);*/

	strcpy(u.sha1, "10345678901234567890");

	ck_assert_msg(autenticate_user(&u, auths) == 0, "auth worked");
	/*autenticate_user(&u, auths);*/

	g_slist_free(auths);
}
END_TEST

Suite * auth_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Auth");

	tc_core = tcase_create("Core");

	tcase_add_checked_fixture(tc_core, setup, teardown);
	tcase_add_test(tc_core, test_auth_work);
	suite_add_tcase(s, tc_core);

	return s;
}

START_TEST(test_colors)
{
	printfclr(CLR_RED, "red\n");
}
END_TEST

START_TEST(test_colors_variable)
{
	printfclr(CLR_RED, "red %d\n", 1);
}
END_TEST

START_TEST(test_colors_user)
{
	printfusr((struct user_s*)auths->data, "colored\n");
}
END_TEST

void setup()
{
	auths = NULL;
	readusers("users.txt", &auths);
}

void teardown()
{
	g_slist_free(auths);
}

Suite * print_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Colors");

	tc_core = tcase_create("Core");

	tcase_add_checked_fixture(tc_core, setup, teardown);
	tcase_add_test(tc_core, test_colors);
	tcase_add_test(tc_core, test_colors_variable);
	tcase_add_test(tc_core, test_colors_user);
	suite_add_tcase(s, tc_core);

	return s;
}

int main()
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	sr = srunner_create(auth_suite());
	srunner_add_suite(sr, print_suite());

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
