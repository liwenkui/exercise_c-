#ifndef VECTOR
#define VECTOR
#define DEFAULT_CAPACITY 3
typedef int Rank;
template <typename T>
class Vector
{
protected:
  Rank _size;
  int _capacity;
  T *_elem;
  void copyFrom(T const *, Rank, Rank);
  void expand();
  void shrink();

public:
  //constructor
  Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
  {
    _elem = new T[_capacity = c];
    for (_size = 0; _size < s; _elem[_size++] = v)
      ;
  }
  Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
  //destructor
  ~Vector() { delete[] _elem; }
  //read
  int disordered() const;
  Rank search(T const &e, Rank lo, Rank hi) const { return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi); }
  Rank size() { return _size; }
  Rank find(T const &e) const { return find(e, 0, _size); }
  Rank find(T const &, Rank, Rank) const;
  //write
  T &operator[](Rank r) const;
  Vector<T> &operator=(Vector<T> const &);
  Rank insert(Rank r, T const &e);
  int remove(Rank lo, Rank hi);
  T remove(Rank r);
  int deduplicate();
  int uniquify();
};
#endif