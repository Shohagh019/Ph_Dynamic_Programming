//top-down approach
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapsack(int n, int w, int weight[], int value[])
{
    if(n==0 || w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(weight[n-1]<=w)
    {
        int op1 = value[n-1]+ knapsack(n-1, w-weight[n-1], weight, value);
        int op2 = knapsack(n-1,w, weight, value);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        return dp[n][w] = knapsack(n-1, w, weight, value);
    }
}
int main()
{
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>value[i];
    }
    int w;
    cin>>w;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            dp[i][j] = -1;
        }
    }
    int result = knapsack(n, w, weight, value);
    cout<<result<<endl;
    return 0;
}