#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int N; 
vector<vector<pair<int, int>>> tmn;

bool check(int b){
    bool srv = true;
    bool doublebreak = false;
    rep(i, 0, N){
        if ((b >> i) & 1){
            for (auto[u, v]: tmn[i]){
                int actual = (b >> (u - 1)) & 1;
                int supposed = v;
                if (actual ^ supposed){
                    srv = false;
                    doublebreak = true;
                    break;
                } 
            }
        }
        if (doublebreak) break;
    }
    return srv;
}

int main()
{
    UNSYNC
    cin >> N;
    tmn.resize(N);
    rep(i, 0, N){
        int A; cin >> A;
        rep(j, 0, A){
            int x, y; cin >> x >> y;
            tmn[i].push_back({x, y});
        }
    }
    int maxpop = 0;
    rep(i, 0, (1 << N)){
        if (check(i)) maxpop = max(maxpop, __builtin_popcount(i));
    }
    cout << maxpop << '\n';
    return 0;
}
