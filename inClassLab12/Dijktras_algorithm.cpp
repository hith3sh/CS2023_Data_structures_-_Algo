#include <bits/stdc++.h>
using namespace std;

//will return the node with minimum distance
int returnMinNode(vector<bool>& visited,vector<int>& distance){
    int min_val=INT_MAX;
    int node;
    for(int i=0;i<6;i++){
        if(visited[i]==false && distance[i]<min_val){
            min_val=distance[i];
            node=i;
        }
    }
    return node;
}
void dijkstras(int G[6][6],int nodes,int start){
    vector<int> distance(6,INT_MAX);   //distance vector
    vector<bool> visited(6,false);   //visited vector all set to false
    int parent[6];                  //parent array that will store who is the parent node

    distance[start]=0;
    parent[start]=-1;
    //after checking distances and by selecting minNode we start traversal
    for(int i=0;i<nodes-1 ; i++){
        //pick the minimum distanced node
        int minNode=returnMinNode(visited,distance);
        //now we're base around minNode and travel
        visited[minNode]=true;

        for(int j=0;j<6;j++){    //now we check all the adjacent nodes of this node
            if(G[minNode][j] +distance[minNode] < distance[j] && G[minNode][j]!=0 && 
                visited[j]==false){
                    distance[j]=G[minNode][j]+distance[minNode];
                    parent[j] =minNode;
                }           

        }
    }
    cout << endl << "source node is: "<< start <<endl;
    for(int i=0;i<6;i++){
        cout <<"distance from source to " << i  <<" is :"<<distance[i];
        cout << endl;
    }


}
int main(){
    int Graph[6][6]={{0,10,0,0,15,5},{10,0,10,30,0,0},{0,10,0,12,5,0},{0,30,12,0,0,20},{15,0,5,0,0,0},{5,0,0,20,0,0}};
    int nodes=6;
    int start=5;

    dijkstras(Graph,nodes,start);
    return 0;
}
