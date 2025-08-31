struct Square
{
  int side{ 0 };


  explicit Square(const int side)
    : side(side)
  {
  }
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};

struct SquareToRectangleAdapter : Rectangle
{
  const Square& square_;
  SquareToRectangleAdapter(const Square& square): square_(square)
  {
      // todo
  }
  // todo
  int width() const override {
    return square_.side;
  }

  int height() const override {
    return square_.side;
  }
};