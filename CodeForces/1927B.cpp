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

VI freq (26);
int firstalphawithfreq(int f){
    int ans = -1;
    rep(i, 0, 26){
        if (freq[i] == f){
            ans = i;
            ++freq[i];
            break;
        }
    }
    return ans;
}

void solve()
{
    int N; cin >> N;
    VI A (N); cin >> A;
    freq = VI (26, 0);
    rep(i, 0, N){
        int x = firstalphawithfreq(A[i]);
        cout << char(x + 'a');
    }
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
