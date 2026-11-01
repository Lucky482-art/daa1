#include <iostream>
using namespace std;

const int N = 4;

void add(int A[N][N], int B[N][N], int C[N][N], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[N][N], int B[N][N], int C[N][N], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[N][N], int B[N][N], int C[N][N], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[N][N], A12[N][N], A21[N][N], A22[N][N];
    int B11[N][N], B12[N][N], B21[N][N], B22[N][N];
    int M1[N][N], M2[N][N], M3[N][N], M4[N][N];
    int M5[N][N], M6[N][N], M7[N][N];
    int T1[N][N], T2[N][N];
    int C11[N][N], C12[N][N], C21[N][N], C22[N][N];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    add(A11, A22, T1, k);
    add(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    add(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    sub(B12, B22, T2, k);
    strassen(A11, T2, M3, k);

    sub(B21, B11, T2, k);
    strassen(A22, T2, M4, k);

    add(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    sub(A21, A11, T1, k);
    add(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    sub(A12, A22, T1, k);
    add(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    add(M1, M4, T1, k);
    sub(T1, M5, T2, k);
    add(T2, M7, C11, k);

    add(M3, M5, C12, k);
    add(M2, M4, C21, k);

    sub(M1, M2, T1, k);
    add(T1, M3, T2, k);
    add(T2, M6, C22, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    cout << "Enter elements of first 4x4 matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    cout << "Enter elements of second 4x4 matrix:\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    strassen(A, B, C, N);

    cout << "Resultant matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}