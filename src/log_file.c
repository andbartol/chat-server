#include "log_file.h"

/*
 * Function to log strings into a file
 * if LOG_PATH is defined the log is saved there
 * if not the file is saved in LOG_PATH_DEFAULT
 */
void log_file(const char* format, ...)
{
	va_list vl;
	va_start(vl, format);

	FILE* logfile;

	#ifdef LOG_PATH
		logfile = fopen(LOG_PATH, "a");
	#else
		logfile = fopen(LOG_PATH_DEFAULT, "a");
	#endif

	if (logfile)
	{
		vfprintf(logfile, format, vl);
		fclose(logfile);
	}
	else
	{
		perror("log file");
	}
	va_end(vl);
}
