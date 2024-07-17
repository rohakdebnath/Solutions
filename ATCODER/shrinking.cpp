#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main() //heavily adapted from tourist and benq, didnt expect a goofy ahh simulation task
{
    UNSYNC
    string s; cin >> s;
    int mini = INT32_MAX;
    for (char c = 'a'; c <= 'z'; ++c) //simulate the shrinking, trying to make the string shrink to a single type char string for each lowercase alphabet
    {
        string t = s;
        for(int i = 0;; ++i)
        {
            if (t.empty()) break; //if string becomes empty, then we have chosen it to shrink to a single char type string of a char which was not present originally, hence ignore and move next
            if (t == string(t.size(), c)) //obv the iterations last till the chars all become of the type we chose
            {
                mini = min(mini, i); //want the no. of iterations it takes to achieve same chars to be minimum amongst all lowercase chars
                break;
            }
            string tmod = "";
            for(int j = 0; j < t.size() - 1; ++j)
            {
                if (t[j] == c or t[j + 1] == c) tmod += c;
                else tmod += t[j];
            }
            t = tmod;
        }
    }
    cout << mini << '\n';
    return 0;
}
