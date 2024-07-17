#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

double f(double x){
    return 1/((x - 0.5)*(x - 0.5) + 1);
}

int main()
{
    UNSYNC
    double l = -1e-5, r = 10 + 1e-5; //qs is find max in 0 to two with 1e-5 accuracy, obs ans should be as close to f at 1/2 as possuble
    while(r - l > 1e-5){
        double m = l + (r - l)/2;
        if (f(m) >= f(m - 1e-5)){
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
    return 0;
}
