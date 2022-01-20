#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
ll MOD = 1e9+7;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// here we have given a vector we have to find minimum subset sum difference
// basically s1 - s2 =minimum  where s1+s2 =sum of vector elements   find minimum
// e.g   4                                 n=4
//       1 6 11 1                          arr
//ans:   3


void subsetSum(vector<vector<bool>>&dp , vector<int>&arr , int n , int sum){

    for( int i=0 ;i< n+1; i++){
        for( int j=0 ;j< sum+1 ;j++){
            if(i==0) 
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
        }
    }

    for( int i=1 ;i< n+1; i++){
        for( int j=1;j< sum+1 ;j++){
            if(arr[i-1] <= j) 
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

}


int ans(vector<int>& arr , int  n, int sum ){
    vector<vector<bool>> dp(n+1 , vector<bool>(sum+1) );

    subsetSum(dp , arr ,n, sum);

    for( int i=sum/2 ; i>=0 ; i--){
        if(dp[n][i] == 1)
            return (sum-(2*i));
    }
    return -1;

}

int main()
{
    fast_cin();
    int  n ;
    cin>>n;
    vector<int>arr(n);
    for( int i=0 ;i<n ;i++){
        cin>>arr[i];
    }

    // here we find the range where s1 and s2 can lie i.e 0 to s1+s2 
    // then just apply subset sum over sum=s1+s2
    // check for sum/2 to 0 for last row of dp
    // first element where we find true it is s1 and s2=sum-s1
    // let's start 

    int sum=0 ;
    for( int i=0 ;i<n ;i++){
        sum+=arr[i];
    }

    cout<<ans(arr , n , sum );
    return 0;
}