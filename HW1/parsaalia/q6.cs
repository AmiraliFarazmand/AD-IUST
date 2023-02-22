using System;
using System.Collections.Generic;
using System.Text;

namespace A7
{
    public class Q3MaximizingArithmeticExpression
    {
        public static long Solve(string expression)
        {
            List<int> numbers = new List<int>();
            List<char> operators = new List<char>();
            for (int i = 0; i < expression.Length; i += 2)
            {
                numbers.Add(int.Parse(expression[i].ToString()));
                if(i+1<expression.Length)
                {
                    operators.Add(expression[i + 1]);
                }

            }

            long[][] answer = new long[numbers.Count][];

            for (int i = 0; i < numbers.Count; i++)
            {
                answer[i] = new long[numbers.Count ];
                answer[i][i] = numbers[i];
            }

            for (int i = 1; i < numbers.Count; i++)
            {
                for (int j = 0; j < numbers.Count; j++)
                {
                    if(j+i<numbers.Count)
                    {
                        answer[j][j + i] = MaxMake(j, j + i, numbers, operators,answer);
                        answer[j + i][j] = MinMake(j, j + i, numbers, operators,answer);
                    }
                }
            }
            return answer[0][numbers.Count - 1];

        }


        private static long MaxMake(int first, int final, List<int> numbers, List<char> operators,long[][]answer)
        {
            long MaxValue = long.MinValue;
            
            for(int i=first;i<final;i++)
            {
                if (Operation(answer[first][i], answer[i + 1][final],i,operators) > MaxValue)
                    MaxValue = Operation(answer[first][i], answer[i + 1][final],i,operators);

                if (Operation(answer[i][first], answer[i + 1][final], i, operators) > MaxValue)
                    MaxValue = Operation(answer[i][first], answer[i + 1][final], i, operators);

                if (Operation(answer[first][i], answer[final][i+1], i, operators) > MaxValue)
                    MaxValue = Operation(answer[first][i], answer[final][i+1], i, operators);

                if (Operation(answer[i][first], answer[final][i+1], i, operators) > MaxValue)
                    MaxValue = Operation(answer[i][first], answer[final][i+1], i, operators);


                
            }
            return MaxValue;
            
        }

        private static long Operation(long v1, long v2, int i,List<char> operators)
        {
            if (operators[i] == '+')
                return v1 + v2;
            if (operators[i] == '*')
                return v1 * v2;
            if (operators[i] == '-')
                return v1 - v2;
            return 0;
        }

        private static long MinMake(int first, int final, List<int> numbers, List<char> operators,long [][]answer)
        {
            long MinValue = int.MaxValue;
            for (int i = first; i < final; i++)
            {
                if (Operation(answer[first][i], answer[i + 1][final], i, operators) < MinValue)
                    MinValue = Operation(answer[first][i], answer[i + 1][final], i, operators);

                if (Operation(answer[i][first], answer[i + 1][final], i, operators) < MinValue)
                    MinValue = Operation(answer[i][first], answer[i + 1][final], i, operators);

                if (Operation(answer[first][i], answer[final][i + 1], i, operators) <MinValue)
                    MinValue = Operation(answer[first][i], answer[final][i + 1], i, operators);

                if (Operation(answer[i][first], answer[final][i + 1], i, operators) <MinValue)
                    MinValue = Operation(answer[i][first], answer[final][i + 1], i, operators);

            }
            return MinValue;
        }
        static void Main(string[] args)
        {
            //creating object of class Program
            string expression = Console.ReadLine();
            Console.WriteLine(Q3MaximizingArithmeticExpression.Solve(expression));
        }
    }
}
