#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
	float x[100], y[100];
    cout << "Nhap so moc noi suy n = ";
    cin >> n;
    for(int i = 0; i <= n;i++)
    {
        cout << "x["<< i <<"] = "; cin >> x[i];
        cout << "y["<< i <<"] = "; cin >> y[i];
    }
    float xs;
    cout << "Nhap x* = ";
    cin >> xs;
    float res = y[0];
    float t = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++) y[j] = (y[j + 1] - y[j]) / (x[i + j] - x[j]);
        t *= xs - x[i-1];
        res += y[0] * t;
    }
    cout << res;
}
