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
    int n, k; cin >> n >> k;
    VI A (n);
    int l = 1, r = n;
    rep(i, 0, k){
        for(int j = i; j < n; j += k){
            if (i & 1){
                A[j] = r--;
            } else {
                A[j] = l++;
            }
        }
    }
    rep(i, 0, n){
        cout << A[i] <<  " \n"[i == n - 1];
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
