/*!
* \brief Singleton.
*/

#include <iostream>

class Singleton
{
public:
  int get_value() {
    return value_;
  }
  void AddOne() {
    value_++;
  }

  static Singleton &GetInstance() {
    static Singleton instance;   //static
    return instance;
  }

private:
  // External direct creation is not allowed.
  Singleton() {
    value_ = 0;
  }

  int value_;

};

int main() {

  Singleton instance1 = Singleton::GetInstance();
  printf("value_1 = %d.\n", instance1.get_value());

  instance1.AddOne();
  printf("value_2 = %d.\n", instance1.get_value());

  Singleton instance2 = Singleton::GetInstance();
  printf("value_3 = %d.\n", instance1.get_value()); // It should be the same as the value_2.

  return 0;
}