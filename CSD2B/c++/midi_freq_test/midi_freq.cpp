#include <iostream>
#include <cmath>

int main() {
  std::cout << "Enter MIDI note: ";
  int note;
  std::cin >> note;

  // Calculate frequency of MIDI note.
  double frequency = 440.0 * std::pow(2.0, (note - 69.0) / 12.0);

  std::cout << "Frequency: " << frequency << " Hz\n";

  return 0;
}
