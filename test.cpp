#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// sum all values of the array
float sumArr (int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

// find the largest number in the array
// that represents the max number of equal integers in the array
int largestNumber (int *arr, int size) {
    for (int i = 1; i < size; i++){
        if (arr[0] < arr[i]){
            arr[0] = arr[i];
        }
    }
    return arr[0];
}

// check if all variables in the array are the same
bool sameValues (int *arr, int size) {
    if (sumArr(arr, size) / arr[0] == 1){
        return true;
    }
}

// find how many equal integers are in the array
int equalNumbers(int *arr, int size){
    int R, ans;
    int equalInt[size];
    for (int k = 0; k < size; k++){
        equalInt[k] = 1;
    }
    // check if all variables in array are same
    if (sameValues(arr, size)){
        return size;
    }
    // if not same, find the maximum number of same integers
    else {
        for (int i = 0; i < size-1; i++){
            for (int j = i+1; j < size; j++){
                if (arr[j] == arr[i]){
                    equalInt[i]++;
                }
            }
        }
    }
    return largestNumber(equalInt, size);
}

// do the operation XOR on each integers in the array
void XOROperation (int *arr, int size, int X, int num) {
    int oper = 0;
    int maxNum, K;

    for (int i = 0; i < size; i++){
        arr[i] = arr[i] ^ X; // XOR operation

        // find the number of equal integers in the array
        K = equalNumbers(arr, size);
        maxNum = K;

        // check if new array has more equal integers
        // than the original or previous one
        if (maxNum > num) {
            num = maxNum;
            oper++;
        }
    }
    // print maximum number of equal integers in the final array and
    // the minimum number of operations to achieve these many equal integers
    cout << num << " " << oper << endl;
}


int main() {
    int T, N, X, ans, R;
    // enter number of test cases
    cin >> T;
    // constraint 1<=T<=10^4
    if (T >= 0 && T <= pow(10, 4)){
        for (int i = 1; i <= T; i++) {
            // enter number of integers for array A, and integer X
            cin >> N >> X;
            int A[N];
            //constraint 1<=N<=10^5 and 0<=X<=10^9
            if (N >= 1 && N <= pow(10, 5) && X > 0 & X <= pow(10, 9)){
                // enter values of array
                for (int j = 0; j < N; j++) {
                    cin >> A[j];
                    // constraint 0<=Ai<=10^9
                    if (A[j] < 0 && A[j] > pow(10, 9)){
                        break;
                    }
                }
                R = equalNumbers(A,N);
                ans = R;
                // call the function that did the operation XOR and
                // checked how many equal integers can be in the array
                XOROperation(A, N, X, ans);
            }
        }
    }
    return 0;
}
