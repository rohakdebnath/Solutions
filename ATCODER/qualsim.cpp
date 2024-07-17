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
    int N, A, B; cin >> N >> A >> B;
    string S; cin >> S;
    int overseaspass = 0;
    int totpass = 0;
    for (int i = 0; i < N; ++i)
    {
        if (S[i] == 'b') ++overseaspass;
        if (S[i] == 'a' and totpass < A + B)
        {
            ++totpass;
            cout << "Yes\n";
        }
        else if (S[i] == 'b' and totpass < A + B and overseaspass <= B)
        {
            ++totpass;
            cout << "Yes\n";
        }
        else cout << "No\n";
    }


    return 0;
}
