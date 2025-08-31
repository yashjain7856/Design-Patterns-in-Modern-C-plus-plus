#include <vector>
using namespace std;

struct Creature;

struct Game
{
  vector<Creature*> creatures;
};

struct StatQuery
{
  enum Statistic { attack, defense } statistic;
  int result;
};

struct Creature
{
protected:
  Game& game;
  int base_attack, base_defense;

public:
  Creature(Game &game, int base_attack, int base_defense)
    : game(game), base_attack(base_attack), base_defense(base_defense) {}

  virtual void query(Creature* source, StatQuery& sq) = 0;

  virtual int get_attack()
  {
    StatQuery q{ StatQuery::attack, 0 };
    for (auto c : game.creatures)
      c->query(this, q);
    return q.result;
  }

  virtual int get_defense()
  {
    StatQuery q{ StatQuery::defense, 0 };
    for (auto c : game.creatures)
      c->query(this, q);
    return q.result;
  }
};

class Goblin : public Creature
{
public:
  Goblin(Game &game, int base_attack, int base_defense)
    : Creature(game, base_attack, base_defense) {}

  Goblin(Game &game)
    : Creature(game, 1, 1) {}

  void query(Creature* source, StatQuery& sq) override
  {
    if (source == this)
    {
      if (sq.statistic == StatQuery::attack)
        sq.result += base_attack;
      else if (sq.statistic == StatQuery::defense)
        sq.result += base_defense;
    }
    else
    {
      if (sq.statistic == StatQuery::defense)
        sq.result += 1; // every other goblin gives +1 defense
    }
  }
};

class GoblinKing : public Goblin
{
public:
  GoblinKing(Game &game)
    : Goblin(game, 3, 3) {}

  void query(Creature* source, StatQuery& sq) override
  {
    if (source == this)
    {
      if (sq.statistic == StatQuery::attack)
        sq.result += base_attack;
      else if (sq.statistic == StatQuery::defense)
        sq.result += base_defense;
    }
    else
    {
      if (sq.statistic == StatQuery::attack)
        sq.result += 1; // gives +1 attack to other goblins
      if (sq.statistic == StatQuery::defense)
        sq.result += 1; // gives +1 defense as a goblin
    }
  }
};
