#include "DSVWriter.h"
#include <sstream>

struct CDSVWriter::SImplementation {
    std::shared_ptr<CDataSink> sink;
    char delimeter;
    bool quoteall;

    SImplementation(std::shared_ptr<CDataSink> sink, char delimeter, bool quoteall)
        : sink(sink), delimeter(delimeter), quoteall(quoteall) {}

    ~SImplementation() { //do clean up if needed
    }
};

CDSVWriter::CDSVWriter(std::shared_ptr<CDataSink> sink, char delimeter, bool quoteall)
    : DImplementation(std::make_unique<SImplementation>(sink, delimeter, quoteall)) {}

CDSVWriter::~CDSVWriter() = default;

bool CDSVWriter::WriteRow(const std::vector<std::string>& row) {
    if (!DImplementation->sink) return false; // Check if sink is valid

    bool firstColumn = true; // Flag to track the first column in the row

    for (const std::string& cell : row) {
        if (!firstColumn) {
            if (DImplementation->delimeter == '"') {
                // If delimeter is a double quote, interpret it as a comma
                DImplementation->sink->Put(',');
            } else {
                DImplementation->sink->Put(DImplementation->delimeter);
            }
        }

        if (DImplementation->quoteall ||
            cell.find(DImplementation->delimeter) != std::string::npos ||
            cell.find('"') != std::string::npos ||
            cell.find('\n') != std::string::npos) {
            // Quote the value if it contains the delimeter, double quote, or newline
            DImplementation->sink->Put('"');

            // Replace double quote characters with two double quotes
            for (char c : cell) {
                if (c == '"') DImplementation->sink->Put('"');
                DImplementation->sink->Put(c);
            }

            DImplementation->sink->Put('"');
        } else {
            // No need to quote, directly output the value
            for (char c : cell) {
                DImplementation->sink->Put(c);
            }
        }

        firstColumn = false; // Update flag for subsequent columns
    }

    // Write newline at the end of the row
    DImplementation->sink->Put('\n');

    return true;
}


