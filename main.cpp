#include <iostream>
#include <vector>
using namespace std;
//Solar Sales Travel Project
//Locations as follows:
//1. Riverside
//2. Moreno Valley
//3. Perris
//4. Hemet

 //for both options 2 & 3
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
//2nd option?
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacent Cities " << v;
        for (auto x: adj[v])
          cout << " -> " << x;
        printf("\n");
    }
}
//2nd option
void printGraph1(vector<int> adj[], int V)
{
      for (int v = 1; v < V; ++v)
      {
          cout << "\n The following is the shortest route: " << v; 
          for (auto x: adj[v])
            cout << " -> " << x;  
            cout << "\n with 96 miles total. ";
          printf("\n");
      }
}
//options 3 & 4
struct Node {
    int val, cost;
    Node* next;
};


struct Edge {
    int src, dest, weight;
};


class Graph
{

  Node* getadjLlistNode(int value, int weight, Node* head)
  {
    Node* newNode = new Node;
    newNode ->val = value; 
    newNode ->cost = weight;
    newNode ->next = head;

  return newNode;
  }
  int N; 

public:
Node **head;

Graph(Edge edges[], int n, int N)
{
  head = new Node*[N]();
  this->N = N;

  for (int i = 0; i < N; i++)
  head[i] = nullptr;

  for (unsigned i = 0; i < n; i++)
  {
  int src = edges[i].src;
  int dest = edges[i].dest;
  int weight = edges[i].weight;
  Node* newNode = getadjLlistNode(dest, weight, head[src]);

  head[src] = newNode;

  newNode = getadjLlistNode(src, weight, head[dest]);
  head[dest] = newNode;

  }
}
~Graph()
  {
  for (int i = 0; i < N; i++)
    delete[] head[i];
    delete[] head;
  }
};  

//Option 3 & 4
void printList(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << " -> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

//Option 4
void printList(Node* ptr, int i)
{
  while (ptr != nullptr)
  {
    cout << "(" << i << ", " << ptr->val
          << ", " << ptr->cost << " Miles) ";

    ptr = ptr->next;
  }
      cout << endl;
}
// Driver code
int main() 
{
  int answer,
      option;

      cout << "Please choose an option from " << endl;
      cout << "those below! " << endl; 
  cout<< "1. Possible Routes " << endl;
  cout<< "2. Route with least miles " << endl;
  cout<< "3. Adjacent Cities " << endl;
  cout<< "4. Distance between Cities " << endl;
  cin >> option;

    if (option <= 0 || option >= 5)
    {
      cout << "Not a possible option, please try another from 1-4. " << endl;
      cin >> option;
    }

    //1st option
    if (option == 1)
    {
        cout << "\nPossible routes (Variations): " << endl << "1. Riverside, 2.Moreno Valley, " << endl;
        cout << "3.Hemet, 4.Perris" << endl;

        Edge edges[] =

        {
          {1,2}, {1,3}, {1,4}, {3,4}, {3,2}, {4,2}
        };

        int N = 5;
        int n = sizeof(edges)/sizeof(edges[0]);
        Graph graph(edges, n, N);
        for (int i = 1; i < N; i++)
        {
              cout << i;
              printList(graph.head[i]);
        }
        cin >> option;
    }
    //2nd option
    if (option == 2)
    {
      cout << "Shortest Path: " << endl;

      cout << "\n1. Riverside, 2. Moreno Valley," << endl;
      cout << "3. Hemet, 4. Perris" << endl;
          int V = 5;
          vector<int> adj[V];
          addEdge(adj, 1, 2);
          addEdge(adj, 1, 3);
          addEdge(adj, 1, 4);
          printGraph1(adj, V);

          cin >> option;
    }

    //3rd option
    if (option == 3)
    { cout << "Adjacent Cities: \n"; 
      cout<< "\n1. Riverside, 2. Moreno Valley," << endl;
      cout << "3. Hemet, 4. Perris" << endl;
      Edge edges[]= 
      {
      {1, 2}, {1, 3}, {1,4}, {2,3}, {2,4}, {3,4}, 
      };
      int N = 4;
      int n = sizeof(edges)/sizeof(edges[0]);

      Graph graph(edges, n, N);

      for (int i = 1; i < N; i++)
      {
        cout << i << " --";
        printList(graph.head[i]);
      }
   
  
    cin >> option;
    }
    //4th option
    if (option == 4)
    {
        cout << "Cities: " << endl << "\n1. Riverside, 2. Moreno Valley," << endl;
        cout << "3. Hemet, 4. Perris" << endl;
        Edge edges[] = 
        { 
          
          {1,2,16}, {1,3,33}, {1,4,24}, {2,3,26}, {3,4,30}, {4,2,18}

        };
        
        int N = 5;

       
        int n = sizeof(edges)/sizeof(edges[0]);

        Graph graph(edges, n, N);
        for (int i = 1; i < N; i++)
        {
          printList(graph.head[i], i );
        }
        cin >> option;

    }
  return 0;
  
} 