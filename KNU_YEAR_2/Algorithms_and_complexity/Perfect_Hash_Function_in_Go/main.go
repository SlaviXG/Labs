package main

import (
	"fmt"
	//"math/rand"
)

func main() {

	var nWords int
	fmt.Print("Number of words?\n")
	fmt.Scanf("%d", &nWords)
	words := generateRandomWords(nWords, 5)
	fmt.Print(words)

}
