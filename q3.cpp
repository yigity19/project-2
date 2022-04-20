//Rahman ve Rahim olan Allah'ın adıyla

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


// C++ program for Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]


//once color ata
//daha sonra  

class Node{
    int degree;
    int id;
    int color_num;

    public:
        Node(int id);//, vector<Node>*);
        void encolor(int color_num){this->color_num = color_num;}
        int getColor(){return color_num;}
        int getDegree(){return degree;}
        int getId(){return id;}
        void setDegree(int degree){this->degree = degree;}
};

Node::Node(int id){
    this->id = id;
    //adjacent = others;
    color_num = -1;
}



int main(){

    vector<Node> nodes;
    Node start(1);
    start.encolor(1);
    nodes.push_back(start);
    for(int i = 2; i <= 7; i++){
        Node temp(i);
        nodes.push_back(temp); 
    }
    
    int matrix[7][7] = {{0,1,0,1,1,0,0},
                        {1,0,1,1,0,0,0},
                        {0,1,0,1,0,1,1},
                        {1,1,1,0,1,1,0},
                        {1,0,0,1,0,1,0},
                        {0,0,1,1,1,0,1},
                        {0,0,1,0,0,1,0}};


    int degreeArr[7];

    for(int i = 0; i < 7;i++){
        int sum = 0;
        
        for(int j = 0; j < 7; j++){
            sum += matrix[i][j];
        }
        degreeArr[i] = sum;
    }

    vector<int> sortedNodes(7);                // create degrees array with length numofvertex
    iota(sortedNodes.begin(), sortedNodes.end(), 0); // assign all index 0
    // sort degree vector insortedNodes vector by their index so each index shows that vertex number
    stable_sort(sortedNodes.begin(), sortedNodes.end(),
                [&degreeArr](int i1, int i2)
                { return degreeArr[i1] > degreeArr[i2]; });

    int color_counter = 1;

    for(int i = 0; i < 7; i++){
        int current_node = sortedNodes[i];
        vector<int> non_adjacent;
        vector<int> non_adjacent_copy;

        for(int j = 0; j < 7; j++ ){
            if(matrix[current_node][j] == 0){ // get the nonadjacent nodes  
                non_adjacent.push_back(j);
                non_adjacent_copy.push_back(j);
                nodes[j].encolor(color_counter);
            }
        }

        /*int deneme = non_adjacent.size();
        for(int j = 0; j < (deneme -1 ) ; j++){
            for(int k = 0; k < 7; k++){
                if(matrix[non_adjacent[j]] == 1){
                    //cout<< non_adjacent[j] << " & " << non_adjacent[k] << endl;
                    vector<int>::iterator it = non_adjacent.begin() + k;
                    non_adjacent.erase(it);
                    deneme--;

                //}
            }
        } */

        

        for(auto& it : non_adjacent){
            for(int j = 0; j < 7; j++){
                //if(nodes[it].getColor() != nodes[j].getColor()){
                matrix[it][j] = -1;
                matrix[j][it] = -1;
            }
        }

        color_counter++;
        
    }

    
    for(int i = 0; i < 7; i++){
        cout<<nodes[i].getId() << " "<< nodes[i].getColor() << endl;
    }/*



    cout<<"---------------------------------"<<endl;

    for(int i = 0; i < 7; i++){
        cout<<nodes[i].getId() << " "<< nodes[i].getDegree() << endl;
    }
    int color_counter;
    for(int i = 0; i < 7; i++){
        int last_color = 0;
        int array[7] = {0};

        for(int j = 0; j < 7; j++){

            if(matrix[i][j] == 1){

                array[nodes[j].getColor()] = 1;        
            }


        }

        color_counter = 1;
        while(array[color_counter]){
            color_counter++;
        } 
        nodes[i].encolor(color_counter);        

    }*/

}