#include <iostream>
#include<sstream>
#include<climits>

//struct represents the weighted edge
struct edge{
    //contains the node, weight and distance
    int node, weight, dist;

};
//struct contains the verticies and edges and is a child of the edge struct
struct bellGraph{
    int vert,edge;
    struct edge* Edge;
};
//struct to 
struct bellGraph* displayGraph(int V, int E) {
    struct bellGraph* bellgraph = new bellGraph;
    bellgraph->vert = V;
    bellgraph->edge = E;
    bellgraph->Edge = new edge[E];
 return bellgraph;   
};


// void printGraph(int dist[], int numVertex){
//     for(int i = 0; i < numVertex; i++){
//             if(dist[i] == INT_MAX){
//                 std::cout<<"INFINITY"<<std::endl;
//             } else{
//                 std::cout<< dist[i] << std::endl;
//             }

//     }
// }

//int j = 0;
    // while(j <vNode){
    //     std::cout<<j <<std::endl;
    //     int k =0;
    //     while(k < edge){
    //         std::cout<< dist[k] <<std::endl;
    //         k++;
    //     }
    //     j++;
    // }
void bellman(struct bellGraph* bellgraph, int srcNode){
    int vNode = bellgraph->vert;
    int edge = bellgraph->edge;
    int dist[vNode];
//initalizating the crap
for(int i =0; i < vNode; i++){
    dist[i] = INT_MAX;
    dist[srcNode] = 0;
}

for(int i=1; i <= vNode-1; i++){
    for(int j =0;  j< edge; j++){
        int  u = bellgraph->Edge[j].node;
        int w = bellgraph->Edge[j].dist;
        int weight = bellgraph->Edge[j].weight;
            if(dist[u] + weight < dist[w] && dist[u] != INT_MAX){
                dist[w] = dist[u] + weight;
        }
    }
}
    int i =0;
    while(i < edge){
        int  u = bellgraph->Edge[i].node;
        int w = bellgraph->Edge[i].dist;
        int weight = bellgraph->Edge[i].weight;
            if(dist[u] + weight < dist[w] && dist[u] != INT_MAX){
                std::cout<<"FALSE" << std::endl;
                return;
            }  
            i++;
    }
    std::cout << "TRUE"<<std::endl;

for(int i = 0; i < vNode; i++){
            if(dist[i] == INT_MAX){
                std::cout<<"INFINITY"<<std::endl;
            } else{
                std::cout<< dist[i] << std::endl;
            }

    }

    //printGraph(dist, vNode);



    // int j = 0;
    // while(j <vNode){
    //     std::cout<<j <<std::endl;
    //     int k =0;
    //     while(k < edge){
    //         std::cout<< dist[k] <<std::endl;
    //         k++;
    //     }
    //     j++;
    // }



}



int main(){
        int u;
        int v;

        std::cin >> u >> v;
        struct bellGraph* graph = displayGraph(u,v);

            int x,y,z;
            for(int j = 0; j < v; j++){
            std::cin >> x >> y >> z;
            graph->Edge[j].node = x;
            graph->Edge[j].dist = y;
            graph->Edge[j].weight = z;
                }  
            
            bellman(graph, 0);
        
          return 0;


}
