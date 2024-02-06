# CDSVWriter

## SImplementation Stucture

### Consutructor

SImplementation(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall);

This initializes the structure with a data sink, a flag, and a delimiter. It takes 3 parameters: sink, delimiter, and quoteall, and initializes them with the provided values.

### Destructor

~SImplementation();

This is a destruct with default setting.

### WriteRow

bool WriteRow(const std::vector<std::string>& row);

Parameters: 'const std::vector<std::string> &row'
This is the vector of strings that represents a row to be written

It checks if the sink is valid or not and returns a boolean value accordingly. It iterates through each cell in the row and takes care of any special delimiters, quoting instances, and newlines.

The WriteRow method also initializes flags like firstColum and isFirstRow which helps manage the format of the output.

With the delimitiers, if it is not the first column, it ouputs the delimiter based on the specified character, unless it is a double quote. 

If it is a quote, we enclose the value in double quotes.