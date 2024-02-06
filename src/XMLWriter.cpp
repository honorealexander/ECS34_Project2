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
        // Set up other XML parsing configurations as needed
    }

    ~SImplementation() {
        XML_ParserFree(parser);
    }

    bool Flush() {
        if (XML_Parse(parser, nullptr, 0, true)) {
            return true;
        } else {
            return false;
        }
    }

    bool WriteEntity(const SXMLEntity& entity) {
        std::vector<char> startTag(entity.DNameData.begin(), entity.DNameData.end());
        std::vector<char> endTag(entity.DNameData.begin(), entity.DNameData.end());
        std::vector<char> cdata(entity.DNameData.begin(), entity.DNameData.end());

        switch (entity.DType) {
            case SXMLEntity::EType::StartElement:
                if (!sink->Write(startTag)) {
                    return false;
                }
                break;
            case SXMLEntity::EType::EndElement:
                if (!sink->Write(endTag)) {
                    return false;
                }
                break;
            case SXMLEntity::EType::CharData:
                if (!sink->Write(cdata)) {
                    return false;
                }
                break;
            default:
                break;
        }

        return true;
    }
};

CXMLWriter::CXMLWriter(std::shared_ptr<CDataSink> sink) {
    DImplementation = std::make_unique<SImplementation>(sink);
}

CXMLWriter::~CXMLWriter() = default;

bool CXMLWriter::Flush() {
    return DImplementation->Flush();
}

bool CXMLWriter::WriteEntity(const SXMLEntity &entity) {
    return DImplementation->WriteEntity(entity);
}
