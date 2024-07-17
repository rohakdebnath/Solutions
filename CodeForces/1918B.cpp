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
    int N; cin >> N;
    VI A (N), B (N); cin >> A >> B;
    VI P (N); iota(all(P), 0);
    sort(all(P), [&] (int i, int j) {return A[i] < A[j];});
    VI Px (N); 
    rep(i, 0, N) cout << i + 1 << ' ';
    cout << '\n';
    for (int i : P) cout << B[i] << ' ';
    cout << '\n';

}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
