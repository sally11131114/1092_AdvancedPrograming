#include <iostream>
#include <climits>
using namespace std;

int main() {
    int l, n;
    while (cin >> l) {
        if (!l) break;
        cin >> n;
        int dp[52][52] = {0};
        int cut[n+2];
        cut[0] = 0; 
        cut[n+1] = l;
        for (int i = 1; i < n+1; i++) 
            cin >> cut[i];

        int r, i, j, k, temp;
        for (r = 2; r <= n+1; r++) {
            for (i = 0; i < n+1; i++) {
                j = i + r;

                if (j > n+1) break;

                dp[i][j] = INT_MAX;
                for (k = i+1; k < j; k++) {
                    temp = dp[i][k] + dp[k][j] + cut[j] - cut[i];
                    if (temp < dp[i][j]) 
                        dp[i][j] = temp;
                }
                
            }
        }
        cout << "The minimum cutting is " << dp[0][n+1] <<  "." << endl;
    }
}