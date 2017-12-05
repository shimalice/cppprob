/* prob3 */
#include <iostream>
using namespace std;
#include <string.h>


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
  person find(string query);
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

person addressbook::find(string query){
  int n;
  for(int i = 0; i < numberOfFriends; i++){
    if (friends[i].name == query) {
      n = i;
    }
  }
  return friends[n];
}

int main()
{
  addressbook abook;
  string name;
  string address;
  string query;
  person friend_found;

  while(1){
    cout << "住所録に登録する名前, アドレスを入力してください（終了するにはquitと入力してください）: \n";
    cin >> name;
    if(name == "quit"){break;}
    cin >> address;
    //   cout << "name.length() = " << name.length() << "\n";
    abook.addFriend(name, address);
  }

  cout << "\n住所を検索したい名前を入力してください:\n";
  cin >> query;
  friend_found = abook.find(query);
  cout << friend_found.address << "\n";
}
