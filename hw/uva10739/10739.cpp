#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
    int n, cnt=0;
    string input;
    cin >> n;
    while(n--){
        cin >> input;
        int len = input.length();
        int dp[len+5][len+5];
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<len;i++)
            dp[i][i]=0;
        for(int i=len-1;i>=0;i--){
            for(int k=i;k<len;k++){
                if(input[i]==input[k])
                    dp[i][k]=dp[i+1][k-1];
                else{
                    int a=dp[i+1][k-1];
                    int b=dp[i+1][k];
                    int c=dp[i][k-1];
                    int minm=min(a, b);
                    minm=min(minm, c);
                    dp[i][k]=minm+1;
                }
            }
        }
        cout << "Case " << ++cnt << ": " << dp[0][len-1] << endl;
    }
}