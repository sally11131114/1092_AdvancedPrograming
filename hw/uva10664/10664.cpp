#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    int i, k, n, temp, sum;
    char ch;
    cin>>noskipws;
    cin >> n;
    cin >> ch;
    while(n--){
        sum=0;
        vector<int> luggage;
        while(cin >> temp >> ch){
            luggage.push_back(temp);
            sum+=temp;
            if(ch == '\n')  
                break;
        }
        if(sum%2){
            cout << "NO" << endl;
            continue;
        }
        int check[sum];
        memset(check, 0, sizeof(check));
        check[0]=1;
        for(i=0;i<luggage.size()-1;i++){
            for(k=sum;k>=luggage[i];k--){
                if(check[k-luggage[i]]==1)
                    check[k]=1;
            }
        }
        if(check[sum/2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

}