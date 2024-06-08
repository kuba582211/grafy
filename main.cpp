#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "list.h"
#include "matrix.h"
using namespace std;

void driver(){
    GraphList g1(5);
    g1.addEdge(1,0,1);
    g1.addEdge(1,2,1);
    g1.addEdge(1,3,1);
    g1.addEdge(2,4,3);
    g1.show();
    g1.dijkstra(1,true);
    g1.dijkstra_two(2,0,true);
    cout<<endl<<endl;
    GraphMatrix g2(6);
    g2.addEdge(2,3,1);
    g2.addEdge(2,4,1);
    g2.addEdge(1,2,1);
    g2.addEdge(0,5,1);
    g2.addEdge(3,5,3);
    g2.show();
    g2.dijkstra(0,true);
    g2.dijkstra_two(0,2,true);
}

int main()
{
    int V[5]={5,10,50,100,250};
    int D[4]={25,50,75,100};
    int odp;
    cout<<"Witaj co chcialbys zrobic?"<<endl;
    cout<<"1. zbadac grafy"<<endl;
    cout<<"2. pokazac przyklady"<<endl;
    cout<<"->";cin>>odp;
    if(odp==1){
        cout<<"Ktora najpierw:"<<endl;
        cout<<"1. lista sasiedztwa"<<endl;
        cout<<"2. macierz sasiedztwa"<<endl;
        cout<<"->";cin>>odp;
        if(odp==1){
            for(int j=0;j<5;j++){
                for(int i=0;i<4;i++){

                    auto start1 = chrono::high_resolution_clock::now();
                    auto stop1 = chrono::high_resolution_clock::now();
                    chrono::duration <double, milli> duration1 = stop1 - start1;
                    auto time = duration1;

                    for(int liczba=0;liczba<100;liczba++){
                        GraphList g(V[j]);
                        g.fillRandomEdges(D[i],9);

                        auto start2 = chrono::high_resolution_clock::now();
                        auto stop2 = chrono::high_resolution_clock::now();
                        chrono::duration <double, milli> duration2 = stop1 - start1;
                        time = duration2;

                        auto start = chrono::high_resolution_clock::now();
                        g.dijkstra_two();
                        auto stop = chrono::high_resolution_clock::now();
                        chrono::duration <double, milli> duration = stop - start;
                        time+=duration;
                    }
                    cout<<time.count()/100<<", ";
                }
                cout<<endl;
            }

        }else if(odp==2){
        cout<<"25%    50%    75%   100%"<<endl;
        for(int j=0;j<5;j++){
                for(int i=0;i<4;i++){

                    auto start1 = chrono::high_resolution_clock::now();
                    auto stop1 = chrono::high_resolution_clock::now();
                    chrono::duration <double, milli> duration1 = stop1 - start1;
                    auto time = duration1;

                    for(int liczba=0;liczba<100;liczba++){
                        GraphMatrix g(V[j]);
                        g.fillRandomEdges(D[i],9);

                        auto start2 = chrono::high_resolution_clock::now();
                        auto stop2 = chrono::high_resolution_clock::now();
                        chrono::duration <double, milli> duration2 = stop1 - start1;
                        time = duration2;

                        auto start = chrono::high_resolution_clock::now();
                        g.dijkstra();
                        auto stop = chrono::high_resolution_clock::now();
                        chrono::duration <double, milli> duration = stop - start;
                        time+=duration;
                    }
                    cout<<time.count()/100<<", ";
                }
                cout<<endl;
            }
        }
    }else if(odp==2){
        driver();
    }
    return 0;
}
