struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    // todo
    if(cmd.action == cmd.Action::deposit){
        balance += cmd.amount;
        cmd.success = true;
    } else if(cmd.amount > balance) {
        cmd.success = false;
    } else {
        balance -= cmd.amount;
        cmd.success = true;
    }
  }
};