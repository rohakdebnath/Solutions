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
    int a, b; cin >> a >> b;
    int countneg = 0;
    int countzero = 0;
    for (int i = a; i <= b; ++i)
    {
        if (i < 0) ++countneg;
        else if (i == 0) ++countzero;
    }

    if (countzero)
    {
        cout << "Zero\n";
        return 0;
    }
    else if (countneg % 2 == 0)
    {
        cout << "Positive\n";
        return 0;
    }
    cout << "Negative\n";
    return 0;
}
