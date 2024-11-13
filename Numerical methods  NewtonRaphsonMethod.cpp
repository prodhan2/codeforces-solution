#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson
{
private:
    double tolerence = 0.0001;
    double function(double x)
    {
        return pow(x, 3) + pow(x, 2) - 1;
    }
    double derivative(double x)
    {
        return 3 * pow(x, 2) + 2 * x;
    }

public:
    double root, new_root;
    void solve()
    {
        srand(time(0));
        while (1)
        {
            root = rand() % 10;
            if (derivative(root) != 0)
            {
                break;
            }
        }
        int k = 1;
        while (1)
        {
            printf("Iteration %2d root =  %9f\n", k++, root);
            if (function(root) == 0.0)
            {
                break;
            }
            new_root = root - function(root) / derivative(root);
            if (abs(root - new_root) < tolerence)
            {
                break;
            }
            root = new_root;
            if (derivative(root) == 0)
            {
                root++;
            }
        }
        printf("Iteration %2d root = %9f\n", k++, new_root);
        cout << "\nThe root is " << new_root << " (correct upto 3 decimal palces) " << endl
             << endl;
    }
};

int main()
{
    NewtonRaphson n = NewtonRaphson();
    n.solve();
    return 0;
}
