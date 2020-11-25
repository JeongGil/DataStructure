using System;

namespace _05_Recursive
{
    class Program
    {
        static void Main(string[] args)
        {
            #region Fibonacci
            for (uint i = 1; i < 10; i++)
            {
                Console.Write("{0}, ", Fibonacci_Recursive(i));
            }
            Console.Write("\n");

            for (uint i = 1; i < 10; i++)
            {
                Console.Write("{0}, ", Fibonacci_NonRecursive(i));
            }
            Console.WriteLine("\n");
            #endregion

            #region Hanoi
            Console.Write("Input the number of disks: ");
            int diskCount = Convert.ToInt32(Console.ReadLine());
            Hanoi hanoi = new Hanoi(diskCount);

            hanoi.PrintTowers();

            hanoi.Run();
            #endregion
        }

        static uint Fibonacci_Recursive(uint index)
        {
            if (index.Equals(1) || index.Equals(2))
            {
                return 1;
            }

            return Fibonacci_Recursive(index - 2) + Fibonacci_Recursive(index - 1);
        }

        static uint Fibonacci_NonRecursive(uint index)
        {
            if (index.Equals(1) || index.Equals(2))
            {
                return 1;
            }

            uint a2 = 1;
            uint a1 = 1;
            uint a0;
            uint counter = 3;
            while (true)
            {
                a0 = a2 + a1;
                if (counter.Equals(index))
                {
                    return a0;
                }
                else
                {
                    a2 = a1;
                    a1 = a0;

                    counter++;
                }
            }
        }
    }
}
