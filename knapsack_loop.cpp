//bottom_up approach
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int weight[n];
    int val[n];
    for(int i=0; i<n; i++)
    {
        cin>>weight[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>val[i];
    }
    int w;
    cin>>w;
    int dp[n][w];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(weight[i-1]<=j)
            {
                dp[i][j] = max(val[i-1]+ dp[i-1][j-weight[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}