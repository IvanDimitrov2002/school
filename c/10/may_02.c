#include <stdio.h>

struct student_t {
    char name[100];
    int grade;
    short number;
};

int main(){
    // FILE *fp = fopen("./out.txt", "r");
    // int f;
    // fscanf(fp, "%d", &f);
    // printf("%d\n", f);
    // char c;
    // while((c = fgetc(fp)) != EOF){
    //     putc(c, stdout);
    // }
    // putc('\n', stdout);
    // fclose(fp);
    FILE *fp = fopen("./binfile", "wb");
    struct student_t s = {"Pesho", 2, 10};
    fwrite(&s, sizeof(struct student_t), 1, fp);
    fread(&s, sizeof(struct student_t), 1, fp);
    fclose(fp);
    return 0;
}