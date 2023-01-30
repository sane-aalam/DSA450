
// print the counting number 1 to 10 using recursive calling

#include <iostream>
using namespace std;

void helper(int i , int n){
    if(i>n) 
      return;
    cout << i << " ";
    helper(i+1,n);
}


int main(){
    int n;
    cout << "Enter the value of n ->" << endl;
    cin>> n;
    helper(1,n);
    return 0;
}