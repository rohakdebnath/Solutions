#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
 
#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)
 
int main()
{   
    i64 n, t;
 
    cin >> n >> t;
 
    vector<i64> bookTime (n);
 
    rep1(n)
    {
        cin >> bookTime[i];
    }
    
    int min 
    i64 time {0};
    int noofbooksread {0};
    for (i64 timeforone : bookTime)
    {
        if (time <= t)
        {
            time += timeforone;
            if (time <= t)
            ++noofbooksread;
        }
        else break;
    }
 
    cout << noofbooksread << '\n';
    return 0;
}
