using System;
using System.Collections.Generic;

class TeleportTubes
{
    static int n, m, cnt;
    static int[] col;
    static bool[] v, isk, flag;
    static List<int>[] e, e1;

    static void DFS(int x)
    {
        col[x] = cnt;
        foreach (int y in e1[x])
        {
            if (col[y] == 0)
            {
                DFS(y);
            }
        }
    }

    static void DFS1(int x)
    {
        v[x] = isk[x] = true;
        foreach (int y in e[x])
        {
            if (!v[y])
            {
                DFS1(y);
            }
            else
            {
                flag[col[y]] |= isk[y];
            }
        }
        isk[x] = false;
    }

    static void Main(string[] args)
    {
        string[] firstLine = Console.ReadLine().Split();
        n = int.Parse(firstLine[0]);
        m = int.Parse(firstLine[1]);

        // Initialize adjacency lists
        e = new List<int>[n + 1];
        e1 = new List<int>[n + 1];
        for (int i = 1; i <= n; i++)
        {
            e[i] = new List<int>();
            e1[i] = new List<int>();
        }

        // Read in teleportation pairs
        for (int i = 0; i < m; i++)
        {
            string[] line = Console.ReadLine().Split();
            int x = int.Parse(line[0]);
            int y = int.Parse(line[1]);
            e[x].Add(y);
            e1[x].Add(y);
            e1[y].Add(x);
        }

        // Initialize arrays
        col = new int[n + 1];
        v = new bool[n + 1];
        isk = new bool[n + 1];
        flag = new bool[n + 1];

        // Use DFS to find the answer
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == 0)
            {
                cnt++;
                DFS(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!v[i])
            {
                DFS1(i);
            }
        }
        for (int i = 1; i <= cnt; i++)
        {
            n += (flag[i] ? 1 : 0);
        }

        Console.WriteLine(n - cnt);
    }
}