#include<iostream>
using namespace std;
#include<bits/stdc++.h> 

int minDistance(vector<int>&dist,vector<bool>&sptSet){
    int min_distance=INT_MAX,min_dist_vertex;
    int V=dist.size();
     for(int i=0;i<V;i++){
          if(!sptSet[i] && dist[i]<min_distance){
               min_distance=dist[i];
               min_dist_vertex=i;
          }
     }
     return min_dist_vertex;
}
 
int main(){ 
    vector<vector<int>>Network(10,vector<int>(10,0));
    Network = {
        {0,1,0,0,1,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,3,1,0,4,0},
        {0,0,0,0,5,0,0,1,0,1},
        {0,0,0,5,0,0,1,0,0,0},
        {0,0,3,0,0,0,0,0,0,1},
        {0,0,1,0,1,0,0,1,0,0},
        {0,0,0,1,0,0,1,0,0,0},
        {0,0,4,2,0,0,0,0,0,0},
        {0,0,0,1,0,1,0,0,0,0}
    };
    int V=10;
    int source=0;
    int destination=4;
    vector<int>dist(V,INT_MAX);
    vector<bool>sptSet(V,false);
    dist[source] = 0;
    for(int edge=0;edge<(V-1);edge++){
        int u = minDistance(dist,sptSet);
        sptSet[u]=true;
        if(u==source){
            cout<<u<<"(Source)->";
        }
        else if(u==destination){
            cout<<u<<"(Destination)"<<endl;
            break;
        }
        else cout<<u<<"->";
        for(int v=0;v<V;v++){
            if(Network[u][v] && !sptSet[v] && dist[u]!=INT_MAX && dist[v]>(dist[u]+Network[u][v]))dist[v]=dist[u]+Network[u][v];
        }
    }
    cout<<dist[destination]<<endl;
    return 0;
}
