import random
import cmath

class TreapNode:
    def __init__(self, key):
        self.key = key
        self.priority = random.randint(0, 99)
        self.left = None
        self.right = None

def rightRotate(y):
    x = y.left
    T2 = x.right
    x.right = y
    y.left = T2
    return x


def leftRotate(x):
    y = x.right
    T2 = y.left
    y.left = x
    x.right = T2
    return y


def insert(root, key):
    if not root:
        return TreapNode(key)

    if abs(key) <= abs(root.key):
        root.left = insert(root.left, key)

        if root.left.priority > root.priority:
            root = rightRotate(root)
    else:
        root.right = insert(root.right, key)

        if root.right.priority > root.priority:
            root = leftRotate(root)
    return root


def deleteNode(root, key):
    if not root:
        return root

    if abs(key) < abs(root.key):
        root.left = deleteNode(root.left, key)
    elif abs(key) > abs(root.key):
        root.right = deleteNode(root.right, key)
    else:
        if not root.left:
            temp = root.right
            root = None
            return temp

        elif not root.right:
            temp = root.left
            root = None
            return temp

        elif root.left.priority < root.right.priority:
            root = leftRotate(root)
            root.left = deleteNode(root.left, key)
        else:
            root = rightRotate(root)
            root.right = deleteNode(root.right, key)

    return root


def search(root, key):
    if not root or abs(root.key) == abs(key):
        return root

    if abs(root.key) < abs(key):
        return search(root.right, key)

    return search(root.left, key)


def inorder(root):
    if root:
        inorder(root.left)
        print("key:", root.key, "| priority:", root.priority, end="")
        if root.left:
            print(" | left child:", root.left.key, end="")
        if root.right:
            print(" | right child:", root.right.key, end="")
        print()
        inorder(root.right)


if __name__ == '__main__':
    random.seed(0)

    root = None
    root = insert(root, complex(9, 10))
    root = insert(root, complex(0, 5))
    root = insert(root, complex(1, 0))
    root = insert(root, complex(3, 10))
    root = insert(root, complex(8, 1))
    root = insert(root, complex(7, 0))
    root = insert(root, complex(0, 5))

    print("Inorder traversal of the given tree")
    inorder(root)

    print("\nDelete 8+i")
    root = deleteNode(root, complex(8, 1))
    print("Inorder traversal of the modified tree")
    inorder(root)

    print("\nDelete 5i")
    root = deleteNode(root, complex(0, 5))
    print("Inorder traversal of the modified tree")
    inorder(root)

    print("\nDelete 3+10i")
    root = deleteNode(root, complex(3, 10))
    print("Inorder traversal of the modified tree")
    inorder(root)

    res = search(root, complex(7, 0))
    if res is None:
        print("7 Not Found")
    else:
        print("7 found")