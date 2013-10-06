/* safe-stack.c */

/* This program has a buffer overflow vulnerability. */
/* Our task is to exploit this vulnerability */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str)
{
    char buffer[12];

    /* The following statement had a buffer overflow problem, we fixed
       it by using the function strncpy, which can be supplied with a
       third argument which limits the number of bytes it copies from
       the second argument into the first. By supplying
       sizeof(buffer), we can ensure that the memory past buffer does
       not get overwritten (preventing our previous exploit). Note,
       however, that this is not perfect, and leads to loss of data
       from str (string truncation). Although we now have no data
       integrity, at least we are not letting a malicious user gain
       shell access through our program. */ 
    strncpy(buffer, str, sizeof(buffer));

    return 1;
}

int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
    bof(str);

    printf("Returned Properly\n");
    return 1;
}
