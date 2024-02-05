# CDSVReader Markdown File

This is a class to read DMV (delimiter-seperated-value) files.

## CDSVReader::CDSVReader

This function takes parameters: 'std::shared_ptr<CDataSource> src' and 'char delimiter', which create a shared pointer to the data source and define a character to use as the delimiting value.

## CDSVReader::~CDSVReader

This function is called when, somewhere in the class, an object is going to be destroyed. This allows for any dynamically allocated memory to be released. This is to prevent any leaks.

## bool CDSVReader::End() const

This function takes no parameters, and returns a boolean value indicitive of of whether or not all rows of the DSV have been read.

ex: True if all rows have been read. False if not all rows have been read.

## bool CDSVReader::ReadRow(std::vector<std::string>)

This function has the parameter 'std::vector<std::string>& row' which is vector of strings where the data from the row is going to be stored. This function returns True if at least one row has been read.