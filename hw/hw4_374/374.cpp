#include<iostream>
using namespace std;

long long f(long long B, long long P, long long M){
    if(P==0)
        return 1;
    else if(P==1)
        return B%M;
    else{
        long long ans = f(B, P/2, M);
        if(P%2)
            return ans*ans*B%M;
        else
            return ans*ans%M;
    }
}

int main(){
    long long B, P, M;
    while(cin >> B >> P >> M)
        cout << f(B, P, M) << endl;

}