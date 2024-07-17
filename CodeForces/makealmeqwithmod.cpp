#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int maxpowtwo(i64 x){
    i64 l = -1, r = 57;
    while (r - l > 1){
        int m = l + (r - l)/2;
        i64 powt = 1;
        rep(i, 0, m){
            powt *= 2;
        }
        if (x % powt == 0){
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve()
{
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    
    i64 prod = 1;
    rep(i, 1, 57){
        prod *= 2;
        set<i64> distinct;
        rep(j, 0, N){
            distinct.insert(A[j] % (prod));
        }
        if (distinct.size() == 2){
            cout << prod << '\n';
            return;
        }
    }
    cout << prod << '\n';
    return;
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
