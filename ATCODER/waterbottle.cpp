#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    double a, b, x; cin >> a >> b >> x;
    cout << setprecision(9);
    if (x <= a*a*b/2)
    {
        cout << atan(a*b*b/(2*x))*180/(M_PI) << '\n';
    }
    else
    {
        x = a*a*b - x;
        cout << atan(2*x/(a*a*a))*180/(M_PI) << '\n';
    }
    return 0;
}
