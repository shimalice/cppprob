/* prib11 */
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
  string filename, b_filename;
  cout << "バックアップをとるファイル名を入力してください．";
  cin >> filename;

  // ファイル読み込み
  ifstream fin(filename);
  if(!fin){cout << "入力ファイルが開けません"; return 1;}
  string str;

  b_filename = filename + ".backup";
  // ファイル書き出し
  ofstream fout(b_filename);
  if(!fout){cout << "出力ファイルが開けません"; return 1;}
  int i;
  while(!fin.eof()){
    fin >> str;
    fout << str << "\n";
    i++;
  }
  fout.close();
  fin.close();

  return 0;
}
