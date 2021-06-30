#include <stdio.h>
#include <string.h>

struct article_t{
    char header[100];
    char content[500];
    int article_rating;
};

struct blog_t{
    struct article_t articles[100];
    int number_of_articles;
};

struct article_t most_common_article(struct blog_t blog, char word[50]){
    int i,number_of_saved_articles=0,index_of_highest_rating=0,saved_articles[100];
    for(i=0;i<blog.number_of_articles;i++){
        if(strstr(blog.articles[i].header,word)!=NULL || strstr(blog.articles[i].content,word)!=NULL){
            saved_articles[number_of_saved_articles]=i;
            number_of_saved_articles++;
        }
    }
    for(i=0;i<number_of_saved_articles;i++){
        int highest_rating=blog.articles[saved_articles[0]].article_rating;
        if(blog.articles[saved_articles[i]].article_rating>highest_rating){
            highest_rating=blog.articles[saved_articles[i]].article_rating;
            index_of_highest_rating=saved_articles[i];
        }
    }
    return blog.articles[index_of_highest_rating];
}

int main(){
    struct blog_t blog;
    strcpy(blog.articles[0].header, "hello world");
    strcpy(blog.articles[0].content, "hello hello hello");
    blog.articles[0].article_rating = 10;
    strcpy(blog.articles[1].header, "hello world asd");
    strcpy(blog.articles[1].content, "hello hello hello");
    blog.articles[1].article_rating = 11;
    strcpy(blog.articles[2].header, " lolz");
    strcpy(blog.articles[2].content, "adasdasd");
    blog.articles[2].article_rating = 12;
    strcpy(blog.articles[3].header, "test");
    strcpy(blog.articles[3].content, "hello hello hello");
    blog.articles[3].article_rating = 13;
    blog.number_of_articles=4;
    printf("%s\n", most_common_article(blog,"hello").header);
    return 0;
}