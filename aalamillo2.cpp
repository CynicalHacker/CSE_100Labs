#include<iostream>
#include <stdlib.h>
#include<list>
#include<iterator>
//using namespace std;

class Hash { 
        std::list<int> *hashtable;
        int key;
    public:
            Hash(int k);
        void insertItem(int n);
            void deleteItem(int num);
            int hashFunction(int k){
                return(k % key);
            }

};

Hash::Hash(int k){
        this->key = k;
        hashtable = new std::list<int>[key];
}

void Hash::insertItem(int n){
        int indexValue = hashFunction(n);
        hashtable[indexValue].push_back(n);
}
 void Hash::deleteItem(int num){
     int deleteIndex = hashFunction(num);
     for (std::list<int>::const_iterator iterator = hashtable[deleteIndex].begin(), end = hashtable[deleteIndex].end(); iterator != end; ++iterator){
         if (*iterator == num ){
               hashtable[deleteIndex].remove(*iterator);
         }
     }
     
 }

// int main(){


//   string input;
//   int n;
//   //cin >> input;
// while(input[0] != 'e'){
//     cin >>input;
//     string str = input.substr(1);
//     stringstream convert(str);
//     convert >> n ;
  
    
//      if(input[0] == 'i'){
      
//        tree = Insert(tree,n);
//     }

//      if(input[0] == 'e'){
//         break;
//     }
//      if(input[0] == 'd'){
        
//         tree =Delete1(tree,n);
//     }

//     else if(input == "opre"){
//         preOrderTree(tree);
//     }
//     else if(input == "opost"){
//         postOrderTree(tree);
//     }
//     else if(input == "oin"){
//         inorderTree(tree);
//     }
//  // cin >> input;


// }
// return 0;

