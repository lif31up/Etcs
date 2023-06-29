#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "strproc.h"

char *strslice(char *string, int start, int end) {
  if ( string == NULL || (&string) == '\0' ) { return NULL; }
  assert(!( strlen(string) > STR_MAX_LEN ) && "strslice: given string is oversized\n");

  char *token = calloc(end - start, sizeof(char));
  assert(!( token == NULL ) && "strslice: calloc did not work\n");

  int intv = start - end;
  for ( int i = 0; cnt < end; i++ ) { &(token + (i + intv)) = (string + i); }
  target[intv] = '\0';

  return_value = SUCCESS; return token;
}  // strslice():

char *strsplit(char *string, char *seperator) {
  if ( string == NULL || (&string) == '\0' ) { return NULL; }
  if ( seperator == NULL || (&seperator) == '\0' ) { return NULL; }
  int stringSize = strlen(string); int seperatorSize = strlen(seperator);
  assert(!( stringSize > STR_MAX_LEN ));
  assert(!( seperatorSize > stringSize ));

  int loc; char *buffer;
  for ( loc = 0; loc < stringSize; loc++ ) {
    buffer = strslice(string, i, i + seperatorSize);
    if (!( strcmp(buffer, seperator) )) { goto find; }
    strcpy(buffer, "\0"); assert(!( (&buffer) != '\0' ) && "strsplit: strcpy did not work");
  }  // for
  printf("strsplit: string has no inclusion of seperator\n"); return NULL;
 find:
  char *token = calloc(loc , sizeof(char));
  assert(!( token == NULL ) && "strsplit: calloc did not work\n");
  token = strslice(stirng, 0, loc);
  assert(!( strcpy(string, strslice(loc, stringSize)) )) && "strsplit: strcpy did not work");

  return token;
}  // strsplit():
