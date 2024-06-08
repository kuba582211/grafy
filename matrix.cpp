#include <iostream>
#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

GraphMatrix::GraphMatrix(int vertices){
        V = vertices;
        Matrix.resize(V, vector<int>(V, 0));
}

void GraphMatrix::addEdge(int x, int y ,int w) {
        Matrix[x][y] = w;
        Matrix[y][x] = w;
    }

void GraphMatrix::show(){
    cout << "Macierz:" << endl;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
                cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void GraphMatrix::fillRandomEdges(int dencity,int max_weight){
    srand(time(nullptr));
    int x,y,w;
    int threshold = (V*(V-1)/2)*dencity/100;
    int edgesCount = 0;
    while(edgesCount<threshold){
        x = rand() % V;
        y = rand() % V;
        w = rand() % max_weight + 1;
        if(Matrix[x][y]==0 && x!=y){
            addEdge(x,y,w);
            edgesCount++;
        }

    }
}

void GraphMatrix::dijkstra(int source,bool show_resoult) {
    if(source==-1){
        srand(time(nullptr));
        source=rand() % V;
    }
    vector<int> distance(V, numeric_limits<int>::max()); // Tablica kosztów dotarcia
    vector<bool> visited(V, false); // Tablica odwiedzonych

    distance[source] = 0;

    // implementacja kopca
    PriorityQueue pq;
    pq.push(0, source); // Dodaj wierzchołek do kopca

    while (!pq.empty()) {
        int u = pq.pop().second;
        if (visited[u]) continue;
        visited[u] = true; // Oznacz wierzchołek jako odwiedzony

        // Aktualizacja kosztów dotarcia do sąsiadów wierzcholka u
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && Matrix[u][v] != 0) {
                // Sprawdzenie czy istnieje
                if (distance[u] != numeric_limits<int>::max() && distance[u] + Matrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + Matrix[u][v];
                    pq.push(distance[v], v); // Dodaj v do kopca
                }
            }
        }
    }

    if(show_resoult){
        cout << "Najkrotsze sciezki z wierzcholka " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Do wierzcholka " << i << ": " << distance[i] << "\n";
        }
    }
}

void GraphMatrix::dijkstra_two(int source, int destination,bool show_resoult) {
    if(source==-1){
        srand(time(nullptr));
        source=rand() % V;
        destination=rand() % V;
    }
    int path = -1;
    vector<int> distance(V, numeric_limits<int>::max()); // Tablica kosztów dotarcia do wierzchoków
    vector<bool> visited(V, false); // Tablica odwiedzonych wierzchoków

    distance[source] = 0; // Koszt dotarcia do  wierzchoka wynosi 0

        // Własna implementacja kopca
    PriorityQueue pq;
    pq.push(0, source); //

    while (!pq.empty()) {
        int u = pq.pop().second; // Wybierz wierzchołek o najniższym koszcie
        if (u == destination){
            path = distance[u];
            break;
        }  // Znaleziono docelowy wierzchołek, koszt dotarcia

        if (visited[u]) continue;
        visited[u] = true; // Oznacz wierzcholek jako odwiedzony

            // Aktualizacja kosztów dotarcia do s¹siadów wierzcholka u
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && Matrix[u][v] != 0) {
                // Sprawdzenie czy krawedz istnieje
                if (distance[u] != numeric_limits<int>::max() && distance[u] + Matrix[u][v] < distance[v]) {
                    distance[v] = distance[u] + Matrix[u][v];
                    pq.push(distance[v], v); // Dodaj v do kopca
                }
            }
        }
    }

    if(show_resoult){
        if(path == -1){
            cout <<source<<" to "<<destination<<"-> Not exists"<<endl;
        }else{
            cout <<source<<" to "<<destination<<"->"<<path<<endl;
        }
    }
}
