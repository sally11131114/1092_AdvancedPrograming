#include<iostream>
#include<vector>
using namespace std;

int main(){
    int c, i, count=1;
    cin >> c;
    while(c--){
        int n, m;
        string s;
        cin >> n >> m;
        vector<int> b[n];
        int w[n]={0};
        for(i=0;i<n;i++)
            cin >> w[i];
        
        for(i=0;i<m;i++){
            int x, y;
            cin >> x >> y;
            b[x].push_back(y);
        }

        int sum=0, tmp=0, cnt, cnt_id;
        while(1){
            if(b[tmp].size()==0)
                break;
            cnt=w[b[tmp][0]];
            for(i=0;i<b[tmp].size();i++){
                if(cnt<=w[b[tmp][i]]){
                    cnt=w[b[tmp][i]];
                    cnt_id=b[tmp][i];
                }
            }

            tmp=cnt_id;
            sum+=cnt;
        }
        cout << "Case " << count++ << ": " << sum << " " << tmp << endl;
    }
}