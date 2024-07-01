#include<bits/stdc++.h>
using namespace std;

#define f(x) (x * x)

double Hinhthang(double a, double b, int n)
{
    double h = (b - a) / n;
    double s = f(a) + f(b);
    for (int i = 1; i < n; ++i)
    {
        double x = a + i * h;
        s += 2 * f(x);
    }
    s *= (h / 2);
    return s;
}


int main()
{
    cout << "Gia tri tich phan: " << fixed << setprecision(4) << Hinhthang(1, 3, 20);
}
