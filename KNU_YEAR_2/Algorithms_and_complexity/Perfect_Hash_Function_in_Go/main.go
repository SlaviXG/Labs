package main

import (
	"fmt"
	"math/rand"
)

func generateRandomWords(number int, length int) []string {

	const letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	var words []string

	for i := 0; i < number; i++ {

		word := ""

		for j := 0; j < length; j++ {
			word += string(letters[rand.Intn(len(letters)-1)])
		}

		words = append(words, word)
	}

	return words
}

func main() {

	var nWords int
	fmt.Print("Number of words?\n")
	fmt.Scanf("%d", &nWords)
	words := generateRandomWords(nWords, 5)
	fmt.Print(words)

}
