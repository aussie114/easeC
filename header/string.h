#ifndef STRING_H
#define STRING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string.h"
int str_capitalise(char input[]);
int str_center(char input[], int total_length, char charactor, char output[]);
int str_count(char input[], char * value, int start, int end);
int str_isalnum(char input[]);
int str_isalpha(char input[]); 
int str_isascii(char input[]);
int str_isdecimal(char input[]);
int str_islower(char input[]);
int str_isupper(char input[]);
int str_isprintable(char input[]);
int str_isspace(char input[]);
#endif
