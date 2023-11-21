#include <iostream>

using namespace std;



/* Abstract class with 2 virtual methods*/
class ADExpression {
  public:
    virtual double evaluate() const = 0;
    virtual double evaluate_derivative() const = 0;
};

/* Concrete instance of the virtual class*/
class Constant : public ADExpression {
  public:
    Constant(const double n)
    : val(n) {}

    virtual double evaluate() const override {
      return val;
    }

    virtual double evaluate_derivative() const override{
      return 0.0;
    }

  private:
    double val;
};

class Var : public ADExpression {
  public:
    Var(const double v): val(v) {}
    
    virtual double evaluate() const override{
      return val;
    }

    virtual double evaluate_derivative() const override{
      return 1.0;
    }

  private:
    double val;
};

class Sum : public ADExpression {
  public:
    Sum(const ADExpression &a, const ADExpression &b)
    : a(a), b(b) {}

    virtual double evaluate() const override{
      return a.evaluate() + b.evaluate();
    }

    virtual double evaluate_derivative() const override {
      return a.evaluate_derivative() + b.evaluate_derivative();
    }
  private:
  /*possible due to polymorphism, use reference for convenience;
  Also possible to use pointers.*/
  const ADExpression &a;
  const ADExpression &b;
};

class Difference : public ADExpression {
  public:
    Difference(const ADExpression &a, const ADExpression &b)
    : a(a), b(b) {}

    virtual double evaluate() const override{
      return a.evaluate() - b.evaluate();
    }

    virtual double evaluate_derivative() const override {
      return a.evaluate_derivative() - b.evaluate_derivative();
    }
  private:
  /*possible due to polymorphism, use reference for convenience;
  Also possible to use pointers.*/
  const ADExpression &a;
  const ADExpression &b;
};

class Product : public ADExpression {
  public:
    Product(const ADExpression &a, const ADExpression &b)
    : a(a), b(b) {}

    virtual double evaluate() const override{
      return a.evaluate() * b.evaluate();
    }

    virtual double evaluate_derivative() const override {
      return a.evaluate_derivative() * b.evaluate() + a.evaluate() * b.evaluate_derivative();
    }
  private:
  /*possible due to polymorphism, use reference for convenience;
  Also possible to use pointers.*/
  const ADExpression &a;
  const ADExpression &b;
};





int main(){
  Var x{2.0};

  auto s = Sum(Sum(x, x), Constant(1));
  auto d = Difference(Difference(x, x), Constant(1));
  auto p = Product(Product(x, x), Constant(2));

  cout << "The sum is " << s.evaluate() << endl;
  cout << "The derivative of the sum is " << s.evaluate_derivative() << endl;

  cout << "The difference is " << d.evaluate() << endl;
  cout << "The derivative of the difference is " << d.evaluate_derivative() << endl;
  
  cout << "The product is " << p.evaluate() << endl;
  cout << "The derivative of the product is " << p.evaluate_derivative() << endl;
  

  return 0;
}