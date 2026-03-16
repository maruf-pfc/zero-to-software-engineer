# C# Access Modifiers — Detailed Notes

> **Topic:** Access Modifiers in C#
> **Category:** Object-Oriented Programming (OOP) — Encapsulation
> **Level:** Beginner → Intermediate

---

## Table of Contents

- [C# Access Modifiers — Detailed Notes](#c-access-modifiers--detailed-notes)
  - [Table of Contents](#table-of-contents)
  - [What Are Access Modifiers?](#what-are-access-modifiers)
  - [Quick Reference Table](#quick-reference-table)
  - [Accessibility Hierarchy](#accessibility-hierarchy)
  - [1. `public`](#1-public)
    - [When to use](#when-to-use)
    - [Example](#example)
    - [Key points](#key-points)
  - [2. `private`](#2-private)
    - [When to use](#when-to-use-1)
    - [Example](#example-1)
    - [Key points](#key-points-1)
  - [3. `protected`](#3-protected)
    - [When to use](#when-to-use-2)
    - [Example](#example-2)
    - [Key points](#key-points-2)
  - [4. `internal`](#4-internal)
    - [When to use](#when-to-use-3)
    - [Example](#example-3)
    - [Key points](#key-points-3)
  - [5. `protected internal`](#5-protected-internal)
    - [When to use](#when-to-use-4)
    - [Example](#example-4)
    - [Key points](#key-points-4)
  - [6. `private protected`](#6-private-protected)
    - [When to use](#when-to-use-5)
    - [Example](#example-5)
    - [Key points](#key-points-5)
  - [Default Access Modifiers](#default-access-modifiers)
    - [Example](#example-6)
  - [Real-World Example — BankAccount](#real-world-example--bankaccount)
  - [Comparison: `protected internal` vs `private protected`](#comparison-protected-internal-vs-private-protected)
  - [Best Practices](#best-practices)
  - [Common Mistakes](#common-mistakes)
  - [Summary](#summary)

---

## What Are Access Modifiers?

Access modifiers are **keywords** in C# that define the **visibility and accessibility** of classes, methods, fields, properties, and other members.

They are the primary tool for implementing **encapsulation** — one of the four core pillars of Object-Oriented Programming (OOP). Without access modifiers, all members of a class would be exposed to the entire codebase, making it impossible to protect internal state or enforce a clean API boundary.

**Why they matter:**

- Protect sensitive data from unintended external mutation
- Force consumers of your class to use only the API you intend
- Reduce coupling between components
- Make refactoring safer — internal details can change without breaking external code
- Enable better architecture in libraries, APIs, and enterprise applications

---

## Quick Reference Table

| Modifier             | Same Class | Derived Class (same assembly) | Derived Class (other assembly) | Same Assembly (non-derived) | Other Assembly (non-derived) |
| -------------------- | :--------: | :---------------------------: | :----------------------------: | :-------------------------: | :--------------------------: |
| `public`             |     ✅     |              ✅               |               ✅               |             ✅              |              ✅              |
| `protected internal` |     ✅     |              ✅               |               ✅               |             ✅              |              ❌              |
| `internal`           |     ✅     |              ✅               |               ❌               |             ✅              |              ❌              |
| `protected`          |     ✅     |              ✅               |               ✅               |             ❌              |              ❌              |
| `private protected`  |     ✅     |              ✅               |               ❌               |             ❌              |              ❌              |
| `private`            |     ✅     |              ❌               |               ❌               |             ❌              |              ❌              |

> **Assembly** = a compiled unit (`.dll` or `.exe`). In most cases, a single Visual Studio project compiles into one assembly.

---

## Accessibility Hierarchy

From most permissive to most restrictive:

```
public
  └── protected internal
        └── internal
              └── protected
                    └── private protected
                          └── private
```

When in doubt, start with `private` and open up access only when necessary.

---

## 1. `public`

**Accessible from:** Anywhere — same class, derived classes, same assembly, other assemblies.

### When to use

- Defining the public API of a class or library
- Methods and properties intended for external consumers
- DTO (Data Transfer Object) properties

### Example

```csharp
public class Car
{
    public string Brand;     // Accessible from anywhere
    public int Year;

    public void Drive()
    {
        Console.WriteLine($"{Brand} is driving.");
    }

    public string GetInfo()
    {
        return $"{Brand} ({Year})";
    }
}

// Usage — anywhere in any project
Car car = new Car();
car.Brand = "BMW";   // ✅
car.Year = 2024;     // ✅
car.Drive();         // ✅
```

### Key points

- No access restriction whatsoever
- Use deliberately — every `public` member is a commitment to external consumers
- Changing a public API later is a breaking change in libraries

---

## 2. `private`

**Accessible from:** Only within the **same class** where it is declared.

### When to use

- Internal fields that back public properties
- Helper methods used only within the class
- Anything that is an implementation detail

### Example

```csharp
public class BankAccount
{
    private double _balance = 0;  // Hidden from outside

    public void Deposit(double amount)
    {
        if (amount <= 0)
            throw new ArgumentException("Amount must be positive.");

        _balance += amount;  // Internal manipulation
    }

    public void Withdraw(double amount)
    {
        if (amount > _balance)
            throw new InvalidOperationException("Insufficient funds.");

        _balance -= amount;
    }

    public double GetBalance()
    {
        return _balance;  // Controlled read access
    }
}

// Usage
BankAccount acc = new BankAccount();
acc.Deposit(1000);
// acc._balance = 9999; ❌ Compile error — private field
Console.WriteLine(acc.GetBalance()); // ✅ 1000
```

### Key points

- **Default** modifier for class members — if you write nothing, it's `private`
- Enforces data hiding — the core goal of encapsulation
- Prevents accidental corruption of internal state from outside code
- Convention: prefix private fields with underscore `_fieldName`

---

## 3. `protected`

**Accessible from:** The declaring class itself AND any class that **inherits** from it (regardless of assembly).

### When to use

- Base class members that derived classes need to access or override
- Template Method Pattern — where a base class defines a skeleton and derived classes fill in the details
- Shared internal state in a class hierarchy

### Example

```csharp
public class Animal
{
    protected string Name;     // Accessible to subclasses
    protected int Age;

    protected void Breathe()
    {
        Console.WriteLine($"{Name} is breathing.");
    }
}

public class Dog : Animal
{
    public void Introduce()
    {
        Name = "Rex";          // ✅ Accessible via inheritance
        Age = 3;               // ✅
        Breathe();             // ✅
        Console.WriteLine($"I am {Name}, {Age} years old.");
    }
}

// Usage
Dog dog = new Dog();
dog.Introduce();
// dog.Name ❌ — protected, not accessible outside the hierarchy
```

### Key points

- Used exclusively in the context of **inheritance**
- Not accessible from unrelated classes, even in the same assembly
- Use `protected` only when derived classes genuinely need the member

---

## 4. `internal`

**Accessible from:** Anywhere within the **same assembly** (project). Completely hidden from other assemblies.

### When to use

- Helper classes and utilities that are internal implementation details of a library
- Classes that should be shared across files in a project but hidden from library consumers
- Domain-specific logic you don't want to expose as a public API

### Example

```csharp
// InternalLogger.cs — inside MyLibrary project
internal class InternalLogger
{
    internal void Log(string message)
    {
        Console.WriteLine($"[LOG] {message}");
    }
}

// UsageClass.cs — also inside MyLibrary project
public class PaymentService
{
    public void ProcessPayment(double amount)
    {
        var logger = new InternalLogger();
        logger.Log($"Processing payment: {amount}"); // ✅ Same assembly
    }
}

// ConsumerApp (different project/assembly)
// var logger = new InternalLogger(); ❌ Not visible
```

### Key points

- The `internal` keyword is the boundary between your library's internals and its public surface
- Default modifier for **top-level classes** (if you write `class Foo {}` with no modifier, it's `internal`)
- Use `[assembly: InternalsVisibleTo("TestProject")]` to allow unit test projects access to internals

---

## 5. `protected internal`

**Accessible from:** The same assembly (like `internal`) **OR** derived classes from another assembly (like `protected`). It is a union — either condition is sufficient.

### When to use

- Framework or base library members that need to be accessible to derived classes across assemblies
- Designing extensible base classes where end-users can subclass but shouldn't access the member directly

### Example

```csharp
// In MyFramework.dll
public class Component
{
    protected internal void Initialize()
    {
        Console.WriteLine("Component initialized.");
    }
}

// In MyFramework.dll (same assembly — any class can access)
public class ComponentManager
{
    public void Setup(Component c)
    {
        c.Initialize(); // ✅ Same assembly
    }
}

// In ConsumerApp.dll (different assembly)
public class CustomComponent : Component
{
    public void Start()
    {
        Initialize(); // ✅ Accessible because CustomComponent derives from Component
    }
}

// In ConsumerApp.dll (different assembly, not derived)
public class SomeOtherClass
{
    public void Try(Component c)
    {
        // c.Initialize(); ❌ Not derived, different assembly
    }
}
```

### Key points

- `protected internal` = `protected` **OR** `internal` (union)
- More permissive than both `protected` and `internal` individually
- Commonly seen in ASP.NET Core and other frameworks

---

## 6. `private protected`

**Accessible from:** Derived classes that are in the **same assembly** only. It is an intersection — both conditions must be true.

### When to use

- Controlling inheritance within a single library — you want derived classes to access the member, but only your own derived classes, not external ones
- Designing sealed class hierarchies that should not be extended outside the library

### Example

```csharp
// In MyLibrary.dll
public class Engine
{
    private protected int HorsePower = 300;

    private protected void Start()
    {
        Console.WriteLine("Engine started.");
    }
}

// In MyLibrary.dll (same assembly, derived)
public class SportsCar : Engine
{
    public void Launch()
    {
        Start();                              // ✅ Same assembly AND derived
        Console.WriteLine($"HP: {HorsePower}"); // ✅
    }
}

// In ConsumerApp.dll (different assembly, derived)
public class CustomCar : Engine
{
    public void Test()
    {
        // Start(); ❌ Different assembly — denied even though derived
    }
}
```

### Key points

- `private protected` = `protected` **AND** `internal` (intersection)
- More restrictive than both `protected` and `internal`
- Useful for framework designers who want inheritance extensibility only within their own library

---

## Default Access Modifiers

When you do not explicitly specify an access modifier, C# assigns a default:

| Element                                     | Default Modifier |
| ------------------------------------------- | ---------------- |
| Top-level class / struct                    | `internal`       |
| Class members (fields, methods, properties) | `private`        |
| Interface members                           | `public`         |
| Enum members                                | `public`         |

### Example

```csharp
class MyClass          // internal by default
{
    int count;         // private by default

    void DoSomething() // private by default
    {
        count++;
    }
}
```

> **Best practice:** Always write access modifiers explicitly — relying on defaults reduces readability and can cause confusion.

---

## Real-World Example — BankAccount

A complete example demonstrating multiple access modifiers working together:

```csharp
public class BankAccount
{
    // private: core data — nobody outside touches this directly
    private double _balance;
    private string _accountNumber;

    // private: internal transaction log
    private List<string> _transactionHistory = new List<string>();

    // protected: derived account types (e.g., SavingsAccount) may need this
    protected string OwnerName;

    // public constructor
    public BankAccount(string accountNumber, string ownerName, double initialBalance)
    {
        _accountNumber = accountNumber;
        OwnerName = ownerName;
        _balance = initialBalance;
        LogTransaction($"Account opened with balance {initialBalance}");
    }

    // public: external operations
    public void Deposit(double amount)
    {
        if (amount <= 0) throw new ArgumentException("Deposit must be positive.");
        _balance += amount;
        LogTransaction($"Deposited {amount}");
    }

    public void Withdraw(double amount)
    {
        if (amount > _balance) throw new InvalidOperationException("Insufficient funds.");
        _balance -= amount;
        LogTransaction($"Withdrew {amount}");
    }

    public double GetBalance() => _balance;

    // private: internal helper — nobody else needs to call this
    private void LogTransaction(string description)
    {
        _transactionHistory.Add($"{DateTime.Now}: {description}");
    }

    // internal: available to other classes in the same project (e.g., BankAuditService)
    internal List<string> GetTransactionHistory() => _transactionHistory;
}

// Derived class in same assembly
public class SavingsAccount : BankAccount
{
    private double _interestRate;

    public SavingsAccount(string accountNumber, string ownerName, double initialBalance, double rate)
        : base(accountNumber, ownerName, initialBalance)
    {
        _interestRate = rate;
    }

    public void ApplyInterest()
    {
        double interest = GetBalance() * _interestRate;
        Deposit(interest);
        Console.WriteLine($"Interest applied to {OwnerName}'s account: {interest}"); // ✅ protected
    }
}
```

---

## Comparison: `protected internal` vs `private protected`

These two are the most frequently confused modifiers:

| Scenario                          | `protected internal` | `private protected` |
| --------------------------------- | -------------------- | ------------------- |
| Derived class, same assembly      | ✅                   | ✅                  |
| Non-derived class, same assembly  | ✅                   | ❌                  |
| Derived class, other assembly     | ✅                   | ❌                  |
| Non-derived class, other assembly | ❌                   | ❌                  |
| Logic                             | OR (union)           | AND (intersection)  |
| Permissiveness                    | More open            | More restrictive    |

**Simple rule:**

- `protected internal` → accessible if derived **or** in same assembly
- `private protected` → accessible only if derived **and** in same assembly

---

## Best Practices

1. **Default to `private`.** Start with the most restrictive modifier and open up only when you have a clear reason.

2. **Expose behavior, not data.** Fields should almost always be `private`. Use `public` properties or methods to expose controlled access.

3. **Use `protected` sparingly.** Every `protected` member is part of your inheritance contract — harder to change later without breaking derived classes.

4. **Use `internal` for library internals.** It lets you share code across files in your library without exposing it to consumers.

5. **Avoid `public` fields.** Prefer `public` properties with getters/setters so you can add validation or change behavior later.

6. **Write modifiers explicitly.** Don't rely on defaults — always write `private`, `public`, etc. for clarity.

7. **Apply Principle of Least Privilege.** Give each member the minimum access it needs to do its job.

---

## Common Mistakes

```csharp
// ❌ Public field — no encapsulation, anyone can set any value
public class User
{
    public string Password; // Direct exposure — dangerous
}

// ✅ Correct — private field with controlled access
public class User
{
    private string _passwordHash;

    public void SetPassword(string plainText)
    {
        _passwordHash = Hash(plainText); // Validation and processing happen here
    }

    private string Hash(string input) { /* ... */ return input; }
}
```

```csharp
// ❌ Making everything public "to be safe"
public class OrderProcessor
{
    public double _taxRate = 0.15;   // Should be private
    public void CalculateTax() { }   // Should be private (internal step)
    public void ProcessOrder() { }   // This one should be public
}

// ✅ Only expose what external code needs
public class OrderProcessor
{
    private double _taxRate = 0.15;
    private void CalculateTax() { }
    public void ProcessOrder() { }
}
```

---

## Summary

| Modifier             | Scope                                       | Use Case                                         |
| -------------------- | ------------------------------------------- | ------------------------------------------------ |
| `public`             | Everywhere                                  | Public API, DTO properties, entry points         |
| `private`            | Same class only                             | Fields, internal helpers, implementation details |
| `protected`          | Same class + derived classes (any assembly) | Base class members for subclasses                |
| `internal`           | Same assembly (any class)                   | Library internals, shared utilities              |
| `protected internal` | Same assembly OR derived (other assembly)   | Extensible framework base classes                |
| `private protected`  | Same assembly AND derived classes           | Inheritance restricted to own library            |

---

> **Bottom line:** Access modifiers are not just syntax — they are design decisions. Every modifier you choose communicates intent: what is stable, what is internal, and what is meant to be extended. Getting these right from the start is what separates maintainable code from code that becomes a burden.
