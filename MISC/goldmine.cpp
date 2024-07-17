#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    int x, z, N; cin >> x >> z >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    int k; cin >> k;

    sort(all(A));
    int j = 0;

    int c = 0, money = 0;

    rep(i, 0, k){
        while (money >= A[j] and (k - i)*z > A[j] and j < N){
            money -= A[j++];
            ++c;
        }
        money += x + c*z;
    }
    cout << money << '\n';
    return 0;
}
