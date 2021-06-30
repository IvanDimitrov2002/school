#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct comment_t{
    char user[100];
    char text[255];
};

struct meme_t{
    char url[255];
    char title[40];
    float rating;
    struct comment_t *comments;
    int comment_count;
};

struct meme_t create_meme(){
    char c;
    struct meme_t meme;
    printf("Enter URL: ");
    fgets(meme.url, 255, stdin);
    printf("Enter title: ");
    fgets(meme.title, 40, stdin);
    meme.rating = ((float)rand()/(float)(RAND_MAX)) * 5;
    meme.comments = NULL;
    meme.comment_count = 0;
    while(1){
        meme.comments = (struct comment_t*)realloc(meme.comments, sizeof(struct comment_t) * (meme.comment_count+1));
        printf("Wanna write a comment?(y/n): ");
        c = getchar();
        getchar();
        if(c=='N' || c=='n') break;
        printf("Comment: ");
        fgets(meme.comments[meme.comment_count].text, 255, stdin);
        printf("Username: ");
        fgets(meme.comments[meme.comment_count].user, 100, stdin);
        meme.comment_count++;
    }
    return meme;
}

void insert_memes(struct meme_t *memes, int *meme_count){
    memes = (struct meme_t*)realloc(memes, sizeof(struct meme_t) * (*meme_count + 1));
    memes[*meme_count] = create_meme();
    *meme_count+=1;
}

void print_meme(struct meme_t meme){
    printf("----------------------------\n");
    printf("URL: %s\n", meme.url);
    printf("Title: %s\n", meme.title);
    printf("Rating: %.2f\n", meme.rating);
    if(meme.comment_count>0){
        printf("Comments:\n");
        for(int i=0;i<meme.comment_count;i++){
            printf("    %s\n", meme.comments[i].user);
            printf("    %s\n", meme.comments[i].text);
        }
    }
    printf("----------------------------\n");
}

void sort_by_rating(struct meme_t *memes, int meme_count){
    int i,j;
    struct meme_t temp_meme;
    for (i = 0 ; i < meme_count - 1; i++){
        for (j = 0 ; j < meme_count - i - 1; j++){
            if (memes[j].rating < memes[j+1].rating){
                temp_meme = memes[j];
                memes[j]   = memes[j+1];
                memes[j+1] = temp_meme;
            }
        }
    }
}

struct meme_t best_meme(struct meme_t *memes, int meme_count){
    sort_by_rating(memes, meme_count);
    return memes[0];
}

int main(){
    srand(time(0)); 
    int meme_count=0;
    struct meme_t *memes = (struct meme_t*)malloc(sizeof(struct meme_t));
    insert_memes(memes, &meme_count);
    insert_memes(memes, &meme_count);
    insert_memes(memes, &meme_count);
    print_meme(memes[1]);
    return 0;
}