#include <iostream>
#include "hello.h"

using namespace std;


HelloGoodbye::HelloGoodbye(void)
{
  encounter=0;
} // HelloGoodbye()


void HelloGoodbye::greeting(void)
{
  if(encounter) cout << "Doei" << endl;
  else cout << "Hallo" << endl;

  encounter = !encounter; // toggle
} // greeting()

int main()
{
HelloGoodbye hg;

  hg.greeting();
  hg.greeting();
  hg.greeting();
  hg.greeting();
}