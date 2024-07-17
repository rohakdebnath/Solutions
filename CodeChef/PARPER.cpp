#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

int factorial(int n)
{
    int ini = 1;
    for (int i {2}; i <= n; ++i) ini *= i;

    return ini;
}

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> vec (N, 0);
    for (int i {0}; i < N; ++i)
    {
        int n ;
        cin >> n;
        if (n % 2 == 1) vec[i] = 1;
    }
    int odds = count(vec.begin(), vec.end(), 1);
    int evens = count(vec.begin(), vec.end(), 0);
    int D = abs (odds - evens);

    if (K == 0 and D == N) cout << factorial(evens);
    else if (K == 1 and N % 2 == 1 and D == 1) cout << factorial(N/2)*factorial((N+1)/2);
    else if (K == 1 and N % 2 == 0 and D == 0) cout << factorial(N/2)*factorial(N/2);
    else cout << 0;

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
