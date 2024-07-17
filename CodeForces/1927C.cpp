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
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    VI A (n), B (m);
    rep(i, 0, n) cin >> A[i];
    rep(i, 0, m) cin >> B[i];
    sort(all(A)); sort(all(B));
    int aco = 0, bco = 0;
    rep(i, 1, k + 1){
        bool found = false;
        if (binary_search(all(A), i)){
            ++aco;
            found = true;
        } 
        if (binary_search(all(B), i)){
            ++bco;
            found = true;
        }
        if (!found) {
            cout << "NO\n";
            return;
        }

    }
    if (aco >= k/2 and bco >= k/2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
