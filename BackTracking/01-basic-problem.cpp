
// print hello world 5 times using recursive call 

#include <iostream>
using namespace std;

void helper(int i , int n){
    if(i>n) 
      return;
    cout << "Hello world!" << endl;
    helper(i+1,n);
}


int main(){
    helper(1,5);
    return 0;
}