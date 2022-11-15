#include <iostream>
class instrument
{

public:
    std::string sound = " sweep ";
    

    void play()
    {
    std::cout << "kaas: " << sound << std::endl;
    }
};





int main(){
instrument kaasballen;

kaasballen.play();

return 0;
}