#include<bits/stdc++.h>
using namespace std;

#define f(x) (x * x)

double Simpson(double a, double b, int n)
{
    double h = (b - a) / n;
    double s = f(a) + f(b);
    for (int i = 1; i < n; ++i)
    {
        double x = a + i * h;
        if(i % 2 == 0) s += 2 * f(x);
        else s += 4 * f(x);
    }
    s *= (h / 3);
    return s;
}


int main()
{
    cout << "Gia tri tich phan: " << fixed << setprecision(4) << Simpson(1, 3, 10);
}
