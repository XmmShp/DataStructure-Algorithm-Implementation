#include <cstdio>
#include <functional>

template <typename T, typename TComparator = std::less<T>>
class AVLTree
{
  public:
    AVLTree() : _root(nullptr), _comparator() {}
    ~AVLTree()
    {
        /*
         * TODO : Implement the destructor
         */
    }
    void Insert(T data) { _root = Insert(_root, data); }
    bool Find(T data) { return Find(_root, data); }
    bool Deleta(T data)
    {
        /*
         * TODO : Implement the deletion
         */
        return false;
    }
    void Print() { Print(_root); }

  protected:
    struct Node
    {
        T Data;
        Node *Left;
        Node *Right;
        int Height;

        Node(T data) : Data(data), Left(nullptr), Right(nullptr), Height(1) {}
    };

    Node *_root;
    TComparator _comparator;

    Node *Insert(Node *node, T data)
    {
        if (node == nullptr) { return new Node(data); }
        if (_comparator(data, node->Data)) { node->Left = Insert(node->Left, data); }
        else { node->Right = Insert(node->Right, data); }
        node->Height = 1 + Max(GetHeight(node->Left), GetHeight(node->Right));
        int balance = GetBalance(node);
        // Left Left
        if (balance > 1 && _comparator(data, node->Left->Data)) { return RightRotate(node); }
        // Right Left
        if (balance < -1 && _comparator(data, node->Right->Data))
        {
            node->Right = RightRotate(node->Right);
            return LeftRotate(node);
        }

        // Right Right
        if (balance < -1 && !_comparator(data, node->Right->Data)) { return LeftRotate(node); }
        // Left Right
        if (balance > 1 && !_comparator(data, node->Left->Data))
        {
            node->Left = LeftRotate(node->Left);
            return RightRotate(node);
        }
        return node;
    }
    void Print(Node *node)
    {
        if (node == nullptr) { return; }

        Print(node->Left);
        printf("%d ", node->Data);
        Print(node->Right);
    }
    bool Find(Node *node, T data)
    {
        if (node == nullptr) { return false; }
        if (!_comparator(data, node->Data) && !_comparator(node->Data, data)) { return true; }
        if (_comparator(data, node->Data)) { return Find(node->Left, data); }
        else { return Find(node->Right, data); }
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
    int Max(int x, int y) { return x < y ? x : y; }
    int GetBalance(Node *node)
    {
        if (node == nullptr) { return 0; }
        return GetHeight(node->Left) - GetHeight(node->Right);
    }
    int GetHeight(Node *node)
    {
        if (node == nullptr) { return 0; }
        return node->Height;
    }
};

/*
Test Region
*/
int main()
{
    AVLTree<int> tree;
    for (int i = 1; i <= 1024; i++) { tree.Insert(i); }
    for (int i = 1024; i >= 1; --i) { tree.Insert(i); }
    tree.Print();
    printf("\n%d", tree.Find(512));
    return 0;
}