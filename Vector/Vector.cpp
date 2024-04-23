#include <cstring>
template <typename T>

class Vector {
public:
  explicit Vector(int size, T init = T(0)) {
    if (_size > _cap)
      _cap = (1 + _size % 100) * 100;
    _vec = new T[_cap];
    for (int i = 0; i < size; i++)
      _vec[i] = init;
    _size = size;
  }

  ~Vector() { delete[] _vec; }

  void PushBack(T val) {
    if (++_size > _cap) {
      _cap *= 2;
      T *_tmp = new T[_cap];
      memcpy(_tmp, _vec, _size - 1);
      delete[] _vec;
      _vec = _tmp;
    }
    *_vec[_size - 1] = val;
  }
  T PopBack() {
    if (_size == 0)
      throw "size is zero.";
    return _vec[--_size];
  }
  T &operator[](int index) {
    if (index >= _size)
      throw "index error!";
    return _vec[index];
  }

private:
  T *_vec;
  int _cap = 100;
  int _size;
};

#include <cstdio>

int main() {
  Vector<int> vec(10, 1);
  for (int i = 0; i < 10; i++)
    printf("%d ", vec[i]);
  printf("\n");
  return 0;
}
