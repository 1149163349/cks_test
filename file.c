#include <stdio.h>
#include <string.h>
#include "file.h"

void readLog(char *buffer)
{
    FILE *fp = fopen("log.txt", "r");

    if(fp == NULL)
    {
        strcpy(buffer, "无法打开日志文件！");
        return;
    }

    char line[100];

    buffer[0] = '\0';

    while(fgets(line, sizeof(line), fp))
    {
        strcat(buffer, line);
    }

    fclose(fp);
}
#include <time.h>

void saveLog(char *msg)
{
    FILE *fp = fopen("log.txt", "a");

    if(fp == NULL)
        return;

    time_t now = time(NULL);

    struct tm *t = localtime(&now);

    fprintf(
        fp,
        "%04d-%02d-%02d %02d:%02d:%02d %s\n",
        t->tm_year + 1900,
        t->tm_mon + 1,
        t->tm_mday,
        t->tm_hour,
        t->tm_min,
        t->tm_sec,
        msg);

    fclose(fp);
}