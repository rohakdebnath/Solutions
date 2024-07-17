#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

int main()
{
    UNSYNC
    int n;
    cin >> n;
    vector<int> weights (2*n);

    rep1(2*n){cin >> weights[i];}

    sort(all(weights));

    int minstability {INT32_MAX};

    for (int i {0}; i < 2*n; ++i)
    {
        for (int j {i + 1}; j < 2*n; ++j)
        {
            vector<int> poppedWeights {weights};
            poppedWeights.erase(poppedWeights.begin() + j);
            poppedWeights.erase(poppedWeights.begin() + i);

            int instab {0};
            for (int p {1}; p < 2*n - 2; p += 2)
            {
                instab += (poppedWeights[p] - poppedWeights[p - 1]);
            }

            minstability = min(minstability, instab);
        }
    }

    cout << minstability << '\n';

    return 0;
}
