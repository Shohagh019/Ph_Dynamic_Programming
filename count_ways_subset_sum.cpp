// count how many subset can  making a given sum from an given array
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int count_subset_sum(int n, int s, int a[])
{
    if(n==0)
    {
        if(s==0) return 1;
        else return 0;
    }
    if(dp[n][s]!=-1) return dp[n][s];
    if(a[n-1]<=s)
    {
        int op1 = count_subset_sum(n-1, s-a[n-1], a);
        int op2 = count_subset_sum(n-1,s,a);
        return dp[n][s]= op1+op2;
    }
    else
    {
        return dp[n][s]= count_subset_sum(n-1,s,a);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<count_subset_sum(n,s,a)<<endl;
    return 0;
}