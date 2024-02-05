#include <gtest/gtest.h>
#include <sstream>
#include "DSVWriter.h"


//case for special characters
bool CDSVWriter::SpecialChar(const std::string &value) {
    return (value.find(DImplementation ->delimeter) !=std::string::npos ||
            value.find('"') != std::string::npos || value.find('\n') !- std::string::npos)
}


//quotes string. ensures proper handling of special character data that might otherwise be misinterpreted.
std::string CDSVWriter::QuoteString(const std::string &value) {
    std::string quoteVal = "\"";
    for(char ch : value){
        if (ch=='"'){
            quoteVal+="\"\"";//put two double quotes in place of one double quote
        }else{
            quoteVal+=ch;
        }
    }
    quoteVal += "\"";
    return quoteVal;
}

bool CDSVWriter WriteRow(const std::vector<std::string> &row){
    std::ostringstream rowStream;
    for(size_t i=0; i<row.size(); ++i){
        if(i>0){    
            rowStream << DImplementation ->delimiter;
        }
        if (DImplementation ->quoteall || SpecialChar(row[i])) {
            rowStream << QuoteString(row[i]);
        }else{
            rowStream <<row[i];
        }
    }
    rowStream << '\n';

    std::string rowString = rowStream.str();

//convert the row string into a vector full of characters
    std::vector<char> rowBuffer(rowString.begin(), rowString.end())

    return DImplementation->sink->Write(rowBuffer);
}
