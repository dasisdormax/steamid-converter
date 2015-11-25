#include "steamid.h"

uint16_t SteamID::getUniverse()
{
  return id64 >> 56;
}

uint16_t SteamID::getAccountType()
{
  return (id64 >> 52) & 0x0F;
}

uint32_t SteamID::getInstance()
{
  return (id64 >> 32) & 0x000FFFFF;
}

uint32_t SteamID::getAccountID()
{
  return id64 & 0xFFFFFFFF;
}

bool SteamID::validate()
{
  // TODO: Do something
  return true;
}

SteamID *SteamID::setUniverse(uint16_t universe)
{
  uint64_t fu = ((uint64_t) universe) << 56;
  id64 = (id64 & 0x00FFFFFFFFFFFFFF) | fu;
  return this;
}

SteamID *SteamID::setAccountType(uint16_t type)
{
  uint64_t ft = ((uint64_t)type & 0x0F) << 52;
  id64 = (id64 & 0xFF0FFFFFFFFFFFFF) | ft;
  return this;
}

SteamID *SteamID::setInstance(uint32_t instance)
{
  uint64_t fi = ((uint64_t)instance & 0x000FFFFF) << 32;
  id64 = (id64 & 0xFFF00000FFFFFFFF) | fi;
  return this;
}

SteamID *SteamID::setAccountID(uint32_t accountID)
{
  id64 = (id64 & 0xFFFFFFFF00000000) | accountID;
  return this;
}

void SteamID::parseString(std::string input, SteamID::Format format)
{
  if (format == SteamID::Format::AutoDetect)
  {
    // Try detecting the format based on the first character
    switch (input[0]) 
    {
      case '[':
        format = SteamID::Format::Modern;
        break;
      case 'S':
        format = SteamID::Format::Legacy;
        break;
      default:
        format = SteamID::Format::Number;
        break;
    }
  }
  // initialize the id with 0, just to be safe
  this->id64 = 0;
  switch (format)
  {
    case SteamID::Format::Modern:
      break;
    case SteamID::Format::Legacy:
      break;
    case SteamID::Format::Number:
      break;
    default:
      break;
      // ERROR ?????
  }
}

SteamID::SteamID(std::string input, SteamID::Format format)
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
