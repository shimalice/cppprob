/* prob10 */
#include <iostream>
using namespace std;

class person{
protected:
  string name;
public:
  person(){};
  void setName(string n){name = n;};
  virtual void requestData(){}; // 仮想関数
  virtual void showData(){}; // 仮想関数
};

class par_node{
public:
  person* participant;
  par_node* next;
};

class member : public person{
public:
  int memberid;
  virtual void requestData(){
    cout << "    会員番号を入力してください。\n    ";
    cin >> memberid;
  };
  virtual void showData(){
    cout << "  " << name << "(会員) 会員番号:" << memberid << "\n";
  };
};

class stmember : public member{
  int grade;
public:
  void requestData(){
    cout << "    会員番号を入力してください。\n    ";
    cin >> memberid;
    cout << "    学年を入力してください. \n    ";
    cin >> grade;
  };
  void showData(){
    cout << "  " << name << "(学生会員) 会員番号:" << memberid << ", 学年:" << grade << "\n";
  };
};

class nonmember : public person {
  string email;
  string phone;
public:
  void requestData(){
    cout << "    メールアドレスを入力してください。\n    ";
    cin >> email;
    cout << "    電話番号を入力してください。\n    ";
    cin >> phone;
  };
  void showData(){
    cout << "  " << name << "(非会員) " << email << " / " << phone << "\n";
  };
};

int main()
{
  int i = 0;
  string name, mtype, stype;
  par_node* p = new par_node;
  par_node* q = p;

  while(1){
    cout << "名前を入力してください。（終了する場合はquitと入力してください）\n";
    cin >> name;
    if(name == "quit"){break;}
    cout << "  会員ですか？(y/n) \n  ";
    cin >> mtype;
    if(mtype == "y"){
      cout<<"  学生会員ですか?(y/n) \n  ";
      cin >> stype;
      if (stype == "y") {
        q->participant = new stmember;
      } else if (stype == "n") {
        q->participant = new member;
      } else {
        cout << "  入力が間違えています．";
      }
    }else{
      q->participant = new nonmember;
    }
    q->participant->setName(name);
    q->participant->requestData();
    q->next = new par_node;
    q = q->next;
    i++;
  }

  cout << "\n参加者一覧：\n";
  q = p;
  while(i > 0){
    q->participant->showData();
    q = q->next;
    i--;
  }
  cout << "\n";
}
