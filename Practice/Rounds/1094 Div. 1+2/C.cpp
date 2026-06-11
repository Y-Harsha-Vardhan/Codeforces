#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5005;
int n, arr[MAXN], sortedArr[MAXN], dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--){
        cin >> n;
        for (int i=1; i<=n; i++) {cin >> arr[i]; sortedArr[i] = arr[i];}
        sort(sortedArr+1, sortedArr+n+1);
        int median = sortedArr[(n+1)/2];

        for (int i=1; i<=n; i++) {
            if (arr[i] < median) arr[i]=-1;
            else if (arr[i] == median) arr[i] = 0;
            else arr[i] =1;
        }
        
        for (int i=1; i<=n; i++) {
            dp[i]=0;
            int zeroCnt = (arr[i]==0);
            if (zeroCnt && (i==1 || dp[i-1]>0)) dp[i] = dp[i-1]+1;
            int sum = arr[i];

            for (int j=i-3; j>=0; j-=2) {
                zeroCnt += (arr[j+1] ==0);
                zeroCnt += (arr[j+2]==0);

                sum += arr[j+1];
                sum += arr[j+2];
                bool valSeg = (abs(sum)<zeroCnt);
                if (!valSeg) continue;
                if (j!= 0 && dp[j]==0) continue;

                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        cout << dp[n] << "\n";
    }  
}