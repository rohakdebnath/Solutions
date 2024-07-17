#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N; //each map inside the vector will have at most log(max(A[i])) (approx only 30) different elements because the gcd will only decrease if we expand the subarray from initally the maximum element only in the subarray, and since it can differ lowest by factor 2, the different values are log(A[i]) max 
    vector<map<int, int>> maxlen (N); //maxlen[i][j] = maxlength of subarray ending at i with gcd = j; 
    vector<int> A (N); 
    rep(i, 0, N){
        cin >> A[i];
        maxlen[i][A[i]] = 1; //you can always pick a single element as the subarray
    }

    rep(i, 1, N){
        for (auto [gc, size] : maxlen[i - 1]){ //our plan is to calculate the different values of gcds we can get if we end at a particular index, note that obviously any subarray ending at i must go thorugh i - 1 (except when only i is taken but we already counted that), hence calculating the new gcd with the different values of gcd of i - 1 is sufficient, we will also store the maximum length obtained for each gcd obtained for each i.
            int newgc = gcd(gc, A[i]);
            maxlen[i][newgc] = max(maxlen[i][newgc], size + 1); //this statement also makes it obvious that each index's map has a gcd maps to size of the subarray (= i + 1 in 0 based i)
        }
    }

    vector<int> ans (N + 1);
    rep(i, 0, N){
        for (auto [gcd, size]: maxlen[i]){
            ans[size] = max(ans[size], gcd);
        }
    }

    rep(i, 1, N + 1){
        cout << ans[i] << " \n"[i == N];
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
