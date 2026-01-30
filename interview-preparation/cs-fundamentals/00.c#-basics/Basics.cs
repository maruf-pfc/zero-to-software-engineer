using System;

namespace CsFundamentals
{
    public static class Basics
    {
        public static void Run()
        {
            Console.WriteLine("Hello, World!");

            int a = 10, b = 20, c = 30;

            // Data types and variables
            Console.WriteLine("Integer a: " + a);
            double pi = 3.14;
            Console.WriteLine("Double pi: " + pi);
            string message = "C# Basics";
            Console.WriteLine("String message: " + message);
            bool isTrue = true;
            Console.WriteLine("Boolean isTrue: " + isTrue);
            char letter = 'A';
            Console.WriteLine("Character letter: " + letter);
            float floatNum = 5.5f;
            Console.WriteLine("Float floatNum: " + floatNum);
            long bigNum = 123456789L;
            Console.WriteLine("Long bigNum: " + bigNum);
            decimal decimalNum = 99.99m;
            Console.WriteLine("Decimal decimalNum: " + decimalNum);
            byte byteNum = 255;
            Console.WriteLine("Byte byteNum: " + byteNum);
            short shortNum = 32767;
            Console.WriteLine("Short shortNum: " + shortNum);
            

            if(a < b && b < c) Console.WriteLine("a < b < c");
            else if(a > b && b > c) Console.WriteLine("a > b > c");
            else Console.WriteLine("No relation");

            for(int i = 0; i < 5; i++)
            {
                Console.WriteLine("Iteration: " + i);
            }

            int count = 0;
            while(count < 3)
            {
                Console.WriteLine("Count: " + count);
                count++;
            }

            int result = Add(a, b);
            Console.WriteLine("Sum of a and b: " + result);
        }

        static int Add(int x, int y)
        {
            return x + y;
        }

    }
}
