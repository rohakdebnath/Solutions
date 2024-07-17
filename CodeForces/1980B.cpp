#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, f, k; cin >> N >> f >> k;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    int fav = A[f - 1];
    sort(all(A), greater<int> ());
    if (k == N){
        cout << "YES\n";
        return;
    } 
    if (k == 0){
        cout << "NO\n";
        return;
    }
    if (A[k] == fav and A[k - 1] == fav) cout << "MAYBE\n";
    else if (A[k - 1] == fav and A[k] != fav) cout << "YES\n";
    else if (A[k - 1] > fav) cout << "NO\n";
    else if (A[k - 1] < fav) cout << "YES\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
