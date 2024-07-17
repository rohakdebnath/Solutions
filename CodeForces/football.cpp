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
    int N; cin >> N;
    map<string, int> goals;
    rep(i, 0, N){
        string s; cin >> s;
        ++goals[s];
    }
    int maxg = 0;
    string s = "";
    for(auto [u, v]: goals){
        if (v > maxg){
            maxg = v;
            s = u;
        }
    }
    cout << s << '\n';
    return 0;
}
