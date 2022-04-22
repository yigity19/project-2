//Rahman ve Rahim olan Allah'ın adıyla

#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <chrono>
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
    int color_time;

    public:
        Node(int id);//, vector<Node>*);
        void encolor(int color_num, int color_time);
        int getColor(){return color_num;}
        int getDegree(){return degree;}
        int getId(){return id;}
        void setDegree(int degree){this->degree = degree;}
};

void Node::encolor(int color_num, int color_time){
    this->color_num = color_num;
    this->color_time = color_time;
}

Node::Node(int id){
    this->id = id;
    //adjacent = others;
    color_num = -1;
}



int main(){

    vector<Node> nodes;
    Node start_node(1);
    //start.encolor(1,-1);
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


    int degreeArr[7];

    for(int i = 0; i < 7;i++){
        int sum = 0;
        
        for(int j = 0; j < 7; j++){
            sum += matrix[i][j];
        }
        degreeArr[i] = sum;
    }

    auto start = chrono::steady_clock::now();

    vector<int> sortedNodes(7);                // create degrees array with length numofvertex
    iota(sortedNodes.begin(), sortedNodes.end(), 0); // assign all index 0
    // sort degree vector insortedNodes vector by their index so each index shows that vertex number
    stable_sort(sortedNodes.begin(), sortedNodes.end(),
                [&degreeArr](int i1, int i2)
                { return degreeArr[i1] > degreeArr[i2]; });

    int color_counter = 1;

    for(int i = 0; i < 7; i++)
        cout<<sortedNodes[i]<<endl;

    for(int i = 0; i < 7; i++){
        int current_node = sortedNodes[i];

        if(nodes[current_node].getColor()< 0){
            map<int,int> non_adjacent;

            //get the non adjacent nodes for every node in the graph
            for(int j = 0; j < 7; j++ ){
                if(matrix[current_node][j] == 0){ // get the nonadjacent nodes  
                    non_adjacent.insert(pair<int,int>(j,0));
                    //nodes[j].encolor(color_counter);
                }
            }

            map<int,int> adjacent_pairs;
            map<int,int>::iterator map_itr1;
            
            map<int,int>::iterator map_itr2;
            for(map_itr1 = non_adjacent.begin(); map_itr1 != non_adjacent.end(); ++map_itr1){
                for(map_itr2 = non_adjacent.begin(); map_itr2 != non_adjacent.end(); ++map_itr2){
                if(map_itr1->second)
                    break;
                    //if(non_adjacent[j] == 21)
                    //   cout<<"burdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
                    if(matrix[map_itr1->first][map_itr2->first] == 1 && nodes[map_itr1->first].getColor() < 0){
                        //cout<< non_adjacent[j] << " & " << non_adjacent[k] << endl;
                        adjacent_pairs.insert(pair<int,int>(map_itr2->first, map_itr1->first));
                        map_itr2->second = 1;
                        //deneme--;
                    }
                }
            }

            
            bool colored = false;
            for(map_itr1 = non_adjacent.begin();map_itr1 != non_adjacent.end(); map_itr1++){
                if(!map_itr1->second){
                            colored = true;
                            if(nodes[map_itr1->first].getColor() < 0)
                                nodes[map_itr1->first].encolor(color_counter, 0);
                }
                //for(map_itr2 = adjacent_pairs.begin(); map_itr2 != adjacent_pairs.end(); ++map_itr2){
                        //if(nodes[it].getColor() != nodes[j].getColor()){
                        //f(map_itr1->first != map_itr2->first){
                        //}
                        //matrix[map_itr1->first][j] = -1;
                        //matrix[j][map_itr1->first] = -1;
                //}
            }

            

            /*bool colored = false;
            for(map_itr1 = non_adjacent.begin();map_itr1 != non_adjacent.end(); map_itr1++){
                if(!map_itr1->second){
                    colored = true;
                    nodes[map_itr1->first].encolor(color_counter, 0);
                    for(int j = 0; j < 7; j++){
                        //if(nodes[it].getColor() != nodes[j].getColor()){
                        matrix[map_itr1->first][j] = -1;
                        matrix[j][map_itr1->first] = -1;
                    }
                }
            }*/

            //cout<<"Vertex " << sortedNodes + 1 << " ---> Color " << nodes[sortedNodes[i]].getColor() <<endl;
            bool isItFirst = true;
            for(auto& it : sortedNodes){
                if(nodes[it].getColor() == color_counter &&  nodes[it].getColor() > 0){
                    if(!isItFirst)
                        cout<<"Checking " << it + 1<< " ---> true"<<endl;
                    isItFirst = false;
                    cout<<"Vertex " << it + 1 << " ---> Color " << nodes[it].getColor() <<endl;

                }
                else if(nodes[it].getColor() < 0 && adjacent_pairs.find(it) != adjacent_pairs.end())
                    cout<<"Checking " << adjacent_pairs.find(it)->second + 1<< " ---> false (since it is connected to " << adjacent_pairs.find(it)->first + 1<<")"<<endl;

                else if(nodes[it].getColor() < 0)
                    cout<<"Checking " << it + 1<< " ---> false"<<endl;
            }

            if(!isItFirst){
                cout<<"Vertices ";
                int j,size = non_adjacent.size();
                for(map_itr1 = non_adjacent.begin();map_itr1 != non_adjacent.end(); map_itr1++)
                    if(nodes[map_itr1->first].getColor()>0 && !map_itr1->second)
                        cout<<map_itr1->first + 1<<",";
                cout<<" are dropped!!"<<endl;
            }    


            if(colored){
                cout<<endl;
                color_counter++;
            }

        }
        
    }

    for(int i = 0; i < color_counter; i++){

        for(auto& it : nodes){
            if(it.getColor() == i)
                cout<<"node "<< it.getId()<< " color: "<<it.getColor()<<endl; 
        }
        cout<<endl<<endl;
    }


    cout<<"Well done!! All the vertices are colored."<<endl;
    cout<<"Min color num:"<<color_counter -1 <<endl;
    auto end = chrono::steady_clock::now();

    double milli = chrono::duration_cast<chrono::microseconds>(end - start).count();
    milli /= 1000;
    cout << "Time in " << milli << "ms" << endl;

}