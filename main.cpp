#include "steamid.h"
#include <iostream>

int main(int argc, char *argv[])
{
  SteamID* id = new SteamID(1);

  std::cout << "Universe:     " << id->getUniverse() << std::endl;

  std::cout << "Account Type: " << id->getAccountType() << std::endl;

  std::cout << "Instance:     " << id->getInstance() << std::endl;

  std::cout << "Account ID:   " << id->getAccountID() << std::endl;
}
