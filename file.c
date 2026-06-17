#include <stdio.h>
#include <string.h>
#include "file.h"

void readLog(char *buffer)
{
    FILE *fp;

    fp = fopen("data/log.txt", "r");

    if (fp == NULL)
    {
        strcpy(buffer, "无法打开日志文件！");
        return;
    }

    char line[100];

    buffer[0] = '\0';

    while (fgets(line, sizeof(line), fp))
    {
        strcat(buffer, line);
    }

    fclose(fp);
}