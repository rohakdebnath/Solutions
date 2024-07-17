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
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) if (i & 1) A[i] *= -1;

    map<i64, int> freq;
    freq[0] = 0;
    i64 curr = 0;
    rep(i, 1, N + 1){
        curr += A[i - 1];
        if (freq.count(curr)){
            cout << "Yes\n";
            return;
        }
        freq[curr] = i;
    }
    cout << "No\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
