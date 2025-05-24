#include <string.h>
#include <ctype.h>

int str_capitalise(char input[])
{
	if (islower(input[0]))
	{
		input[0] -= 32;
		return 0;
	}
	else
	{
		return -1;
	}
}

int str_center(char input[], int total_length, char charactor, char output[])
{
	int length = strlen(input);
	if (length >= total_length) return -1;
	memset(output, charactor, total_length);               // fill array with char
	char * start = output + ((total_length - length) / 2); // set pointer to start of centered string
	memcpy(start, input, length);                          // write string
	output[total_length] = 0;
	return 0;
}

int str_count(char input[], char *value, int start, int end)
{
    if (end == -1) end = strlen(input);
    if (start > end) return -1;

    int count = 0;
    int val_len = strlen(value);
    const char *ptr = input + start;
    const char *limit = input + end;

    while (ptr < limit) 
	{
        const char *match = strstr(ptr, value);
        if (!match || match >= limit) break;

        char before = (match == input) ? '\0' : *(match - 1);
        char after  = *(match + val_len);

        int before_ok = (match == input || !isalnum(before));
        int after_ok  = ((match + val_len) >= input + end || !isalnum(after));

        if (before_ok && after_ok)
            count++;

        ptr = match + val_len;
    }

    return count;
}

int str_isalnum(char input[]) 
{
    while (*input) 
    {
        if (!isalnum((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

int str_isalpha(char input[]) 
{
    while (*input) 
    {
        if (!isalpha((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

int str_isascii(char input[]) 
{
    while (*input) 
    {
        if (!isascii((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

int str_isdecimal(char input[]) 
{
    while (*input) 
    {
        if (!isdigit((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

int str_islower(char input[]) 
{
    while (*input) 
    {
        if (!islower((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

int str_isupper(char input[]) 
{
    while (*input) 
    {
        if (!isupper((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

int str_isprintable(char input[]) 
{
    while (*input) 
    {
        if (!isprint((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

int str_isspace(char input[]) 
{
    while (*input) 
    {
        if (!isspace((unsigned char)*input)) return 0;
        input++;
    }
    return 1;
}

