/* prob5 */
#include <iostream>
#include <stdio.h>
using namespace std;

class person{
protected:
  string name;
public:
  person(){}; // constructor
  void setName(string n){name = n;}
  string getName(){return name;}
};

int main()
{
  person user;
  string name;
  cout << "ユーザの名前を入力してください: ";
  cin >> name;
  user.setName(name);

  cout << "ユーザ名: " << user.getName()<< "\n";

}
