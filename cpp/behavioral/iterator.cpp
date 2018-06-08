/*!
* \brief   Iterator. Provide a way to access the elements of
*       an aggregate Object sequentially without exposing its
*       underlying representation.
*
*      client   ->    Iterator   ->    Aggregate      ->   Object
*                        |                |
*                ConcreteIterator  ConcreteAggregate
*/

#include <iostream>
#include <vector>  

class Object {
public:
  Object(int value) : value_(value) {};
  void Excute() {
    std::cout << value_ << std::endl;
  }
private:
  int value_;
};

class Aggregate {
public:
  virtual void add(Object &obj) = 0;
  virtual Object& operator[](int index) = 0;
  virtual int size() = 0;
};

class ConcreteAggregate : public Aggregate {
public:
  void add(Object &obj) {
    objects_.push_back(obj);
  }
  int size() {
    return objects_.size();
  }
  Object& operator[](int index) {
    return objects_[index];
  }
private:
  std::vector<Object> objects_;
};

class Iterator {
public:
  virtual void     next() = 0;
  virtual bool has_next() = 0;
};

class ConcreteIterator :public Iterator {
public:
  ConcreteIterator(Aggregate *agg) {
    this->agg_ = agg;
    index_ = 0;
  }
  void next() {
    (*agg_)[index_++].Excute();
  }
  bool has_next() {
    return (index_ < agg_->size());
  }
public:
  Aggregate *agg_;
  int index_;
};

int main() {
  Aggregate *objects = new ConcreteAggregate();
  Object a(1), b(2), c(3);

  objects->add(a);
  objects->add(b);
  objects->add(c);

  Iterator *iter = new ConcreteIterator(objects);
  while (iter->has_next()) {
    iter->next();
  }
  std::cout << "Finish." << std::endl;

  delete objects;
  delete iter;

  system("pause");
  return 0;
}