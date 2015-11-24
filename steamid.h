#include <string>
#include <stringstream>

enum class SteamIDFormat {
  AutoDetect,
  StringLegacy,
  StringModern,
  Int64
};

enum SteamUniverse {
  SU_Invalid  = 0,
  SU_Public   = 1,
  SU_Beta     = 2,
  SU_Internal = 3,
  SU_Dev      = 4
};

enum SteamAccountType {
  ST_Invalid        = 0,
  ST_Individual     = 1,
  ST_Multiseat      = 2,
  ST_GameServer     = 3,
  ST_AnonGameServer = 4,
  ST_Pending        = 5,
  ST_ContentServer  = 6,
  ST_Clan           = 7,
  ST_Chat           = 8,
  ST_P2PSuperSeeder = 9,
  ST_AnonUser       = 10
};

class SteamID
{
  protected:
    unsigned long id64;
  public:
    SteamUniverse    getUniverse();
    SteamAccountType getAccountType();
    unsigned int     getInstance();
    unsigned int     getAccountID();

    bool validate();

    SteamID *setUniverse    (SteamUniverse    universe);
    SteamID *setAccountType (SteamAccountType type);
    SteamID *setInstance    (unsigned int     instance);
    SteamID *setAccountID   (unsigned int     accountid);

    void parseString(std::string input, SteamIDFormat = SteamIDFormat::AutoDetect);

    SteamID(std::string input, SteamIDFormat format = SteamIDFormat::AutoDetect);
    SteamID(unsigned long id64);
    SteamID();
};

