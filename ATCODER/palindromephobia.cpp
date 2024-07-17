#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    string s; cin >> s;
    VI alpha (26);
    for (char c: s) ++alpha[c - 'a'];
    int a = alpha[0];
    int b = alpha[1];
    int c = alpha[2];
    int sz = (a + b + c)/3;
    if ((a >= sz and a <= sz + 1) and (b >= sz and b <= sz + 1) and (c >= sz and c <= sz + 1)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
