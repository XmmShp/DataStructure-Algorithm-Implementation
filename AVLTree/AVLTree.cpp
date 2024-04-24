#include <cstdio>

template <typename T>
class AVLTree
{
  public:
    AVLTree() : _root(nullptr)
    {
    }
    void Insert(T data)
    {
        _root = InsertInternal(_root, data);
    }
    bool Find(T data)
    {
        return FindInternal(_root, data);
    }
    void Print()
    {
        PrintInternal(_root);
    }

  private:
    struct Node
    {
        T Data;
        Node *Left;
        Node *Right;
        int Height;

        Node(T data) : Data(data), Left(nullptr), Right(nullptr), Height(1)
        {
        }
    };

    Node *_root;

    Node *InsertInternal(Node *node, T data)
    {
        if (node == nullptr)
        {
            return new Node(data);
        }
        if (data < node->Data)
            node->Left = InsertInternal(node->Left, data);
        else
            node->Right = InsertInternal(node->Right, data);
        node->Height = 1 + Max(GetHeight(node->Left), GetHeight(node->Right));
        int balance = GetBalance(node);
        if (balance > 1 && data < node->Left->Data) // Left Left
            return RightRotate(node);
        if (balance < -1 && data > node->Right->Data) // Right Right
            return LeftRotate(node);
        if (balance > 1 && data > node->Left->Data) // Left Right
        {
            node->Left = LeftRotate(node->Left);
            return RightRotate(node);
        }
        if (balance < -1 && data < node->Right->Data) // Right Left
        {
            node->Right = RightRotate(node->Right);
            return LeftRotate(node);
        }
        return node;
    }
    void PrintInternal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        PrintInternal(node->Left);
        printf("%d ", node->Data);
        PrintInternal(node->Right);
    }
    bool FindInternal(Node *node, T data)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (!(node->Data < data) && !(data < node->Data))
        {
            return true;
        }
        if (node->Data > data)
        {
            return FindInternal(node->Left, data);
        }
        else
        {
            return FindInternal(node->Right, data);
        }
    }

    Node *LeftRotate(Node *node)
    {
        Node *temp = node->Right;
        node->Right = temp->Left;
        temp->Left = node;
        return temp;
    }
    Node *RightRotate(Node *node)
    {
        Node *temp = node->Left;
        node->Left = temp->Right;
        temp->Right = node;
        return temp;
    }
    int Max(int x, int y)
    {
        return x < y ? x : y;
    }
    int GetBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return GetHeight(node->Left) - GetHeight(node->Right);
    }
    int GetHeight(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->Height;
    }
};

/*
Test Region
*/
int main()
{
    AVLTree<int> tree;
    for (int i = 1; i <= 1024; i++)
    {
        tree.Insert(i);
    }
    tree.Print();
    printf("\n%d", tree.Find(512));
    return 0;
}