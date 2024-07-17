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

int main()
{
    UNSYNC
    string s; cin >> s;
    int popcount = count(all(s), '1');
    int pow = (s.size())/2;
    if (popcount > 1 and (s.size() & 1) == 1) ++pow;
    cout << pow << '\n';
    return 0;
}
