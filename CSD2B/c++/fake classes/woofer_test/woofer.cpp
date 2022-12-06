#include <iostream>
#include <math.h>


class Woofer
{
public:
  float magnet;
  float coil;

  void move(float position)
  {
  
  coil = position;
  }

  void printcoilposition()
  {
  
  std::cout << "Coil position: " << coil << std::endl;
  }



};


int main()
{
  Woofer myWoofer;
  
  for(int i = 0; i < 10; i++){
  myWoofer.move(i);
  myWoofer.printcoilposition();
  }
  
  return 0;
}

