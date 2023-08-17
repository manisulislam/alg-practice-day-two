#include<bits/stdc++.h>
using namespace std;
//global n and m
int n,m;

//range
const int N=1e3+5;

//adjacency string list
vector<string>g;

//visited
int visited[N][N];

//validity check
bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}
//dfs implementation
void dfs(int i,int j){
    if(!isValid(i,j)) return;
    if(visited[i][j]) return;
    if(g[i][j]=='#') return;

    visited[i][j]=true;


    dfs(i, j-1);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i+1, j);
}
int main(){
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        g.push_back(x);
    }

    //counter
    int ct=0;
    //access every node 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visited[i][j]) continue;
            if(g[i][j]=='#') continue;
            dfs(i,j);
            ct++;

        }
    }

    //print room
    cout<<ct<<endl;
    return 0;
}