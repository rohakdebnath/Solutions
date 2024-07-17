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
    int N, X; cin >> N >> X;

    int bounces = 1;
    int curr = 0;
    rep(0, N)
    {
        int a; cin >> a;
        curr += a;
        if (curr <= X) ++bounces;
        else break;
    }
    cout << bounces << '\n';
}
