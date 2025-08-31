#include <bits/stdc++.h>
using namespace std;

class CodeBuilder
{
public:
  string name;
  vector<pair<string,string>> fields;
  CodeBuilder(const string& class_name)
  {
      name = class_name;
  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
    fields.push_back({type,name});
    return *this;
  }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
    os<<"class "<<obj.name<<endl;
    os<<"{"<<endl;
    for(auto field:obj.fields){
        os<<"  "<<field.first<<" "<<field.second<<";"<<endl;
    }
    os<<"};";
    return os;
  }
};
