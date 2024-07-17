#include <bits/stdc++.h>

using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 1048576
#define PI 3.1415926535
int grid[3][3] = {};
int main() {
	REP(i, 3) {
		REP(q, 3) {
			cin >> grid[i][q];
		}
	}
	for (int i = 0;i < 3;++i) {
		for (int q = 1;q < 3;++q) {
			if (grid[i][q] - grid[i][q - 1] != grid[0][q] - grid[0][q - 1]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	for (int i = 0;i < 3;++i) {
		for (int q = 1;q < 3;++q) {
			if (grid[q][i] - grid[q - 1][i] != grid[q][0] - grid[q-1][0]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
