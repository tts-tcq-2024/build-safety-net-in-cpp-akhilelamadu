#include <gtest/gtest.h>
#include "Soundex.h"


TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
}

TEST(SoundexTest, HandlesMultipleCharacters) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Rupert"), "R163");
    EXPECT_EQ(generateSoundex("Rubin"), "R150");
}

TEST(SoundexTest, HandlesCaseInsensitivity) {
    EXPECT_EQ(generateSoundex("Ashcroft"), generateSoundex("ashcroft"));
}

TEST(SoundexTest, HandlesNonAlphabeticalCharacters) {
    EXPECT_EQ(generateSoundex("A123"), "A000");
    EXPECT_EQ(generateSoundex("A!@#"), "A000");
}

TEST(SoundexTest, HandlesNoSoundexCodes) {
    EXPECT_EQ(generateSoundex("Aeio"), "A000");
}

TEST(SoundexTest, HandlesNameWithVowels) {
    EXPECT_EQ(generateSoundex("Abraham"), "A165");
}

TEST(SoundexTest, TrimsToFourCharacters) {
    EXPECT_EQ(generateSoundex("Washington"), "W252");

TEST(SoundexTest, abc) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");

    
}

TEST(SoundexTest, PadsWithZerosIfNeeded) {
    EXPECT_EQ(generateSoundex("Ray"), "R000");
    EXPECT_EQ(generateSoundex("P"), "P000");
}
