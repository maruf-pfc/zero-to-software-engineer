public static class BasicExercise
{
    public static void Run(string[] args)
    {
        // 1. Print Hello and Name
        String myName = "Maruf";
        Console.WriteLine($"Hello, {myName}!");

        // 2. Sum of Two Numbers
        int num1 = 5;
        int num2 = 10;
        int sum = num1 + num2;
        Console.WriteLine($"The sum of {num1} and {num2} is: {sum}");

        // 3. Divide Two Numbers
        double dividend = 10;
        double divisor = 2;
        if (divisor != 0)
        {
            double quotient = dividend / divisor;
            Console.WriteLine($"The quotient of {dividend} divided by {divisor} is: {quotient}");
        }
        else
        {
            Console.WriteLine("Cannot divide by zero.");
        }

        // 4. Specified Operations Results
        Console.WriteLine($"-1 + 4 * 6 = {-1 + 4 * 6}");
        Console.WriteLine($"(35 + 5) % 7 = {(35 + 5) % 7}");
        Console.WriteLine($"14 + -4 * 6 / 11 = {14 + -4 * 6 / 11}");
        Console.WriteLine($"2 + 15 / 6 * 1 - 7 % 2 = {2 + 15 / 6 * 1 - 7 % 2}");

        // 5. Swap Two Numbers
        int a = 3;
        int b = 7;
        Console.WriteLine($"Before swapping: a = {a}, b = {b}");
        int temp = a;
        a = b;
        b = temp;
        Console.WriteLine($"After swapping: a = {a}, b = {b}");

        // 6. Multiply Three Numbers
        Console.WriteLine($"The product of 2, 3, and 6 is: {2 * 3 * 6}");

        // 7. Arithmetic Operations
        int x = 25;
        int y = 4;
        Console.WriteLine($"{x} + {y} = {x + y}");
        Console.WriteLine($"{x} - {y} = {x - y}");
        Console.WriteLine($"{x} x {y} = {x * y}");
        Console.WriteLine($"{x} / {y} = {x / y}");
        Console.WriteLine($"{x} mod {y} = {x % y}");

        // 8. Multiplication Table
        Console.Write("Enter a number to display its multiplication table: ");
        int number = int.Parse(Console.ReadLine());
        for (int i = 1; i <= 10; i++)
        {
            Console.WriteLine($"{number} x {i} = {number * i}");
        }

        // 9. Average of Four Numbers
        Console.WriteLine("Enter four numbers to calculate their average:");
        double numA = double.Parse(Console.ReadLine());
        double numB = double.Parse(Console.ReadLine());
        double numC = double.Parse(Console.ReadLine());
        double numD = double.Parse(Console.ReadLine());

        double average = (numA + numB + numC + numD) / 4;
        Console.WriteLine($"The average of {numA}, {numB}, {numC}, and {numD} is: {average}");

        // 10. Specified Formula with Three Numbers
        Console.WriteLine("Enter three numbers to calculate the specified formula:");
        double num1Formula = double.Parse(Console.ReadLine());
        double num2Formula = double.Parse(Console.ReadLine());
        double num3Formula = double.Parse(Console.ReadLine());

        double result = (num1Formula + num2Formula) * num3Formula;
        Console.WriteLine($"The result of the formula (num1 + num2) * num3 is: {result}");

        double result2 = (num1Formula * num2Formula) + (num2Formula * num3Formula);
        Console.WriteLine($"The result of the formula (num1 * num2) + (num2 * num3) is: {result2}");
    }
}