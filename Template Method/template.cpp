#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct Creature
{
    int attack, health;

    Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
    vector<Creature> creatures;

    CardGame(const vector<Creature> &creatures) : creatures(creatures) {}

    // return the index of the creature that won (is a live)
    // example:
    // - creature1 alive, creature2 dead, return creature1
    // - creature1 dead, creature2 alive, return creature2
    // - no clear winner: return -1
    int combat(int c1, int c2)
    {
      // todo
    //   cout<<creatures[c1].attack<<"/"<<creatures[c1].health<<" "<<creatures[c2].attack<<"/"<<creatures[c2].health<<endl;
      hit(creatures[c1],creatures[c2]);
      hit(creatures[c2],creatures[c1]);
      auto is1alive = creatures[c1].health > 0;
      auto is2alive = creatures[c2].health > 0;
    //   cout<<is1alive<<" "<<is2alive<<endl;
      if(!is1alive && !is2alive) return -1;
      if(!is1alive) return c2;
      if(!is2alive) return c1;
      return -1;
    }

    virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override {
      // todo
      if(attacker.attack >= other.health) {
          other.health -= attacker.attack;
      }
    }
};

struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override
    {
      // todo
      other.health -= attacker.attack;
    }
};