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
    bitset<33> bin (N);
    vector<int> s (33);
    rep(i, 0, 33) s[i] = bin[i];
    rep(i, 0, int(s.size())){
        int j = i;
        while (s[j] == 1) ++j;
        if (j > i + 1){
            s[j] = 1;
            rep(k, i, j){
                if (k == i) s[k] = -1;
                else {
                    s[k] = 0;
                }
            }
            i = j - 1;
        }
    }
    int sz = 0;
    rep(i, 0, 33) if (s[i] != 0) sz = i + 1;
    cout << sz << '\n';
    rep(i, 0, sz){
        cout << s[i] << " \n"[i == sz - 1];
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
