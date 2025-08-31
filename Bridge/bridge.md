# Bridge Coding Exercise
You are given an example of an inheritance hierarchy which results in Cartesian-product duplication.

Please refactor this hierarchy, giving the base class Shape  an initializer that takes a `Renderer` defined as
```
struct Renderer
{
  virtual string what_to_render_as() const = 0;
}
```
as well as `VectorRenderer` and `RasterRenderer`.

The expectation is that each constructed object has a member called `str()` that returns its textual representation, for example,
```
Triangle(RasterRenderer()).str() // returns "Drawing Triangle as pixels"
```