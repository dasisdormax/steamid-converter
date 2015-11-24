# steamid-converter
A simple steamid string parser and converter

This includes a small class "SteamID", that can be used to read strings programmatically, detect their format, and store the information in a 64-bit data structure.

# The SteamID class
Parse a SteamID string by using `id = new SteamID(std::string steamidstr [, SteamIDFormat format] )` or `id = new SteamID(unsigned long steamid64)`.

Export your id as string using `id.asString(SteamIDFormat format)`

# The command line program

TO BE DONE
