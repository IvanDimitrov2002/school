#include <stdio.h>
#include <string.h>

struct packet_t {
    char content[255];
    char start_address[16];
    char end_address[16];
};

void sort(struct packet_t *buffer) 
{ 
    int i, j;
    struct packet_t temp; 
    for (i=0;i<10-1;i++){
        for (j=0;j<10-i-1;j++){
            if(strlen((buffer+j)->content) > strlen((buffer+j+1)->content)){
                temp=buffer[j];
                buffer[j]=buffer[j+1];
                buffer[j+1]=temp;
            }
        }  
    }       
}

void process_packets(){
    struct packet_t buffer[10];
    for(int i=0;i<10;i++){
        scanf("%s", buffer[i].start_address);
        scanf("%s", buffer[i].end_address);
        scanf("%[^\n]", buffer[i].content);
    }
    printf("sending out packets...\n");
    sort(buffer);
    for(int i=0;i<10;i++){
        printf("From %s To %s Content:%s\n", buffer[i].start_address, buffer[i].end_address, buffer[i].content);
    }
    memset(buffer, 0, sizeof buffer);
    printf("\n");
}

//Функцията се изпълнява до изричното терминиране на програмата (CTRL+C)
int main(){
    while(1)
        process_packets();
    return 0;
}