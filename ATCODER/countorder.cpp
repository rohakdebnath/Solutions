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
    int N; cin >> N;
    VI P (N); rep(0, N) cin >> P[i];
    VI Q (N); rep(0, N) cin >> Q[i];

    VI S (N);
    iota(all(S), 1);

    int a = 0, b = 0;
    bool va = true, vb = true;
    do
    {
        if (S == P and va) va = false;
        if (va) ++a;
        if (S == Q and vb) vb = false;
        if (vb) ++b;
        if (!va and !vb) break;
    } while (next_permutation(all(S)));
    cout << abs(a - b) << '\n';
    
    return 0;
}
