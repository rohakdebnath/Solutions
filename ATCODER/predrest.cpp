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
    int N, K, R, S, P; cin >> N >> K >> R >> S >> P;
    string T; cin >> T;
    string o = "";
    int pts = 0;
    rep(i, 0, K)
    {
        if (T[i] == 'r') o += 'p', pts += P;
        else if (T[i] == 'p') o += 's', pts += S;
        else o += 'r', pts += R;
    }
    rep(i, K, N)
    {
        if (T[i] == 'r')
        {
            if (o[i - K] == 'p') o += 'a';
            else pts += P, o += 'p';
        }
        else if (T[i] == 'p')
        {
            if (o[i - K] == 's') o += 'b';
            else pts += S, o += 's';
        }
        else
        {
            if (o[i - K] == 'r') o += 'c';
            else pts += R, o += 'r';
        }
    }
    cout << pts << '\n';
    return 0;
}
