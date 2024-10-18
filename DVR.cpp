#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int find_min(vector<int> distance , vector<bool> visited , int N){
    int smol_distance = INT_MAX;
    int smol_idx; 
    for(int i=0;i<N;i++){
        if(!visited[i] && distance[i]<smol_distance){
            smol_distance = distance[i];
            smol_idx = i ; 
        }
    }
    return smol_idx;
}
int main(){
    int temp ; 
    cout<<"Enter number of nodes : ";
    int N ;
    cin>> N;.
    cout<<"Use -1 if there is no link between nodes"<<endl;
    int graph[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i<j){
                cout<<"Enter the weight between nodes "<<i<<" and "<<j<<" :";
                cin>>temp;
                graph[i][j] = temp ; 
                graph[j][i] = temp ; 
            }
            else if(i==j){
                graph[i][j] = 0;
            }
        }
    }
    //logic
    for(int node=0;node<N;node++){
        vector<int> distance(N,INT_MAX-1000);
        vector<bool> visited(N,false);
        int src = node ; 
        distance[src] = 0 ; 
        for(int i=0;i<N;i++){
            int smol  = find_min(distance,visited,N);
            visited[smol] = true;
            for(int j=0;j<N;j++){
                if(graph[smol][j]==-1) {
                    temp = INT_MAX - 1000;
                }
                else{
                    temp = graph[smol][j];
                }
                if(!visited[j] && distance[j]>distance[smol]+temp){
                    distance[j] = distance[smol] + temp;
                }
            }
        } 
        cout<<"Final table for Node "<<node<< " : "<<endl;
        for(int k=0;k<N;k++){
            cout<< node << " to "<< k << " : "<<distance[k]<<endl;
        }
        cout<<"------------------------------------------------"<<endl;
    }
    return 0 ; 

}