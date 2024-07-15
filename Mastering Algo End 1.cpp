#include <bits/stdc++.h>
using namespace std;

// int c=0;
int mod = 1e9+7;

void solve(vector<int>& arr, int target, int n) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= target; j++) {
            dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
        }
    }

    cout << dp[target] << endl;
}

int main() {

    int n,x;
    cin>>n>>x;

    vector<int> nums;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
// 	c=0;
    vector<int> set;
    solve(nums,x,n);
// 	cout<<c<<endl;
}
