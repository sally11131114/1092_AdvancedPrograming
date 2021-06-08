#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int node, edge;
    cin >> node;
    while(node){
        cin >> edge;
        vector<int> b[200];
        int i, flag=1, tmp;
        
        for(i=0;i<edge;i++){
            int x, y;
            cin >> x >> y;
            b[x].push_back(y);
        }
        int n[200]={0};
        queue<int> q;
        q.push(0);
        n[0]=1;
        while(1){
            tmp=q.front();
            for(i=0;i<b[tmp].size();i++){
                if(n[b[tmp][i]]==0){
                    q.push(b[tmp][i]);
                    n[b[tmp][i]]=3-n[tmp];
                }
                if(n[b[tmp][i]]==n[tmp]){
                    flag=0;
                    break;
                }
            }
            q.pop();
            if(q.empty() || flag==0)
                break;
        }
        if(flag)
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
        
        cin >> node;
    }
    

}