#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int n; cin >> n;
    VI V (n); rep(i, 0, n) cin >> V[i];
    unordered_map<int, int> freq1;
    unordered_map<int, int> freq2;

    for(int i = 0; i < n; i += 2) ++freq1[V[i]];
    for(int i = 1; i < n; i += 2) ++freq2[V[i]];

    int hfe1 = 0;
    int hf1 = 0;
    for(auto [u, v]: freq1)
    {
        if (v > hf1)
        {
            hfe1 = u;
            hf1 = v;
        }
    }

    int hfe2 = 0;
    int hf2 = 0;
    for(auto [u, v]: freq2)
    {
        if (v > hf2)
        {
            hfe2 = u;
            hf2 = v;
        }
    }
    
    int shf1 = 0;
    for(auto [u, v]: freq1)
    {
        if (v > shf1 and u != hfe1)
        {
            shf1 = v;
        }
    }
    int shf2 = 0;
    for(auto [u, v]: freq2)
    {
        if (v > shf2 and u != hfe2)
        {
            shf2 = v;
        }
    }
    int ans = hf1 + hf2;
    if (hfe1 == hfe2) ans = max(hf1 + shf2, hf2 + shf1);

    cout << n - ans << '\n';
    return 0;
}
