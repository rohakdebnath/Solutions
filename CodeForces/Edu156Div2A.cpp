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
    int n;
    cin >> n;

    vector<int> tooLow {1, 2, 3, 4, 5, 6, 9};
    if (find(all(tooLow), n) != tooLow.end()) 
    {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES\n";

    if (n % 3 == 0)
    {
        cout << 1 << ' ' << 4 << ' ' << n - 5 << '\n';
    }
    else 
    {
        cout << 1 << ' ' << 2 << ' ' << n - 3 << '\n';
    }

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
