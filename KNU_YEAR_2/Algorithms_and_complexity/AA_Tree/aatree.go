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
	ReplaceNode(node_old TreeNode, node_new TreeNode)
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
	tree.InsertNode(&tree.root, nil, node)
	println("Insert: ", value)
	tree.Print()
}

func (tree *AATree) InsertNode(curRoot **TreeNode, parentRoot *TreeNode, node *TreeNode) {
	if *curRoot == nil {
		*curRoot = node
		(*curRoot).parent = parentRoot
		fmt.Println(&tree.root, " ", curRoot)
	} else if node.value < (*curRoot).value {
		tree.InsertNode(&((*curRoot).left), *curRoot, node)
	} else if node.value > (*curRoot).value {
		tree.InsertNode(&((*curRoot).right), *curRoot, node)
	}
	fmt.Println("curRoot: ", (*curRoot).value)
	tree.Skew(curRoot)
	tree.Split(curRoot)
}

func (tree *AATree) Delete(node *TreeNode) {

}

func (tree *AATree) Split(node **TreeNode) {
	if (*node).right != nil {
		if (*node).right.right != nil {
			if (*node).right.right.level == (*node).level {
				tree.RotateLeft(node)
				fmt.Println("Split:")
				tree.Print()
			}
		}
	}
}

func (tree *AATree) Skew(node **TreeNode) {
	if (*node).left != nil {
		if (*node).left.level == (*node).level {
			tree.RotateRight(node)
			fmt.Println("Skew:")
			tree.Print()
		}
	}
}

func (tree *AATree) ReplaceNode(node_old **TreeNode, node_new **TreeNode) {

	old_parent := (*node_old).parent

	if (*node_old).parent == nil {
		tree.root = *node_new
	} else {
		if *node_old == (*node_old).parent.left {
			(*node_old).parent.left = *node_new
		} else {
			(*node_old).parent.right = *node_new
		}
	}
	if node_new != nil {
		(*node_new).parent = old_parent
	}
}

func (tree *AATree) RotateLeft(node **TreeNode) {

	y := (*node).right
	n := (*node)
	tree.ReplaceNode(node, &y)
	s := (*node).left
	(*node).left = n
	if s != nil {
		s.parent = n
	}
	n.right = s
	n.parent = (*node)
	y.level++
}

func (tree *AATree) RotateRight(node **TreeNode) {
	y := (*node).left
	n := (*node)
	tree.ReplaceNode(node, &y)
	s := (*node).right
	(*node).right = n
	if s != nil {
		s.parent = n
	}
	n.left = s
	n.parent = (*node)
	y.level++
}

func (tree *AATree) DecreaseLevel(node **TreeNode) {

	var w int
	if (*node).left != nil && (*node).right != nil {
		w = _min((*node).left.level, (*node).right.level) + 1
		if w < (*node).level {
			(*node).level = w
			if (*node).right != nil && w < (*node).right.level {
				(*node).right.level = w
			}
		}
	}
}

func (tree *AATree) Print() {
	_printTree(tree.root, 0)
	println("\n")
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
