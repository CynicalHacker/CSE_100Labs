#include <iostream>
#include<vector>
#include<stack>
#include <list>
#include<sstream>

class SCC{
        int vert;
        int edgeCount;
        std::list<int> *adjacent;
        

        void ID(int vertex, bool checked[], std::stack<int> &Stack);
        void DFS(int vertex, bool checked[],int vCount, int arr[]);
    
    public:
    SCC(int vert,int edgeCount);
    void connectedEdge(int vertex, int w);
    void printSCC(int arr[]);

    SCC getTranspose();
    //~SCC();
};                                                                 


SCC::SCC(int vert,int edgeCount){
    this->vert = vert;
    adjacent = new std::list<int>[vert];
    this->edgeCount = edgeCount;
}



void SCC:: DFS(int vertex, bool checked[], int vCount, int arr[]){
        checked[vertex] = true;
        arr[vertex] = vCount;
        //std::cout << vertex << std::endl;

        std::list<int>::iterator i ;
            for( i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i){
                    
                    if(checked[*i] == false){
                            DFS(*i, checked,vCount,arr);
                    }
            }
}


 SCC SCC::getTranspose(){
     SCC m(vert,edgeCount);
     int i = 0;
        while(i < vert){
            for(std::list<int>::iterator j = adjacent[i].begin(); j != adjacent[i].end();++j){
                        m.adjacent[*j].push_back(i);
                    }
                i++;
        }
        return m;
 }

 void SCC::connectedEdge(int vertex, int x){
     adjacent[vertex].push_back(x);
 }




void SCC::ID(int vertex, bool checked[], std::stack<int> &Stack){
    checked[vertex] = true;
        int j = 0;
        std::list<int>::iterator k = adjacent[vertex].begin();
        while( k != adjacent[vertex].end()){
             if(checked[*k] == false){
                    ID(*k, checked, Stack);
                }
                ++k;
        }
            Stack.push(vertex);
}

void SCC::printSCC(int arr[]){


for(int i = 0; i < vert; i++){
            arr[i] = 0 ;
        }

        std::stack<int> Stack;

    
        bool *visited = new bool[vert];
        for(int i = 0; i < vert; i++)
                visited[i] = false;
        

        int j = 0;
        while(j < vert){
            if(!visited[j])
                    ID(j, visited, Stack);
                    j++;
        }
       
        // for(int i =0; i < vert; i++)
        //         if(!visited[i])
        //             ID(i, visited, Stack);
            
        

        SCC reversed = getTranspose();


        for(int i = 0; i < vert; i++)
                visited[i] = false;
        

        do{
            int vertex = Stack.top();
            Stack.pop();

            if(visited[vertex] == false){
                reversed.DFS(vertex, visited,vertex, arr);
                int root = vertex;
                for(int i = 0; i < vert;i++){
                        if(arr[i] == vertex && root > i){ 
                                    root = i; 
                            }
                        }
                            for(int i = 0; i < vert; i ++){
                                if(arr[i] == vertex)
                                        arr[i] = root;                     
                            }
                        }
                    }while(!Stack.empty());
            

            for(int i =0; i < vert; i ++){
              std::cout<<arr[i]<<std::endl;
          }
        }
         //while(!Stack.empty());
    


int main(){
         int vCount;
        std::cin >> vCount;
        int numEdge;
        SCC g(vCount,numEdge);
         std::cin >> numEdge;
         int i =0;
         do{
            int n1,n2;
            std::cin >> n1 >> n2;
            g.connectedEdge(n1,n2);
            i++;
         }while(i < numEdge);

        int arr[vCount];
       
          g.printSCC(arr);

        
          return 0;


}
