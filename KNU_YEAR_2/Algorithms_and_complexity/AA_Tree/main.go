package main

func main() {

	tree := NewAATree()
	tree.InsertValue(6)
	tree.InsertValue(7)
	tree.InsertValue(8)
	tree.InsertValue(5)

	tree.InsertValue(4)
	tree.InsertValue(3)
	tree.InsertValue(2)
	tree.InsertValue(1)

	tree.Print()
}
