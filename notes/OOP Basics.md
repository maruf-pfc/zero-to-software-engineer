using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

// ==================================================
// C# COOKBOOK — OOP ONLY (SINGLE RUNNABLE FILE)
// ==================================================
// Focus: Object-Oriented Programming
// NO procedural demos, everything through objects

class Program
{
    static async Task Main()
    {
        Console.WriteLine("=== OOP-Only C# Cookbook ===\n");

        // 1. Object creation & encapsulation
        Customer customer = new Customer("Maruf", "maruf@mail.com");

        // 2. Composition (Order HAS products)
        Order order = new Order(customer);
        order.AddItem(new Product("Laptop", 85000));
        order.AddItem(new Product("Mouse", 1500));

        // 3. Polymorphism via interface
        IPaymentMethod payment = new CardPayment();
        await order.CheckoutAsync(payment);

        // 4. Inheritance + polymorphism
        Employee emp1 = new Developer("Rahim");
        Employee emp2 = new Manager("Karim");

        emp1.Work();
        emp2.Work();

        // 5. Encapsulation & domain rules
        BankAccount account = new BankAccount();
        account.Deposit(10000);
        account.Withdraw(3000);

        Console.WriteLine($"Final balance: {account.Balance}");

        Console.WriteLine("\n=== End of OOP Cookbook ===");
    }
}

// ==================================================
// DOMAIN MODELS
// ==================================================

// ------------------------------
// 1. ENCAPSULATION
// ------------------------------
class BankAccount
{
    private decimal balance;

    public decimal Balance => balance;

    public void Deposit(decimal amount)
    {
        if (amount <= 0)
            throw new ArgumentException("Deposit must be positive");

        balance += amount;
    }

    public void Withdraw(decimal amount)
    {
        if (amount > balance)
            throw new InvalidOperationException("Insufficient balance");

        balance -= amount;
    }
}

// ------------------------------
// 2. ENTITY + CONSTRUCTOR
// ------------------------------
class Customer
{
    public string Name { get; }
    public string Email { get; }

    public Customer(string name, string email)
    {
        Name = name;
        Email = email;
    }

    public void Notify(string message)
    {
        Console.WriteLine($"Notify {Name}: {message}");
    }
}

// ------------------------------
// 3. VALUE OBJECT
// ------------------------------
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

// ------------------------------
// 4. COMPOSITION (HAS-A)
// ------------------------------
class Order
{
    private readonly List<Product> items = new();
    private readonly Customer customer;

    public Order(Customer customer)
    {
        this.customer = customer;
    }

    public void AddItem(Product product)
    {
        items.Add(product);
    }

    public decimal TotalAmount()
    {
        return items.Sum(p => p.Price);
    }

    public async Task CheckoutAsync(IPaymentMethod paymentMethod)
    {
        decimal total = TotalAmount();
        await paymentMethod.PayAsync(total);
        customer.Notify($"Order placed. Total: {total}");
    }
}

// ------------------------------
// 5. INTERFACE (ABSTRACTION)
// ------------------------------
interface IPaymentMethod
{
    Task PayAsync(decimal amount);
}

class CardPayment : IPaymentMethod
{
    public async Task PayAsync(decimal amount)
    {
        await Task.Delay(1000);
        Console.WriteLine($"Paid {amount} using Card");
    }
}

class MobilePayment : IPaymentMethod
{
    public async Task PayAsync(decimal amount)
    {
        await Task.Delay(1000);
        Console.WriteLine($"Paid {amount} using Mobile Payment");
    }
}

// ------------------------------
// 6. INHERITANCE + POLYMORPHISM
// ------------------------------
abstract class Employee
{
    public string Name { get; }

    protected Employee(string name)
    {
        Name = name;
    }

    public abstract void Work();
}

class Developer : Employee
{
    public Developer(string name) : base(name) { }

    public override void Work()
    {
        Console.WriteLine($"{Name} writes code");
    }
}

class Manager : Employee
{
    public Manager(string name) : base(name) { }

    public override void Work()
    {
        Console.WriteLine($"{Name} manages the team");
    }
}

// ------------------------------
// 7. OPEN/CLOSED PRINCIPLE
// ------------------------------
// Add new payment methods or employee types
// WITHOUT modifying existing code

This file is now **pure OOP — no procedural teaching, no syntax demos**, only **real object-driven design**, exactly how C# is used in real systems.

### What this OOP-only cookbook teaches (implicitly)

You’re not *told* OOP rules — you **see them in action**:

| Concept       | Where it appears                       |
| ------------- | -------------------------------------- |
| Encapsulation | `BankAccount` protects its balance     |
| Abstraction   | `IPaymentMethod`                       |
| Inheritance   | `Employee → Developer / Manager`       |
| Polymorphism  | `Employee` & `IPaymentMethod` usage    |
| Composition   | `Order` **has** `Product` & `Customer` |
| Immutability  | `Product`, `Customer`                  |
| Async OOP     | `CheckoutAsync()`                      |

This is **enterprise-grade thinking**, not tutorial thinking.

### How to study this file (important)

Do **not** read top to bottom.

Instead:

1. Pick **one class**
2. Ask:

   * Why is this `private`?
   * Why constructor instead of setters?
   * Why interface here?
3. Change **one thing**, re-run, observe behavior

Example exercises:

* Add `CashPayment` **without touching existing code**
* Add `Admin` employee
* Prevent order checkout if no items
* Add `OrderStatus` enum

If you can do those, you *understand* OOP.
