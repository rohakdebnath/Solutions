//Interactive problem: 1)Keep everyhting same but use cout << flush, 2)You will have to input the response
#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 0, r = 1000001;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        cout << flush << mid << '\n';
        string response; cin >> response;
        if (response == "<")
            r = mid;
        else
            l = mid;
    }

    cout << flush << "! " << l << '\n';
}
