
/*before solving any problem understand the pattern ->

- let's understand the pattern - inclue and not include 
- you don't need learn code you need to understand the pattern
- if you can create a recursive tree then FUCK THE PROBLEM STATEMENT ):


TC = 0(2)N means 2powerN
SC = 0(N)

*/

#include <bits/stdc++.h>
using namespace std;

void printAll(int index, vector<int>&ds,int arr [], int n){

        // base condtion
        if(index == n){
            for(auto x: ds){
                cout << x << " ";
            }
            // not you are not including nothing print empty solution
            if(ds.size() == 0){
                cout << "{ }" ;
            }
            cout <<endl; 
            return;
        }
        
        // pick the element 
        ds.push_back(arr[index]);
        printAll(index+1,ds,arr,n);
        ds.pop_back();

        // not pick the element
        printAll(index+1,ds,arr, n);
}


// start code --
int main(){
    int arr[3] = {3,1,2};
    int sizeArray = 3;
    vector<int> ds;
    int index = 0;
    printAll(index,ds,arr,sizeArray);
}