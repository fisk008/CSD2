#include <iostream>
#pragma once

class UserInput{
public:

UserInput();
bool validateSelection(std::string selection, std::string selectionOptions[],int numOptions);

std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

int retrieveUserSelection(std::string selectionOptions[], int numOptions);

float retrieveValueInRange(float min, float max);
float retrieveBPMInRange(float min, float max);
~UserInput();

};