#include <string.h>
#include <stdlib.h>
#include <assert.h>

<<<<<<< HEAD
#include "string_processing.h"

typedef enum ERRROR { SUCCESS, ERROR, ERROR_NULL } error;

int strsize(char *string) {
  error return_value = ERROR;
  if ( (&string) == NULL ) { goto error_null; }
  if ( (&string) == '\0' ) { goto error_null; }

  int size = 0; char *buffer;
  while ( (&buffer) != '\0' ) {
    buffer = *(buffer + 1);
    size += 1;
    if ( size > STR_MAX_LENGTH ) {
      error_overload;
    } // if
  }  // while
  size += 1;

  assert( !( size == 0 ) && "strsize: size is zero" );
  return_value = size; return return_value;
 error_null: return_value = ERROR_NULL; return ERROR_NULL;
 error_overload:
  assert( !( size == STR_MAX_LEN ) && "strsize: size is too big" );
}  // size_string(): return length of the given string

int strslice(char *token, char *string, int start, int end) {
  if ( (&string) == NULL ) { goto error_null; }
  if ( (&string) == '\0' ) { goto error_null; }
  if ( end >= STR_MAX_LENGTH ) { goto error_overload; }
  error return_value = ERROR;

  if (( token = (char *)calloc(end - start, sizeof(char)) )) { goto error_calloc; }
  char *buffer = string; int cnt = 0;
  for ( cnt = start; i < end; cnt++ ) {
    &(target + 1) = (string + 1);
  }  // for
  target[cnt] = '\0';

  return_value = SUCCESS; return return_value;
 error_calloc: return_value = ERROR_CALLOC; return return_value;
 error_null: return_value = ERROR_NULL; return return_value;
 error_overload: return_value = ERROR_OVERLOAD; return return_value;
}  // strslice(): slice string which between start and end

int strsplit(char *token, char *string, char *seperator) {
  if ( (&string) == NULL ) { goto error_null; }
  if ( (&string) == '\0' ) { goto error_null; }
  error return_value = ERROR;

  int string_size = strsize(string); int seperator_size = strsize(seperator);
  char *buffer = string;
  int cnt = 0;
  while ( 1 ) {  // found a spot to split
    if (!( strslice(tok, string, cnt, cnt + seperator_size) )) { goto error_strslice; }

    if (!( strcmp(sliced_string, seperator) )) { break; }
    if ( cnt >= STR_MAX_LEN ) { goto error_overload; }
=======
#define SUCCESS 1
#define ERROR 0
#define ERROR_STRSLICE -1
#define ERROR_STRSPLIT -2

#define STR_MAX_LENGTH 100

int strsize(char string[STR_MAX_LENGTH]) {
  assert( !( string[0] == '\0' ) && "strsize: string is strNULL" );
  assert( !( string == NULL ) && "strsize: string is NULL" );
  int return_value = ERROR;

  for ( int i = 0; i < STR_MAX_LENGTH; i++ ) {
    if ( string[i]  == '\0' ) { return return_value; }
    size++;
  }  // for

  assert( !( return_value == ERROR ) && "size_string: size is zero" );
  assert( !( return_value == STR_MAX_LENGTH ) && "size_string: size is greater than MAX_STR_LENGTH" );

  return return_value;
}  // size_string(): return length of the given string

int strslice(char tok[STR_MAX_LENGTH], char string[STR_MAX_LENGTH], int start_index, int end_index) {
  assert( !( start_index >= end_index ) && "strslice: start index is greater or same with end index" );
  int return_value = ERROR;

  char buffer[STR_MAX_LENGTH]; int cnt = 0;
  for ( int i = start_index; i < end_index; i++ ) {
    tok[cnt] = string[i];
    cnt++;
  }  // for
  target[cnt] = '\0';

  return_value = SUCCESS;
  return return_value;
}  // strslice(): slice string which between start and end

int strsplit(char tok[STR_MAX_LENGTH] , char string[STR_MAX_LENGTH], char seperator[STR_MAX_LENGTH]) {
  assert( !( tok == NULL ) && "strsplit: return_string is NULL" );
  assert( !( string[0] == '\0' ) && "strsplit: target_string is strNULL" );
  assert( !( string == NULL ) && "strsplit: target_string is NULL" );
  assert( !( seperator[0] == '\0' ) && "strsplit: sepeartor is strNULL" );
  assert( !( seperator == NULL ) && "strsplit: seperator is NULL" );
  assert( !( seperator[0] == '\0' ) && "strsplit: seperator is strNULL" );
  int return_value = ERROR;

  char slice[STR_MAX_LENGTH]; char *buff = string; 
  int seperator_size = strsize(seperator); int cnt = 0;
  while ( 1 ) {  // found a spot to split
    if ( strcmp(slice, seperator)  == 0 ) { break; }
    if (!( strslice(slice, buff, cnt, cnt + seperator_size) )) { return_value = ERROR_STRSLICE; goto free_slice; }
    if ( cnt > STR_MAX_LENGTH ) { return_value = ERROR; goto free_slice; }
>>>>>>> b64dcc68016b704d55bd216d966e31d664ec5fcf
    cnt++;
  }  // while
  
  int slice_size = strsize(slice); slice[slice_size] = '\0';
  if (!( strcpy(tok, slice) )) { return ERROR_STRCPY; }

<<<<<<< HEAD
  &(tok + cnt) = '\0';
  pretok = (char *)calloc(stirng_size - cnt + seperator_size, sizeof(char));
  if (!( strslice(pretok, string, cnt + seperator_size, seperator_size) )) { goto error_strslice; }
  if (!( strcpy(tok, pretok) )) {
    for ( int i = 0; i < cnt + 1; i++ ) { free( *(pretok + i) ); }
    goto error_strcpy;
  }  // if

  return_value = SUCCESS; return return_value;
 error_calloc: return_value = ERROR_CALLOC; return return_value;
 error_null: return_value = ERROR_NULL; return return_value;
 error_strslice:
  assert(!( strslice(tok, string, 0, cnt) ) && "strslice: strslice did not worked");
 error_strcpy:
  assert(!( strcpy(return_string, seperated_string) ) && "strcpy: strcpy did not worked");
=======
  char residue[STR_MAX_LENGTH]; int string_size = strsize(string);
  if ( residue[string_size] == '\0' ) { goto free_residue; }
  if (!( strslice(residue, string, cnt + seperator_size, strsize(string)) )) { return_value = ERROR_STRSLICE; goto free_residue; }
  if (!( strcpy(string, residue) )) { ERROR_STRCPY; goto free_residue; }
  return_value = SUCCESS;

  free_residue:
    strfree(residue, STR_MAX_LEN);
  free_slice:
    strfree(slice, STR_MAX_LEN);

  return return_value;
>>>>>>> b64dcc68016b704d55bd216d966e31d664ec5fcf
}  // strsplit(): split string by seperator
