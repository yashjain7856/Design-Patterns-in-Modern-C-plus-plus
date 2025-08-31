using namespace std;
struct Sentence
{
    
    struct WordToken
    {
        bool capitalize;
    };
    
    Sentence(const string& text) : txt(text)
    {
        // todo
        // txt = text;
        int spc_count = count(txt.begin(),txt.end(),' ');
        tokens = vector<WordToken> (spc_count+1,{false});
    }
    
    WordToken& operator[](size_t index)
    {
        // todo
        return tokens[index];
    }
    
    string str() const
    {
        // todo
        string res;
        int w_ind = 0;
        for(long unsigned int i=0;i<txt.size();i++){
            if(txt[i]==' '){
                res += ' ';
                w_ind ++;
                continue;
            } else{
                if(tokens[w_ind].capitalize) res += toupper(txt[i]);
                else res += txt[i];
            }
        }
        return res;
    }
    string txt;
    vector<WordToken> tokens;
    
};