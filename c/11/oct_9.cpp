// #include <iostream>
// #include <string>
// using namespace std;



// int main(){
//     // string firstName;
//     // string lastName;
//     // cout << "Enter first name: " << endl;
//     // cin >> firstName;
//     // cout << "Enter last name: " << endl;
//     // cin >> lastName;
//     // cout << "Full name: " << firstName + " " + lastName << endl;
//     // cout << "Size: " << firstName.length() << endl;
//     // cout << "Capacity: " << firstName.capacity() << endl;
//     string fullName;
//     cout << "Enter full name: " << endl;
//     getline(cin, fullName);
//     cout << fullName << endl;
//     return 0;
// }

// #include <iostream>
// #include <stack>
// using namespace std;

// int main(){
//     stack<int> s;
//     cout << "Empty: " << s.empty() << endl;
//     for(int i=0;i<10;i++){
//         s.push(i);
//     }

//     cout << "Size: " << s.size() << endl;
//     s.pop();
//     cout << "Top: " << s.top() << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// void print_vector(vector<int> v){
//     for(int i=0;i<v.size();i++){
//         cout << v[i] << endl;
//     }
// }

// int main(){
//     vector<int> v;
//     for(int i=0;i<10;i++){
//         v.push_back(i);
//     }
//     cout << "Size: " << v.size() << endl;
//     cout << "Capacity: " << v.capacity() << endl;
//     print_vector(v);
//     return 0;
// }

#include <iostream>
#include <list>
using namespace std;

void print_list(list<int> l){
    list<int>::iterator it;
    for(it = l.begin();it != l.end();it++){
        cout << *it << endl;
    }
}

int main(){
    list<int> l;
    for(int i=0;i<10;i++){
        l.push_back(i);
    }
    print_list(l);
    return 0;
}