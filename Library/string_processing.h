#ifndef STRING_PROCESSING_H
#define STRING_PROCESSING_H

#define STR_MAX_LEN 100

int strsize(char *string);
int strslice(char *token, char *string, int start, int end);
int strsplit(char *token, char *string, char *seperator);

#endif
