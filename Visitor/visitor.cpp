using namespace std;
struct Expression;
struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor
{
  virtual void visit(Value& v) = 0;
  virtual void visit(AdditionExpression& ae) = 0;
  virtual void visit(MultiplicationExpression& me) = 0;
};

struct Expression
{
  virtual void accept(ExpressionVisitor& ev) = 0;
  virtual ~Expression() = default;
};

struct Value : Expression
{
  int value;
  Value(int value) : value(value) {}

  void accept(ExpressionVisitor& ev) override
  {
    ev.visit(*this);
  }
};

struct AdditionExpression : Expression
{
  Expression &lhs, &rhs;
  AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}

  void accept(ExpressionVisitor& ev) override
  {
    ev.visit(*this);
  }
};

struct MultiplicationExpression : Expression
{
  Expression &lhs, &rhs;
  MultiplicationExpression(Expression &lhs, Expression &rhs)
    : lhs(lhs), rhs(rhs) {}

  void accept(ExpressionVisitor& ev) override
  {
    ev.visit(*this);
  }
};

struct ExpressionPrinter : ExpressionVisitor
{
  ostringstream oss;

  void visit(Expression& expr)
  {
    expr.accept(*this);
  }

  void visit(Value& v) override
  {
    oss << v.value;
  }

  void visit(AdditionExpression& ae) override
  {
    oss << "(";
    ae.lhs.accept(*this);
    oss << "+";
    ae.rhs.accept(*this);
    oss << ")";
  }

  void visit(MultiplicationExpression& me) override
  {
    me.lhs.accept(*this);
    oss << "*";
    me.rhs.accept(*this);
  }

  string str() const { return oss.str(); }
};