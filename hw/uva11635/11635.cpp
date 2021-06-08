#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
#include<iomanip>
#include<queue>
using namespace std;
#define max 1000000
int cnt;
struct node{
    int x, y, d;
    node(int a, int b, int c):x(a), y(b), d(c){};
};
int h2h[101][101];

int main(){
    cnt=0;
    int city, nh, ne, i, k;
    cin >> city ;
    while(city){
        cnt++;
        cin >> nh;
        vector<int> hotel;
        vector<struct node> node_edge;
        hotel.push_back(1);
        hotel.push_back(city);
        for(i=0;i<nh;i++){
            int temp;
            cin >> temp;
            if(temp!=1&&temp!=city)
                hotel.push_back(temp);
        }
        nh=hotel.size();
        cin >> ne;
        for(i=0;i<ne;i++){
            int x, y, d;
            cin >> x >> y >> d;
            struct node a(x, y, d), b(y, x, d);
            node_edge.push_back(a);
            node_edge.push_back(b);
        }

        /* Bellman-Ford */
        int dis[city+1];
        int copy[city+1];
        int check=1;        //check if algo finish
        for(i=0;i<101;i++){
            for(k=0;k<101;k++)
                h2h[i][k]=max;
            h2h[i][i]=0;
        }
        
        for(i=0;i<nh;i++){
            for(k=0;k<city+1;k++)
                dis[k]=max;
            dis[hotel[i]]=0;
            while(check){
                check=0;
                for(k=0;k<city+1;k++)
                    copy[k]=dis[k];
                for(k=0;k<node_edge.size();k++){
                    if(dis[node_edge[k].y]>dis[node_edge[k].x]+node_edge[k].d){
                        dis[node_edge[k].y]=dis[node_edge[k].x]+node_edge[k].d;
                    }
                }
                for(k=0;k<city+1;k++){
                    if(copy[k]!=dis[k])
                        check=1;
                }
            }
            for(k=0;k<nh;k++){
                if(dis[hotel[k]]<=600){
                    h2h[i][k]=h2h[k][i]=1;
                }
            }
            check=1;
        }
        /* BFS */
        queue<int> q;
        q.push(0);
        int h_num[nh];
        for(i=0;i<nh;i++)
            h_num[i]=max;
        h_num[0]=0;    
        while(!q.empty()){
            int tmp=q.front();
            q.pop();
            for(i=0;i<nh;i++){
                if(h_num[i]>h_num[tmp]+h2h[tmp][i]){
                    h_num[i]=h_num[tmp]+h2h[tmp][i];
                    q.push(i);
                }
            }
        }
        if(h_num[1]!=max)
            cout << h_num[1]-1 << endl;
        else
            cout << "-1" << endl;
        
        cin >> city;
    }
}