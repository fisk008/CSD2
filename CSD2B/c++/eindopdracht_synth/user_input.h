#include <iostream>
#pragma once
//this code was given to me by my teachers Cyska and marc and belongs to them, i added some functionalities 
class UserInput{
public:

    UserInput();
    ~UserInput();

    std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

    bool validateSelection(std::string selection, std::string selectionOptions[],int numOptions);
    int retrieveUserSelection(std::string selectionOptions[], int numOptions);
    float retrieveValueInRange(float min, float max);
    float retrieveBPMInRange(float min, float max);
    

};