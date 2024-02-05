# CDSVWriter Functions

## SpecialCharacter function

Parameters: 'const std::string &value' 
This is the input string

This function takes an input string and checks for any special characters, and returns a boolean True or False value depending on whether or not any are present.

## QuoteString Function

Parameters: 'const std::string &value'
This is the input string to quote

This function quotes the input string and replaces any double quote characters with two double quote characters. This makes it so that any confusion from special characters in the DSV writing is avoided.

## WriteRow Function

Parameters: 'const std::vector<std::string> &row'
This is the vector of strings that represents a row to be written

This function writes a row on the DSV using the provided vector of strings. It considers the delimter and quote rules to format. This function facilitates the writing of the rows.