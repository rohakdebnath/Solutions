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
    int x, n; cin >> x >> n;
    set<int> lights {0, x};
    multiset<int> gaps {x};

    rep(i, 0, n){
        int p; cin >> p;
        auto it = lights.upper_bound(p);
        auto it2 = it; --it2;
        gaps.erase(gaps.find(*it - *it2));
        gaps.insert(*it - p);
        gaps.insert(p - *it2);
        lights.insert(p);
        auto maxgap = gaps.end(); --maxgap;
        cout << *maxgap << ' ';
    }
    cout << '\n';
    return 0;
}
