using System;
using System.Collections.Generic;
using System.Text;

namespace _05_Recursive
{
    class Hanoi
    {
        private List<int> rodA = new List<int>();
        private List<int> rodB = new List<int>();
        private List<int> rodC = new List<int>();
        private int size;

        public void PrintTowers()
        {
            Console.Clear();

            Console.Write("A: ");
            foreach(var disk in rodA)
            {
                Console.Write("{0} ", disk);
            }
            Console.Write("\n");

            Console.Write("B: ");
            foreach (var disk in rodB)
            {
                Console.Write("{0} ", disk);
            }
            Console.Write("\n");

            Console.Write("C: ");
            foreach (var disk in rodC)
            {
                Console.Write("{0} ", disk);
            }
            Console.Write("\n");
        }

        public void Run()
        {
            Solve(rodA, rodC, rodB, size);
        }

        private void Move(List<int> src, List<int> dest)
        {
            string temp=Console.ReadLine();
            if (temp.Equals("x"))
            {
                Environment.Exit(0);
            }

            dest.Add(src[src.Count - 1]);
            src.RemoveAt(src.Count - 1);
            PrintTowers();
        }

        private void Solve(List<int> src, List<int> dest, List<int> temp, int n)
        {
            if (n.Equals(1))
            {
                Move(src, dest);
            }
            else
            {
                Solve(src, temp, dest, n - 1);
                Move(src, dest);
                Solve(temp, dest, src, n - 1);
            }
        }

        public Hanoi(int size)
        {
            if (size < 1)
            {
                size = 1;
            }
            this.size = size;

            for (; !size.Equals(0); size--)
            {
                rodA.Add(size);
            }
        }
    }
}
