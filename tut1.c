#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define vertices 5
int graph[vertices][vertices];
#define inf INT_MAX

void create_graph(int src, int dest, int weight)
{

    graph[src][dest] = weight;
    graph[dest][src] = weight;
}

void bellman_ford(int src)
{

    int distance[vertices];

    for (int i = 0; i < vertices; i++)
    {
        distance[i] = inf;
    }

    distance[src] = 0;

    for (int k = 1; k <= vertices; k++)
    {

        for (int i = 0; i < vertices; i++)
        {

            for (int j = 0; j < vertices; j++)
            {

                if (graph[i][j] && distance[i] + graph[i][j] < distance[j])
                {
                    distance[j] = distance[i] + graph[i][j];
                }
            }
        }
    }
    // printing the distances from the vertex;
    for (int i = 0; i < vertices; i++)
    {

        printf("%d is the -->%d th distance from the vertex\n", distance[i], i);
    }
}

int main(){
    int src,dest,weight;
    for(int i=0;i<vertices;i++){

        printf("enter the src,dest and weight\n");

        scanf("%d%d%d",&src,&dest,&weight);

        create_graph(src,dest,weight);

    }
    bellman_ford(1);
    return 0;

}