#include<bits/stdc++.h>
using namespace std;

//global n and m;
int n, m;

//typedef pair
typedef pair<int,int>pii;

//range
const int N=1e3+5;

//vector adjacency matrix
vector<string>g;

//visited bool array
bool visited[N][N];

//level track
int level [N][N];

//parent track
pii parent[N][N];

//direction track
vector<pii>direct={{0,-1},{0,1},{-1,0},{1,0}};

//validity check
bool isValid(int i, int j){
    return ( i>=0 && i<n && j>=0 && j<m);
}

//bfs implementation
void bfs(int si,int sj){
    queue<pii>q;
    q.push({si,sj});
    visited[si][sj]=true;
    level[si][sj]=0;
    while(!q.empty()){
        pii uPair= q.front();
        int i=uPair.first;
        int j=uPair.second;
        q.pop();
        for(auto d: direct){
            int ni=i+d.first;
            int nj=j+d.second;
            if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]!='x'){
                q.push({ni,nj});
                visited[ni][nj]=true;
                level[ni][nj]=level[i][j]+1;
                parent[ni][nj]={i,j};
            }
        }

    }
}
int main(){
    int si,sj, di,dj;
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;

        for(int j=0; j<m; j++){
            if(x[j]=='s') {
                si=i,sj=j;
            }
            if(x[j]=='e'){
                di=i,dj=j;
            }
        }
        g.push_back(x);
    }

    //bfs invoke
    bfs(si,sj);

    // if(visited[di][dj]==0){
    //     cout<<"-1"<<endl;
    //     return 0;
    // }

    if(level[di][di]!=0){
       cout<<level[di][dj]<<endl;
    }
    else{
        cout<<"-1"<<endl;
        return 0;
        
    }

    //track path
    vector<pii>path;
    pii curr={di,dj};
    while(!(curr.first==si && curr.second==sj)){
        path.push_back(curr);
        curr=parent[curr.first][curr.second];
    }
    path.push_back({si,sj});
    reverse(path.begin(), path.end());
    //print yes or no also no path print -1
    for(int i=1; i<path.size(); i++){
        //path[i-1]---->>>path[i]
        if(path[i-1].first==path[i].first){
            if(path[i-1].second==path[i].second-1){
                cout<<"R";
            }
            else{
                cout<<"L";
            }
        }
        else{
            if(path[i-1].first==path[i].first-1){
                cout<<"D";
            }
            else{
                cout<<"U";
            }

        }
    }
    

    return 0;
}