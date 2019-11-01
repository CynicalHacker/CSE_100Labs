#include<iostream>
#include<stdlib.h>
#include<list>
#include<iterator>
#include<string>
#include<sstream>

//using namespace std;

class Hash { 
    private:
        std::list<int> *hashtable;
        int hashBucket;
    public:
            Hash(int k);
            void insertItem(int n);
            void deleteItem(int num);
            void findItem(int key);
            int hashFunction(int k){
                return(k % hashBucket);
            }
            void displayHash();
            ~Hash(){
                delete[] hashtable;
            }
};

Hash::Hash(int k){
        this->hashBucket = k;
        hashtable = new std::list<int>[hashBucket];
}

void Hash::findItem(int key){
        int index  = hashFunction(key);
        int counter =0;
        std::list<int>:: iterator iter;
        for ( iter= hashtable[index].begin(); iter != hashtable[index].end();++iter){
         if (*iter == key ){
               std::cout << key << ":FOUND_AT" << index << "," <<counter <<  ";"<<std::endl;
               return ;
         }
         counter++;
         }
            std::cout << "NOT_FOUND";
     }


void Hash::insertItem(int n){
        int indexValue = hashFunction(n);
        hashtable[indexValue].push_front(n);
}
 void Hash::deleteItem(int num){
     
     int deleteIndex = hashFunction(num);
   //std::list<int> table = hashtable[deleteIndex];
     std::list<int>::iterator iter;
     for (iter = hashtable[deleteIndex].begin(); iter != hashtable[deleteIndex].end(); iter++){
         if (*iter == num ){
              hashtable[deleteIndex].erase(iter);
                std::cout << num <<":"<<"DELETED";
                return ;
         }       
     }
     std::cout << num << ":" <<"DELETE_FAILED";
     
 }
 void Hash::displayHash(){
     for (int i = 0; i < hashBucket; i++){
         std::cout << i <<":";
         for(auto j: hashtable[i]){
             std::cout  << j <<"->";
             
         }
         std::cout << ";"<<std::endl;
     }

 }


int main(){
  int m;
  std::cin >> m;

  std::string input;
  std::cin >> input;
//std::stringstream str1 (input);
  Hash Hash(m);
while(input[0] != 'e'){
    //std::cin >>input;
    if(input[0] == 'i'){
        input.erase(0,1);
        int num = stoi(input);
        Hash.insertItem(num);
    }
     if(input[0] == 'd'){
         input.erase(0,1);
         int num = stoi(input);
         Hash.deleteItem(num);
    }
    if(input[0] == 's'){
        input.erase(0,1);
        int num = stoi(input);
        Hash.findItem(num); 
    }
    if(input[0] == 'o'){
        Hash.displayHash();
    }
    std::cin >>input;
}

}
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

