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
    string S; cin >> S;
    reverse(all(S));
    int l = 0;
    while (l < S.size()){
        if (S.substr(l, 5) == "esare"){
            l += 5;
        } else if (S.substr(l, 5) == "maerd"){
            l += 5;
        } else if (S.substr(l, 7) == "remaerd"){
            l += 7;
        } else if (S.substr(l, 6) == "resare"){
            l += 6;
        } else {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
