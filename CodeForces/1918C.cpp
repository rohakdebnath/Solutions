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
    i64 a, b, r; cin >> a >> b >> r;
    if (a > b) swap(a, b);
    bool firstswitch = true;
    i64 ans = 0;
    per(i, 60, 0){
        if ((((a >> i) & 1) ^ ((b >> i) & 1)) == 1 and firstswitch){
            firstswitch = false;
        } else if (((b >> i) & 1) == 1 and (ans + (1LL << i)) <= r and ((a >> i) & 1) == 0) {
            ans += (1LL << i);
        }
    }
    cout << (b^ans) - (a^ans) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
