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
    vector<pair<int, int>> A (N); 
    map<int, multiset<int>> mm;
    rep(i, 0, N) {
        cin >> A[i].second;
        A[i].first = A[i].second >> 2;
        mm[A[i].first].insert(A[i].second);
    } 
    vector<int> srt;
    rep(i, 0, N){
        int t = A[i].first;
        auto u = mm[t].begin();
        srt.push_back(*u);
        mm[t].erase(u);
    }
    rep(i, 0, N) cout << srt[i] << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
