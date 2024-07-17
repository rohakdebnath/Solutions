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
    VVI matrix (3, VI (3));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j) cin >> matrix[i][j];
    }
    int N; cin >> N;
    VI B (101);
    rep(0, N)
    {
        int n; cin >> n;
        ++B[n];
    }

    VVI matrixBool (3, VI (3));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (B[matrix[i][j]]) matrixBool[i][j] = 1;
        }
    }

    bool hunted = false;

    rep(0, 3) if (accumulate(all(matrixBool[i]), 0) == 3) {hunted = true; break;}

    for(int i = 0; i < 3; ++i)
    {
        int sum = 0;
        for (int j = 0; j < 3; ++j) sum += matrixBool[j][i];
        if (sum == 3)
        {
            hunted = true;
            break;
        }
    }

    int sumd1 = 0;
    int sumd2 = 0;
    for (int i = 0; i < 3; ++i)
    {
        sumd1 += matrixBool[i][i];
        sumd2 += matrixBool[i][2 - i];
    }

    if (sumd1 == 3 or sumd2 == 3) hunted = true;

    cout << (hunted? "Yes\n" : "No\n");
    
    return 0;
}
