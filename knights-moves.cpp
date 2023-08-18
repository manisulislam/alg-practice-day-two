#include<bits/stdc++.h>
using namespace std;

//typedef pair
typedef pair<int ,int> pii;

//range
const int N=1e3+5;
//level
int level[N][N];

//bool visited
bool visited[N][N];

//direction
vector<pii>direct={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-2}};

//validity check
bool isValid(int i, int j){
    return (i>=0 && i<8 && j>=0 && j<8);
}

//bfs implementation
void bfs(int si, int sj){
    queue<pii>q;
    q.push({si,sj});
    level[si][sj]=0;
    visited[si][sj]=true;
    while(!q.empty()){
        pii uPair = q.front();
        int i=uPair.first;
        int j=uPair.second;
        q.pop();
        for(auto d:direct){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj)&&!visited[ni][nj]){
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
            }
        }
    }

}

//reset level and visited
void reset(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            level[i][j]=0;
            visited[i][j]=false;
        }
    }
}
int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int si,sj,di,dj;
        string x, y;
        cin>>x>>y;
        //source coordinator
        si=x[0]-'a';
        sj=x[1]-'1';

        //distance coordinator
        di=y[0]-'a';
        dj=y[1]-'1';

        //cout<<"("<<si<<","<<sj<<")"<<" ";
        //cout<<"("<<di<<","<<dj<<")"<<endl;
        bfs(si,sj);
        cout<<level[di][dj]<<endl;
        reset();
    
        
    }
    return 0;
}