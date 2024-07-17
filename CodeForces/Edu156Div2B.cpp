//shouldve used a struct for this im stupid

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

#include <iostream>
#include <cmath>

double distance(int& Lx, int& Ly, int& Mx, int& My)
{
    return hypot(Lx - Mx, Ly - My);
}

void solve()
{
    int Ox = 0;
    int Oy = 0;
    int Px, Py, Ax, Ay, Bx, By;
    cin >> Px >> Py >> Ax >> Ay >> Bx >> By;
    double BP = distance(Bx, By, Px, Py);
    double BO = distance(Bx, By, Ox, Oy);
    double AP = distance(Ax, Ay, Px, Py);
    double AO = distance(Ax, Ay, Ox, Oy);
    double R = distance(Ax, Ay, Bx, By)/2;
    double ans1 = max(BO, BP);
    double ans2 = max(AO, AP);
    double ans3 = max({R, AO, BP});
    double ans4 = max({R, AP, BO});
    
    cout << min({ans1, ans2, ans3, ans4}) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;

    cout << fixed << setprecision(10);
    while(T--)
    {
        solve();
    }

    return 0;
}
