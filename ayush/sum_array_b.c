#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int T = 0;
    int N = 0;
    cin >> T;
    
    while(T--){
        cin >> N;
        vector<int> arr(N);
        vector<int> dp(N);
        
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        dp[0] = arr[0];
        if(N > 1){
            dp[1] = max(arr[1], dp[0]);
        }
        
        for(int i=2; i<N; i++){
            //dp[i-2] + arr[i] : Incase we are considering element
            //dp[i-1] :,Incase we are skipping element
            //dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
            dp[i] = max(dp[i-2] + arr[i], max(dp[i-1], arr[i]));
        }
        
        cout << dp[N-1] << endl;
        
    }

    return 0;
}