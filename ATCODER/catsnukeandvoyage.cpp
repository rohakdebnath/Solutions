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
    int N, M; cin >> N >> M;
    vector<bool> fromone (200001);
    vector<bool> ton (200001);
    rep(0, M)
    {
        int a, b; cin >> a >> b;
        if (a == 1) fromone[b] = true;
        if (b == N) ton[a] = true;
    }
    rep(2, 200001)
    {
        if (fromone[i] and ton[i])
        {
            cout << "POSSIBLE\n";
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
