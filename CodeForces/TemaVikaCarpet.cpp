#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> carpet (n);

    for (int i {0}; i < n; ++i)
    {
        cin >> carpet[i];
    }

    vector<bool> flag (4, false);

    for (int i {0}; i < m; ++i)
    {
        for (int j {0}; j < n; ++j)
        {
            if (carpet[j][i] == 'v' and !flag[0])
            {
                flag[0] = true;
                break;
            }
            else if (carpet[j][i] == 'i' and !flag[1] and flag[0])
            {
                flag[1] = true;
                break;
            }
            else if (carpet[j][i] == 'k' and !flag[2] and flag[1] and flag[0])
            {
                flag[2] = true;
                break;
            }
            else if (carpet[j][i] == 'a' and !flag[3] and flag[2] and flag[1] and flag[0])
            {
                flag[3] = true;
                break;
            }
        }
    }

    if (flag[0] and flag[1] and flag[2] and flag[3]) cout << "YES\n";
    else cout << "NO\n";

}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}
