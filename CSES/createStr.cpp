#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

string s;
vector<int> countChar (26);
vector<string> perms;

void permRec(const string& current = "")
{
	if (current.size() == s.size())
	{
		perms.emplace_back(current);
	}

	for (int i {0}; i < 26; ++i)
	{
		if (countChar[i] > 0)
		{
			--countChar[i];
			permRec(current + static_cast<char>('a' + i));
			++countChar[i];
		}
	}
}

int main()
{
	cin >> s;
	for (char& c : s)
	{
		++countChar[c - 'a'];
	}

	permRec();

    cout << perms.size() << '\n';

	for (const auto& x : perms)
	{
		cout << x << '\n';
	}
	return 0;
}
