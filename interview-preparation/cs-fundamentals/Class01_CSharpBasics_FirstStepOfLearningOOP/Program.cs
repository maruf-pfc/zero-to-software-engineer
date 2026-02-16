using System;

class Program
{
    static void Main(string[] args)
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
        // if value is y do something, if value is n do something else -> Install a program.
        
        if(args.Length > 0)
        {
            string arg = args[0];
            if(arg == "y")
            {
                Console.WriteLine("You chose yes.");
            }
            else if(arg == "n")
            {
                Console.WriteLine("You chose no.");
            }
            else
            {
                Console.WriteLine("Invalid argument. Please use 'y' or 'n'.");
            }
        }
        else
        {
            Console.WriteLine("No command-line arguments provided.");
        }

        int age = 25;
        switch (age)
        {
            // you can vote
            case int n when (n >= 18):
                Console.WriteLine("You can vote.");
                break;

            // you can drive
            case int n when (n >= 16):
                Console.WriteLine("You can drive.");
                break;  

            default:
                Console.WriteLine("You are too young to vote or drive.");
                break;
        }

        for(int i = 0; i < 5; i++)
        {
            Console.WriteLine($"For loop iteration: {i}");
        }

        int count = 0;
        while(count < 5)
        {
            Console.WriteLine($"While loop iteration: {count}");
            count++;
        }

        do
        {
            Console.WriteLine($"Do-while loop iteration: {count}");
            count++;
        } while(count < 10);

        foreach (char c in name)
        {
            Console.WriteLine($"Character in name: {c}");
        }

        int [,] grid = new int[3, 3]
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        string [,] str = new string[2, 2]
        {
            {"Alice", "Bob"},
            {"Charlie", "Dave"}
        };

        // random array sort
        int[] numbers = { 5, 2, 9, 1, 5, 6 };
        Array.Sort(numbers);
        Console.WriteLine("Sorted numbers: " + string.Join(", ", numbers));

        string name1 = "Alice";
        string name2 = "Bob";
        
        char[] chars = name1.ToCharArray();
        Array.Reverse(chars);
        Array.Sort(chars);
        Console.WriteLine("Sorted characters in name1: " + new string(chars));


        List<int> numbers = new List<int>();
        numbers.Add(1);
        numbers.Add(2);
        numbers.Add(3);
        
        foreach (int num in numbers)
        {
            Console.WriteLine($"Number in list: {num}");
        }

        numbers.Remove(2);
        Console.WriteLine("After removing 2:");
        foreach (int num in numbers)
        {
            Console.WriteLine($"Number in list: {num}");
        }

        Dictionary<string, int> marks = new Dictionary<string, int>();
        marks.Add("Math", 90);
        marks.Add("Science", 85);
        foreach (var subject in marks)
        {
            Console.WriteLine($"Subject: {subject.Key}, Marks: {subject.Value}");
        }

        marks.Remove("Math");
        Console.WriteLine("After removing Math:");
        foreach (var subject in marks)        {
            Console.WriteLine($"Subject: {subject.Key}, Marks: {subject.Value}");
        }

        // safe way
        if(marks.ContainsKey("Math"))
        {
            marks.Remove("Math");
        }

        // add a new subject
        if(!marks.ContainsKey("English"))
        {
            marks.Add("English", 88);
        }

        // not safe way
        marks["English"] = 88; // This will add English if it doesn't exist, or update it if it does.
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