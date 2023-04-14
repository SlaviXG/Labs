package main

import (
	"fmt"
)

//A level of a node is the number of left links to a NULL reference.

type TreeNode struct {
	parent *TreeNode
	left   *TreeNode
	right  *TreeNode
	isRed  bool
	level  int
	value  int
}

type AATree struct {
	root *TreeNode
	size int
}

// Node constructor:
func NewTreeNode(value int) *TreeNode {
	return &TreeNode{
		parent: nil,
		left:   nil,
		right:  nil,
		isRed:  false,
		level:  1,
		value:  value,
	}
}

// Tree constructor:
func NewAATree() *AATree {
	return &AATree{
		nil,
		0,
	}
}

// Interface for interaction with AA-Tree
type AATreeInterface interface {
	Find(value int) *TreeNode
	InsertValue(value int)
	InsertNode(root *TreeNode, node *TreeNode)
	Delete(node *TreeNode)
	Split(node *TreeNode)
	Skew(node *TreeNode)
	RotateLeft(node *TreeNode)
	RotateRight(node *TreeNode)
	DecreaseLevel(node *TreeNode)
	Print()
}

func (tree *AATree) Find(value int) *TreeNode {

	curNode := tree.root

	for curNode != nil && curNode.value != value {
		if value < curNode.value {
			curNode = curNode.left
		} else if value > curNode.value {
			curNode = curNode.right
		}
	}

	return curNode
}

func (tree *AATree) InsertValue(value int) {
	node := NewTreeNode(value)
	tree.InsertNode(tree.root, node)
}

func (tree *AATree) InsertNode(curRoot *TreeNode, node *TreeNode) {
	if curRoot == nil {
		curRoot = node
	} else if node.value < curRoot.value {
		tree.InsertNode(curRoot.left, node)
	} else if node.value > curRoot.value {
		tree.InsertNode(curRoot.right, node)
	}
	tree.Skew(curRoot)
	tree.Split(curRoot)
}

func (tree *AATree) Delete(node *TreeNode) {

}

func (tree *AATree) Split(node *TreeNode) {
	if node.right != nil {
		if node.right.right != nil {
			if node.right.right.level == node.level {
				tree.RotateLeft(node)
			}
		}
	}
}

func (tree *AATree) Skew(node *TreeNode) {
	if node.left != nil {
		if node.left.level == node.level {
			tree.RotateRight(node)
		}
	}
}

func (tree *AATree) RotateLeft(node *TreeNode) {

	y := node.right
	node.right = y.left
	if y.left != nil {
		y.left.parent = node
	}
	y.parent = node.parent
	if node.parent == nil {
		tree.root = y
	} else if node == node.parent.left {
		node.parent.left = y
	} else {
		node.parent.right = y
	}
	y.left = node
	node.parent = y
	y.level++
}

func (tree *AATree) RotateRight(node *TreeNode) {
	y := node.left
	node.left = y.right
	if y.right != nil {
		y.right.parent = node
	}
	y.parent = node.parent
	if node.parent == nil {
		tree.root = y
	} else if node == node.parent.right {
		node.parent.right = y
	} else {
		node.parent.left = y
	}
	y.right = node
	node.parent = y
	y.level++
}

func (tree *AATree) DecreaseLevel(node *TreeNode) {

	var w int
	if node.left != nil && node.right != nil {
		w = _min(node.left.level, node.right.level) + 1
		if w < node.level {
			node.level = w
			if node.right != nil && w < node.right.level {
				node.right.level = w
			}
		}
	}
}

func (tree *AATree) Print() {
	_printTree(tree.root, 0)
}

func _min(x int, y int) int {
	if x <= y {
		return x
	} else {
		return y
	}
}

func _printTree(node *TreeNode, lv int) {
	var i int

	if node == nil {
		return
	}

	_printTree(node.right, lv+1)

	for i = 0; i < lv; i++ {
		fmt.Print("    ")
	}

	fmt.Println(node.value)

	_printTree(node.left, lv+1)
}
