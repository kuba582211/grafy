#include <iostream>
#include <vector>
#include "list.h"
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

GraphList::GraphList(int vertices){
    V = vertices;
    List.resize(V);
}

void GraphList::addEdge(int x,int y,int w){
    List[x].push_back(make_pair(y,w));
    List[y].push_back(make_pair(x,w));
}

void GraphList::show(){
    cout<<"Lista:"<<endl;
        for (int i = 0; i < V; ++i) {
            cout << i << " -> ";
            for (int j = 0; j < List[i].size(); ++j) {
                cout << "(" << List[i][j].first << "," << List[i][j].second << ") ";
            }
            cout << endl;
        }
}


void GraphList::fillRandomEdges(int dencity, int max_weight){
    srand(time(nullptr));
    int x,y;
    int threshold = (V*(V-1)/2)*dencity/100;
    int edgesCount = 0;
    while(edgesCount<threshold){
        x = rand() % V;
        y = rand() % V;
        if(hasEdge(x,y)==false && x!=y){
            addRandomEdge(x,y,max_weight);
            edgesCount++;
        }
    }
}

bool GraphList::hasEdge(int x, int y) {
        for (const auto& edge : List[x]) {
            if (edge.first == y) {
                return true;
            }
        }
        return false;
}

void GraphList::addRandomEdge(int x,int y,int max_weight){
    int weight = rand() % max_weight + 1;
    addEdge(x,y,weight);
}

void GraphList::dijkstra(int source,bool show_resoult){
    if(source==-1){
        srand(time(nullptr));
        source=rand() % V;
    }

    vector<int> distance(V, numeric_limits<int>::max()); // Tablica koszt�w dotarcia do wierzcho�k�w
    vector<bool> visited(V, false); // Tablica odwiedzonych wierzcho�k�w
    PriorityQueue pq; // Kolejka priorytetowa

    distance[source] = 0; // Koszt dotarcia do �r�d�owego wierzcho�ka wynosi 0
    pq.push(0, source); // Dodaj �r�d�owy wierzcho�ek do kolejki

    while (!pq.empty()) {
        pair<int, int> top = pq.pop();
        int u = top.second;
        if (visited[u]) continue;
        visited[u] = true;

        // Iteracja przez s�siaduj�ce kraw�dzie wierzcho�ka u
        for (const pair<int, int>& edge : List[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Zaktualizuj koszt dotarcia do s�siaduj�cego wierzcho�ka v
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(distance[v], v); // Dodaj v do kolejki
            }
        }
    }

    // Wy�wietlenie wynik�w
    if(show_resoult){
        cout << "Najkrotsze sciezki z wierzcholka " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Do wierzcholka " << i << ": " << distance[i] << "\n";
    }
    }

}

 void GraphList::dijkstra_two(int source, int destination,bool show_resoult) {
    if(source==-1){
        srand(time(nullptr));
        source=rand() % V;
        destination=rand() % V;
    }
    int path = -1;
    vector<int> distance(V, numeric_limits<int>::max()); // Tablica koszt�w dotarcia do wierzcho�k�w
    vector<bool> visited(V, false); // Tablica odwiedzonych wierzcho�k�w

    distance[source] = 0; // Koszt dotarcia do �r�d�owego wierzcho�ka wynosi 0

    // W�asna implementacja kopca min-heap
    PriorityQueue pq;
    pq.push(0, source); // Dodaj �r�d�owy wierzcho�ek do kopca

    while (!pq.empty()) {
        int u = pq.pop().second; // Wybierz wierzcho�ek o najni�szym koszcie

        if (u == destination){
            path = distance[u];
            break;
        }

        if (visited[u]) continue;
        visited[u] = true; // Oznacz wierzcho�ek jako odwiedzony

        // Aktualizacja koszt�w dotarcia do s�siad�w wierzcho�ka u
        for (auto& neighbor : List[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!visited[v] && distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(distance[v], v); // Dodaj v do kopca
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
