using namespace std;
struct ExpressionProcessor
{
  map<char,int> variables;

  int calculate(const string& expression)
  {
    // TODO
    int n = expression.size(), res=0;
    int last = 1, i=0;
    while(i<n){
        if(expression[i]>='0' && expression[i]<='9'){
            int curr = 0;
            while(i<n && expression[i]>='0' && expression[i]<='9'){
                curr += expression[i]-'0';
                i++;
            }
            res += last*curr;
            cout << res <<" " <<i<<"Y"<<endl;
            if(i>=n) return res;
            else if(expression[i]=='+') {
                last = 1;
                i++;
            } else if(expression[i]=='-') {
                last = -1;
                i++;
            }
            else return 0;
        } else {
            char ch = expression[i];
            i++;
            if(i<n && expression[i]!='+' && expression[i]!='-'){
                return 0;
            }
            
            int curr = 0;
            if(variables.find(ch) == variables.end()) return 0;
            else curr = variables[ch];
            
            res += last*curr;
            if(i>=n) return res;
            else if(expression[i]=='+') {
                last = 1;
                i++;
            }
            else if(expression[i]=='-') {
                last = -1;
                i++;
            }
            
        }
        
        
        
    }
    return 0;
  }
};