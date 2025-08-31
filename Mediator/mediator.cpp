#include <bits/stdc++.h>
using namespace std;

struct Participant;

struct Mediator {
  vector<Participant*> participants;  
};


struct Participant
{
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : mediator(mediator)
    {
      mediator.participants.push_back(this);
    }

    void say(int value)
    {
        // todo
        for(auto &p:mediator.participants){
            if(p!=this){
                p->value = value;
            }
        }
    }
};