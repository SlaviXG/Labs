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
	InsertNode(curRoot **TreeNode, parentNode *TreeNode, node *TreeNode)
	DeleteValue(value int)
	DeleteNode(node **TreeNode)
	Split(node **TreeNode)
	Skew(node **TreeNode)
	ReplaceNode(node_old **TreeNode, node_new **TreeNode)
	RotateLeft(node **TreeNode)
	RotateRight(node **TreeNode)
	DecreaseLevel(node **TreeNode)
	Print()
	Size()
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
}

func (tree *AATree) InsertNode(curRoot **TreeNode, parentNode *TreeNode, node *TreeNode) {
	if *curRoot == nil {
		*curRoot = node
		(*curRoot).parent = parentNode
		tree.size++
	} else if node.value < (*curRoot).value {
		tree.InsertNode(&((*curRoot).left), *curRoot, node)
	} else if node.value > (*curRoot).value {
		tree.InsertNode(&((*curRoot).right), *curRoot, node)
	}
	tree.Skew(curRoot)
	tree.Split(curRoot)
}

func (tree *AATree) DeleteValue(value int) {
	node := tree.Find(value)
	tree.DeleteNode(node)
}

func (tree *AATree) DeleteNode(node *TreeNode) {
	if node == nil {
		return
	}

	if node.left != nil && node.right != nil {
		successor := node.right
		for successor.left != nil {
			successor = successor.left
		}
		node.value = successor.value
		node = successor
	}

	var child *TreeNode
	if node.left != nil {
		child = node.left
	} else {
		child = node.right
	}

	if child != nil {
		child.parent = node.parent
		if node.parent == nil {
			tree.root = child
		} else if node == node.parent.left {
			node.parent.left = child
		} else {
			node.parent.right = child
		}

		if node.level == 1 {
			tree.DecreaseLevel(&child.parent)
		}
	} else {
		if node.parent == nil {
			tree.root = nil
		} else {
			if node == node.parent.left {
				node.parent.left = nil
			} else {
				node.parent.right = nil
			}
			tree.DecreaseLevel(&node.parent)
		}
	}

	node.parent = nil
	node.left = nil
	node.right = nil
	node.level = 0
	tree.size--
}

func (tree *AATree) Split(node **TreeNode) {
	if (*node).right != nil {
		if (*node).right.right != nil {
			if (*node).right.right.level == (*node).level {
				tree.RotateLeft(node)
				(*node).level++
			}
		}
	}
}

func (tree *AATree) Skew(node **TreeNode) {
	if (*node).left != nil {
		if (*node).left.level == (*node).level {
			tree.RotateRight(node)
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
	fmt.Println("")
}

func (tree *AATree) Size() int {
	return tree.size
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
