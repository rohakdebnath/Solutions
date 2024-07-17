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
    string S; cin >> S;
    int K = 0;
    int ptr = 0;
    int lastSize = 1;
    while(ptr < S.size())
    {
        if (S[ptr] == S[ptr + 1] and lastSize == 1)
        {
            ++K;
            ptr += 2;
            lastSize = 2;
        }
        else
        {
            ++K;
            ++ptr;
            lastSize = 1;
        }
    }
    cout << K << '\n';
    return 0;
}
