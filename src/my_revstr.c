#include "runner.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    int t = 0;

    while (str[j] != '\0')
        j++;
    j--;
    while (i < j) {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
    return str;
}
