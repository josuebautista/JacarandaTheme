class Person:
    count = 0
    def __init__(self, name: str, age: int) -> None:
        self.id = ++Person.count
        self.name = name
        self.age = age

    def greet(self: Object) -> None:
        """
        Prints a greeting message for the person.
        """
        print(f"Hello, {self.name}! You are {self.age} years old.")


def main() -> None:
    person = Person("Alice", 25)
    person.greet()


if __name__ == "__main__":
    main()
