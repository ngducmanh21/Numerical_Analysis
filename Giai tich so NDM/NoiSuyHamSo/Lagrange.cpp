#include<bits/stdc++.h>
using namespace std;

//// y = 2x

struct Data{
    double x;
    double y;
};

double Lagrange(vector<Data> &data, double &x)
{
    double res = 0.0;
    for (int i = 0; i < data.size(); ++i)
    {
        double cur = data[i].y;
        for (int j = 0; j < data.size(); ++j)
        {
            if(j != i)
            {
                cur *= (x - data[j].x) / (data[i].x - data[j].x);
            }
        }
        res += cur;
    }
    return res;
}


int main(){
    vector<Data> data = {{1.0, 2.0}, {2.0, 4.0}, {3.0, 6.0}, {4.0, 8.0}};
    double x = 2.5;
    double y = Lagrange(data, x);
    cout << "Gia tri noi suy tai: " << x << " = " << y << '\n';
}
