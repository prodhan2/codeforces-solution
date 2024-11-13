#include <bits/stdc++.h>
using namespace std;

class FalsePosition
{
private:
    const double tolerence = 0.0001;
    double a, b;

    // Given function is x^3 + x^2 - 1 = 0
    double functional_value(double x)
    {
        return pow(x, 3) + pow(x, 2) - 1;
    }

    double intersect(double a, double b)
    {
        return a - (functional_value(a) * (b - a)) / (functional_value(b) - functional_value(a));
    }

public:
    void solve()
    {
        srand(time(0));
        while (1)
        {
            a = rand() % 10 - 9;
            b = rand() % 10;
            if (functional_value(a) * functional_value(b) < 0)
            {
                break;
            }
        }
        double root;
        while (1)
        {
            root = intersect(a, b);
            printf("a = %9f     b = %9f     root = %9f\n", a, b, root);
            if (functional_value(root) == 0.0)
            {
                break;
            }
            if (functional_value(root) * functional_value(a) > 0)
            {
                a = root;
            }
            else
            {
                b = root;
            }
            if (abs((root - intersect(a, b))) < tolerence)
            {
                break;
            }
        }
        cout << "\nThe root is " << root << " (correct upto 3 decimal palces)\n";
    }
};

int main(void)
{
    FalsePosition f = FalsePosition();
    f.solve();
}
