#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

VI nums (4);
bool foundAns = false;
void opeRec(VI ops = {})
{
    if (!foundAns)
    {
        if (ops.size() == 3) 
        {
            int ans = nums[0];
            rep(0, 3)
            {
                ans += (ops[i] == 1? nums[i + 1] : -nums[i + 1]);
            }
            if (ans == 7)
            {
                cout << nums[0] << (ops[0] == 1 ? "+": "-") << nums[1] << (ops[1] == 1 ? "+": "-") << nums[2] << (ops[2] == 1 ? "+": "-") << nums[3] << "=7" << '\n';
                foundAns = true;
            }
            return;
        }
        ops.emplace_back(0);
        opeRec(ops);
        ops.pop_back();
        ops.emplace_back(1);
        opeRec(ops);
    }
    else return;
}

int main()
{
    UNSYNC
    string s; cin >> s;
    rep(0, 4) nums[i] = s[i] - '0';
    opeRec();
    
    return 0;
}
