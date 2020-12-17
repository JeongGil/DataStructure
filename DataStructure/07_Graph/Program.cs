using System;
using System.Collections.Generic;

namespace _07_Graph
{
    class Program
    {
        static void Main(string[] args)
        {
            Node[] nodes = new Node[9];
            for (int i = 0; i < nodes.Length; i++)
            {
                nodes[i] = new Node();
                nodes[i].index = i;
                nodes[i].isVisit = false;
            }
            nodes[0].adjs.Add(nodes[1]);

            nodes[1].adjs.Add(nodes[0]);
            nodes[1].adjs.Add(nodes[2]);
            nodes[1].adjs.Add(nodes[3]);

            nodes[2].adjs.Add(nodes[1]);
            nodes[2].adjs.Add(nodes[4]);

            nodes[3].adjs.Add(nodes[1]);
            nodes[3].adjs.Add(nodes[4]);
            nodes[3].adjs.Add(nodes[5]);

            nodes[4].adjs.Add(nodes[2]);
            nodes[4].adjs.Add(nodes[3]);

            nodes[5].adjs.Add(nodes[3]);
            nodes[5].adjs.Add(nodes[6]);
            nodes[5].adjs.Add(nodes[7]);

            nodes[6].adjs.Add(nodes[5]);
            nodes[6].adjs.Add(nodes[8]);

            nodes[7].adjs.Add(nodes[5]);

            nodes[8].adjs.Add(nodes[6]);

            Graph.DFS(nodes[0]);
            //Graph.BFS(nodes[0]);
        }
    }
}
