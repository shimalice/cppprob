/* prob8 */
#include <iostream>
using namespace std;

void swap(int &x, int &y){
  int a = x;
  x = y;
  y = a;
}

int main(){
  int x = 10;
  int y = 20;
  cout << "x:" << x << ", y:" << y << "\n";
  swap(x, y);
  cout << "x:" << x << ", y:" << y << "\n";
}
