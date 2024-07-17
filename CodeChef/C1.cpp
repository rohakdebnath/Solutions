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

void solve()
{
    int N; cin >> N;
    string S; cin >> S;
    int zeroc = 0;
    rep(i, 0, N)
    {
        if (S[i] == '0') ++zeroc, cout << "NO\n";
        else if (S[i] == '1' and !zeroc and i < N - 1) cout << "IDK\n";
        else if (zeroc) cout << "NO\n";
        else if (!zeroc and i == N - 1 and S[i] == '1') cout << "YES\n";
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
