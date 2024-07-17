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
    string sa, sb, sc; cin >> sa >> sb >> sc;
    int topa = 1, topb = 0, topc = 0;
    char disc = sa[0];
    while (true)
    {
        if (disc == 'a')
        {
            if (topa < sa.size())
            {
                disc = sa[topa];
                ++topa;
            }
            else
            {
                cout << "A\n";
                return 0;
            }
        }
        else if (disc == 'b')
        {
            if (topb < sb.size())
            {
                disc = sb[topb];
                ++topb;
            }
            else
            {
                cout << "B\n";
                return 0;
            }
        }
        else if (disc == 'c')
        {
            if (topc < sc.size())
            {
                disc = sc[topc];
                ++topc;
            }
            else
            {
                cout << "C\n";
                return 0;
            }
        }
    }
    
    return 0;
}
