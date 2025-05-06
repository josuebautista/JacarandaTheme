package main

import "fmt"

struct Person {
	Name string
	Age int
}

// Main function
func main() {
	person := Person{
		Name: "John",
		Age: 25,
	}

	fmt.Println(person)
}
