#include <iostream>
#include <vector>
using namespace std;

struct IRat
{
    int attack{1};
};

struct Game
{
    // todo
    vector<IRat*> rats;
    void addRat(IRat* rat){
        // cout<<"ADD CALLED"<<endl;
        rats.push_back(rat);
        notify();
    }
    
    void removeRat(IRat* rat){
        // cout<<"REMOVE CALLED"<<endl;
        auto it = find(rats.begin(), rats.end(), rat);
        rats.erase(it);
        notify();
    }
    
    void notify(){
        // cout<<"NOTIFY CALLED"<<endl;
        for(auto rat:rats){
            cout<<rats.size()<<" ";
            rat->attack = rats.size();
        }
        cout<<endl;
    }
};

struct Rat : IRat
{
    Game& game;

    Rat(Game &game) : game(game)
    {
      // todo, obviously
      game.addRat(this);
    }

    ~Rat() 
    { 
        // rat dies here!
        game.removeRat(this);
    }
};