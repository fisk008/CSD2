#include "jack_module.h"
#include "callback.h"

#include <array>
#include <iostream>

int main() {

    auto callback = Callback {};
    auto jack = JackModule (callback);
    Amp amp;
    
    // start jack client with 2 inputs and 2 outputs
    jack.init (1, 2);
    amp.setAmpValue(0.3);
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }

    return 0;
}
