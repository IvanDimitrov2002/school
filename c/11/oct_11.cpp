#include <iostream>
#include <string>
#include <queue>
using namespace std;

class iterateString{
    string S;
    queue<char> brackets;
    public:
        int brackets_count = 0;
        bool isBalanced = true;
        iterateString(string S){
            this->S = S;
            for(int i=0;i<S.length();i++){
                if(S[i] == '(' || S[i] == ')'){
                    brackets.push(S[i]);
                }
            }
            brackets_count = brackets.size();

            

        }
};

int main(){
    string S = "((()()(())))";
    iterateString iterator = iterateString(S);
    cout << "Brackets: " << iterator.brackets_count << endl;
    cout << "Is balanced: " << iterator.isBalanced << endl;
    return 0;
}