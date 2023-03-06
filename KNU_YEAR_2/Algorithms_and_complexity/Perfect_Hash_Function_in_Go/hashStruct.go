package main

import (
	//"fmt"
	"math/rand"
)

type HashStruct struct {
	m         int
	p         int
	words     []string
	hashTable [][]int
}

func NewHashStruct(words []string) *HashStruct {

	hashStruct := new(HashStruct)

	hashStruct.words = hashStruct.UniqueWords(words)
	hashStruct.m = len(words)
	hashStruct.p = greaterPrime(hashStruct.m)

	//creating hash table

	return hashStruct
}

func (hashStruct HashStruct) HashFunction(str string) int {

	var res int
	var x int = 0
	var a int = rand.Intn(hashStruct.p-1) + 1
	var b int = rand.Intn(hashStruct.p)
	var length int = len(str)

	for i := 0; i < length; i++ {
		x += int(str[i])
	}

	res = ((a*x + b) % hashStruct.p) % hashStruct.m

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
