#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class Vector
{
public:
    float a, b;

    Vector(float _a, float _b)
    {
        a = _a;
        b = _b;
    }

    Vector operator+(Vector &v2) const
    {
        return Vector(a + v2.a, b + v2.b);
    }

    Vector operator-(Vector &v2) const
    {
        return Vector(a - v2.a, b - v2.b);
    }

    Vector operator*(Vector &v2) const
    {
        return Vector(a * v2.a, b * v2.b);
    }

    Vector operator/(Vector &v2) const
    {
        return Vector(a / v2.a, b / v2.b);
    }
};

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    float a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    Vector A(a1, b1), B(a2, b2);
    Vector C(0, 0);

    // Output
    C = A + B;
    cout << C.a << " " << C.b << endl;

    C = A - B;
    cout << C.a << " " << C.b << endl;

    C = A * B;
    cout << C.a << " " << C.b << endl;

    C = A / B;
    cout << C.a << " " << C.b << endl;


}