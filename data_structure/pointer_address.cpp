#include <iostream>
using namespace std;

int main() {
  int num = 10;
  int* pointer;
  cout<<pointer<<"\n";
  cout<<&pointer<<"\n";
  pointer = &num;
  cout<<pointer<<"\n";
  cout<<&pointer<<"\n";
  cout<<*pointer<<"\n";
  return 0;
}
