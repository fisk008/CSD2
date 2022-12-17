#include <iostream>

class UserInput{
public:

UserInput();
~UserInput();
bool validateSelection(std::string selection, std::string selectionOptions[],int numOptions);

std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

std:: string retrieveUserSelection(std::string selectionOptions[], int numOptions);

float retrieveValueInRange(float min, float max);
};