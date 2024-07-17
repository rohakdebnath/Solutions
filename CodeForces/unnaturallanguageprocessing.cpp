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

void solve()
{
    int N; cin >> N;
    string S; cin >> S;
    vector<char> cons = {'b', 'c', 'd'};
    map<int, int> partition;
    string nu = "";
    for(char c: S){
        if (find(all(cons), c) != cons.end()) nu += 'C';
        else nu += 'V';
    }
    rep(i, 0, N - 2){
        if (nu.substr(i, 3) == "VCV") ++partition[i];
    }
    rep(i, 0, N - 1){
        if (nu.substr(i, 2) == "CC") ++partition[i];
    }

    rep(i, 0, N){
        cout << S[i];
        if (partition[i]) cout << '.';
    }
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
