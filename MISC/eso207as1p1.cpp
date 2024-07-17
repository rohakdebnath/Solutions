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

void solve()
{
    int N, K; cin >> N >> K;
    string s; cin >> s; s += '0';
    stack<char> lastunremoved; lastunremoved.push(s[0]);
    rep(i, 1, N + 1){
        while (!lastunremoved.empty() and lastunremoved.top() > s[i] and i < N + 1 and K){
            lastunremoved.pop();
            --K;
        }
        lastunremoved.push(s[i]);
    }
    string fin;
    while (!lastunremoved.empty()){
        fin += lastunremoved.top();
        lastunremoved.pop();
    }
    reverse(all(fin));

    int i = 0;
    while(fin[i] == '0' and i < fin.size()) ++i;
    if (i == fin.size()){
        cout << "0\n";
        return;
    }
    for(; i < fin.size() - 1; ++i) cout << fin[i];
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
