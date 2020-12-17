using System;
using System.Collections.Generic;
using System.Text;

namespace _06_Hash
{
    public enum HashAlgorithm
    {
        Addchars,
        Polynomial,
        Horner
    }
    
    class HashTable
    {
        public static long Hash(string str)
        {
            HashAlgorithm ha = HashAlgorithm.Addchars;
            long hashVal = 0;
            switch (ha)
            {
                case HashAlgorithm.Addchars:
                    for (int i = 0; i < str.Length; i++)
                    {
                        hashVal += (long)str[i];
                    }

                    return hashVal;
                case HashAlgorithm.Polynomial:
                    int p = 31; // 알파벳 개수 26보다 큰 가장 작은 소수.
                    int m = (int)(1e9 + 9); // 적당히 큰 소수. 10^9+9

                    long powerOfP = 1;
                    for (int i = 0; i < str.Length; i++)
                    {
                        hashVal = (hashVal + (str[i] - 'a' + 1) * powerOfP) % m;
                        powerOfP = powerOfP * p % m;
                    }

                    return hashVal;
                case HashAlgorithm.Horner:
                    for (int i=0; i< str.Length; i++)
                    {
                        hashVal = (hashVal << 4) + str[i];
                        long g=hashVal & 0xF0000000L;
                        
                        if (!g.Equals(0))
                        {
                            hashVal ^= (long)((ulong)g >> 24);
                        }

                        hashVal &= ~g;
                    }

                    return hashVal;
                default:
                    break;
            }

            return 0;
        }
    }
}
