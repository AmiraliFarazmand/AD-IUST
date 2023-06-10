using System;

class MaximumBipartiteMatching
{
  private int M; // Number of vertices in the first partition
  private int N; // Number of vertices in the second partition
  private bool[,] graph;

  public MaximumBipartiteMatching(int n, int m)
  {
    M = m;
    N = n;
    graph = new bool[M, N];
  }

  // Add an edge from vertex u in the first partition to vertex v in the second partition
  public void AddEdge(int u, int v)
  {
    graph[u, v] = true;
  }

  // Ford-Fulkerson algorithm for finding the maximum bipartite matching
  private bool DFS(int u, bool[] visited, int[] matchR)
  {
    for (int v = 0; v < N; v++)
    {
      if (graph[u, v] && !visited[v])
      {
        visited[v] = true;

        if (matchR[v] == -1 || DFS(matchR[v], visited, matchR))
        {
          matchR[v] = u;
          return true;
        }
      }
    }
    return false;
  }

  public int[] FindMaximumMatching()
  {
    int[] matchR = new int[N];
    bool[] visited = new bool[N];
    for (int i = 0; i < N; i++)
    {
      matchR[i] = -1;
    }

    for (int u = 0; u < M; u++)
    {
      for (int i = 0; i < N; i++)
      {
        visited[i] = false;
      }

      DFS(u, visited, matchR);
    }

    return matchR;
  }

  public static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split();
    int n = int.Parse(input[0]);
    int m = int.Parse(input[1]);

    MaximumBipartiteMatching matching = new MaximumBipartiteMatching(n, m);

    for (int i = 0; i < n; i++)
    {
      input = Console.ReadLine().Split();
      for (int j = 0; j < m; j++)
      {
        int value = int.Parse(input[j]);
        if (value == 1)
        {
          matching.AddEdge(j, i);
        }
      }
    }

    int[] result = matching.FindMaximumMatching();

    for (int i = 0; i < n; i++)
    {
      if (result[i] != -1)
      {
        Console.Write((result[i] + 1) + " ");
      }
      else
      {
        Console.Write("-1 ");
      }
    }
    Console.WriteLine();
  }
}