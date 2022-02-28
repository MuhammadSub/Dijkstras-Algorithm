#include<iostream>
#include<climits>
using namespace std;



int minimumDist(int dist[], bool Tset[])
{
    int min=INT_MAX,index = 0;
              
    for(int i=0;i<11;i++)
    {
        if(Tset[i]==false && dist[i]<=min)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}

void Dijkstra(int graph[11][11],int src)
{
    int dist[11]; // AN integer array that will calculate minimum distance for each node.
    bool Tset[11];
    
    
    for(int i = 0; i<11; i++)
    {
        dist[i] = INT_MAX;
        Tset[i] = false;
    }
    
    dist[src] = 0;   //Here  Source vertex distance is set to zero.
    
    for(int i = 0; i<11; i++)
    {
        int m=minimumDist(dist,Tset);
        Tset[m]=true;
        for(int i = 0; i<11; i++)
        {
            
            if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
                dist[i]=dist[m]+graph[m][i];
        }
    }
    cout<<"Vertex\t\tDistance from source"<<endl;
    for(int i = 0; i<11; i++)
    {
        char str=65+i;
        cout<<str<<"\t\t\t"<<dist[i]<<endl;
    }
}

int main()
{
    int graph[11][11]={
        {0,2,0,0,0,0,0,0,0,0,3},
        {1,0,3,0,4,0,0,0,0,0,0},
        {0,3,0,9,0,6,0,0,0,0,0},
        {0,0,9,0,0,0,10,11,0,0,0},
        {0,4,0,0,0,0,0,0,0,0,1},
        {0,0,6,0,0,0,0,0,0,7,0},
        {0,0,0,10,0,0,0,12,0,0,0},
        {0,0,0,11,0,0,12,0,8,0,0},
        {0,0,0,0,0,0,0,8,0,1,0},
        {0,0,0,0,0,7,0,0,1,0,5},
        {3,0,0,0,1,0,6,9,0,5,0}};
    Dijkstra(graph,0);
    return 0;   
}
