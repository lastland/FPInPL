#ifndef LIST_H_
#define LIST_H_

#include <optional> // for optional
#include <utility>  // for pair

template <typename T>
class List
{
  public:
  List<T> (T e)
  {
    elem = std::make_pair(e, nullptr);
  }

  List<T> (T e, List<T>* next)
  {
    elem = std::make_pair(e, next);
  }

  T head()
  {
    return std::get<0>(elem);
  }

  List<T>* tail()
  {
    return std::get<1>(elem);
  }

  private:
  std::pair<T, List<T>*> elem;
};

template <typename T>
List<T>* cons(T x, List<T>* xs)
{
  List<T>* ys = new List<T>(x, xs);
  return ys;
}

template <typename T>
List<T>* take(int n, List<T>* xs)
{
  if (n == 0 || nullptr == xs)
  {
    return nullptr;
  }
  else
  {
    auto y = xs->head();
    auto ys = xs->tail();
    return cons(y, take(n-1, ys));
  }  
}

#endif // LIST_H_
