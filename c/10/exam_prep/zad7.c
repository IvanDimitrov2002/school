#include <stdio.h>

char make_low(char c)
{
    if (c < 'a') return c - ('A' - 'a');
    return c;
}

int compare(char *str1, char *str2){
    int i = 0;
    while (1)
    {
        if (str1[i] == '\0' && str2[i] == '\0') return 0;
        if (str1[i] != '\0' && str2[i] == '\0') return 1;
        if (str1[i] == '\0' && str2[i] != '\0') return 2;
        if (make_low(str1[i]) > make_low(str2[i])) return 1;
        else if (make_low(str1[i]) < make_low(str2[i])) return 2;
        i++;
    }
}

int main()
{
printf("%d\n", compare("HELLO", "Hello"));
printf("%d\n", compare("HELLp", "Hello"));
printf("%d\n", compare("HELL", "Hello"));
return 0;
}