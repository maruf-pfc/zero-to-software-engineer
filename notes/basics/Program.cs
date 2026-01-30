using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
// using Basics.OOP;
// ===============================
// C# COOKBOOK
// ===============================

// This file is intentionally BIG.
// Treat it like a cookbook, not a library.

class Program
{
    static async Task Main()
    {
        Console.WriteLine("=== C# Cookbook ===\n");

        Basics();
        Decisions();
        Loops();
        MethodsDemo();
        ClassesAndObjects();
        EncapsulationDemo();
        InheritanceDemo();
        InterfaceDemo();
        CollectionsDemo();
        LinqDemo();
        ExceptionDemo();
        FileDemo();
        await AsyncDemo();

        Console.WriteLine("\n=== End of Cookbook ===");
    }

    // -------------------------------
    // 1. BASICS & TYPES
    // -------------------------------
    static void Basics()
    {
        Console.WriteLine("\n-- Basics & Types --");

        int orderId = 1001;
        string customer = "Maruf";
        bool isPaid = true;
        decimal amount = 2499.50m;
        DateTime created = DateTime.Now;

        Console.WriteLine($"Order {orderId} for {customer}");
        Console.WriteLine($"Paid: {isPaid}, Amount: {amount}");
        Console.WriteLine($"Created: {created}");

        var city = "Dhaka";          // inferred type
        const decimal Vat = 0.15m;   // constant business rule

        Console.WriteLine($"City: {city}, VAT: {Vat}");
    }

    // -------------------------------
    // 2. DECISIONS
    // -------------------------------
    static void Decisions()
    {
        Console.WriteLine("\n-- Decisions --");

        decimal total = 3200m;

        if (total >= 3000)
            Console.WriteLine("Free delivery");
        else
            Console.WriteLine("Delivery fee applied");

        string message = total >= 3000 ? "Free delivery" : "Delivery fee applied";
        Console.WriteLine(message);

        string status = "Shipped";
        switch (status)
        {
            case "Pending": Console.WriteLine("Order pending"); break;
            case "Shipped": Console.WriteLine("Order on the way"); break;
            default: Console.WriteLine("Unknown status"); break;
        }
    }

    // -------------------------------
    // 3. LOOPS
    // -------------------------------
    static void Loops()
    {
        Console.WriteLine("\n-- Loops --");

        string[] cart = { "Laptop", "Mouse", "Keyboard" };

        for (int i = 0; i < cart.Length; i++)
            Console.WriteLine(cart[i]);

        foreach (var item in cart)
            Console.WriteLine($"Item: {item}");

        int retry = 0;
        while (retry < 3)
        {
            Console.WriteLine("Retrying payment...");
            retry++;
        }
    }

    // -------------------------------
    // 4. METHODS
    // -------------------------------
    static void MethodsDemo()
    {
        Console.WriteLine("\n-- Methods --");

        Console.WriteLine(CalculateDiscount(5000));
        Console.WriteLine(Add(10, 20));
        Console.WriteLine(Add(10.5m, 20.5m));
    }

    static decimal CalculateDiscount(decimal amount) => amount * 0.10m;
    static int Add(int a, int b) => a + b;
    static decimal Add(decimal a, decimal b) => a + b;

    // -------------------------------
    // 5. CLASSES & OBJECTS
    // -------------------------------
    static void ClassesAndObjects()
    {
        Console.WriteLine("\n-- Classes & Objects --");

        Customer c = new Customer("Maruf", "maruf@mail.com");
        c.Notify();

        Product p = new Product("Laptop", 85000);
        Console.WriteLine($"{p.Name} costs {p.Price}");
    }

    // -------------------------------
    // 6. ENCAPSULATION
    // -------------------------------
    static void EncapsulationDemo()
    {
        Console.WriteLine("\n-- Encapsulation --");

        BankAccount acc = new BankAccount();
        acc.Deposit(5000);
        acc.Deposit(-100); // ignored
        Console.WriteLine($"Balance: {acc.Balance}");
    }

    // -------------------------------
    // 7. INHERITANCE
    // -------------------------------
    static void InheritanceDemo()
    {
        Console.WriteLine("\n-- Inheritance --");

        Employee e = new Employee();
        Employee d = new Developer();

        e.Work();
        d.Work();
    }

    // -------------------------------
    // 8. INTERFACES
    // -------------------------------
    static void InterfaceDemo()
    {
        Console.WriteLine("\n-- Interfaces --");

        IPaymentMethod payment = new CardPayment();
        payment.Pay(2000);
    }

    // -------------------------------
    // 9. COLLECTIONS
    // -------------------------------
    static void CollectionsDemo()
    {
        Console.WriteLine("\n-- Collections --");

        List<string> users = new() { "Maruf", "Rahim", "Karim" };
        users.ForEach(u => Console.WriteLine(u));

        Dictionary<int, string> orders = new();
        orders[101] = "Delivered";
        orders[102] = "Pending";

        foreach (var o in orders)
            Console.WriteLine($"Order {o.Key}: {o.Value}");
    }

    // -------------------------------
    // 10. LINQ
    // -------------------------------
    static void LinqDemo()
    {
        Console.WriteLine("\n-- LINQ --");

        int[] prices = { 500, 1500, 3000, 7000 };

        var expensive = prices.Where(p => p > 2000);
        foreach (var p in expensive)
            Console.WriteLine(p);
    }

    // -------------------------------
    // 11. EXCEPTIONS
    // -------------------------------
    static void ExceptionDemo()
    {
        Console.WriteLine("\n-- Exceptions --");

        try
        {
            int value = int.Parse("abc");
        }
        catch (FormatException)
        {
            Console.WriteLine("Invalid number format");
        }
        finally
        {
            Console.WriteLine("Exception demo finished");
        }
    }

    // -------------------------------
    // 12. FILE I/O
    // -------------------------------
    static void FileDemo()
    {
        Console.WriteLine("\n-- File I/O --");

        File.WriteAllText("log.txt", "Order created");
        string log = File.ReadAllText("log.txt");
        Console.WriteLine(log);
    }

    // -------------------------------
    // 13. ASYNC / AWAIT
    // -------------------------------
    static async Task AsyncDemo()
    {
        Console.WriteLine("\n-- Async / Await --");
        await Task.Delay(1000);
        Console.WriteLine("Async operation completed");
    }
}

// ===============================
// SUPPORTING TYPES
// ===============================

class Customer
{
    public string Name { get; }
    public string Email { get; }

    public Customer(string name, string email)
    {
        Name = name;
        Email = email;
    }

    public void Notify()
    {
        Console.WriteLine($"Notification sent to {Name}");
    }
}

class Product
{
    public string Name { get; }
    public decimal Price { get; }

    public Product(string name, decimal price)
    {
        Name = name;
        Price = price;
    }
}

class BankAccount
{
    private decimal balance;
    public decimal Balance => balance;

    public void Deposit(decimal amount)
    {
        if (amount > 0)
            balance += amount;
    }
}

class Employee
{
    public virtual void Work()
    {
        Console.WriteLine("Employee working");
    }
}

class Developer : Employee
{
    public override void Work()
    {
        Console.WriteLine("Developer writing code");
    }
}

interface IPaymentMethod
{
    void Pay(decimal amount);
}

class CardPayment : IPaymentMethod
{
    public void Pay(decimal amount)
    {
        Console.WriteLine($"Paid {amount} using card");
    }
}
