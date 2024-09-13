# Test Specification for `Soundex` Function

## Test File: `SoundexTest.cpp`
## Test Class: `SoundexTest`

## Objective
The goal is to verify the correctness of the `generateSoundex` function across different input scenarios, including edge cases such as empty strings, single-character inputs, multiple-character names, and handling of special characters and case sensitivity.

## Test Cases

### 1. **Test: ChecksEmptyString**
- **Purpose**: Ensure that an empty string returns an empty Soundex code.
- **Input**: `""`
- **Expected Output**: `""`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, ChecksEmptyString) {
        EXPECT_EQ(generateSoundex(""), "");
    }
    ```

### 2. **Test: ChecksSingleCharacter**
- **Purpose**: Validate that a single alphabetic character is padded with zeros to form a four-character code.
- **Inputs**: `"A"`, `"B"`
- **Expected Outputs**:
  - `"A"` → `"A000"`
  - `"B"` → `"B000"`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, ChecksSingleCharacter) {
        EXPECT_EQ(generateSoundex("A"), "A000");
        EXPECT_EQ(generateSoundex("B"), "B000");
    }
    ```

### 3. **Test: ChecksMultipleCharacters**
- **Purpose**: Confirm that names with multiple characters generate valid Soundex codes.
- **Inputs**: `"Robert"`, `"Rupert"`, `"Rubin"`
- **Expected Outputs**:
  - `"Robert"` → `"R163"`
  - `"Rupert"` → `"R163"`
  - `"Rubin"` → `"R150"`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, ChecksMultipleCharacters) {
        EXPECT_EQ(generateSoundex("Robert"), "R163");
        EXPECT_EQ(generateSoundex("Rupert"), "R163");
        EXPECT_EQ(generateSoundex("Rubin"), "R150");
    }
    ```

### 4. **Test: ChecksCaseInsensitivity**
- **Purpose**: Ensure that the function produces identical Soundex codes for names regardless of case (upper or lower).
- **Inputs**: `"Ashcroft"`, `"ashcroft"`
- **Expected Output**: Both inputs should generate the same Soundex code.
- **Test Code**:
    ```cpp
    TEST(SoundexTest, ChecksCaseInsensitivity) {
        EXPECT_EQ(generateSoundex("Ashcroft"), generateSoundex("ashcroft"));
    }
    ```

### 5. **Test: ChecksNonAlphabeticalCharacters**
- **Purpose**: Verify that non-alphabetical characters are ignored during Soundex code generation.
- **Inputs**: `"A123"`, `"A!@#"`
- **Expected Outputs**:
  - `"A123"` → `"A000"`
  - `"A!@#"` → `"A000"`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, ChecksNonAlphabeticalCharacters) {
        EXPECT_EQ(generateSoundex("A123"), "A000");
        EXPECT_EQ(generateSoundex("A!@#"), "A000");
    }
    ```

### 6. **Test: ChecksNoSoundexCodes**
- **Purpose**: Check that names containing no consonants still generate a valid Soundex code with padding.
- **Input**: `"Aeio"`
- **Expected Output**: `"A000"`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, ChecksNoSoundexCodes) {
        EXPECT_EQ(generateSoundex("Aeio"), "A000");
    }
    ```

### 7. **Test: ChecksNameWithVowels**
- **Purpose**: Ensure correct Soundex generation when vowels are present in the input.
- **Input**: `"Abraham"`
- **Expected Output**: `"A165"`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, ChecksNameWithVowels) {
        EXPECT_EQ(generateSoundex("Abraham"), "A165");
    }
    ```

### 8. **Test: TrimsToFourCharacters**
- **Purpose**: Ensure that the Soundex code is limited to four characters, trimming excess characters if necessary.
- **Input**: `"Washington"`
- **Expected Output**: `"W252"`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, TrimsToFourCharacters) {
        EXPECT_EQ(generateSoundex("Washington"), "W252");
    }
    ```

### 9. **Test: PadsWithZerosIfNeeded**
- **Purpose**: Check that the Soundex code is padded with zeros if it is shorter than four characters.
- **Inputs**: `"Ray"`, `"P"`
- **Expected Outputs**:
  - `"Ray"` → `"R000"`
  - `"P"` → `"P000"`
- **Test Code**:
    ```cpp
    TEST(SoundexTest, PadsWithZerosIfNeeded) {
        EXPECT_EQ(generateSoundex("Ray"), "R000");
        EXPECT_EQ(generateSoundex("P"), "P000");
    }
    ```
