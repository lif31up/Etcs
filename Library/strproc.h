#ifndef STRPROC_H
#define STRPROC_H

#define STR_MAX_LEN 300

char *strslice(char *string, int start, int end);
char *strsplit(char *token, char *string, char *seperator);

#endif
