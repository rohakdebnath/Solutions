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
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    string counter = "";
    int j = 0;
    bool srv = true;
    while(n--){
        int count = 0;
        vector<int> aonce (k);
        while (j < m and count < k){
            count += !aonce[s[j] - 'a'];
            aonce[s[j] - 'a'] = 1;
            ++j;
        }
        if (count < k){
            srv = false;
            rep(i, 0, k){
                if (!aonce[i]){
                    counter += 'a' + i;
                    break;
                }
            }
        } else {
            counter += s[j - 1];
        }
    }
    if (srv) cout << "YES\n";
    else {
        cout << "NO\n" << counter << '\n';
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
