/*#include <iostream>
#include <string>
using namespace std;

int main()
{
    int Dec;
    string Bin = "";
    // cout << "Nhập số nguyên dương Dec: ";
    cin >> Dec;
    while (Dec > 0)
    {
        Bin = to_string(Dec % 2) + Bin;
        Dec /= 2;
    }
    // cout << "Số nhị phân tương ứng: " <<
    cout << Bin << endl;
    return 0;*/

#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int dec, bin = 0, product = 1;
  string kq;
  cin >> dec;
  while (dec != 0) 
  {
    bin = bin + (dec % 2 * product);
    dec = dec / 2;
    product *= 10;
  }
  //cout << bin;
  kq=to_string(bin);
  cout<<kq;
  return 0;
}
