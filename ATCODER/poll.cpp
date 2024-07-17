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
    int maxKey = 0;
    map<string, int> votedata;
    rep(0, N)
    {
        string S; cin >> S;
        ++votedata[S];
        maxKey = max(maxKey, votedata[S]);
    }
    for (auto [u, v] : votedata)
    {
        if (v == maxKey) cout << u << '\n';
    }
    
    return 0;
}
