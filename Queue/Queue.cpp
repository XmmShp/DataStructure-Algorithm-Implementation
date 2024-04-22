template <typename T>
class Queue
{
    struct QueueNode
    {
        T Val;
        QueueNode *Next;
    };

public:
    Queue() : _head(nullptr), _tail(nullptr) {}
    T Front()
    {
        if (_head == nullptr)
            throw "Empty Queue!";
        return _head->Val;
    }
    void Pop() { _head == nullptr ? throw "Empty Queue!" : _head = _head->Next; }
    void Push(T val)
    {
        if (_tail == nullptr)
        {
            _head = _tail = new QueueNode{val, nullptr};
            return;
        }
        _tail->Next = new QueueNode{val, nullptr};
        _tail = _tail->Next;
    }
    bool Empty() { return _head == nullptr; }

private:
    QueueNode *_head, *_tail;
};

/*
Test Region
*/
#include <cstdio>

int main()
{
    Queue<int> q;
    q.Push(1);
    q.Push(2);
    q.Push(3);
    printf("%d\n", q.Front());
    q.Pop();
    printf("%d\n", q.Front());
    q.Pop();
    printf("%d\n", q.Front());
    q.Pop();
    printf("%d\n", q.Empty());
    return 0;
}