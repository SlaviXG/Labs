package main

import (
	"fmt"
	"math/rand"
)

type HashStruct struct {
	m         int
	p         int
	a         int
	b         int
	words     []string
	hashTable [][]string
}

func NewHashStruct(words []string) *HashStruct {

	hashStruct := new(HashStruct)

	hashStruct.words = hashStruct.UniqueWords(words)
	hashStruct.m = len(words)
	hashStruct.p = greaterPrime(hashStruct.m)
	hashStruct.RegenerateHashParameters()

	hashStruct.hashTable = make([][]string, hashStruct.m)

	for _, w := range words {

		id := hashStruct.HashFunction(w)

		hashStruct.hashTable[id] = append(hashStruct.hashTable[id], w)
	}

	return hashStruct
}

func (hashStruct *HashStruct) RegenerateHashParameters() {
	hashStruct.a = rand.Intn(hashStruct.p-1) + 1
	hashStruct.b = rand.Intn(hashStruct.p)
}

func (hashStruct HashStruct) HashFunction(str string) int {

	var res int
	var x int = 0
	var length int = len(str)

	for i := 0; i < length; i++ {
		x += int(str[i])
	}

	res = ((hashStruct.a*x + hashStruct.b) % hashStruct.p) % hashStruct.m

	return res
}

func (hashStruct HashStruct) UniqueWords(s []string) []string {

	inResult := make(map[string]bool)
	var result []string

	for _, str := range s {
		if _, ok := inResult[str]; !ok {
			inResult[str] = true
			result = append(result, str)
		}
	}

	return result
}

func (hashStruct HashStruct) FindIDXs(word string) (int, int) {

	i := hashStruct.HashFunction(word)

	for j := 0; j < len(hashStruct.hashTable[i]); j++ {

		if word == hashStruct.hashTable[i][j] {
			return i, j
		}
	}

	return -1, -1
}

func (hashStruct HashStruct) Print() {

	var mx_len int = 0

	for _, b := range hashStruct.hashTable {
		mx_len = Max(mx_len, len(b))
	}

	fmt.Println("\nBucket table:")

	fmt.Print("\ni\\j\t")

	for i := 0; i < mx_len; i++ {
		fmt.Print(i, "\t")
	}

	fmt.Print("\n")

	for i, hi := range hashStruct.hashTable {

		fmt.Print(i, ":\t")
		for _, hj := range hi {
			fmt.Print(hj, "\t")
		}
		fmt.Print("\n")
	}
}
