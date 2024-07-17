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
    int N, K; cin >> N >> K;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    int g = accumulate(all(A), 0, [&] (int s, int a) {return gcd(s, a);});
    if (K % g == 0 and K <= *max_element(all(A))) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
    return 0;
}

//Chadtag female gaze:
//wide shoulder
//thin waist
//low body fat
//abs
//thicker neck
