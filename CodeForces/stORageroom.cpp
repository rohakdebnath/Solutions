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
    VI A (N, (1 << 30) - 1);
    VVI M (N, VI (N));
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            cin >> M[i][j];
            if (i != j)
            {
                A[i] &= M[i][j];
                A[j] &= M[i][j]; 
            }
        }
    }
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            if (i != j and (A[i] | A[j]) != M[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for(int i: A) cout << i << ' ';
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
