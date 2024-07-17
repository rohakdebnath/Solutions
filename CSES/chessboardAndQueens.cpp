#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

const int dim {8};
vector<vector<bool>> blocked (dim, vector<bool> (dim));
vector<bool> rowStatus (dim);
vector<bool> diag1 (2 * dim - 1);
vector<bool> diag2 (2 * dim - 1);
int validPos {0};

void queenRec(int c = 0)
{
    if (c == dim)
    {
        ++validPos;
        return;
    }
    for (int r {0}; r < dim; ++r)
    {
        bool rowAvailable = !rowStatus[r];
        bool diagAvailable = !diag1[c + r] and !diag2[r - c + dim - 1];
        if (rowAvailable and diagAvailable and !blocked[r][c])
        {
            rowStatus[r] = true;
            diag1[c + r] = true;
            diag2[r - c + dim - 1] = true;

            queenRec(c + 1);

            rowStatus[r] = false;
            diag1[c + r] = false;
            diag2[r - c + dim - 1] = false;
        }
    }
}

int main()
{
    for (int i {0}; i < dim; ++i)
    {
        string s;
        cin >> s;

        for (int j {0}; j < dim; ++j)
        {
            if (s[j] == '*') blocked[i][j] = true;
        }
    }

    queenRec();

    cout << validPos << '\n';

    return 0;
}
