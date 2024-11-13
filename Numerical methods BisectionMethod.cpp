#include <bits/stdc++.h>
using namespace std;

class BisectionMethod
{
private:
    double tolarence = 0.0001;
    double a, b;
    double function(double x)
    {
        return pow(x, 3) + pow(x, 2) - 1;
    }

public:
    void solve()
    {
        srand(time(0));
        while (1)
        {
            a = -9 + rand() % 10;
            b = rand() % 10;
            if (function(a) * function(b) < 0)
            {
                break;
            }
        }
        double root;
        while (1)
        {
            root = (a + b) / 2;
            printf(" a = %9f b = %9f root = %9f\n", a, b, root);
            if (function(root) == 0.0)
            {
                break;
            }
            if (function(root) * function(a) > 0)
            {
                a = root;
            }
            else
            {
                b = root;
            }
            if (abs(root - (a + b) / 2) < tolarence)
            {
                break;
            }
        }
        cout << "The root is " << root << " (correct upto 3 decimal places)" << endl;
    }
};

int main()
{
    BisectionMethod b = BisectionMethod();
    b.solve();
    return 0;
}
