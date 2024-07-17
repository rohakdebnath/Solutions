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
    i64 N, M; cin >> N >> M;
    string S, T; cin >> S >> T;
    i64 g = gcd(N, M);
    bool survive = true;
    rep(0, g)
    {
        if (S[i*N/g] != T[i*M/g])
        {
            survive = false;
            break;
        }
    }
    cout << (survive? (N*M/g) : -1) << '\n';
    return 0;
}
