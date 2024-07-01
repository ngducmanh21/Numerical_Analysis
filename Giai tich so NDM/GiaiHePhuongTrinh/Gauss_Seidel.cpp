#include <bits/stdc++.h>
using namespace std;
bool KiemTraCheoTroi(double** A, int n) {
    bool kt = 1;
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) if (j != i) sum += abs(A[i][j]);
        if (sum >= A[i][i]) {
            kt = 0;
            break;
        }
    }
    if (kt) return 1;
    kt = 1;
    for (int j = 0; j < n; j++) {
        double sum = 0;
        for (int i = 0; i < n; i++) if (i != j) sum += abs(A[i][j]);
        if (sum >= A[j][j]) return 0;
    }
    return 1;
}
double SaiSo(double* X0, double* X1, int n) {
    double MAX = 0;
    for (int i = 0; i < n; i++) MAX = max(MAX, abs(X0[i]-X1[i]));
    return MAX;
}
int main() {
    int n;
    cout << "Ma tran Anxn voi n = ";
    cin >> n;
    double** A = new double*[n];
    for (int i = 0; i < n; i++) A[i] = new double[n];
    cout << "Nhap vao ma tran A\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
    double* B = new double[n];
    cout << "Nhap vao ma tran B\n";
    for (int i = 0; i < n; i++) {
        cout << "B[" << i << "] = ";
        cin >> B[i];
    }
    double *X0 = new double[n], *X1 = new double[n];
    cout << "Nhap vector nghiem ban dau\n";
    for (int i = 0; i < n; i++) {
        cout << "X[" << i << "] = ";
        cin >> X0[i];
    }
    cout << "Nhap sai so err = ";
    double err;
    cin >> err;
    for (int i = 0; i < n; i++) X1[i] = X0[i];
    if (KiemTraCheoTroi(A, n)) {
        for (int i = 0; i < n; i++) {
            double temp = -1/A[i][i];
            B[i] /= A[i][i];
            A[i][i] = 0;
            for (int j = 0; j < n; j++) {
                A[i][j] *= temp;
            }
        }
        do {
            for (int i = 0; i < n; i++) {
                X0[i] = X1[i];
            }
            for (int i = 0; i < n; i++) {
                X1[i] = B[i];
                for (int j = 0; j < i; j++) {
                    X1[i] += A[i][j]*X1[j];
                }
                for (int j = i; j < n; j++) {
                    X1[i] += A[i][j]*X0[j];
                }
            }
        } while (SaiSo(X0, X1, n) >= err);
        cout << "Nghiem cua he phuong trinh la\n";
        for (int i = 0; i < n; i++) {
            cout << "X[" << i << "] = " << X1[i] << endl;
        }
    } else cout << "Ma tran khong co tinh cheo troi";
}
