/* 抽象クラス */

class content{
protected:
  string name;
public:
  content(){};
  void setName(string n){name = n;};
  virtual void requestData() = 0; // 純粋仮想関数,インタフェース
  virtual void showData() = 0; // 純粋仮想関数,インタフェース
};

class con_node{
public:
  content* contents;
  con_node* next;
};

class movie : public content{
public:
  int movieid;
  virtual void requestData(){
    cout << "    映画番号を入力してください。\n    ";
    cin >> movieid;
  };
  virtual void showData(){
    cout << "  映画番号:" << movieid << ",映画名:" << name << "\n";
  };
};

class tvseries : public content{
  int tvid;;
public:
  void requestData(){
    cout << "    テレビ番組番号を入力してください。\n    ";
    cin >> tvid;
  };
  void showData(){
    cout << "  テレビ番組番号:" << tvid << ",テレビ番組名:" << name << "\n";
  };
};



int main()
{
  int i = 0;
  string name, mtype;
  con_node* p = new con_node;
  con_node* q = p;

  while(1){
    cout << "コンテンツ名を入力してください。（終了する場合はquitと入力してください）\n";
    cin >> name;
    if(name == "quit"){break;}
    cout << "  映画ですか？テレビ番組ですか？(m/t) \n  ";
    cin >> mtype;
    if(mtype == "m"){
      q->contents = new movie;
    }else{
      q->contents = new tvseries;
    }
    q->contents->setName(name);
    q->contents->requestData();
    q->next = new con_node;
    q = q->next;
    i++;
  }

  cout << "\n参加者一覧：\n";
  q = p;
  while(i > 0){
    q->contents->showData();
    q = q->next;
    i--;
  }
  cout << "\n";
}
