#include <algorithm>
#include <iostream>
#include <string>

/* Usr input variables */
std::string message;
std::string mode;
int key;

/* Available characters */
std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
std::string numbers = "1234567890";
std::string extra = " ,.:;!?";
std::string symbols = lowercase + uppercase + numbers + extra;

/* Ask for encryption/decryption mode */
void ask_mode() {
  std::cout << "Select mode encrypt[enc] / decrypt[dec]: ";
  std::getline(std::cin, mode);

  if (mode != "enc" && mode != "dec") {
    std::cout << "Select a valid mode." << std::endl;
    ask_mode();
  }

  if (mode == "dec") {
    reverse(symbols.begin(), symbols.end());
  }

  return;
}

void ask_message() {
  std::cout << "Write down your message (MAX length: " << symbols.length()
            << " charcters): ";
  std::getline(std::cin, message);

  /* Maximum length of the message */
  if (message.length() > 100) {
    std::cout << "Invalid message length." << std::endl;
    ask_message();
  }

  return;
}

void ask_key() {
  std::cout << "Enter encryption/decryption key [1 - " << symbols.length()
            << "] : ";
  std::cin >> key;

  if (key > symbols.length() || key <= 0) {
    std::cout << "Enter a valid key." << std::endl;
    ask_key();
  };

  return;
}

int main() {
  int position;

  /* Call the functions to enter the required information  */
  ask_message();
  ask_mode();
  ask_key();

  /* Use a ranged-loop to encrypt/decrypt all the characters of the message */
  for (auto &character : message) {
    if (symbols.find(character) != std::string::npos) {
      position = (symbols.find(character) + key) % symbols.length();
      character = symbols[position];
    }
  }

  /* Print encrypted/decrypted message */
  std::cout << message << std::endl;
}
