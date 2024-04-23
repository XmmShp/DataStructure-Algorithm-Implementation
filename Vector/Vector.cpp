#include <cstring>
template <typename T>
class Vector
{
private:
    static const int PAGESIZE = 100;

public:
    Vector() : Vector(0){};
    explicit Vector(size_t size, T init = T()) : _capacity(PAGESIZE), _size(size)
    {
        if (_size > _capacity)
            _capacity = (1 + _size % PAGESIZE) * PAGESIZE;
        _vec = new T[_capacity];
        for (size_t i = 0; i < size; i++)
            _vec[i] = init;
    }

    ~Vector() { delete[] _vec; }

    void PushBack(T val)
    {
        if (++_size > _capacity)
        {
            _capacity *= 2;
            T *_tmp = new T[_capacity];
            memcpy(_tmp, _vec, sizeof(T) * (_size - 1));
            delete[] _vec;
            _vec = _tmp;
        }
        _vec[_size - 1] = val;
    }
    void PopBack()
    {
        if (_size == 0)
            throw "Vector is empty.";
        --_size;
    }
    int Size()
    {
        return _size;
    }
    bool Empty()
    {
        return _size == 0;
    }
    T &operator[](size_t index)
    {
        if (index >= _size)
            throw "index error!";
        return _vec[index];
    }

private:
    T *_vec;
    size_t _capacity;
    size_t _size;
};

/*
Test Region
*/
#include <cstdio>
int main()
{
    Vector<int> vec;
    for (int i = 0; i < 1024; i++)
        vec.PushBack(i);
    for (int i = 0; i < 1024; i++)
        printf("%d ", vec[i]);
    return 0;
}
