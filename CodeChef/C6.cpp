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
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

void solve()
{
    int X; cin >> X;
    int s1 = 0, s2 = 0;
    int turn = 1;
    int turn2 = 1;
    int ans = 1;
    per(i, 31, 0){
        if ((X >> i) & 1 and turn){
            s1 += (1 << i);
            turn = 0;
        } else if ((X >> i) & 1){
            if (turn2){
                s2 += (1 << i);
                turn2 = 0;
            }
        } else if ((X >> i & 1) == 0 and !turn2){
            ans *= 2;
        }

    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
