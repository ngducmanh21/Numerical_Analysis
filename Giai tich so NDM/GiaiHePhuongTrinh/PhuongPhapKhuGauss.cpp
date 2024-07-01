#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Ma tran Anxn voi n = ";
    cin >> n;
    double **A = new double*[n];
    for (int i = 0; i < n; i++) A[i] = new double[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }
    cout << "Nhap ma tran B\n";
    double *B = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "B[" << i << "] = ";
        cin >> B[i];
    }
    double *X = new double[n];
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            double temp = A[j][i] / A[i][i];
            A[j][i] = 0;
            for (int k = i+1; k < n; k++) {
                A[j][k] -= A[i][k] * temp;
            }
            B[j] -= B[i] * temp;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        double temp = B[i];
        for (int j = i+1; j < n; j++) {
            temp -= A[i][j] * X[j];
        }
        X[i] = temp / A[i][i];
    }
    cout << "Ma tran A sau khi khu Gauss:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << A[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "Nghiem cua he phuong trinh la:\n";
    for (int i = 0; i < n; i++) {
        cout << "X[" << i + 1 << "] = " << X[i] << endl;
    }
    return 0;
}
