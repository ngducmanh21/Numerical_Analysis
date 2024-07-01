#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x - x - 1;
}

double Chia_doi(double a, double b, double epsilon)
{
    double c;
    int it = 1;
    do
    {
        c = (a + b) / 2;
        if(f(c) * f(a) > 0) a = c;
        else b = c;
        it++;
    }while(fabs(b - a) >= epsilon);
    return c;
}

int main(){
    double a = 0.0;
    double b = 5.0;
    double epsilon = 0.0001;
    double res = Chia_doi(a, b, epsilon);
    cout << "Nghiem gan dung cua phuong trinh la: " << res << '\n';
    return 0;
}
