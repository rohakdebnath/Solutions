#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define aint(x) x.begin(), x.end()
#define MAX static_cast<int>(1e5)

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> vec (N, 0);
    for (int i {0}; i < N/2; ++i)
    {
        vec[i] = 1;
    }
    for (int i {N/2}; i < N; ++i)
    {
        vec[i] = 2;
    }

    if ((N/2 % 2 == 0 and K % 2 != 0) or (N/2 % 2 != 0 and K % 2 == 0) or (K < 3*N/2) or (K > N * MAX - N / 2)) cout << -1;
    else 
    {
        int rem = K - 3*N/2;
        for (int i {N - 1}; i >= 0; --i)
        {
            if (rem >= MAX) 
            {
                if (i >= N / 2)
                {
                    rem -= MAX - 2;
                    vec[i] = MAX;
                }
                else
                {
                    rem-= MAX - 2;
                    vec[i] = MAX - 1;
                }
            }
            else
            {
                vec[i] += rem;
                break;
            }
        }
        for (int i : vec) cout << i << ' ';
    }
    cout << '\n';
}

int main()
{
    Unsync
    int tests;
    cin >> tests;

    while (tests--)
    {
        solve();
    }

    return 0;
}
