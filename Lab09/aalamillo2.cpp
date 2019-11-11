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
        for(int i = 0; i < vert; i++){
                //std::list<int>::iterator j;
                    for(std::list<int>::iterator j = adjacent[i].begin(); j != adjacent[i].end();++j){
                        m.adjacent[*j].push_back(i);
                    }
        }
        return m;
 }

 void SCC::connectedEdge(int vertex, int x){
     adjacent[vertex].push_back(x);
 }




void SCC::ID(int vertex, bool checked[], std::stack<int> &Stack){
    checked[vertex] = true;

        for(std::list<int>::iterator j = adjacent[vertex].begin(); j != adjacent[vertex].end(); ++j ){
                if(checked[*j] == false){
                    ID(*j, checked, Stack);
                }
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
        

        for(int i =0; i < vert; i++)
                if(!visited[i])
                    ID(i, visited, Stack);
            
        

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
         for(int i = 0; i < numEdge; i ++){
            int n1,n2;
            std::cin >> n1 >> n2;
            g.connectedEdge(n1,n2);
         }

        // SCC g(9);
        // g.connectedEdge(0,1);
        // g.connectedEdge(2,3);
        // g.connectedEdge(4,5);
        // g.connectedEdge(6,7);
        // g.connectedEdge(8,9);

         //std::vector<int>vec;
        int arr[vCount];
        // for(int i = 0; i < vCount; i++){
        //     arr[i] = 0 ;
        // }
        //  for(int i = 0 ; i < vCount; i ++){
        //      vec.push_back(0);
        //  } 
          g.printSCC(arr);

        //   for(int i =0; i < vCount; i ++){
        //       std::cout<<arr[i]<<std::endl;
        //   }
          return 0;
        
        // int vertexCount;
        // int edgeCount;

        // std::cin >> vertexCount;
        // std::cin >> edgeCount;

        // SCC j(vertexCount);
        
        // for(int i = 0; i < edgeCount; i++){
        //     int u,w;
        //     std::cin >> u >>w;
            

        //         // std::string input;
        //         // std::cin >> input;

        //         // std::string str = input.substr(0);
        //         // std::stringstream convert(str);
        //         // convert >>u;

        //         // std::string str1 = input.substr(1);
        //         // std::stringstream convert1(str1);
        //         // convert1 >>w;

        //         j.connectedEdge(u,w);
        // }

        // std::vector<int>vec;
        // for(int i = 0; i < vertexCount;i++){
        //     vec.push_back(vertexCount + 2);
        // }
        // j.printSCC();

        // for(int i = 0; i < vertexCount; i ++){
        //     std::cout<<vec[i] << std::endl;
        // }



}
