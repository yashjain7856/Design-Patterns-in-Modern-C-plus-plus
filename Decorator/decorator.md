# Decorator Coding Exercise
Roses can be red, blue or red and blue. Given the class interface `Flower` and class Rose, build decorators `RedFlower` and `BlueFlower` that would print the following:

```
Rose rose;
RedFlower red_rose{rose};
RedFlower red_red_rose{red_rose};
BlueFlower blue_red_rose{red_rose};
cout << rose.str();          // "A rose"
cout << red_rose.str();      // "A rose that is red"
cout << red_red_rose.str();  // "A rose that is red"
cout << blue_red_rose.str(); // "A rose that is red and blue"
```