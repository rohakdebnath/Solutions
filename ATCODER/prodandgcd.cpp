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
    i64 N, P; cin >> N >> P;
    unordered_map<i64, i64> freqMap;
    while (P % 2 == 0) 
    {
        freqMap[2]++;
        P /= 2;
    }
    for (i64 i = 3; i * i <= P; i += 2) 
    {
        while (P % i == 0) 
        {
            freqMap[i]++;
            P /= i;
        }
    }
    if (P > 2) freqMap[P]++;

    i64 maxG = 1;
    for(auto [u, v]: freqMap)
    {
        maxG *= pow(u, v/N);
    }
    cout << maxG << '\n';
    return 0;
}
