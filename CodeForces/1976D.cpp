#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    string s; cin >> s;
    int bal = 0;
    map<int, int> M;
    i64 ans = 0;
    for (char c: s){
        bal += (c == '(' ? 1 : -1);
        ans += M[bal];
        ++M[bal];
        while (2 * (*M.begin()).first < bal) M.erase(M.begin()); // a bal which is greater than twice of some potential matches of an r (found in later iterations) will block this r from matching with any of the matches (l - 1) values since all of those matches occur before this current bal. This curr bal acts as those particular values of bal[i] st that bal[i] <= 2 * bal[l - 1] = 2 * bal[r] DOES not hold.
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
