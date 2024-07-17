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
    int N, L; cin >> N >> L;
    VI modflavours (N);
    VI flavours (N);
    rep(0, N) 
    {
        flavours[i] = L + i;
        modflavours[i] = abs(L + i);
    }

    int leastelepos = distance(modflavours.begin(), min_element(all(modflavours)));

    cout << accumulate(all(flavours), 0) - flavours[leastelepos] << '\n';

    return 0;
}
