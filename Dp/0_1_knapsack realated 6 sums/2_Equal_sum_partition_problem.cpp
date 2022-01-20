#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
 
using namespace std;
 
typedef long long ll;
ll MOD = 1e9+7;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
// Given a non-empty array nums containing only positive integers, find if the array can be 
// partitioned into two subsets such that the sum of elements in both subsets is equal.
// leetcode question 416
// e.g.  4                                 n=4
//       1 5 11 5                          arr
// ans: true


bool subsetSum(int sum1 , vector<int>&arr){
    int n =arr.size();
    vector<vector<bool>>dp(n+1 , vector<bool>(sum1 + 1));

    for( int i=0 ;i< n+1; i++){
        for( int j=0 ;j< sum1+1 ; j++){
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
        }
    }

    // always  start i and j with 1
    for( int i=1 ;i< n+1 ; i++){
        for( int  j=1 ;j<sum1+1 ;j++){
            if(arr[i-1] <=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    
    return dp[n][sum1];

}


bool equalSumPartition(vector<int>&arr){
    int sum=0;
    for( int i=0 ;i<arr.size() ; i++){
        sum+=arr[i];
    }

    if((sum & 1) != 0){
        return 0;
    }

    return subsetSum(sum/2 , arr);
}

int main()
{
    fast_cin();
    int n; 
    cin>>n;
    vector<int>arr(n);
    
    for (int i=0 ;i< n; i++){
        cin>>arr[i];
    }

    cout<<equalSumPartition(arr);

    return 0;
}