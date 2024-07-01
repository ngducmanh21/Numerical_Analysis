#include<bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - x - 1;
}

int main() {
    double a, b, err;
    cout << "Nhap vao khoang [a, b]" << endl;
    cin >> a >> b;
    cout << "Nhap vao sai so err = ";
    cin >> err;

    if (f(a)*f(b) > 0) {
        cout << "Khong giai duoc" << endl;
    } else {
        if (f(a) < 0) {
            double x0 = a;
            double x1 = x0 + f(x0)*(x0-b)/(f(b)-f(x0));
            while (abs(x1-x0) > err) {
                x0 = x1;
                x1 = x0 + f(x0)*(x0-b)/(f(b)-f(x0));
            }
            cout << "x = " << x1 << endl;
        } else {
            double x0 = b;
            double x1 = x0 + f(x0)*f(x0-a)/(f(a)-f(x0));
            while (abs(x1-x0) > err) {
                x0 = x1;
                x1 = x0 + f(x0)*f(x0-a)/(f(a)-f(x0));
            }
            cout << "x = " << x1 << endl;
        }
    }

    return 0;
}

