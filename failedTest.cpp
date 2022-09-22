#include <iostream>
#include <bits/stdc++.h>

using namespace std;

float sumArr (int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {
    int T, ans, R = 0;
    cout <<"Enter tests: ";
    cin >> T;

    int N[T], X[T];
    int som [T][3][R];
    //constraint T
    if (T >= 0 && T <= pow(10, 4)){
        for (int i = 0; i < T; i++) {

            for (int k = 0; k < 2; k++){
                if (k == 0){
                    cout <<"Enter N: ";
                    cin >> som[i][k][R];
                    N[i] = som[i][k][R];
                }
                else if  (k == 1){
                    cout <<"Enter X: ";
                    cin >> som[i][k][R];
                    X[i] = som[i][k][R];
                }
                cout << "som: " << som[i][k][R]<< endl;
            }

            int A[N[i]];

            //constraint N
            if (N[i] >= 1 && N[i] <= pow(10, 5)){

                cout << "Enter array: ";
                for (int j = 0; j < N[i]; j++) {
                    cin >> A[j];
                    cout << "\n array [" <<j<<"] : " << A[j] <<endl;
                    som[i][3][j] = A[j];
                    for (int h = 0; h < T; h++){
                        cout << "check N: " <<h<< " " <<N[h]<<endl;
                    }
                    cout << "array som [i: "<< i<<"][j: "<< j<< "] " << som[i][3][j]<<endl;
                }
            }
        }

        for (int i = 0; i < T; i++) {
            int A[N[i]];
            for (int j = 0; j < N[i]; j++) {
                cout << "array som new " << som[i][3][j]<<endl;
                A[j] = som[i][3][j];
                cout << "array new: " << A[j]<<endl;
            }
            //constraint X
            if (X[i] >= 0 && X[i] <= pow(10,9)) {
                for (int j = 0; j < N[i]; j++) {
                        //constraint Ai
                    if (A[j] >= 0 && A[j] <= pow(10, 9)) {
                        if (sumArr(A, N[i]) / T <= 5 * pow(10, 5)){
                            //R = EqualNumbers(A,N);
                            //ans = R;
                            //cout << "Sum: " << sumArr(A,N)<< endl;
                            //cout << "\n" << EqualNumbers(A, N) << endl;

                            //XOROperation(A, N, X, ans);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
