#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

struct node{
    int x, y;
    node(){};
    node(int x, int y): x(x), y(y){};
};
vector<node> v;
int main(){
    int R, C;
    int n;
    cin >> n;
    v.push_back(node(1, 0));
    v.push_back(node(0, 1));
    v.push_back(node(-1, 0));
    v.push_back(node(0, -1));
    while(n--){
        vector<node> fire;
        //initialization
        cin >> R >> C;
        int maze[R+5][C+5];
        int J[R+5][C+5];
        int F[R+5][C+5];
        struct node Jn;
        memset(maze, 0, sizeof(maze));
        memset(J, 0, sizeof(J));
        memset(F, 0, sizeof(F));
        for(int i=0;i<R;i++){
            for(int k=0;k<C;k++){
                char temp;
                cin >> temp;
                if(temp=='#') {
                    maze[i][k]=-1;
                    F[i][k]=-1;
                    J[i][k]=-1;
                }
                else if(temp=='J'){
                    Jn.x=i;
                    Jn.y=k;
                }
                else if(temp=='F'){
                    struct node Fn(i, k);
                    fire.push_back(Fn);
                }
                    
            }
        }
        //bfs_fire
        queue <struct node> fq;
        for(int i=0;i<fire.size();i++){
            F[fire[i].x][fire[i].y]=1;
            fq.push(fire[i]);
        }
        while(!fq.empty()){
            node temp = fq.front();
            fq.pop();
            for(int i=0;i<4;i++){
                int next_x = temp.x+v[i].x;
                int next_y = temp.y+v[i].y;
                if(next_x<0 || next_x >=R || next_y <0 || next_y>=C)
                    continue;
                if(F[next_x][next_y]==0 || F[next_x][next_y]>F[temp.x][temp.y]+1){
                    F[next_x][next_y]=F[temp.x][temp.y]+1;
                    node tmp(next_x, next_y);
                    fq.push(tmp);
                }
            }
        }

        //bfs_joe
        queue <struct node> jq;
        jq.push(Jn);
        J[Jn.x][Jn.y]=1;
        int ans=0;
        while(!jq.empty() && ans==0){
            node temp = jq.front();
            jq.pop();
            if(temp.x==R-1||temp.y==C-1||temp.x==0||temp.y==0){
                ans=1;
                break;
            }
            for(int i=0;i<4;i++){
                int next_x = temp.x+v[i].x;
                int next_y = temp.y+v[i].y;
                if(next_x<0 || next_x >=R || next_y <0 || next_y>=C)
                    continue;
                if(J[next_x][next_y]==0 && (J[temp.x][temp.y]+1<F[next_x][next_y] || F[next_x][next_y]==0)){
                    J[next_x][next_y]=J[temp.x][temp.y]+1;
                    if (next_x==R-1||next_y==C-1||next_x==0||next_y==0){
                        ans=J[temp.x][temp.y]+1;
                        break;
                    }
                    node tmp(next_x, next_y);
                    jq.push(tmp);
                }
            }
        }
        if (ans)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }  
}