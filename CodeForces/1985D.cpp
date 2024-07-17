#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, M; cin >> N >> M;
    vector<vector<int>> grid (N, vector<int> (M));
    rep(i, 0, N) rep(j, 0, M){
        char c; cin >> c;
        grid[i][j] = c == '#';
    } 

    int h = 0, k = 0;
    int hm = 0, km = 0;
    rep(i, 0, N){
        int m = 0;
        rep(j, 0, M){
            m += grid[i][j];
        }
        if (m > hm){
            hm = m;
            h = i + 1;
        }
    }
    rep(i, 0, M){
        int m = 0;
        rep(j, 0, N){
            m += grid[j][i];
        }
        if (m > km){
            km = m;
            k = i + 1;
        }
    }
    cout << h << ' ' << k << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
