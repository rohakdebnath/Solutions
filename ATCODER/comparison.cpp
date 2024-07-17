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
    string A, B; cin >> A >> B;
    if (A.size() > B.size())
    {
        cout << "GREATER\n";
        return 0;
    }
    else if (A.size() < B.size())
    {
        cout << "LESS\n";
        return 0;
    }
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] > B[i])
        {
            cout << "GREATER\n";
            return 0;
        }
        else if (A[i] < B[i])
        {
            cout << "LESS\n";
            return 0;
        }
    }
    cout << "EQUAL\n";
    return 0;
}
