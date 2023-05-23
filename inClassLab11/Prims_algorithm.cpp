#include <bits/stdc++.h>
using namespace std;

//returns index of the minimum value of the distance array
int minIndex(vector<int> distance,vector<bool> boolArray){
    //set the minimum value to a large value and compare
    int min=INT_MAX;
    int index=0;

    for(int i=0;i<6;i++){
        if(boolArray[i]==false && distance[i] < min){ //if its an untravelled node and the min from distance then choose it
            min=distance[i];
            index=i;
        }
    }
    return index;
}
void printMST(vector<int> parent,int graph[6][6]){
    cout << "Edge  Weight "<<endl;
    for (int i = 1; i < 6; i++)
        cout << parent[i] << " - " << i << "  "<< graph[i][parent[i]] << endl;
}


void prims(int graph[6][6]){
    vector<int> distance(6,INT_MAX);   //set all distances to infinity
    vector<bool> boolArray(6,false);       //set all values to false
    vector<int> parent(6);

    //first set node 0 as starting node
    distance[0]=0;
    parent[0]=-1;

    //two for loops to traverse through each
    for(int i=0;i<5;i++){  //5 because only 5 edges can exist
        int min_d=minIndex(distance,boolArray);   //find the minimum of the distance array ,min_index 
        boolArray[min_d]=true;
        //now loop through that row with min_index
        for(int j=0;j<6;j++){   //j traverse through row 
            //we're updating the distance array checking if distance mentioned in graph is lesser than distance array values
            if(graph[min_d][j]!=0 && boolArray[j]==false && graph[min_d][j] <distance[j]){   //checking if less than infinity
                distance[j]=graph[min_d][j];   //updating the distance array using graph values
                parent[j]=min_d;
            }
        }
    }
    //printing mst
    printMST(parent,graph);

}

int main(){
    int graph[6][6] ={{0,3,0,0,0,1},{3,0,2,0,10,0},{0,2,0,3,0,0},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,0,0,4,0}};
    prims(graph);
    return 0;
}
