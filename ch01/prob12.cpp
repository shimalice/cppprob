/* prob12 */
#include <iostream>
using namespace std;

class ex_account_too_long{
public:
  string account;
  ex_account_too_long(string str){account = str;};
  string show(){return "アカウント '" + account + "' は長すぎます。";};
};

class ex_account_too_short{
public:
  string account;
  ex_account_too_short(string str){account = str;};
  string show(){return "アカウント '" + account + "'は短すぎます.";};
};

int main(){

  string account;
  int accountlenlim = 6;
  int accountlenmin = 2;
  cout << "希望アカウントを入力してください（英数字6文字以内）: ";
  cin >> account;

  try{
    if(account.length() > accountlenlim){
      ex_account_too_long ex2long(account);
      throw ex2long;
    }else if(account.length() < accountlenmin){
      ex_account_too_short ex2short(account);
      throw ex2short;
    }else{
      cout << "\n" << account << "さん、ようこそ！\n\n";
    }
  }catch(ex_account_too_long e){
    cout << "\nException: " << e.show() << "\n\n";
  }catch(ex_account_too_short e){
    cout << "\nException: " << e.show() << "\n\n";
  }
}
