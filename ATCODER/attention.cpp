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
    int N; cin >> N;
    string S; cin >> S;
    VI e (N), w (N);
    e[0] = S[0] == 'E';
    rep(i, 1, N)
    {
        e[i] = e[i - 1] + (S[i] == 'E');
    }
    w[N - 1] = S[N - 1] == 'W';
    per(i, N - 2, 0)
    {
        w[i] = w[i + 1] + (S[i] == 'W');
    }
    int mini = min(N - 1 - w[1], N - 1 - e[N - 2]);
    rep(i, 1, N - 1)
    {
        mini = min(mini, i - e[i - 1] + N - 1 - i - w[i + 1]);
    }
    cout << mini << '\n';
    return 0;
}
