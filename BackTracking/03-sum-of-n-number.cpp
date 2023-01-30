#include <iostream>
using namespace std;

int helper(int n){
    if(n == 0)  
        return 0;
    else 
        return n + helper(n-1);
}

int main(){
    int n;
    cout << "Enter the number" << endl;
    cin>> n;
    cout << helper(n) << " "; // calling function directly 
    return 0;
}