#include <iostream>
#include <map>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

int main()
{
    map<int, int> assorray;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int n; 
        cin >> n;
        if (n == 0)
        {
            int k, v;
            cin >> k >> v;
            assorray[k] = v;
        }
        else
        {
            int  k;
            cin >> k;
            cout << assorray[k] << '\n';
        }
    }
    return 0;
}
