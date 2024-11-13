#include <bits/stdc++.h>
using namespace std;

class CurveFitting
{
public:
    int n;
    double x[10], y[10];
    double a, b;
    CurveFitting()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
    }
    void solve()
    {
        double sumxy = 0, sumx = 0, sumy = 0, sumxx = 0;
        for (int i = 0; i < n; i++)
        {
            sumx = sumx + x[i];
            sumy = sumy + y[i];
            sumxx = sumxx + x[i] * x[i];
            sumxy = sumxy + x[i] * y[i];
        }
        b = (sumxy - (sumx * sumy) / n) / (sumxx - (sumx * sumx) / n);
        a = (sumy / n) - b * (sumx / n);
        cout << "a = " << a << endl
             << "b = " << b << endl;
        cout << "Equation = " << a << " + " << b << "x" << endl;
    }
};

int main()
{
    CurveFitting c = CurveFitting();
    c.solve();
    return 0;
}
