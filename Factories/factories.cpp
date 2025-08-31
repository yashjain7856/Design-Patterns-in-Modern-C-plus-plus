#include <string>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
public:
  int ID = 0;
  Person create_person(const string& name)
  {
    Person p;
    p.id = ID++;
    p.name = name;
    return p;
  }
};