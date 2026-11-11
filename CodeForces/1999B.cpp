#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int al, ar, bl, br; cin >> al >> ar >> bl >> br;
    if (al > ar) swap(al, ar);
    if (bl > br) swap(bl, br);

    if (al < bl) cout << "0\n";
    else if (al == bl) {
        if (bl == br and ar > br) cout << "4\n";
        else if (ar > br) {
            cout << "2\n";
        } else {
            cout << "0\n";
        }
    } else if (al > bl and al < br) {
        if (ar < br) cout << "0\n";
        else {
            cout << "2\n";
        }
    } else {
        cout << "4\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
