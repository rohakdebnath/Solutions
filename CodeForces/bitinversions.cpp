#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()

string s;
int m;
set<int> dif;
priority_queue<int> ret;
int cnt[200005];

void ad(int x) {
	cnt[x]++;
	ret.push(x);
}
void modify(int x) {
	if (x == 0 || x == sz(s)) return;
	auto it = dif.find(x);
	if (it != end(dif)) {
		int a = *prev(it), b = *next(it);
		dif.erase(it);
		cnt[x - a]--, cnt[b - x]--;
		ad(b - a);
	} else {
		it = dif.insert(x).first;
		int a = *prev(it), b = *next(it);
		cnt[b - a]--, ad(x - a), ad(b - x);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> m;
	dif.insert(0);
	dif.insert(sz(s));
	for (int i = 0; i < sz(s) - 1; ++i) {
		if (s[i] != s[i + 1]) dif.insert(i + 1);
	}
	for (auto it = dif.begin(); next(it) != dif.end(); it++) {
		ad(*next(it) - *it);
	}
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		modify(x - 1);
		modify(x);
		while (!cnt[ret.top()]) ret.pop();
		// pop elements that should no longer be present in priority queue
		cout << ret.top() << " ";
	}
}
