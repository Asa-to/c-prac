#define _USE_MATH_DEFINES
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

struct Point{ double x, y;};

void solve(int i, Point a, Point b){
    if(i == 0) return;
    Point s, u, t;
    s.x = a.x + (b.x - a.x) / 3;
    s.y = a.y + (b.y - a.y) / 3;
    t.x = a.x + (b.x - a.x) / 3 * 2;
    t.y = a.y + (b.y - a.y) / 3 * 2;
    double rad = 60.0 / 180 * M_PI;
    u.x = (t.x - s.x) * cos(rad) - (t.y - s.y) * sin(rad) + s.x;
    u.y = (t.x - s.x) * sin(rad) + (t.y - s.y) * cos(rad) + s.y;
    solve(i - 1, a, s);
    cout << fixed;
    cout << setprecision(8) << s.x << " " << s.y << endl;
    solve(i - 1, s, u);
    cout << setprecision(8) << u.x << " " << u.y << endl;
    solve(i - 1, u, t);
    cout << setprecision(8) << t.x << " " << t.y << endl;
    solve(i - 1, t, b);
}

int main(void){
    int i; cin >> i;
    Point a, b;
    a.x = 0.0;
    a.y = 0.0;
    b.x = 100.0;
    b.y = 0.0;
    cout << fixed; 
    cout << setprecision(8) << a.x << " " << a.y << endl;
    solve(i, a, b);
    cout << setprecision(8) << b.x << " " << b.y ;
    return 0;
}