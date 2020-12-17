using System;
using System.Collections.Generic;
using System.Text;

namespace _07_Graph
{
    class Node
    {
        public int index { get; set; }
        public bool isVisit { get; set; }
        public List<Node> adjs = new List<Node>();
    }
    class Graph
    {
        public static void DFS(Node start)
        {
            Stack<Node> stack = new Stack<Node>();
            stack.Push(start);
            start.isVisit = true;
            while (stack.Count > 0)
            {
                Node curNode = stack.Pop();
                foreach (var node in curNode.adjs)
                {
                    if (!node.isVisit)
                    {
                        stack.Push(node);
                        node.isVisit = true;
                    }
                }

                Console.WriteLine(curNode.index);
            }
        }

        public static void BFS(Node start)
        {
            Queue<Node> queue = new Queue<Node>();
            queue.Enqueue(start);
            while (queue.Count > 0)
            {
                Node curNode = queue.Dequeue();
                foreach (var node in curNode.adjs)
                {
                    if (!node.isVisit)
                    {
                        queue.Enqueue(node);
                        curNode.isVisit = true;
                    }
                }

                Console.WriteLine(curNode.index);
            }
        }
    }
}
