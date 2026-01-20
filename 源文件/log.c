#include "studentmanager.h"
#include <stdio.h>
#include <time.h>
void log_action(const char *username, const char *action)
{
    FILE *fp = fopen("safelog.txt", "a");
    if (!fp) return;

    time_t now = time(NULL);
    fprintf(fp, "[%ld] user=%s action=%s\n",
            now,
            username ? username : "unknown",
            action);

    fclose(fp);
}