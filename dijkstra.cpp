#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int find_min(vector<int> distance , vector<bool> visited , int N){
    int smol = INT_MAX; 
    for(int i=0;i<N;i++){
        if(!visited[i] && distance[i]<smol){
            smol = i;
        }
    }
    return smol;
}
int main(){
    cout<<"Enter number of nodes : ";
    int N ;
    cin>> N;
    cout<<"Use -1 if there is no link between nodes"<<endl;
    int graph[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i<j){
                cout<<"Enter the weight between nodes "<<i<<" and "<<j<<" :";
                int temp;
                cin>>temp;
                graph[i][j] = temp ; 
                graph[j][i] = temp ; 
            }
            else if(i==j){
                graph[i][j] = 0;
            }
        }
    }
    vector<int> distance(N,INT_MAX-1000);
    vector<bool> visited(N,false);
    int src ;
    cout<<"Enter the source : ";
    cin >> src ; 
    //logic 
    distance[src] = 0 ; 
    for(int i=0;i<N;i++){
        int smol  = find_min(distance,visited,N);
        visited[smol] = true;
        for(int j=0;j<N;j++){
            if(graph[smol][j]==-1) graph[smol][j] = INT_MAX - 1000;
            if(!visited[j] && distance[j]>distance[smol]+graph[smol][j]){
                distance[j] = distance[smol] + graph[smol][j];
            }
        }
    }
    int dest; 
    cout<<"Enter destination : ";
    cin>>dest; 
    cout<<"The minimum distance between "<<src << " and "<<dest << " is "<< distance[dest];
    return 0;
}