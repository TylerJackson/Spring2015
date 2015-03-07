using System;
using System.Collections.Generic;

namespace HW.HW2
{
    public interface IHw2
    {
        Tuple<int, int> SumEvenAndOdd(List<int> input);

        List<int> ListElementsDivisibleBy3(List<int> input);

        List<int> ListElementsDivisibleBy3Recursive(List<int> input);

        List<int> ListElementsDivisibleBy3Iterative(List<int> input);
    }

}
