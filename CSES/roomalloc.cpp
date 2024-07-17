#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

//The main idea is that we allocate an empty room to a customer, then we check if the next customer can be given "the room which will be departed earliest" or not (if not then no other room which has been allocated till now will be empty since they all depart later). We can use a min heap structure to store this information efficiently.
//We will be storing the information of the departure time of the current resident of a room along what room has been allocated in a minHeap pririty queue, doing so we can just check the top element for whether the departure time is less than the current customer's arrival time. If so we replace that room with the current customer otherwise we just put the customer in a new room and add the departure time and room number to the minHeap.

int main()
{
    UNSYNC
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> arrdepind (n); //store arrival departure and index for later use

    rep(i, 0, n){
        cin >> arrdepind[i].first.first >> arrdepind[i].first.second;
        arrdepind[i].second = i;
    }
    sort(all(arrdepind)); //sort according to arrival time, kind of a greedy allocation of room, makes intuitive sense ig
    vector<int> ans (n); //with the help of the indices stored in arrdepind we can allocate the room number associated with each person
    priority_queue<pair<int, int>> ed; //this will be a minHeap and also store the allocated room with it, so that when a customer who can possibly replace the current customer of the room, will be allocated this room only
    
    int maxroom = 0, lastroom = 0; //maximum number of room is the maximum size the minHeap reaches at any point in time
    rep(i, 0, n){
        if (ed.empty()){
            ++lastroom;
            ed.push({-arrdepind[i].first.second, lastroom}); //Using a minus for the implementation of a min heap
            ans[arrdepind[i].second] = lastroom;
        }
        else{
            pair<int, int> mini = ed.top();
            if (-mini.first < arrdepind[i].first.first){
                ed.pop();
                ed.push({-arrdepind[i].first.second, mini.second});
                ans[arrdepind[i].second] = mini.second;
            }
            else {
                ++lastroom;
                ed.push({-arrdepind[i].first.second, lastroom});
                ans[arrdepind[i].second] = lastroom;
            }
        }
        maxroom = max(maxroom, sci(ed.size()));
    }
    cout << maxroom << '\n';
    rep(i, 0, n) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
