#include<iostream>
#include<cmath>
#include<cstring>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<long long> s;
    long long A, B;
    long long end = sqrt(pow(10, 12));
    int  check[end+5];
    memset(check, 0, sizeof(check));
    for(int i=2; i<=end; i++){
        for(int k=2*i;k<=end;k+=i){
            if(check[i]==0){
                check[k]=1;
            }
        }
    }
    long long temp=0;
    int x=2;
    for(int i=2;i<=end;i++){
        if(check[i]==0){
            while(temp<=pow(10, 12)){
                temp = pow(i, x++);
                s.insert(temp);
            }
        }
        temp=0;
        x=2;
    }

    while(n--){
        cin >> A >> B;
        int count=0;
        for(auto i=s.begin(); i!=s.end(); i++){
            if(*i>=A && *i <=B)
                count++;
        }
        cout << count << endl;
    }



}