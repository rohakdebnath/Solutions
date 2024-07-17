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
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    int one = 0;
    i64 sum = 0;
    rep(i, 0, N){
        sum += A[i];
        if (A[i] % 3 == 1) one = 1;
    }
    int rem = (sum % 3);
    if ((rem == 1 and one) or (rem == 2)){
        cout << "1\n";
    } else {
        if (rem == 0) cout << "0\n";
        else cout << "2\n";
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
