//Rahman ve Rahim olan Allah'ın adıyla

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

class Node{
    int id;
    //vector<Node>* adjacent;
    int color_num;
    public:
        Node(int id);//, vector<Node>*);
        void encolor(int color_num){this->color_num = color_num;}
        int getColor(){return color_num;}
        int getId(){return id;}
};

Node::Node(int id){
    this->id = id;
    //adjacent = others;
    color_num = -1;
}

int main(){
    vector<Node> nodes;
    Node start_node(1);
    start_node.encolor(1);
    nodes.push_back(start_node);
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
    auto start = chrono::steady_clock::now();
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
        while(array[color_counter]){ // 1 2 4 ->-1 1 0 1
            color_counter++;
        } 
        nodes[i].encolor(color_counter);        

    }
    
    auto end = chrono::steady_clock::now();

    double milli = chrono::duration_cast<chrono::microseconds>(end - start).count();
    milli /= 1000;
    cout << "Time in " << milli << "ms" << endl;

    for(int i = 0; i < 7; i++){
        cout<<nodes[i].getId() << " "<< nodes[i].getColor() << endl;
    }
}