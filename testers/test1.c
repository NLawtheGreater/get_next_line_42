#include <stdio.h>
#include <stdlib.h>

char * first()
{
    char * word = malloc(sizeof(char) * 10);
    word[0] = 'a';
    word[1] = 'b';
    word[2] = '\0';
    return word;
}

int main ()
{
    char * out = first();
    printf("%s", out);
    free(out);
    return 0;
}