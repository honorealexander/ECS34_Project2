# ECS34_Project2

## Student 1: Honoré Alexander 921129112
## Student 2: Olive Maunupau 918816205

## Links
* I used this to help my understanding of XML
  * https://www.howtogeek.com/357092/what-is-an-xml-file-and-how-do-i-open-one/



### Propmt 1
void EndElementHandler(const std::string &name){
        
    }

Can you explain to me what EndElementHandler wants me to do? 

### Response 1
Certainly! The EndElementHandler function is a callback that gets invoked by the XML parser whenever it encounters the end of an XML element in the document being parsed. This function gives you an opportunity to perform any necessary actions or processing based on the end of the element.

Here's what you might typically do within the EndElementHandler:

Check the Name: The name parameter passed to the EndElementHandler function represents the name of the XML element that has just ended. You might want to inspect this name to determine which element has ended.

Process Element Data: If your XML document structure requires specific handling or processing when an element ends, you can implement that logic here. For example, if you're parsing an XML document representing a book, and each <book> element contains information about a book, you might want to gather all the data related to a book when the </book> element is encountered.

Update State or Data Structures: Depending on your application's needs, you might need to update some internal state or data structures to reflect the fact that an XML element has ended. For instance, if you're parsing a hierarchical structure like an XML tree, you might need to adjust the current node pointer or stack of nodes.

Error Handling: You might want to perform error handling or validation checks based on the element that has ended. For example, you could validate that certain required child elements were present within the parent element.

In summary, the EndElementHandler function provides a hook for you to respond to the end of XML elements during the parsing process. You can use it to perform any necessary actions or processing based on the specific requirements of your XML parsing application.

### Changes 1
I used this response to help me understand where I need to start for this funciton. I already had the code from discussion for this function but I wanted to understand it's purpose better.

### Prompt 2
What does each function want me to do?
CDSVReader(std::shared_ptr< CDataSource > src, char delimiter);
// Destructor for DSV reader
~CDSVReader();
// Returns true if all rows have been read from the DSV
bool End() const;
// Returns true if the row is successfully read, one string will be put in
// the row per column
bool ReadRow(std::vector< std::string > &row);

### Response 2
Sure, let's break down each function:

CDSVReader(std::shared_ptr< CDataSource > src, char delimiter);

This is a constructor function for the CDSVReader class. It takes two parameters:
src: a shared pointer to a CDataSource object, presumably the source from which to read data.
delimiter: a character that specifies the delimiter used in the delimited-separated values (DSV) file.
This function is responsible for initializing a CDSVReader object with the provided data source and delimiter.
~CDSVReader();

This is the destructor function for the CDSVReader class. It is called automatically when an object of the CDSVReader class goes out of scope or is explicitly deleted.
This function is responsible for releasing any resources (memory, file handles, etc.) that the CDSVReader object may have acquired during its lifetime.
bool End() const;

This function returns a boolean value indicating whether all rows have been read from the DSV (delimited-separated values) file.
It does not modify the state of the CDSVReader object and is marked as const, indicating that it does not modify any member variables of the object.
bool ReadRow(std::vector< std::string > &row);

This function attempts to read a row from the DSV file and store the values in the provided row vector.
It returns a boolean value indicating whether the row was successfully read.
If successful, the values of the row are stored in the row vector passed by reference.
This function modifies the state of the CDSVReader object by advancing its internal position to the next row in the file.

### Changes 2
Again I used this to help me start my code, was for understanding purposes. This allowed me to start my code.

### Prompt 3
CDSVWriter(std::shared_ptr< CDataSink > sink, char delimiter,
bool quoteall = false);

What does this want me to do and how can I implement this in my file?

### Response 3
The CDSVWriter constructor you provided expects several parameters:

sink: This is a shared pointer to a CDataSink object. It represents the destination where data will be written.

delimiter: This is a character that represents the delimiter to be used in the delimited-separated values (DSV) file. The delimiter separates the fields or columns in each row.

quoteall: This is a boolean parameter that determines whether to quote all values when writing rows. By default, it is set to false, indicating that quoting will not be applied to all values. However, you have the option to override this default behavior by setting it to true if you want all values to be quoted.

Given these parameters, the constructor is asking you to create an instance of the CDSVWriter class, providing at least a valid shared pointer to a CDataSink object and specifying the delimiter character to be used. Optionally, you can also specify whether you want all values to be quoted by setting the quoteall parameter accordingly.

To implement the constructor within your file, you'll follow a similar structure to what you already have. Here's how you can implement the constructor:

cpp
Copy code
#include "DSVWriter.h" // Include the header file for CDSVWriter
#include <memory> // Include the <memory> header for std::shared_ptr

// Define the constructor for the CDSVWriter class
CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimiter, bool quoteall)
    : DImplementation(std::make_unique<SImplementation>(sink, delimiter, quoteall))
{
    // Constructor implementation
    // Here you initialize DImplementation with a new SImplementation object
    // constructed with the provided sink, delimiter, and quoteall parameters.
}

// Destructor definition (already implemented)
CDSVWriter::~CDSVWriter() = default;
This code snippet defines the constructor for the CDSVWriter class. It takes a shared pointer to a CDataSink object (sink), a character representing the delimiter (delimiter), and a boolean flag indicating whether to quote all values (quoteall). Inside the constructor, it initializes the DImplementation member variable with a new instance of SImplementation created using std::make_unique, passing the provided parameters.

Remember to include necessary header files, such as "DSVWriter.h", and any other headers needed for the types used in the constructor (e.g., <memory> for std::shared_ptr).

### Changes 3
This prompted us to change our code within our DSVWriter.cpp file to:
CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimeter, bool quoteall)
    : DImplementation(std::make_unique<SImplementation>(sink, delimeter, quoteall)) {}

CDSVWriter::~CDSVWriter() = default;

under the struct.

### Prompt 4
How can I replace quote characters with double quotes within my WriteRow function?

### Response 4
To replace quote characters with double quotes within your WriteRow function, you can modify the loop that iterates over each character in the cell string. Here's how you can do it:

cpp
Copy code
for (char c : cell) {
    if (c == '"') {
        // If the character is a quote, output two quotes instead
        DImplementation->sink->Put('"');
        DImplementation->sink->Put('"');
    } else {
        // Otherwise, output the character as it is
        DImplementation->sink->Put(c);
    }
}
This loop checks each character in the cell string. If the character is a quote ("), it outputs two quote characters to the sink instead of one. Otherwise, it outputs the character as it is. This effectively replaces each quote character with double quotes in the output.

### Changes 4
Added this section into my writerow function, it is cited within the code as a comment.

### Prompt 5
bool CDSVWriter::WriteRow(const std::vector<std::string>& row) {
    if (!DImplementation->sink) {
        return false;
    } 

    bool isFirstRow = true;
    if (!isFirstRow) {
        DImplementation->sink->Put('\n'); 
    } else {
        isFirstRow = false; 
    }

    bool firstColumn = true;

    for (const std::string& cell : row) {
        if (!firstColumn) {
            if (DImplementation->delimeter == '"') { //checking to see if delimeter is " the delimeter interpret it as a comma according to guidelines
                DImplementation->sink->Put(','); 
            } else {
                DImplementation->sink->Put(DImplementation->delimeter);
            }
        }

        if (DImplementation->quoteall || //checks if quoteall is true
            cell.find(DImplementation->delimeter) != std::string::npos ||
            cell.find('"') != std::string::npos ||
            cell.find('\n') != std::string::npos) {
            DImplementation->sink->Put('"');

            // Replace double quote characters with two double quotes
            // got this section from ChatGPT (Changes 4 in ReadME)
            for (char c : cell) {
                if (c == '"') {
                    DImplementation->sink->Put('"');
                    DImplementation->sink->Put('"'); 
                } else {
                    DImplementation->sink->Put(c);
                }
            }

            DImplementation->sink->Put('"');
        } else {
            for (char c : cell) {
                DImplementation->sink->Put(c);
            }
        }

        firstColumn = false;
    }

    return true;

}

### Response 5
The issue with your first row section is that isFirstRow is declared inside the function and initialized to true every time the function is called. As a result, isFirstRow will always be true, and the code inside the if (!isFirstRow) block will never execute.

To fix this issue, you should declare isFirstRow as static, ensuring that its value persists across function calls. This way, it will correctly track whether it's the first row being written each time the function is called. Here's the modified version of your function:

cpp
Copy code
bool CDSVWriter::WriteRow(const std::vector<std::string>& row) {
    if (!DImplementation->sink) {
        return false;
    } 

    static bool isFirstRow = true; // Declare isFirstRow as static
    if (!isFirstRow) {
        DImplementation->sink->Put('\n'); 
    } else {
        isFirstRow = false; 
    }

    // Rest of your function remains unchanged...
}

### Changes 5
I added static to my bool variable and it started working.

### Prompt 6
  void StartElementHandler(const std::string &name, const std::vector<std::string> &attrs){
        SXMLEntity TempEntity;
        TempEntity.DNameData = name;
        TempEntity.DType = SXMLEntity::EType::StartElement;
        for(size_t i = 0; i < attrs.size(); i += 2){
            TempEntity.SetAttribute(attrs[i], attrs[i+1]);
        }
        DEntityQueue.push(TempEntity);
    }

    void EndElementHandler(const std::string &name){
        SXMLEntity TempEntity;
        TempEntity.DNameData = name;
        TempEntity.DType = SXMLEntity::EType::EndElement;
        DEntityQueue.push(TempEntity);
    }
    
    void CharacterDataHandler(const std::string &data){
        SXMLEntity TempEntity;
        TempEntity.DNameData = data;
        TempEntity.DType = SXMLEntity::EType::CharData;
        DEntityQueue.push(TempEntity);
}
Do my endelement handlers and characterdata handlers need loops or are these complete?

### Response 6

Based on the provided code, your EndElementHandler and CharacterDataHandler functions seem complete as they are. There's no need for loops in these handlers because you're dealing with individual XML elements or character data, which are typically singular entities.

However, your StartElementHandler function involves processing attributes, and you've correctly implemented a loop to handle them. This loop iterates over the attrs vector, which presumably contains attribute names followed by their corresponding values. Inside the loop, you're setting these attribute-value pairs using the SetAttribute function.

So, overall, your EndElementHandler and CharacterDataHandler functions do not require loops, but your StartElementHandler does due to the handling of attributes.

### Changes 6
Just added the comments about the loop, didn't change anything just wanted to make sure I had implemented these correctly since I was going along with what was done in discussion

### Prompt 7

What does the "no suitable conversion" error mean?

### Response 7

The "no suitable conversion" error typically occurs when there is an attempt to convert or assign a value of one type to another, but there is no valid conversion available between the two types.

In the context of C++ code, this error often happens when there is an incompatible type assignment or conversion. For example, it might occur when trying to assign a value of one data type to a variable of a different data type, and there is no direct or implicit conversion between them.

To resolve this error, you should carefully check the assignment or conversion in your code and make sure that the types involved are compatible. If there is no direct conversion, you might need to perform a manual conversion or reconsider the design of your code to ensure proper type compatibility.

If you provide the specific code snippet or line where this error is occurring, I can offer more targeted guidance on how to address the issue.

### Changes 7

I used this to idenitfy the issue in a line 'DImplementation->sink->Put(cell.begin(), cell.end()). I realized that I should modify my line to explicitly conver to constant character pointers before using them.

### Prompt 8

how does a quotestring function work with regards to DSV writing

### Response 8

A quoteString function in the context of Delimiter-Separated Values (DSV) writing is typically employed to handle cases where the data being written contains the delimiter character or other special characters. DSV formats, such as CSV (Comma-Separated Values) or TSV (Tab-Separated Values), use a specific character (e.g., comma or tab) to separate individual fields within a record.

The purpose of the quoteString function is to encapsulate a string within quotation marks if it contains the delimiter or any other characters that may cause misinterpretation during parsing. This ensures that the DSV parser correctly identifies the boundaries of each field, even if the data within the field includes the delimiter itself.

The basic steps involved in a quoteString function include:

Check for Special Characters: Examine the input string to identify whether it contains the delimiter character or any other characters that might interfere with the correct parsing of the DSV.

Quotation Mark Encapsulation: If special characters are found, encapsulate the entire string within double quotation marks. This signals to the parser that the enclosed content should be treated as a single field, irrespective of any internal delimiters.

Escape Existing Quotation Marks: If the string already contains double quotation marks, they are typically escaped to prevent misinterpretation. This often involves doubling the existing quotation marks within the string.

Return Modified String: Provide the modified string (either original or encapsulated within quotation marks) as the output of the quoteString function.

Example in Python:

python
Copy code
def quoteString(input_str, delimiter=','):
    if delimiter in input_str or '"' in input_str:
        # Encapsulate the string within double quotation marks
        return '"' + input_str.replace('"', '""') + '"'
    else:
        return input_str
This function can be utilized before writing data to a DSV file, ensuring that the resulting file maintains proper formatting and can be accurately parsed.

### Changes 8

This was very helpful in understanding how to appraoch the Writer function. I was confused about where to start but this helped me gain understand of what to do in special conditions. Specifically, this gave me a starting point to look at, which was special delimiters.

### Propmt 9
#include "XMLWriter.h"
#include "XMLEntity.h"
#include <expat.h>
#include "DataSink.h"

struct CXMLWriter::SImplementation {
    XML_Parser parser;
    std::shared_ptr<CDataSink> sink;

    SImplementation(std::shared_ptr<CDataSink> sink) : sink(sink) {
        parser = XML_ParserCreate(NULL);
        XML_SetUserData(parser, this);
    }

    ~SImplementation() {
        XML_ParserFree(parser);
    }

    bool Flush() {

    }

Can you explain to me what Flush() wants me to do and how I may implement it?

### Response 9
Certainly! If you want to use XML_Parse() to parse the remaining data and write it to your sink, you can do it like this:

cpp
Copy code
bool CXMLWriter::Flush() {
    // Parse remaining data and write it to the sink
    if (XML_Parse(parser, nullptr, 0, true)) {
        // Parsing and writing successful
        return true;
    } else {
        // Parsing or writing failed
        return false;
    }
}
In this implementation:

XML_Parse() is called with nullptr for the buffer, 0 for the length, and true to indicate that it should parse the remaining buffered data.
If XML_Parse() returns true, it means that parsing and writing were successful.
If XML_Parse() returns false, it means that either parsing or writing failed.
We return true or false accordingly to indicate the success or failure of the operation.
This approach directly utilizes XML_Parse() to handle parsing and writing of the remaining data in the parser, simplifying the implementation of the Flush() function. Adjust the implementation according to the specifics of your data sink and how it handles writing data.

### Changes 9
Add if (XML_Parse(parser, nullptr, 0, true)) { 
            return true;
        } else {
            return false;
        }
to XMLWriter.cpp. Chat cited in file.

### Prompt 10
./src/XMLWriter.cpp: In member function ‘bool CXMLWriter::SImplementation::WriteEntity(const SXMLEntity&)’:
./src/XMLWriter.cpp:28:16: warning: enumeration value ‘CompleteElement’ not handled in switch [-Wswitch]
   28 |         switch (entity.DType) {
      |                ^
g++ -o obj/XMLTest.o -c ./testsrc/XMLTest.cpp -std=c++17 -I ./include -Wall

### Response 10
The warning you're encountering indicates that there is a case in your switch statement where not all enumeration values of SXMLEntity::EType are being handled. Specifically, the compiler is warning you that the CompleteElement value is not being handled.

You can handle this case by adding a corresponding case in your switch statement. For example:

cpp
Copy code
bool CXMLWriter::SImplementation::WriteEntity(const SXMLEntity& entity) {
    switch (entity.DType) {
        case SXMLEntity::EType::StartElement:
            // Handle start element
            break;
        case SXMLEntity::EType::EndElement:
            // Handle end element
            break;
        case SXMLEntity::EType::CharData:
            // Handle character data
            break;
        case SXMLEntity::EType::CompleteElement:
            // Handle complete element
            break;
        default:
            // Handle unknown or unexpected entity type
            // This could be an error condition, depending on your design
            return false;
    }
    return true;  // Indicate success
}
In this example, I've added a case for SXMLEntity::EType::CompleteElement and provided a comment to indicate where you can handle this case in your code. Adjust the implementation according to your requirements and how you want to handle each type of XML entity.

### Changes 10
Used this response as an outline for my code in my XMLWriter.cpp. My error ended up going away for the CompleteElement so I deleted that part.


### Prompt 11
i have a static bool isFirstRow that is staying as false and not going back to true with each new test, how do I fix it?
bool CDSVWriter::WriteRow(const std::vector<std::string>& row) {
    if (!DImplementation->sink) {
        return false;
    } 

    static bool isFirstRow = true; //help from Chat, use static to make sure that it's not being changed everytime function is called
    if (!isFirstRow) {
        DImplementation->sink->Put('\n'); 
    } else {
        isFirstRow = false; 
    }

    bool firstColumn = true;

    for (const std::string& cell : row) {
        if (!firstColumn) {
            if (DImplementation->delimeter == '"') { //checking to see if delimeter is " the delimeter interpret it as a comma according to guidelines
                DImplementation->sink->Put(','); 
            } else {
                DImplementation->sink->Put(DImplementation->delimeter);
            }
        }

        if (cell.find(DImplementation->delimeter) != std::string::npos || // check that we are still looking for things to be put in double quotes
            cell.find('"') != std::string::npos || //these are all according to the guidelines on Project2 doc
            cell.find('\n') != std::string::npos ||
            DImplementation->quoteall) {
            DImplementation->sink->Put('"');

            // Replace double quote characters with two double quotes
            // got this section from ChatGPT (Changes 4 in ReadME)
            for (char c : cell) {
                if (c == '"') {
                    DImplementation->sink->Put('"');
                    DImplementation->sink->Put('"'); 
                } else {
                    DImplementation->sink->Put(c);
                }
            }

            DImplementation->sink->Put('"');
        } else {
            for (char c : cell) {
                DImplementation->sink->Put(c);
            }
        }

        firstColumn = false;
    }

    return true;

}

### Response 11
It seems like the isFirstRow variable is declared as a static variable inside the WriteRow() function. This means that its value persists across multiple function calls and is not reset to true at the beginning of each test case. To fix this, you should reset isFirstRow to true at the start of each test case.

One way to achieve this is to move the isFirstRow variable outside of the function and make it a member variable of the CDSVWriter class. Then, you can reset it to true in the setup phase of each test case. Here's how you can modify your test cases and the CDSVWriter class:

cpp
Copy code
class DSVWriterTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset isFirstRow to true before each test case
        CDSVWriter::isFirstRow = true;
    }
};
In your CDSVWriter class, remove the static keyword from the declaration of isFirstRow and declare it as a member variable of the class instead of inside the WriteRow() function:

cpp
Copy code
class CDSVWriter {
private:
    std::shared_ptr<CDataSink> sink;
    char delimiter;
    bool quoteall;
    bool isFirstRow = true; // Initialize isFirstRow to true as a member variable

public:
    // Constructor, member functions, etc.
};
By doing this, isFirstRow will be reset to true at the beginning of each test case, ensuring that it behaves as expected and is not influenced by previous test cases.

### Changes 11
I changed my DSVWriter.cpp from having static bool isFirstRow in the WriteRow function to having bool firstRow initialized in the class.