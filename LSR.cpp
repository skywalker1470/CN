#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ; 
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
    cout<<"Enter number of nodes : ";
    int N ; 
    cin>>N;
    //cout<<"Enter a character for each nodes: ";
    //vector<char> nodes;
    /*for(int i=0;i<N;i++){
        char temp;
        cin>>temp;
        nodes.push_back(temp);
    }&*/
    int graph[N][N] ; 
    cout<<"Enter the distances between nodes (-1 if there is no link) : "<<endl ; 
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j>i){
                int temp ;
                cout<<i<<" & "<<j<<" : ";
                cin>>temp; 
                graph[i][j] = temp ; 
                graph[j][i] = temp ;
            }
            else if(i==j){
                graph[i][j] = 0 ; 
            }
        }
    }
    //giving link state tables for each node ; 
    cout<<"These are the link state routing tables for every node : ";
    for(int i=0;i<N;i++){
         cout<<"The link state routing table for "<<i<< " is : "<<endl;
         cout<<"-----------------------------------"<<endl;
        for(int j=0;j<N;j++){
            if(i<j && graph[i][j]!=-1){
                cout<<j<<" : "<<graph[i][j]<<endl;
            }
        }
        cout<<"-----------------------------------"<<endl;
    }
    //using dijstra to find the routes to every other node
    int temp ; 
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
        cout<<"Final Routing Table for node "<<node<< " : "<<endl;
        for(int k=0;k<N;k++){
            cout<< node << " to "<< k << " : "<<distance[k]<<endl;
        }
        cout<<"------------------------------------------------"<<endl;
    }
    return 0 ; 
}