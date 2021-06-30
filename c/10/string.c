#include "stdio.h"
#include "string.h"


int main() {
    int arr1[] = {1,2,3};
    char arr2[] = {'a','b','c'};
    int arr3[] = {'a','b','c'};
    char arr4[] = {97,98,99};
    char arr5[] = {"abc"};
    char arr6[] = {1,2,3,4,5};
	printf("\n %d %c", arr3[2], arr3[2]);
    printf("\n %d %c", arr2[2] - arr2[1], arr2[2] - arr2[1]);
    printf("\n %s", arr5);
    // printf("\n %d", strlen(arr5));
    // printf("\n %d", strlen(arr6));
    // char str[10] = "asd";
    // char str2[] = "def";
    // strcat(str,str2);
    // printf("\n %s", str);
    // char str1[] = "abc";
    // char str2[] = "abc";
    // char str3[] = "bcd";
    // char str4[] = "1ab";
    // printf("\n %s", strcat(str1, str4));
    return 0;
}


//dopulnitelna zadacha 1-25