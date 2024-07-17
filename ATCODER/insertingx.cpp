#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    string s; cin >> s;
    int l = 0, r = s.size() - 1;
    int ans = 0;
    while (r > l){
        if (s[l] == s[r]) ++l, --r;
        else if (s[l] == 'x') ++l, ++ans;
        else if (s[r] == 'x') --r, ++ans;
        else {
            cout << "-1\n";
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
