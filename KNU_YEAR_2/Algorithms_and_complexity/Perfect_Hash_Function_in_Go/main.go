package main

import (
	"fmt"
)

func main() {

	var nWords int
	fmt.Print("Number of words?\n")
	fmt.Scanf("%d", &nWords)
	words := generateRandomWords(nWords, 5)
	fmt.Println("\nWords:\n", words)

	hashStruct := NewHashStruct(words)
	hashStruct.Print()

	var search_index int = nWords / 4
	fmt.Println("\nSearch:", words[search_index])
	x, y := hashStruct.FindIDXs(words[search_index])
	fmt.Println("x:", x, "\ty:", y)

	search_index = nWords * 3 / 4
	fmt.Println("\nSearch:", words[search_index])
	x, y = hashStruct.FindIDXs(words[search_index])
	fmt.Println("x:", x, "\ty:", y)
}
