// The code assumes that the vertices are numbered from 0 to V-1. Make sure to input
// valid source and destination vertices within this range.

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 21

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(int parent[], int j, char loc[][50])
{
    // Base Case: If j is source
    if (parent[j] == -1)
    {
        printf("\e[38;2;255;105;105m%s\e[m ", loc[j]);
        return;
    }

    printPath(parent, parent[j], loc);

    printf("--> \e[38;2;255;105;105m%s\e[m ", loc[j]);
}

void printShortestPath(int parent[], int src, int dest, int dist[], char loc[][50])
{
    printf("Shortest Path from %d to %d: ", src, dest);
    printPath(parent, dest, loc);
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("\n");
    printf("Travel Distance: \e[38;2;255;105;105m%d km\e[m\n", dist[dest]);
    int avg_speed = 42;
    float time = (float)dist[dest] / avg_speed;
    time *= 60;
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("\n");
    printf("Travel Time: \e[38;2;255;105;105m%1.1f mins\e[m\n", time);
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("...............THANK YOU FOR USING METRO HELPER AUTOMATED SYSTEM...................................");
    printf("\n");
    printf("___________________________________________________________________________________________________");
}

void dijkstra(int graph[V][V], int src, int dest, char loc[][50])
{
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printShortestPath(parent, src, dest, dist, loc);
}

int main()
{
    int graph[V][V] = {{0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {6, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0},
                       {0, 14, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 7, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 3, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0},
                       {0, 0, 0, 0, 0, 9, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 6, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 7, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 23, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 4, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
    int src, dest;
    printf("__________________________________________________________________________________________________");
    printf("\n");
    printf("\n\e[1;4;38;2;255;255;0mWelcome to Metro-Helper Automated System !!!\e[m\n\n\tHere is the list of stations under Patna Metro, please take referrence from the list and enter the \e[38;2;255;105;105;3mIndex\e[0m corresponding to your source station and destination station to find the shortest route of travel and time taken for the journey.\n\n");

    char loc[21][50] = {{"Ara Jn."}, {"Jamira"}, {"Pali"}, {"Bihta"}, {"Patel Halt"}, {"Sadisopur"}, {"Goriya Dera"}, {"Danapur"}, {"Phulwari"}, {"Sachiwalay Halt"}, {"Patna Jn."}, {"Parsa Bazaar"}, {"Neema Halt"}, {"Jehanabad"}, {"Rajendra Nagar Tr."}, {"Patna Saheb"}, {"Dedarganj"}, {"Dak Bangla"}, {"Fraser Road"}, {"Bihar Mueseum"}, {"Patliputra Jn."}};
    printf("\n");
    printf("\n \n\e[38;2;0;255;0mIndex\tStation\e[m\n");

    for (int i = 0; i < 21; i++) // need to change this 21 to a standard #define statement later
    {
        printf("\e[38;2;79;192;208m%d.\e[m ->\t\e[38;2;79;192;208m%s\e[m\n", i, loc[i]);
    }
    printf("\n \n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("Enter source: \n");
    scanf("%d", &src);
    printf("\n");
    printf("___________________________________________________________________________________________________");
    printf("\n");
    printf("Enter destination: \n");
    scanf("%d", &dest);
    printf("\n");
    printf("____________________________________________________________________________________________________");
    printf("\n\n");
    dijkstra(graph, src, dest, loc);
    printf("\n\n\n");
    return 0;
}