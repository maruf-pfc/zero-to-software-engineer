public class Car
{
    public string Brand = "";
    public int Speed = 0;
    public Car() {}

    public Car(int speed)
    {
        Speed = speed;
    }
    public Car(string brand, int speed)
    {
        Brand = brand;
        Speed = speed;
    }
    public void Drive()
    {
        Console.WriteLine("Car is Driving");
    }

    public int GetSpeed()
    {
        return Speed;
    }
}

public class Person
{
    protected string Name;
    public string email;
    public string phoneNumber;
}

public class Teacher : Person
{

}

public class Student : Person
{
    public int RollNumber;

    public Student(string name)
    {
        this.Name = name;
    }
}

public class Animal
{

}

public abstract class AbstractAnimal
{
    public abstract void MakeSound();

    //public abstract void Eat();
    public void Eat()
    {
        Console.WriteLine("Animal is eating");
    }
}

public class Dog : AbstractAnimal
{
    public override void MakeSound()
    {
        Console.WriteLine("Dog barks");
    }

    // public void Eat(){
    // Console.WriteLine("Dog is eating");
    // }
}

public sealed class SealedClass
{
    public void Test()
    {

    }
}

public class TestClass
{

}

/*
Class
Property
Method
Different of class
- Concrete
- Abstract
- Sealed
- Partial
Inherit class
Constructor
Object
Access modifier
*/

class Program
{
    static void Main(string[] args)
    {
        // ----- Car Examples (Constructors) -----
        Car bmwCar = new Car();
        Car bmwCarWithSpeed = new Car(100);
        Car bmwCarWithBrandAndSpeed = new Car("BMW", 100);

        bmwCar.Drive();
        Console.WriteLine($"Speed = {bmwCarWithSpeed.GetSpeed()}");
        Console.WriteLine($"{bmwCarWithBrandAndSpeed.Brand} car has speed = {bmwCarWithBrandAndSpeed.GetSpeed()}");

        Console.WriteLine();

        // ----- Student Example (Inheritance) -----
        Student student = new Student("Maruf");
        student.RollNumber = 101;
        student.email = "maruf@example.com";
        student.phoneNumber = "01700000000";

        Console.WriteLine($"Student Name: Maruf");
        Console.WriteLine($"Roll Number: {student.RollNumber}");
        Console.WriteLine($"Email: {student.email}");

        Console.WriteLine();

        // ----- Teacher Example -----
        Teacher teacher = new Teacher();
        teacher.email = "teacher@example.com";
        teacher.phoneNumber = "01800000000";

        Console.WriteLine($"Teacher Email: {teacher.email}");

        Console.WriteLine();

        // ----- Abstract Class Example -----
        Dog dog = new Dog();
        dog.MakeSound();
        dog.Eat();

        Console.WriteLine();

        // ----- Sealed Class Example -----
        SealedClass sealedObj = new SealedClass();
        sealedObj.Test();

        Console.WriteLine("Program Finished");
    }
}