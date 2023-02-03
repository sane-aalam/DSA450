#include <iostream>
using namespace std;


// RECURSIVE CODE Approach = BASE CONDITION + CHOICE DIAGRAM 
/*
 ----------------BASE CONDITION---------------
 
 if your array size is zero then you can not get maximum profit - no profitable way
                1) values.size( ) == 0
                2) n == 0;

CHOICE DIAGRAM - include and not include ( we can accroding to questions)

*/

int knapscak01(int values[], int wieght[] , int W, int n){

    // base condition- 
    if(n == 0 || W == 0){
        return 0;
    }
    // choice diagram

    // value of weight is equal and less than we can include - so we have choice we include or Not );
    if(wieght[n-1] <= W){
        // we are including the element ( so we store the value )
        return values[n-1] + knapscak01(values, wieght, W-values[n-1], n - 1 );
    }else{
        // we are not including the element 
        return knapscak01(values, wieght, W, n-1);
    }

    // value of weight is greater then your kanspcak bug capacity so totally 
    // we are not able inlcude this element, so n-1 for next element
    if(wieght[n-1] > W){
        // we are not including the element 
        return knapscak01(values, wieght, W, n-1);
    }
}

int main(){

    // Input: N = 3, W = 4
    // values[] = {1,2,3}
    // weight[] = {4,5,1}
    // Output: 3

    int values[] = {1,2,3};
    int weight[] = {4,5,1};
    int n = 3; // here n is size of value array
    int W = 4; // W is the capacity of the array

    int maximum_Profit = knapscak01(values,weight,W,n);
    cout << endl;
    cout << "The maximum Profit "  << maximum_Profit << endl;
    cout << endl;

    return 0;
}