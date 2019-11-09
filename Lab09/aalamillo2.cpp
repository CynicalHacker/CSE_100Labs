#include <iostream>
#include<vector>
#include<stack>
#include <list>
#include<sstream>

class SCC{
        int vert;
        std::list<int> *adjacent;
        

        void ID(int vertex, bool checked[], std::stack<int> &Stack);
        void DFS(int vertex, bool checked[]);
    
    public:
    SCC(int vert);
    void connectedEdge(int vertex, int w);
    void printSCC(int edgeCount);

    SCC getTranspose();
    //~SCC();
};                                                                 


SCC::SCC(int vert){
    this->vert = vert;

    adjacent = new std::list<int>[vert];
}



void SCC:: DFS(int vertex, bool checked[]){
        checked[vertex] = true;
        std::cout << vertex << std::endl;

        std::list<int>::iterator i ;
            for( i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i){
                    
                    if(checked[*i] == false){
                            DFS(*i, checked);
                    }
            }
}


 SCC SCC::getTranspose(){
     SCC m(vert);
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

void SCC::printSCC(int edgeCount){

        std::stack<int> Stack;

    
        bool *visited = new bool[vert];
        for(int i = 0; i < vert; i++){
                visited[i] = false;
        }

        for(int i =0; i < vert; i++){
                if(!visited[i]){
                        ID(i, visited, Stack);
            }
        }

        SCC reversed = getTranspose();

        for(int i = 0; i < vert; i++){
                visited[i] = false;
        }

        do{
            int vert = Stack.top();
            Stack.pop();

            if(visited[vert] == false){
                reversed.DFS(vert, visited);
                int root = vert;
                for(int i = 0; i < edgeCount;i++){

                }
            }
            

            
        } while(!Stack.empty());

    
}

int main(){
        // int vCount;
        // std::cin >> vCount;
        SCC g(9);
        g.connectedEdge(0,1);
        g.connectedEdge(2,3);
        g.connectedEdge(4,5);
        g.connectedEdge(6,7);
        g.connectedEdge(8,6);


        // int numEdge;
        // std::cin >> numEdge;
        // for(int i = 0; i < numEdge; i ++){
        //     int n1,n2;
        //     std::cin >> n1 >> n2;
        //     g.connectedEdge(n1,n2);
        // } 
          g.printSCC(5);
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
