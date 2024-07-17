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
    int N, M; cin >> N >> M;
    vector<int> counts (100001);
    vector<pair<int, int>> syear (M);
    rep(i, 0, M){
        int P, Y; cin >> P >> Y;
        syear[i] = {Y, P};
    }

    vector<int> id (M); iota(all(id), 0);
    sort(all(id), [&] (int i, int j) {return syear[i].first < syear[j].first;});
    vector<int> pid (M);
    rep(i, 0, M) pid[id[i]] = i;
    
    sort(all(syear));
    vector<int> P (M);
    vector<int> X (M);
    rep(i, 0, M){
        ++counts[syear[i].second];
        P[i] = syear[i].second;
        X[i] = counts[syear[i].second];
    }
    rep(i, 0, M){
        cout << setw(6) << setfill('0') << P[pid[i]];
        cout << setw(6) << setfill('0') << X[pid[i]] << '\n';
    }
    return 0;
}
