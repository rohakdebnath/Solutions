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

void solve()
{
    int N; cin >> N;
    string s; cin >> s;
    VI a;
    per(i, N - 1, 0){
        if (a.empty() or (s[i] >= s[a.back()])){
            a.push_back(i);
        }
    }
    reverse(all(a));
    int j = 0;
    while (j < a.size() and s[a[0]] == s[a[j]]) ++j;
    int ans = a.size() - j;

    rep(i, 0, a.size() - 1 - i){
        swap(s[a[i]], s[a[a.size() - 1 - i]]);
    }

    if (!is_sorted(all(s))){
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
