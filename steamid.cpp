#include "steamid.h"

SteamUniverse SteamID::getUniverse()
{
  return id64 >> 56;
}

SteamAccountType SteamID::getAccountType()
{
  return (id64 >> 52) & 0x0F;
}

unsigned int SteamID::getInstance()
{
  return (id64 >> 32) & 0x000FFFFF;
}

unsigned int SteamID::getAccountID()
{
  return id64 & 0xFFFFFFFF;
}

bool SteamID::validate()
{
  // TODO: Do something
  return true;
}

SteamID *SteamID::setUniverse(SteamUniverse universe)
{
  SteamUniverse filteredUniverse = universe & 0xFF;
  id64 = id64 - getUniverse() + filteredUniverse;
  return this;
}

SteamID *SteamID::setAccountType(SteamAccountType type)
{
  SteamAccountType filteredType = type & 0x0F;
  id64 = id64 - getAccountType() + filteredType;
  return this;
}

SteamID *SteamID::setInstance(unsigned int instance)
{
  unsigned int filteredInstance = instance & 0x000FFFFF;
  id64 = id64 - getInstance() + filteredInstance;
  return this;
}

SteamID *SteamID::setAccountID(unsigned int accountID)
{
  id64 = id64 - getAccountID() + accountID;
  return this;
}

void SteamID::parseString(std::string input, SteamIDFormat format)
{
  if (format == SteamIDFormat::AutoDetect)
  {
    // Try detecting the format based on the first character
    switch (char firstchar = input.first()) 
    {
      case '[':
        format = SteamIDFormat::StringModern;
        break;
      case 'S':
        format = SteamIDFormat::StringLegacy;
        break;
      default:
        format = SteamIDFormat::Int64;
        break;
    }
  }
  // initialize the id with 0, just to be safe
  this->id64 = 0;
  switch (format)
  {
    case SteamIDFormat::StringModern:
      break;
    case SteamIDFormat::StringLegacy:
      break;
    case SteamIDFormat::Int64:
      break;
    default:
      // ERROR ?????
  }
}

SteamID::SteamID(std::string input, SteamIDFormat format)
{
  parseString(input, format);
}

SteamID::SteamID(unsigned long id64)
{
  this->id64 = id64;
}

SteamID::SteamID()
{
  this->id64 = 0;
}
