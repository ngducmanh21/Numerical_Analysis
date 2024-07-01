#include<bits/stdc++.h>
using namespace std;

void NewtonLui(int n, float x[], float y[], float a)
{
	float SP[50];
	float h = x[1] - x[0];
	float t = (a - x[n]) / h;
	float cur = t;
	for(int i = 0; i < n; i++)
		SP[i] = y[i + 1] - y[i];
	float res = y[n] + SP[n - 1] * t;
	for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= n - i; j++) SP[j] = SP[j + 1] - SP[j];
        cur *= (t + i - 1) / i;
        res += SP[n - i] * cur;
    }
	cout << res;
 }
int main()
{
	int n;
	cout << "Nhap so moc noi suy n = ";
	cin >> n;
    float x[50], y[50], xs;
    for(int i = 0; i <= n; i++)
	{
		cout << "x[" << i << "] = "; cin >> x[i];
		cout << "y[" << i << "] = "; cin >> y[i];
	}
	cout << "Nhap x* = ";
	cin >> xs;
	NewtonLui(n,x,y,xs);
}

