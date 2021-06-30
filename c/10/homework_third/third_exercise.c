#include <stdio.h>
#include <string.h>

char S[2][17]; // Направил съм го 17, а не 16 заради '\0'

char F(char x){
    return S[0][x>>6] + S[1][x>>4];
}

void encrypt(char L, char R, char* out){
    for(int i=0;i<16;i++){
        R^=F(L);
        L^=F(R);
    }
    out[0]=R;
    out[1]=L;
}

void decrypt(char L, char R, char* out){
    for(int i=0;i<16;i++){
        R^=F(L);
        L^=F(R);
    }
    out[0]=R;
    out[1]=L;
}

/*  
    Два цикъла, чрез които се преработва глобалната променлива
    според ключа. Взима се големината на ключа и когато той достигне краят си
    се повтаря. Ако не се достигне краят на ключа през първата итерация,
    то той при втората започва със следващия символ от там от където е свършил при първата.
*/
void init_boxes(char* key){
    int length_of_key=strlen(key),k=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<16;j++){
            if(k==length_of_key) k=0;
            S[i][j]=key[k];
            k++;
        }
    }
}


/*
    Взима се големината на текста и се създава временен стринг, който съдържа
    в случая двата криптирани символа, като после се добавят към encrypted чрез конкатинация.
*/
void perform_encryption(char* text, char* key, char* encrypted){
    int length_of_text=strlen(text);
    char temporary_encrypted[2];
    init_boxes(key);
    for(int i=0;i<length_of_text;i+=2){
        encrypt(text[i], text[i+1], temporary_encrypted);
        strcat(encrypted, temporary_encrypted);
    }
}

/*
    Същото като при криптирането, но в случая с декриптиране.
*/
void perform_decryption(char* encrypted, char* decrypted){
    int length_of_encrypted=strlen(encrypted);
    char temporary_decrypted[2];
    for(int i=0;i<length_of_encrypted;i+=2){
        decrypt(encrypted[i], encrypted[i+1], temporary_decrypted);
        strcat(decrypted, temporary_decrypted);
    }
}

/*
    Пример показващ работата на криптирането и декриптирането.
*/
int main(int argc, char* argv[]){
    char encrypted[65];
    char decrypted[65];
    perform_encryption(argv[1], argv[2], encrypted);
    puts(encrypted);
    perform_decryption(encrypted,decrypted);
    puts(decrypted);
    return 0;
}