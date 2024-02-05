#include "XMLReader.h"


struct CXMLReader::SImplementation{
    std::shared_ptr< CDataSource > DDataSource;
    XML_Parser DXMLParser;

    void StartElementHandler(const std::string &name, const std::vector<std::string> &attrs){

    }

    void EndElementHandler(const std::string &name){

    }

    static void StartElementHandlerCallback(void *context, const XML_Char *name, const XML_Char **atts){
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        std::vector<std::string> Attribute;
        auto AttrPtr = atts;
        while(*AttrPtr){
            std::string Temp = *AttrPtr;
            Attributes.push_back(Temp);
            Attributes.push_back(*AttrPtr);
            AttrPtr++;
        }

        ReaderObject->StartElementHandler(name, )
    };

    static void EndElementHandlerCallback(void *context, const XML_Char *name){
        SImplementation *ReaderObject = static_cast<SImplementation *>(context);
        ReaderObject->EndElementHandler(name);
    
    };

    static void CharacterDataHandlerCallback(void *context, const XML_Char *s, int len){

    };

    SImplementation(std::shared_ptr< CDataSource > src){
        DDataSource = src;
        DXMLParser = XML_ParserCreate(NULL);
        XML_SetStartElementHandler(DXMLParser, StartElementHandlerCallback);
        XML_SetEndElementHandler(DXMLParser, EndElementHandlerCallback);
        XML_SetCharacterDataHandlerCallback(DXMLParser, CharacterDataHandlerCallback);
    };

    bool End() const{

    };

    bool ReadEntity(SXMLEntity &entity, bool skipcdata){

    };
};

CXMLReader::CXMLReader(std::shared_ptr<CDataSource> src) {
    // Implementation
}

CXMLReader::~CXMLReader() {
    // Implementation
}

bool CXMLReader::End() const {
    // Implementation
}

bool CXMLReader::ReadEntity(SXMLEntity &entity, bool skipcdata) {
    // Implementation
}