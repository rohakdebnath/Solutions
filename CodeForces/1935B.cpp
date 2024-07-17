#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int SZ = 100001;
void solve()
{
    bitset<SZ> num;
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    rep(i, 0, N){
        int x = A[i];
        num[x] = 1;
    }
    int MEX = -1;
    rep(i, 0, SZ){
        if (!num[i]){
            MEX = i;
            break;
        }
    }
    int blocks = 0;
    int j = 1;
    bitset<SZ> numtillnow;
    vector<pair<int, int>> segs;
    int count = 0;
    rep(i, 0, N){
        if (blocks >= 2) break;
        if (!numtillnow[A[i]] and A[i] < MEX) ++count;
        numtillnow[A[i]] = 1;
        if (count == MEX){
            ++blocks;
            segs.push_back({j, i + 1});
            j = i + 2;
            numtillnow.reset();
            count = 0;
        }

    }
    if (blocks >= 2){
        cout << 2 << '\n';
        for (int i = 0; i < 1; ++i){
            auto [u, v] = segs[i];
            cout << u << ' ' << v << '\n';
        }
        cout << segs[1].first << ' ' << N << '\n';
    } else {
        cout << "-1\n";
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
