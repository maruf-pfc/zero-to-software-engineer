# C# COOKBOOK — FROM SCRATCH

_A real‑world, example‑driven guide to the entire C# language_

> Goal: Read this like a **cookbook**. Each section shows:
>
> - a real‑world problem
> - multiple ways to solve it in C#
> - why one way is better than another

---

## 1. How a C# Program Actually Runs

### Mental model (real world)

- **Project** → Company
- **Main method** → Office opening time
- **Methods** → Departments doing work

```csharp
using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Application started");
    }
}
```

### Modern C# (same thing, cleaner)

```csharp
Console.WriteLine("Application started");
```

Use this when:

- small tools
- scripts
- learning

---

## 2. Variables & Types (Real Business Data)

### Example: Online order

```csharp
int orderId = 501;
string customer = "Maruf";
bool isConfirmed = true;
decimal totalAmount = 3499.75m;
DateTime createdAt = DateTime.Now;
```

### Same thing – different styles

```csharp
var orderId = 501;           // compiler decides type
const decimal Vat = 0.15m;  // cannot change
```

**Rule of thumb**

- `var` → when type is obvious
- `const` → business rules
- `decimal` → money (never float/double)

---

## 3. Decisions (Business Rules)

### Example: Delivery charge

```csharp
if (totalAmount >= 3000)
{
    Console.WriteLine("Free delivery");
}
else
{
    Console.WriteLine("Delivery fee applied");
}
```

### Same logic – ternary (compact)

```csharp
string delivery = totalAmount >= 3000
    ? "Free delivery"
    : "Delivery fee applied";
```

### Same logic – switch (status based)

```csharp
string status = "Delivered";

switch (status)
{
    case "Pending": Console.WriteLine("Processing order"); break;
    case "Delivered": Console.WriteLine("Order completed"); break;
    default: Console.WriteLine("Unknown status"); break;
}
```

---

## 4. Loops (Processing Many Things)

### Example: Cart items

```csharp
string[] cart = { "Laptop", "Mouse", "Keyboard" };

for (int i = 0; i < cart.Length; i++)
{
    Console.WriteLine(cart[i]);
}
```

### Better & safer

```csharp
foreach (string item in cart)
{
    Console.WriteLine(item);
}
```

### Retry logic (real world)

```csharp
int attempts = 0;
while (attempts < 3)
{
    Console.WriteLine("Trying payment...");
    attempts++;
}
```

---

## 5. Methods (Reusable Work Units)

### Example: Discount calculation

```csharp
static decimal CalculateDiscount(decimal amount)
{
    return amount * 0.10m;
}
```

### Same method – modern

```csharp
static decimal CalculateDiscount(decimal amount)
    => amount * 0.10m;
```

### Overloading (same idea, different input)

```csharp
static int Add(int a, int b) => a + b;
static decimal Add(decimal a, decimal b) => a + b;
```

---

## 6. Classes & Objects (Real Entities)

### Example: Customer

```csharp
class Customer
{
    public string Name;
    public string Email;

    public void Notify()
    {
        Console.WriteLine($"Email sent to {Name}");
    }
}
```

### Using it

```csharp
Customer c = new Customer();
c.Name = "Maruf";
c.Notify();
```

### Better version (encapsulation)

```csharp
class Customer
{
    public string Name { get; set; }
    public string Email { get; set; }
}
```

---

## 7. Constructors (Safe Initialization)

```csharp
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
```

```csharp
var p = new Product("Laptop", 85000);
```

---

## 8. Encapsulation (Protecting State)

### Example: Bank account

```csharp
class BankAccount
{
    private decimal balance;

    public void Deposit(decimal amount)
    {
        if (amount > 0)
            balance += amount;
    }

    public decimal Balance => balance;
}
```

Why this matters:

- no invalid state
- business rules in one place

---

## 9. Inheritance (Is‑A Relationship)

```csharp
class Employee
{
    public string Name;
    public virtual void Work()
    {
        Console.WriteLine("Employee working");
    }
}

class Developer : Employee
{
    public override void Work()
    {
        Console.WriteLine("Writing code");
    }
}
```

---

## 10. Interfaces (Contracts)

### Example: Payment system

```csharp
interface IPaymentMethod
{
    void Pay(decimal amount);
}

class CardPayment : IPaymentMethod
{
    public void Pay(decimal amount)
    {
        Console.WriteLine($"Paid {amount} by card");
    }
}
```

Why interfaces matter:

- easy replacement
- testable code

---

## 11. Collections (Real Data Storage)

```csharp
using System.Collections.Generic;

List<string> users = new();
users.Add("Maruf");
users.Add("Rahim");
```

### Dictionary (ID → Value)

```csharp
Dictionary<int, string> orders = new();
orders[1001] = "Shipped";
```

---

## 12. LINQ (Data Thinking)

### Problem: expensive orders

```csharp
var expensive = orders
    .Where(o => o.Key > 1000)
    .Select(o => o.Value);
```

### Same logic – no LINQ

```csharp
foreach (var o in orders)
{
    if (o.Key > 1000)
        Console.WriteLine(o.Value);
}
```

---

## 13. Error Handling (Reality)

```csharp
try
{
    int value = int.Parse("abc");
}
catch (FormatException)
{
    Console.WriteLine("Invalid input");
}
finally
{
    Console.WriteLine("Operation finished");
}
```

---

## 14. File Handling (Logs & Reports)

```csharp
using System.IO;

File.WriteAllText("log.txt", "Order created");
string log = File.ReadAllText("log.txt");
```

---

## 15. Async Programming (Real APIs)

```csharp
async Task ProcessOrderAsync()
{
    await Task.Delay(2000);
    Console.WriteLine("Order processed");
}
```

### Bad but common

```csharp
Task.Delay(2000).Wait();
```

---

## 16. SOLID Thinking (How Professionals Write C#)

- **Single Responsibility** → one reason to change
- **Open/Closed** → extend, don’t modify
- **Liskov** → child behaves like parent
- **Interface Segregation** → small contracts
- **Dependency Inversion** → depend on abstractions

---

## 17. Mental Project (Tie Everything Together)

**Order System**

1. Customer places order
2. Order validated
3. Payment processed
4. Status saved
5. Notification sent

Every C# feature exists for this flow.

---

## How to Study This (Very Important)

1. Rewrite each section in your own words
2. Change domain (shop → hospital → university)
3. Always compare:
   - simple vs clean
   - old vs modern

This is how C# becomes _engineering_, not syntax.
