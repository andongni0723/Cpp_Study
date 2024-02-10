#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

class Rectangle
{
public:
    double width;
    double length;

    double Area(double w, double l)
    {
        return w * l;
    }

    Rectangle()
    {
        width = 0;
        length = 0;
    }

    Rectangle(double w, double l)
    {
        width = w;
        length = l;
    }
};

class RectangleVolume : public Rectangle
{
public:
    double height;

    RectangleVolume()
    {
        width = 0;
        length = 0;
        height = 0;
    }
    RectangleVolume(double w, double l, double h)
    {
        width = w;
        length = l;
        height = h;
    }
    double Surface(double w, double l, double h)
    {
        return w * l * 2 + h * w * 2 + h * l * 2;
    }

    double Volume(double w, double l, double h)
    {
        return w * l * h;
    }

};

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    double h, w, l;
    cin >> h >> w >> l;

    RectangleVolume A(w, l, h);

    cout << A.Surface(A.width, A.length, A.height) << endl;
    cout << A.Volume(A.width, A.length, A.height) << endl;
    
}