#include "runner.h"

int len_nb (int nb)
{
    int i = 0;

    if (nb >= 0 && nb <= 9)
        i = 1;
    else {
        while (nb != 0) {
            nb = nb / 10;
            i++;
        }
    }
    i++;
    return i;
}

char *my_getchar(int nb)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (len_nb(i) + 1));
    int result = 0;

    if (nb >= 0 && nb <= 9)
        str[i] = nb + 48;
    else {
        while (nb != 0) {
            result = nb % 10;
            str[i] = result + 48;
            nb = nb / 10;
            i++;
        }
    }
    str[i] = '\0';
    my_revstr(str);
    return str;
}
