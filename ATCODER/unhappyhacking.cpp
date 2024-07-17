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
    string s; cin >> s;
    deque<char> final;
    int B = 0;
    transform(s.rbegin(), s.rend(), front_inserter(final), 
    [&B] (char c)
    {
        if (c == 'B') 
        {
            ++B;
            return '\0';
        }
        else if (!B and c != 'B') return c;
        else 
        {
            --B;
            return '\0';
        }
    });
    for (char c: final) if (c != '\0') cout << c;
    cout << '\n';
    return 0;
}
