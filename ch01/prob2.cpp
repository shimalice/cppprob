/* prob2 */
#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name;
};

class addressbook{
  person friends[100];
  int numberOfFriends;
public:
  addressbook();
  void listFriends();
  void addFriend(string n);
  void addFriend(string n, string a);
};

// constructor
addressbook::addressbook(){
  numberOfFriends = 0;
}

void addressbook::addFriend(string n){
  friends[numberOfFriends].name = n;
  numberOfFriends++;
}

void addressbook::addFriend(string n, string a){
  friends[numberOfFriends].name = n;
  friends[numberOfFriends].address = a;
  numberOfFriends++;
}


void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << "\n";
    cout << friends[i].address << "\n";
  }
}

int main()
{
  addressbook abook;
  string name;
  string address;

  while(1){
    cout << "住所録に登録する名前, アドレスを入力してください（終了するにはquitと入力してください）: \n";
    cin >> name;
    if(name == "quit"){break;}
    cin >> address;
    //   cout << "name.length() = " << name.length() << "\n";
    abook.addFriend(name, address);
  }

  cout << "\n名前リスト:\n";
  abook.listFriends();
}
