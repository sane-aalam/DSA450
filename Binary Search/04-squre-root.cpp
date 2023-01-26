#include <iostream>
using namespace std;


int FindSqureRoot(int n){
    int start = 0;
    int end = n ;

   long long int mid = start + (end-start)/2;

   long long int squre ;

   long long int ans = -1;

    while(start<=end){
        squre = mid * mid;
        if(squre == n){
            return mid;
        }else if(squre < n){
            ans = mid;
            start = mid + 1;
        }else{
            end  = mid - 1;
        }
        mid = start + (end-start)/2;
    }
}


int main(){
    int n;
    cout << "Enter the value which we want to find squre root" << endl;
    cin>> n;
   int value = FindSqureRoot(n);
   cout << "now value is : " <<value << endl <<endl;
    return 0;
}