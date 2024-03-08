//given a difference. count the subsetsum which are maintain this difference
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    // if there are two subsets there sum = a+b;
    //difference = a-b
    int dif;
    cin>>dif;
    int s= (sum+dif)/2;
    int dp[n+1][s+1];
    dp[0][0]=1;
    for(int i=1; i<=n; i++)
    {
        dp[0][i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s]<<endl;
    return 0;
}