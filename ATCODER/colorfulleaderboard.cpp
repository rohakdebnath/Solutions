#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define mll map<ll,ll>
#define sll set<ll>
#define fo(i,n) for(i=0;i<n;i++)
#define MOD 1000000007
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    ll n,i,j,k,t,a[10]={0};

    cin>>n;

    fo(i,n)
    {
        cin>>j;
        if(j>=1 && j<=399)
            a[0]=1;
        if(j>=400 && j<=799)
            a[1]=1;
        if(j>=800 && j<=1199)
            a[2]=1;
        if(j>=1200 && j<=1599)
            a[3]=1;
        if(j>=1600 && j<=1999)
            a[4]=1;
        if(j>=2000 && j<=2399)
            a[5]=1;
        if(j>=2400 && j<=2799)
            a[6]=1;
        if(j>=2800 && j<=3199)
            a[7]=1;
        if(j>=3200)
            a[8]++;
    }

    ll sum=0;
    fo(i,8)
        sum+=a[i];

    if(sum==0)
    {
        sum++;
        a[8]--;
    }
    cout<<sum<<" "<<sum+a[8];

    return 0;
}
