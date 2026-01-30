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


            int[] numbers = new int[] {5, 2, 4, 3, 1};
            
            Array.Sort(numbers);

            foreach(int num in numbers)
            {
                Console.WriteLine("Number: " + num);
            }

            Array.Reverse(numbers);

            foreach(int num in numbers)
            {
                Console.WriteLine("Number: " + num);
            }

            string s = "Hello C#";
            Console.WriteLine("String s: " + s);

            // palindrome check
            string rev = "";
            char[] cArray = s.ToCharArray();
            Array.Reverse(cArray);
            rev = new string(cArray);
            Console.WriteLine("Reversed string: " + rev);

            if(s == rev)
            {
                Console.WriteLine("The string is a palindrome.");
            }
            else
            {
                Console.WriteLine("The string is not a palindrome.");
            }

            IList<int> list = new List<int>();

            list.Add(10);
            list.Add(20);
            list.Add(30);

            Console.WriteLine("Index 1 item: " + list[1]);
            foreach(int item in list)
            {
                Console.WriteLine("List item: " + item);
            }

            IList<string> strList = new List<string>() {"apple", "banana", "cherry"};

            foreach(string fruit in strList)
            {
                Console.WriteLine("Fruit: " + fruit);
            }

            Dictionary<string, int> dict = new Dictionary<string, int>();
            dict["one"] = 1;
            dict["two"] = 2;
            dict["three"] = 3;

            foreach(var kvp in dict)
            {
                Console.WriteLine("Key: " + kvp.Key + ", Value: " + kvp.Value);
                Console.WriteLine($"Key: {kvp.Key}, Value: {kvp.Value}");
            }

            foreach(KeyValuePair<string, int> kvp in dict)
            {
                Console.WriteLine("Key: " + kvp.Key + ", Value: " + kvp.Value);
            }

            string[] key = new string[] {"red", "green", "blue"};
            int[] value = new int[] {1, 2, 3};

            for(int i = 0; i < key.Length; i++)
            {
                dict.Add(key[i], value[i]);
                // way 2
                // dict[key[i]] = value[i];
                // way 3
                // dict.TryAdd(key[i], value[i]);
                // way 4
                // dict.Append(new KeyValuePair<string, int>(key[i], value[i]));
            }

            foreach(var kvp in dict)
            {
                Console.WriteLine("Key: " + kvp.Key + ", Value: " + kvp.Value);
            }

            dict.Remove("two");
            Console.WriteLine("After removing key 'two':");
            foreach(var kvp in dict)
            {
                Console.WriteLine("Key: " + kvp.Key + ", Value: " + kvp.Value);
            }
        }

        static int Add(int x, int y)
        {
            return x + y;
        }
    }
}
