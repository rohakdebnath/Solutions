#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 N; cin >> N;
	vector<i64> A(N);
	i64 res = 0;
	for (i64 i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(all(A));
	if (N % 2 == 0) {
		for (i64 i = 0; i < N - 1; i++) {
			res += min((N - i - 1) * 2, (i + 1) * 2) * (A[i + 1] - A[i]);
		}
		res -= A[N / 2] - A[(N / 2) - 1];
	} else {
		for (i64 i = 0; i < N - 1; i++) {
			res += min((N - i - 1) * 2, (i + 1) * 2) * (A[i + 1] - A[i]);
		}
		res -= min(A[N / 2] - A[(N / 2) - 1], A[(N / 2) + 1] - A[(N / 2)]);
	}
	cout << res << endl;
}
