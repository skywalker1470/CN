#include<iostream>
#include<vector>
using namespace std;
int main(){
    int B;
    cout<<"Give bucket capacity : ";
    cin>>B;
    int R;
    cout<<"Give R value : ";
    cin>>R;
    vector<int> tap ; 
    int N;
    cout<<"Give the amount of time the data flows : ";
    cin>>N;
    cout<<"Give the tap flow at times : "<<endl;
    for(int i=0;i<N;i++){
        cout<<"at time "<<i<<" : ";
        int temp;
        cin>>temp;
        tap.push_back(temp);
    }
    //Logic
    int bucket = 0 ;  
    for(int i=0;i<N;i++){
        bucket += tap[i];
        int overflow = 0 ;
        if(bucket>B){
            overflow = bucket - B ;
            bucket = B;
            cout<<overflow<<" lost at time "<<i<<endl; 
        }
        if(bucket<R) {
            cout<<bucket<<" packets sent at time "<<i<<endl;
            bucket = 0; 
        }
        else{
            cout<<R<<" packets sent at time "<<i<<endl;
            bucket -= R;
        }
    }
    if(bucket>0) cout<<"there are still "<<bucket<<" packets in the bucket"<<endl;
    return 0;
}