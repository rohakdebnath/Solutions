#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    int K;
    multiset<int> ans;
    rep(i, 0, N){
        cin >> K;
        auto it = ans.upper_bound(K);
        if (it == ans.end()) ans.insert(K);
        else{
            ans.erase(it);
            ans.insert(K);
        }
    }
    cout << ans.size() << '\n';
    return 0;
}
