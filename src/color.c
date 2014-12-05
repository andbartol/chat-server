/* vim: set ts=8 sw=8 tw=0 noet : */
#include "color.h"

/*
 * Function to print with colors
 * color: color to print with
 * fstring: string formatted as in printf
 * va_list: args like printf
 */
int vprintfclr(enum colors color, char * fstring, va_list arg)
{
	char csi[] = "\x1b[";
	int final_color = color+30;
	//				csi	color m   fstring
	char* final_str = (char*)malloc(strlen(csi)+2+1+strlen(fstring));
	//Array used to store the color string number
	char number[2];
	sprintf(number, "%d", final_color);

	strcpy(final_str, csi);
	strcat(final_str, number);
	strcat(final_str, "m");
	strcat(final_str, fstring);
	int ret;
	ret = vprintf(final_str, arg);

	return ret;
}

/*
 * Function to print with user's color
 * user: user to print with
 * fstring: string formatted as in printf
 * ...: args like printf
 */
int printfusr(struct user_s * user, char * fstring, ...)
{


}
