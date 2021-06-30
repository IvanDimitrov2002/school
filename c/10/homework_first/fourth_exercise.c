#include <stdio.h>
#include <string.h>

int is_valid_mac(char mac[20]){
    int k=0;
    for(int i=0;i<strlen(mac);i++){
        if(mac[i]>'9'){
            if('a'<=mac[i] && mac[i]<='z'){
                if(mac[i]>'f'){
                    return 0;
                }
            }
            else if('A'<=mac[i] && mac[i]<='Z'){
                if(mac[i]>'F'){
                    return 0;
                }
            }
            else if(mac[i]==':'){
                if(i==2 || i==5 || i==8 || i==11 || i==14){
                    k++;
                }
                else{
                    return 0;
                }
            }
            else if(mac[i]!=':'){
                return 0;
            }
        }
    }
    if(k!=5){
        return 0;
    }
    return 1;
} 

int main(int argc, char* argv[]){
    int i,mac_length=0;
    for(i=1;i<argc;i++){
        mac_length+=strlen(argv[i]);
    }
    if(mac_length==17){
        if(is_valid_mac(argv[1])){
            printf("Mac address is valid!\n");
            return 0;
        }
    }
    printf("Mac address is invalid\n");
    return 0;
}
