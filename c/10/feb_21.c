#include <stdio.h>

struct my_struct_t{
    int val;
};

int main(){
    struct my_struct_t s1;
    s1.val=10;

    struct my_struct_t *s2 = &s1;
    //s2.val=10;
    s2->val=10;

    printf("%d\n", sizeof(struct my_struct_t));

    // int address;
    // int scan_result = scanf("%d", &address);
    // printf("%d\n", scan_result);
    // printf("%d\n", &address);


    // int address;
    // int value;
    // scanf("%d %d", &address, &value);
    // *(int*) address = value;


    // int arr[5] = {5, 100, 270, 8000, 60000};
    // for(int i=0;i<5;i++){
    //     printf("%d ", arr[i]);
    // }

    // printf("\n");

    // for(int i=0;i<5;i++){
    //     printf("%d ", *(arr+i));
    // }

    // printf("\n");

    // for(int i=0;i<5;i++){
    //     printf("%d ", ((char*)arr+i));
    // }

    // printf("\n");

    // for(int i=0;i<5;i++){
    //     printf("%d ", *((char*)arr+i));
    // }

    return 0;
}