# Visitor Coding Exercise
You are asked to implement a double-dispatch visitor called `ExpressionPrinter` for printing different mathematical expressions. The range of expressions covers addition and multiplication - please put round brackets around addition but not around multiplication! Also, please avoid any blank spaces in output.

Example:

Input: `AdditionExpression{Literal{2}, Literal{3}}`  -- btw, this is pseudocode, you cannot inline those references unfortunately

Output: `(2+3)` 
Here is the corresponding unit test:
```
Value v2{2};
Value v3{3};
AdditionExpression simple{v2,v3};
ExpressionPrinter ep;
ep.accept(simple);
ASSERT_EQ("(2+3)", ep.str());
```