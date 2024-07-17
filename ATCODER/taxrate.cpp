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
    int pretax = double(N)/1.08;
    bool hunted = false;
    int i;
    for (i = pretax - 1; i <= pretax + 1; ++i)
    {
        if (int(i * 1.08) == N)
        {
            hunted = true;
            break;
        }
    }
    if (hunted) cout << i << '\n';
    else cout << ":(\n";
    return 0;
}
