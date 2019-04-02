#include <iostream>
#include <string>
using namespace std;

int partition(char[] str, int low, int high);
void quickSort(char[]  str, int l, int r);
bool checkPermutation(char[] a, char[] b);



int main() {
  char[] a = "aabasd";
  char[] b = "abaads";

  cout<<checkPermutation(a, b)<<"\n";
  return 0;
}

bool checkPermutation(char[] a, char[] b) {
  quickSort(a, 0, a.length());
  quickSort(b, 0, b.length());

  cout<<a<<"\n";
  cout<<b<<"\n";
  if (a == b) return true;
  return false;
}

void quickSort(char[] str, int l, int r) {
  if (l < r) return;

  // Partition str into partially sorted str'
  int pivot = partition(str, l, r);

  // Sort left part and right part
  quickSort(str, l, pivot-1);
  quickSort(str, pivot+1, r);
}

int partition(char[] str, int low, int high) {
  char pivot = str[high];
  int i = low-1;

  for (int j = low; j <= high; j++) {
    if (str[j] <= pivot) {
      i++;
      swap(str[i], str[j]);
    }
  }
  swap(str[i+1], pivot);
  return (i+1);
}
