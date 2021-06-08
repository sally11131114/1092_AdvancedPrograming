#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int N, i, k, cnt=1;
    string s, tmp;

    cin >> N;
    while(N--){
        cin >> s;

        string tmp=s;
        int count=0;
        int len=s.length();
        cout << "Case " << cnt << ": ";
        if(len==1){
            cout << "S" << endl;
            cnt++;
            continue;
        }
        while(1){
            if(i==s.length()){
                if(count%2==0)
                    cout << "T" << endl;
                else
                    cout << "S" << endl;
                cnt++;
                break;
            }
            if(s.length()==1){
                if(count%2==1)
                    cout << "T" << endl;
                else
                    cout << "S" << endl;
                cnt++;
                break;
            }
            for(i=0;i<tmp.length();i++){
                int sum=0;
                tmp.erase(tmp.begin()+i);
                for(k=0;k<tmp.length();k++)
                    sum+=tmp[k];
                if(sum%3==0){
                    count++;
                    s=tmp;
                    break;
                }
                tmp=s;
            }
        }
    }
}