// #include <bits/stdc++.h>

// using namespace std;
// using i64 = long long;

// #define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
// #define sci(x) static_cast<i64>(x)
// #define all(x) x.begin(), x.end()
// #define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
// #define per(i, fin, x) for (i64 i = fin; i >= x; --i)
// #define VI vector<i64>
// #define VVI vector<vector<i64>>

// int main()
// {
//     UNSYNC
//     i64 N; cin >> N;
//     VI A (N); rep(i, 0, N) cin >> A[i];
//     VI pref (N); pref[0] = A[0];
//     rep(i, 1, N) pref[i] = pref[i - 1] + A[i];
//     i64 minpref = 0;
//     i64 maxsum = pref[0];
//     rep(i, 1, N)
//     {
//         minpref = min(minpref, pref[i - 1]);
//         maxsum = max(maxsum, pref[i] - minpref);
//     }
//     cout << maxsum << '\n';
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<long long> x(n);
	for (int i = 0; i < n; i++) { cin >> x[i]; }
	ll current_sum = x[0];
	ll max_subarray_sum = x[0];
	for (int i = 1; i < n; i++) {
		/*
		 * Continue the subarray sum or start a new
		 * subarray sum beginning at the current element.
		 */
		current_sum = max(current_sum + x[i], x[i]);
		max_subarray_sum = max(max_subarray_sum, current_sum);
	}
	cout << max_subarray_sum << endl;
}
