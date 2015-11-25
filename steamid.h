#include <string>
#include <sstream>

class SteamID
{
  enum class Format : uint16_t {
    AutoDetect,
    Legacy,
    Modern,
    Number
  };

  enum class Universe : uint16_t {
    SU_Invalid  = 0,
    SU_Public   = 1,
    SU_Beta     = 2,
    SU_Internal = 3,
    SU_Dev      = 4
  };

  enum class AccountType : uint16_t {
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

  protected:
    uint64_t id64;
  public:
    uint16_t getUniverse();
    uint16_t getAccountType();
    uint32_t getInstance();
    uint32_t getAccountID();

    bool validate();

    SteamID *setUniverse    (uint16_t  universe);
    SteamID *setAccountType (uint16_t  type);
    SteamID *setInstance    (uint32_t instance);
    SteamID *setAccountID   (uint32_t accountid);

    void parseString(std::string input, Format = Format::AutoDetect);

    SteamID(std::string input, Format format = Format::AutoDetect);
    SteamID(uint64_t id64);
    SteamID();
};

