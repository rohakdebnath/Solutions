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
    int N, Y; cin >> N >> Y;
    Y /= 1000;
    int B = Y - N;
    int x = -1, y = -1, z = -1;
    for (int i = 0; i <= B/9; ++i)
    {
        for (int j = 0; j <= B/4; ++j)
        {
            if (9*i + 4*j == B) 
            {
                x = i;
                y = j;
                z = N - x - y;
                if (z >= 0) break;
            }
        }
    }
    if (x < 0 or y < 0 or z < 0) cout << "-1 -1 -1\n";
    else
    {
        cout << x << ' ' << y << ' ' << N - x - y << '\n';
    }
    return 0;
}
