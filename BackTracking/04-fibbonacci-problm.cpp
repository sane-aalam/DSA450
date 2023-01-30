#include <iostream>
using namespace std;

int helper(int n){
    if(n <= 1){
        return n;
    }
    int firstCall = helper(n-1);
    int secondCall = helper(n-2);
    return firstCall + secondCall;
}

// here you can see, there are multiple recursive calls but first call would be complete first then second.
// you can make recusive tree, for deep understanding

// TC = (2 power n)

int main(){
    int n;
    cout << "Enter the number" << endl;
    cin>> n;
    cout << helper(n) << " "; // calling function directly 
    return 0;
}