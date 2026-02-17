using System;
using System.Collections.Generic;

public static class ClassNotes
{
    public static void Run(string[] args)
    {
        Console.WriteLine("Hello, World!");

        Add(1, 2);

        int res = Subtract(5, 3);
        Console.WriteLine(res);

        // Data Types
        int a = 10;
        double b = 3.14;
        string name = "Alice";
        bool isActive = true;

        Console.WriteLine($"Integer: {a}, Double: {b}, String: {name}, Boolean: {isActive}");

        // Args
        Console.WriteLine("Command-line arguments:");

        if (args.Length > 0)
        {
            string arg = args[0];

            if (arg == "y")
                Console.WriteLine("You chose yes.");
            else if (arg == "n")
                Console.WriteLine("You chose no.");
            else
                Console.WriteLine("Invalid argument. Please use 'y' or 'n'.");
        }
        else
        {
            Console.WriteLine("No command-line arguments provided.");
        }

        int age = 25;
        switch (age)
        {
            case int n when n >= 18:
                Console.WriteLine("You can vote.");
                break;

            case int n when n >= 16:
                Console.WriteLine("You can drive.");
                break;

            default:
                Console.WriteLine("Too young.");
                break;
        }

        for (int i = 0; i < 5; i++)
            Console.WriteLine($"For loop: {i}");

        int count = 0;
        while (count < 5)
        {
            Console.WriteLine($"While loop: {count}");
            count++;
        }

        do
        {
            Console.WriteLine($"Do-while: {count}");
            count++;
        } while (count < 10);

        foreach (char c in name)
            Console.WriteLine(c);

        int[,] grid =
        {
            {1,2,3},
            {4,5,6},
            {7,8,9}
        };

        int[] arr = { 5, 2, 9, 1, 6 };
        Array.Sort(arr);
        Console.WriteLine(string.Join(", ", arr));

        char[] chars = name.ToCharArray();
        Array.Sort(chars);
        Console.WriteLine(new string(chars));

        List<int> list = new() { 1, 2, 3 };
        list.Remove(2);

        foreach (var n in list)
            Console.WriteLine(n);

        Dictionary<string, int> marks = new()
        {
            { "Math", 90 },
            { "Science", 85 }
        };

        if (!marks.ContainsKey("English"))
            marks["English"] = 88;

        foreach (var m in marks)
            Console.WriteLine($"{m.Key}: {m.Value}");
    }

    public static void Add(int a, int b)
    {
        Console.WriteLine(a + b);
    }

    public static int Subtract(int a, int b)
    {
        return a - b;
    }
}
