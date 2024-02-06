#include <gtest/gtest.h>
#include "XMLReader.h"
#include "StringDataSource.h"
#include "StringDataSink.h"
#include "XMLEntity.h"
#include "XMLWriter.h"

TEST(XMLReader, ReadEntity) {
    std::string xmlData = "<root><element1 attribute=\"value\">Hello</element1><element2>World</element2></root>";
    std::shared_ptr<CStringDataSource> dataSource = std::make_shared<CStringDataSource>(xmlData);
    CXMLReader xmlReader(dataSource);

    SXMLEntity entity;
    bool success = xmlReader.ReadEntity(entity, false);

    ASSERT_TRUE(success);
    ASSERT_EQ(entity.DType, SXMLEntity::EType::StartElement);
    ASSERT_EQ(entity.DNameData, "root");
    // You can add more assertions for attributes or other properties if needed
}

TEST(XMLWriter, WriteEntity) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CXMLWriter xmlWriter(sink);

    SXMLEntity entity;
    entity.DType = SXMLEntity::EType::StartElement;
    entity.DNameData = "element";
    
    bool success = xmlWriter.WriteEntity(entity);
    
    ASSERT_TRUE(success);

    ASSERT_EQ(sink->String(), "<element>");
}

