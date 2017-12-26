/* h2 */
#include <iostream>
using namespace std;

class bookshelf{
protected:
  string top, middle, bottom, null;
public:
  bookshelf();
  string& getShelf(string destination);
  void showShelves();
};

bookshelf::bookshelf(){
  top = "test";
  middle = "test";
  bottom = "test";
}

string& bookshelf::getShelf(string destination){
  if (destination == "すぐ読む") {
    return top;
  } else if (destination == "あとで読む") {
    return middle;
  } else if (destination == "積ん読") {
    return bottom;
  } else {
    return null;
  }
}

void bookshelf::showShelves(){
  cout << top << "\n";
  cout << middle << "\n";
  cout << bottom << "\n";
}

int main(){
  bookshelf bs;
  string bookname;
  string destination;

  while(1){
    cout << "本棚に登録する本の名前を入力してください（終了するにはquitと入力してください）: \n";
    cin >> bookname;
    if(bookname == "quit"){break;}
    cout << "いつ読みますか: すぐ読む/あとで読む/積ん読）: \n";
    cin >> destination;
    bs.getShelf(destination) = bookname;
    bs.showShelves();
  }
};
