#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/*
this is the code of the question for the P.I. works software internship testcase
 
 IMPORTANT:
    The inputs are taken from a text file named "input.txt" for this question,
 
    so in order for the code to work we need a .txt file named "input.txt" and type our input to there.
 
 
*/
using namespace std;

/*
 This will be the node we use, It contains 2 integer values
 one is the value of the node
 the second is the maximum value when we start from the top.
*/
struct node{
    
    int value;
    int max;
  
    node(){
        value = 0;
        max = 0;
    }
    
    node(int val){
        value = val ;
        max = val;
    }
    
};


/*
 This is the function to decide if a number is Prime.
*/
bool isPrime(int a){
    if(a == 1)
        return false;

    int b = 0;
    b = a/2;
      for(int i = 2; i <= b; i++)
      {
          if(a % i == 0)
          {
              return false;
          }
      }
    return true;
    
}



int main() {
    
    vector<vector<node>> myVector; // we will keep the pyramid in a 2D vector.
    ifstream file;
    string line;
    file.open("input.txt");
    
    int num, result = INT_MIN;
    /*
     result will be the final solution,
     I assigned the minimum integer possible at first,
     I will increment it if I find a better, higher solution.
    */
    if(!file){
        cout << "Cannot open file!" << endl;
    }else{
        int i = 0, j;
        while(getline(file, line)){
            stringstream ss (line);
            vector<node> v;
            j = 0;
            while(ss >> num){
                
                node element(num);
                
                
                if(isPrime(num)){
                    /*
                     If the value of the node is prime,
                     I assigned the minimum integer to it in order for my algorithm to not find a path on this node.
                    */
                    element.value = INT_MIN;
                    element.max = INT_MIN;
                }else if (i > 0){
                
                    /*
                     I assign the max value of the node to
                    */
                    if(j < myVector[i-1].size() && (element.max < myVector[i-1][j].max + element.value)){
                        element.max = myVector[i-1][j].max + element.value;
                    }
                    
                    if(j > 0 && (element.max < myVector[i-1][j-1].max + element.value)){
                        element.max = myVector[i-1][j-1].max + element.value;
                    }
                    
                    if(j < myVector[i-1].size()-1 && (element.max < myVector[i-1][j+1].max + element.value)){
                        element.max = myVector[i-1][j+1].max + element.value;
                    }
                    
                    if(element.max > result){
                        result = element.max;
                    }
                    
                }
                
                v.push_back(element);
                j++;
            }
            myVector.push_back(v);
            i++;
        }
    }
    
    file.close();
    

    cout << "The result is: " << result << '\n' ;
    
    return 0;
}
