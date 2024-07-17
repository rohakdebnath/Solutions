#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    vector<string> grid (N);
    rep(i, 0, N) cin >> grid[i];

    rep(i, 1, N){
        if (count(all(grid[i]), '1') != count(all(grid[i - 1]), '1') and count(all(grid[i]), '1') and count(all(grid[i - 1]), '1')){
            cout << "TRIANGLE\n";
            return;
        }
    }
    cout << "SQUARE\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
