#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int N; cin >> N;
    string S; cin >> S;
    vector<int> blackonleft (N); blackonleft[0] = S[0] == '#';
    rep(i, 1, N) blackonleft[i] = blackonleft[i - 1] + (S[i] == '#'); 
    vector<int> whiteonright (N); whiteonright[N - 1] = S[N - 1] == '.';
    per(i, N - 2, 0) whiteonright[i] = whiteonright[i + 1] + (S[i] == '.');

    int ans = min(whiteonright[0], blackonleft[N - 1]);
    rep(i, 0, N - 1) ans = min(ans, whiteonright[i + 1] + blackonleft[i]);

    cout << ans << '\n'; 
    return 0;
}
