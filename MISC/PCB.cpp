#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const int MOD = 1e9 + 7;
void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    UNSYNC
    //setIO("pcb");
    int N; cin >> N;
    vector<int> A (N); 
    vector<int> B (N); 
    rep(i, 0, N){
        cin >> A[i] >> B[i];
    }
    vector<int> idx (N); iota(all(idx), 0);
    sort(all(idx), [&] (int i, int j) {return B[i] < B[j];});
    vector<int> sA (N);
    rep(i, 0, N) sA[i] = A[idx[i]];
    reverse(all(sA));
    vector<int> dp (N + 1, MOD); dp[0] = -MOD;
    rep(i, 0, N){
        int l = upper_bound(all(dp), sA[i]) - dp.begin();
        dp[l] = sA[i];
    }
    int ans = 0;
    rep(i, 1, N + 1){
        if (dp[i] < MOD) ans = i;
        else break;
    }
    cout << ans << '\n';
    return 0;
    
    return 0;
}
