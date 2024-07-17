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
    int N; cin >> N;
    unordered_map<string, int> data;
    stack<string> words;
    string s; cin >> s;
    words.push(s);
    ++data[s];
    rep(1, N)
    {
        string w; cin >> w;
        if (w[0] != words.top().back())
        {
            cout << "No\n";
            return 0;
        }
        words.push(w);
        ++data[w];
        if (data[w] > 1)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
