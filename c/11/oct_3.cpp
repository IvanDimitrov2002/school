#include <stdlib.h>
#include <iostream>
using namespace std;

class VectorPopException : exception {};

class VectorFullException : exception{};

class VectorMaxLength : exception{};

class Vector {
    int *items;
    int max_count = 10;
    int max_length = 1000;
public:
    Vector(){
        count=0;
        items = NULL;
    }

    Vector(int max_count, int max_length){
        this->max_count = max_count;
        this->max_length = max_length;
        count=0;
        items = NULL;
    }
    int count;

    void push(int new_item){
        if(count == max_count){
            throw VectorFullException();
        }
        if(new_item == max_length){
            throw VectorMaxLength();
        }
        items = (int*)realloc(items, sizeof(int)*(++count));
        items[count - 1] = new_item;
    }
    
    int is_empty(){
        if(count<=0){
            return 1;
        }
        return 0;
    }

    int pop(){
        if(is_empty()){
            throw VectorPopException();
        }
        return items[--count];
    }

};


int main(){
    Vector v1 = Vector(11, 1);
    try{
        for(int i=0;1;i++){
            v1.push(i);
        }
    } catch (VectorFullException ex){
        cout << "Vector is full." << endl;
    } catch(VectorMaxLength ex) {
        cout << "Too large item!" << endl;
    }
    cout << v1.count << endl;
    try{
        int popped_item;
        while(1){
            popped_item = v1.pop();
            printf("Popped item: %d\n", popped_item);
        }
    } catch(VectorPopException ex) {
        cout << "it broke" << endl;
    } catch(exception ex) {
        cout << "it just broke" << endl;
    }
    
    return 0;
}