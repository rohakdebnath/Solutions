#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    int x = 0, y = 0, t = 0;
	while (N--)
	{
		int x2, y2, t2;
		cin >> t2 >> x2 >> y2 ;

		int xd = x2 - x,yd=y2-y,td=t2-t;

		if (((std::abs(xd) + std::abs(yd)) & 1) != (td & 1)) {
			cout << "No\n"; return 0;
		}
		if ((std::abs(xd) + std::abs(yd)) > td) {
			cout << "No\n"; return 0;
		}

		x = x2; y = y2; t = t2;
	}
	cout << "Yes\n";

	return 0;
    return 0;
}
