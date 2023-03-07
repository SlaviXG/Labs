package main

import (
	"math/rand"
)

func generateRandomWords(number int, length int) []string {

	const letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
	var words []string

	for i := 0; i < number; i++ {

		word := ""

		for j := 0; j < length; j++ {
			word += string(letters[rand.Intn(len(letters))])
		}

		words = append(words, word)
	}

	return words
}

func power(x int, y int, p int) int {

	var res int = 1
	x = x % p

	for y > 0 {

		if y%2 == 1 {
			res = (res * x) % p
		}

		y = y >> 1 // y = y/2
		x = (x * x) % p
	}

	return res
}

func miillerTest(d int, n int) bool {

	var a int = 2 + (rand.Intn(1000) % (n - 4))

	var x int = power(a, d, n)

	if x == 1 || x == n-1 {
		return true
	}

	for d != n-1 {
		x = (x * x) % n
		d *= 2

		if x == 1 {
			return false
		}
		if x == n-1 {
			return true
		}
	}

	return false
}

func isPrime(n int) bool {

	var k int = 4

	if n <= 1 || n == 4 {
		return false
	}

	if n <= 3 {
		return true
	}

	var d int = n - 1

	for d%2 == 0 {
		d /= 2
	}

	for i := 0; i < k; i++ {
		if !miillerTest(d, n) {
			return false
		}
	}

	return true
}

func greaterPrime(n int) int {

	for i := n + 1; ; i++ {
		if isPrime(i) {
			return i
		}
	}

}

func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func Min(x, y int) int {
	if x > y {
		return y
	}
	return x
}
