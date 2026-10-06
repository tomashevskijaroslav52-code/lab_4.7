#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double xp, xk, dx, eps;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    
    cout << fixed;
    cout << "---------------------------------------------" << endl;
    cout << "|" << setw(7) << "x"
        << "|" << setw(10) << "sin(x)/x"
        << "|" << setw(12) << "S"
        << "|" << setw(5) << "n"
        << "|" << endl;
    cout << "---------------------------------------------" << endl;

    double x = xp;

   
    while (x <= xk + eps / 10.0) {
        int n = 0;
        double a = 1.0; 
        double S = a;   
    
        do {
            n++;
            double R = -x * x / (2.0 * n * (2.0 * n + 1.0)); 
            a *= R;
            S += a;
        } while (abs(a) >= eps);
        
        double f_exact = (abs(x) < 1e-12) ? 1.0 : sin(x) / x;

        
        cout << "|" << setw(7) << setprecision(2) << x
            << "|" << setw(10) << setprecision(5) << f_exact
            << "|" << setw(12) << setprecision(5) << S
            << "|" << setw(5) << n
            << "|" << endl;

        x += dx;
    }

    cout << "---------------------------------------------" << endl;

    return 0;
}
