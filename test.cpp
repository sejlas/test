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
    // ckeck if all variables in array are same
    if (sumArr(arr, size) / arr[0] == 1){
        return size;
    }
    // if not same find the max number of same variables
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

int XOROperation (int *arr, int size, int X, int num) // this function does not have to return anything, just print variables, so it can be void (do later)
{
    int oper = 0;
    int maxNum, K;

    for (int i = 0; i < size; i++){
        arr[i] = arr[i] ^ X; // XOR operation
        // print the array, just for
        for (int j = 0; j < size; j++)
        {
             cout << "arr: " << arr[j]<<endl;
        }
        // find the number of equal integers
        K = EqualNumbers(arr, size);
        maxNum = K;
        cout << "maxNum: " << maxNum << endl; // print it
        // check if found max number for new array has more equal integers than the original or previous one
        if (maxNum > num) {
            num = maxNum;
            oper++;
            cout << "oper: " << oper << endl;
        }
        // when the max number of equal integers is same as previous one, number of operations does not change
        else if (maxNum <= num){
            cout << "oper1: " << oper << endl;
        }
    }
    cout << "Num: " << maxNum << endl;
    return oper;
}

int main()
{
    int T, N, X, ans, R, R2;
    cout << "Enter number of tests cases: ";
    cin >> T;
    int A[N];
    for (int i = 1; i <= T; i++) {
        R2 = 0; // not needed
        cout << "Enter N and X: ";
        cin >> N >> X;
        cout << "N: " << N << " ";
        cout << "X: " << X << endl;
        // Enter values of array
        for (int j = 0; j < N; j++) {
            cin >> A[j];
            cout << "Array: " << A[j] <<" ";
        }
        // print max number of equal integers in the original array
        R = EqualNumbers(A, N);
        ans = R;
        cout << "\n" << "R: " << ans << endl;
        // check how many operations are needed to find max number of equal integers after XOR operation
        R2 = XOROperation(A, N, X, ans);
        cout << "Operations: " << R2 << endl;
    }
    return 0;
}
