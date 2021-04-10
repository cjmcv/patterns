/*!
* \brief   Interpreter. Given a language, define a representation 
*       for its grammar along with an Interpreter that uses the
*       representation to interpret sentences in the language.
*
*                    ------>          Context
*         Client     ------>     AbstractExpression
*                                  |           |
*                    TerminalExpression      NonterminalExpression
*                      (ValExpression)  (AddExpression, SubtractExpression)
*/

#include <iostream>
#include <vector>
#include <map>

// Context.
class Context {
public:
  void AddValue(std::string key, int value) {
    value_map_.insert(std::pair<std::string, int>(key, value));
  }
  int GetValue(std::string key) {
    return value_map_[key];
  }

private:
  std::map<std::string, int> value_map_;
};

// AbstractExpression
class Expression {
public:
  virtual int Interpreter(Context *context) = 0;
};

// TerminalExpression
class ValExpression : public Expression {
public:
  ValExpression(std::string key) {
    this->key_ = key;
  }
  int Interpreter(Context *context) {
    return context->GetValue(key_);
  }
private:
  std::string key_;
};

// NonterminalExpression - Add Function.
class AddExpression : public Expression {
public:
  AddExpression(Expression *left, Expression *right) {
    this->left_ = left;
    this->right_ = right;
  }
  int Interpreter(Context *context) {
    std::cout << "Get into the Interpreter of AddExpression." << std::endl;
    int ret = this->left_->Interpreter(context) + this->right_->Interpreter(context);
    std::cout << "Finish the interpreting of AddExpression." << std::endl;
    return ret;
  }

private:
  Expression *left_;
  Expression *right_;
};

// NonterminalExpression - Subtract Function.
class SubtractExpression : public Expression {
public:
  SubtractExpression(Expression *left, Expression *right) {
    this->left_ = left;
    this->right_ = right;
  }
  int Interpreter(Context *context) {
    std::cout << "Get into the Interpreter of SubtractExpression." << std::endl;
    int ret =  this->left_->Interpreter(context) - this->right_->Interpreter(context);
    std::cout << "Finish the interpreting of SubtractExpression." << std::endl;
    return ret;
  }
private:
  Expression *left_;
  Expression *right_;
};

int main() {
  // a - b + c
  Context *context = new Context();
  context->AddValue("a", 3);
  context->AddValue("b", 6);
  context->AddValue("c", 8);

  Expression *a = new ValExpression("a");
  Expression *b = new ValExpression("b");
  Expression *c = new ValExpression("c");

  Expression *value_subtract = new SubtractExpression(a, b);
  Expression *value_add = new AddExpression(value_subtract, c);

  std::cout << std::endl << "Final Result: " << value_add->Interpreter(context) << std::endl;

  delete context;
  delete a;
  delete b;
  delete c;
  delete value_subtract;
  delete value_add;

  return 0;
}
