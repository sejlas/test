#include <iostream>

using namespace std;

int sumArr (int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int EqualNumbers (int *arr, int size ) {
    // check if all numbers are the same
    if (sumArr(arr, size) / arr[0] == 1){
        return size;
    }
    // if different find maximum same numbers
    else {
        int maxEqualInt = 1;  //number of equal integers
        for (int i = 0; i < size; i++){
            int EqualInt = 1;
            for (int j = 1; j < size; j++){
                if (arr[j] == arr[i]){
                    EqualInt++;
                    if (EqualInt > maxEqualInt){
                        maxEqualInt = EqualInt;
                    }
                }
            }
        return maxEqualInt;
        }
    }
}

int main() {
    int T, N, X, ans;
    cout << "Enter number of tests cases: ";
    cin >> T;
    int A[N];
    for (int i = 0; i < T; i++) {
        cin >> N >> X; // Enter N and X
    }
    // enter values of array
    for (int j = 0; j < N; j++) {
        cin >> A[j];
        cout << "Array: " << A[j] <<" ";
    }
    cout << "\n" << "N: " << N << " X: " << X << endl;
    ans =  EqualNumbers(A, N); // kad se ovo izbrise i linija ispod i napise samo "cout << EqualNumbers(A, N);" bude okej sve
    cout << ans << endl;
}
