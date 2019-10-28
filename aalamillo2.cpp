#include<iostream>
#include <stdlib.h>
#include<vector>
#include<list>
using namespace std;

class Hash { 
        list<int> *hashtable;
    public:
        Hash(int num);
        void insertItem(int n);
        void deleteItem(int num);
        int hashFunction(int k){
            return(k % 10);
        }

};

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

