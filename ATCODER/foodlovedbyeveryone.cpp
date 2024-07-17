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
    int N, M; cin >> N >> M;
    int temp = N;
    VI likes (M);
    while(temp--)
    {
        int k; cin >> k;
        while(k--)
        {
            int a; cin >> a;
            ++likes[a - 1];
        }
    }
    int likeall = 0;
    for (int l : likes)
    {
        if (l == N) ++likeall;
    }
    cout << likeall << '\n';
    return 0;
}
