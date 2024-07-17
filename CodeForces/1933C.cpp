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
    int g = 0;
    vector<int> A (N); 
    rep(i, 0, N){
        cin >> A[i];
        g = gcd(A[i], g);
    }
    int cg = count(all(A), g);
    cout << (cg >= 2 ? "No\n" : "Yes\n");
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
