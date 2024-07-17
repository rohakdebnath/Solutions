#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int S, N; cin >> S >> N;
    vector<vector<pair<int, int>>> data (S + 1);
    rep(i, 0, N){
        int V, W, K; cin >> V >> W >> K;
        data[W].push_back({V, K});
    }
    vector<int> dp (2001);
    rep(i, 0, S + 1){
        sort(all(data[i]), [](const pair<int, int>& a, const pair<int, int>& b) {return a.first > b.first;});
        int id = 0;
        for (int j = 0; j * i <= S; ++j){
            if (id >= data[i].size()) break;
            per(k, S, i){
                dp[k] = max(dp[k], dp[k - i] + data[i][id].first);
            }
            --data[i][id].second;
            if (data[i][id].second == 0) ++id;
        }
    }
    cout << dp[S] << '\n';
    return 0;
}
