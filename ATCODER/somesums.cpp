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
    int count = 0;
    for (int i = 1; i <= N; ++i)
    {
        int n = i;
        int sum = 0;
        while (n > 0)
        {
            sum += (n % 10);
            n /= 10;
        }
        if (sum >= A and sum <= B) count += i;
    }
    cout << count << '\n';
    return 0;
}
