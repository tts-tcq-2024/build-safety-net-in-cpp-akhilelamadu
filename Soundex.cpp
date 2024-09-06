#include "Soundex.h"
#include <cctype>
#include <iostream>

// Function to get the Soundex code for a given character
char getSoundexCode(char c) {
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', '2', '4', '5', '5', '0', 
        '1', '2', '6', '2', '3', '0', '0', '0', '2', '0', '2'
    };

    c = toupper(c);
    return (c >= 'A' && c <= 'Z') ? soundexTable[c - 'A'] : '0';
}


void addSoundexCode(std::string& soundex, char c, char& prevCode) {
    char code = getSoundexCode(c);
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
}


void addCodes(std::string& soundex, const std::string& name) {
    char prevCode = getSoundexCode(name[0]);
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        addSoundexCode(soundex, name[i], prevCode);
    }
}


std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    // initialization with a single character string
    std::string soundex(1, toupper(name[0]));
    addCodes(soundex, name);

    soundex.resize(4, '0');
    return soundex;
}

