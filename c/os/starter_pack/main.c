#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

void *read_image(const char *filepath);

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int main(int argc, const char* argv[]){
    void *data = read_image(argv[1]);
    
    if (data == NULL){
        printf("Unable to open file\n");
        return 0;
    }

    if (strcmp(get_filename_ext(argv[1]), "png") != 0){
        printf("Unable to parse file\n");
        return 0;
    }

    data+=16;
    printf("PNG image width: %d\n", ntohl(*(uint32_t*)data));

    data+=4;
    printf("PNG image height: %d\n", ntohl(*(uint32_t*)data));

    FILE *f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
    printf("PNG file size: %ld\n", ftell(f));
    fclose(f);


    return 0;
}