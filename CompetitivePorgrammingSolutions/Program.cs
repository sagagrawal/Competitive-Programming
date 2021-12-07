using System;
using System.Collections.Generic;
using System.Linq;

namespace CompetitivePorgrammingSolutions
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> test = new List<int>();
            test.Add(8);
            test.Add(4);
            test.Add(5);
            test.Add(4);
            test.Add(8);

            Console.WriteLine($"Max SubSequence in test List is: {getMaxSubsequenceCount(test)}");
        }

        static int getMaxSubsequenceCount(List<int> input)
        {
            int maxSubSeq = 0;
            List<List<int>> subSequences = new List<List<int>>();
            int counter = 0;
            input.Sort();

            for (int i = 0; i < input.Count; i++)
            {
                if (counter == 0)
                {
                    subSequences.Add(new List<int>());
                }
                if (subSequences.ElementAt(counter).Count > 0)
                {
                    if (input.ElementAt(i) - subSequences.ElementAt(counter).Last() <= 1)
                    {
                        subSequences.ElementAt(counter).Add(input.ElementAt(i));
                    }
                    else
                    {
                        counter++;
                        subSequences.Add(new List<int>());
                        subSequences.ElementAt(counter).Add(input.ElementAt(i));
                    }
                }
                else
                {
                    subSequences.ElementAt(counter).Add(input.ElementAt(i));
                }
            }

            foreach (List<int> item in subSequences)
            {
                if (item.Count > maxSubSeq)
                    maxSubSeq = item.Count;
            }

            return maxSubSeq;
        }
    }
}
