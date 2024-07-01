#include<bits/stdc++.h>
using namespace std;

void NewtonTien(int n, float x[], float y[], float a)
{
	float SP[50];
	float h = x[1] - x[0];
	float t = (a - x[0]) / h;
	float cur = t;
	for(int i = 0; i < n; i++)
		SP[i] = y[i + 1] - y[i];
	float res = y[0] + SP[0] * t;
	for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= n - i; j++) SP[j] = SP[j + 1] - SP[j];
        cur *= (t - i + 1) / i;
        res += SP[0] * cur;
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
        cin >> x[i];
        cin >> y[i];
	}
	cout << "Nhap x* = ";
	cin >> xs;
	NewtonTien(n,x,y,xs);
}

