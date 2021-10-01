/* #include <bits/stdc++.h> */ // Apparently this is used for competitive
                               // programming
#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::string uppercase;
  std::string lowercase;
  std::string numbers;
  std::string extra;
  std::string symbols;
  std::string message;
  int key;
  int position;

  uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  lowercase = "abcdefghijklmnopqrstuvwxyz";
  numbers = "1234567890";
  extra = " !?";

  symbols = lowercase + uppercase + numbers + extra;

  /* Ask for the message to be encrypted/decrypted */
  std::cout << "Write down your message: ";
  std::getline(std::cin, message);

  /* Enter key */
  std::cout << "Enter encryption/decryption key: ";
  std::cin >> key;

  /* To allow negative keys */
  if (key < 0) {
    reverse(symbols.begin(), symbols.end());
    key = -key;
  }

  /* Encryption/decryption */
  for (int i = 0; i < message.length(); ++i) {
    if (symbols.find(message[i]) != std::string::npos) {
      position = (symbols.find(message[i]) + key) % symbols.length();
      message[i] = symbols[position];
    }
  }

  /* Print encrypted/decrypted message */
  std::cout << message << std::endl;
}
