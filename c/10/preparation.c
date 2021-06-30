#include <stdio.h>
#include <stdlib.h>

// int count;
// char words[10][10];

// void input_words(){
//     printf("broi dumi: \n");
//     scanf("%d", &count);
//     for(int i=0;i<count;i++){
//         scanf("%s", words[i]);
//     }
// }

int get_letter_score(char letter){
    if(letter >= 'a' && letter <= 'z'){
        return letter - 'a' + 1;
    } else if(letter >= 'A' && letter <= 'Z'){
        return letter - 'A' + 1;
    }
    return 0;
}

int get_word_score(char word[10]){
    int score=0;
    for(int i=0;i<10 && word[i] != '\0';i++){
        score += get_letter_score(word[i]);
    }
    return score;
}

void find_best_word(int argc, char* argv[]){
    int best_word_index=0;
    int best_word_score=0;
    for(int i=1; i<argc;i++){
        int score = get_word_score(argv[i]);
        if(score>best_word_score){
            best_word_index=i;
            best_word_score=score;
        }
    }
    printf("nai-dobra duma: %s (%d)\n", argv[best_word_index], best_word_score);
}

int main(int argc, char* argv[]) {
    // input_words();
    for(int i=1;i<argc;i++){
        printf("%s - %d\n", argv[i], get_word_score(argv[i]));
    }
    find_best_word(argc,argv);
    return 0;
}