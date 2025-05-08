using System;
using System.Collections.Generic;
using System.Linq;

// Main program to initialize and run the system
class Program
{
    static void Main(string[] args)
    {
        var names = new Names();
        var mySystem = new MySystem(names);
        mySystem.Run();
    }
}

// Data Logic
// Component Names
public class Names
{
    private readonly List<string> _names = new List<string>();

    public void Save(string name)
    {
        if (!string.IsNullOrWhiteSpace(name))
        {
            _names.Add(name);
        }
    }

    public IEnumerable<string> Get()
    {
        return _names;
    }
}

// Presentation Logic
public class MySystem
{
    private readonly Names _names;

    public MySystem(Names names)
    {
        _names = names ?? throw new ArgumentNullException(nameof(names));
    }

    public void Run()
    {
        while (true)
        {
            Console.WriteLine("\nMenu:");
            Console.WriteLine("1. Add a name");
            Console.WriteLine("2. Show names");
            Console.WriteLine("3. Exit");
            Console.Write("\nEnter your choice: ");

            string option = Console.ReadLine();

            switch (option)
            {
                case "1":
                    Console.Write("Enter a name: ");
                    string name = Console.ReadLine();
                    _names.Save(name);
                    break;
                case "2":
                    Console.WriteLine("\nNames:");
                    var namesList = _names.Get().ToList();
                    if (namesList.Count == 0)
                    {
                        Console.WriteLine("No names have been added yet.");
                    }
                    else
                    {
                        foreach (string n in namesList)
                        {
                            Console.WriteLine(n);
                        }
                    }
                    break;
                case "3":
                    Console.WriteLine("Exiting...");
                    return;
                default:
                    Console.WriteLine("Invalid option");
                    break;
            }
        }
    }
}
