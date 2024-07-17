#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int A, B, C; cin >> A >> B >> C;
    int n = A % B;
    VI modus (B + 1);
    int ini = n;
    while (true)
    {
        if (!modus[n]) modus[n] = 1;
        else break;
        n = (n + ini) % B; 
    }
    bool hunted = false;
    rep(0, B + 1)
    {
        if (modus[i] and i == C)
        {
            hunted = true;
            break;
        }
    }
    cout << (hunted? "YES\n" : "NO\n");
    return 0;
}
