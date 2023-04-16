package main

import "fmt"

func main() {
	demonstrate_tree()
}

func demonstrate_tree() {
	tree := NewAATree()
	tree.InsertValue(6)
	tree.InsertValue(7)
	tree.InsertValue(8)
	tree.InsertValue(5)
	tree.InsertValue(4)
	tree.InsertValue(3)
	tree.InsertValue(2)
	tree.InsertValue(1)
	fmt.Println("Size: ", tree.Size())
	tree.Print()
	tree.DeleteValue(5)
	fmt.Println("Size: ", tree.Size())
	tree.Print()
	tree.DeleteValue(1)
	fmt.Println("Size: ", tree.Size())
	tree.Print()
	tree.DeleteValue(7)
	fmt.Println("Size: ", tree.Size())
	tree.Print()
	tree.DeleteValue(3)
	fmt.Println("Size: ", tree.Size())
	tree.Print()
	tree.InsertValue(3)
	fmt.Println("Size: ", tree.Size())
	tree.Print()
	tree.DeleteValue(4)
	fmt.Println("Size: ", tree.Size())
	tree.Print()
}
