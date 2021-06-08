#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int check[1000005];
    int ans[1000005];
    memset(check, 0, sizeof(check));
    for(int i=2; i<=1000000; i++){
        for(int k=2*i;k<=1000000;k+=i){
            if(check[i]==0){
                check[k]=1;
            }
        }
    }
    int count=0, sum;
    ans[1]=0;
    for(int i=2;i<=1000000;i++){
        sum=0;
        int temp=i;
        if(check[i]==0){
            while(temp!=0){
                sum+=temp%10;
                temp/=10;
            }
            if(check[sum]==0)
                count++;
        }
        ans[i]=count;
    }
    
    int n, A, B;
    cin >> n;
    while(n--){
        scanf("%d %d", &A, &B);
        cout << ans[B]-ans[A-1] << endl;
    }
}


