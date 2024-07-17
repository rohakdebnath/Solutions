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
    for (int i = 0; i <= X/100; ++i)
    {
        int rem = X - 100*i;
        if (0 <= rem and rem <= 5*i)
        {
            cout << "1\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}
