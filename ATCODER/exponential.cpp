#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int X; cin >> X;
    if (X == 1)
    {
        cout << "1\n";
        return 0;
    }
    int maxi = 1;
    for (int b = 2; b*b <= X; ++b)
    {
        for (int p = 2; pow(b, p) <= X; ++p)
        {
            maxi = max(maxi, sci(pow(b, p)));
        }
    }
    cout << maxi << '\n';
    return 0;
}
