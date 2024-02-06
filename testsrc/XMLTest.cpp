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


TEST(XMLWriter, WriteTwoEntities) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CXMLWriter xmlWriter(sink);
    
    SXMLEntity entity1;
    entity1.DType = SXMLEntity::EType::StartElement;
    entity1.DNameData = "element1";
    ASSERT_TRUE(xmlWriter.WriteEntity(entity1));

    SXMLEntity entity2;
    entity2.DType = SXMLEntity::EType::StartElement;
    entity2.DNameData = "element2";
    ASSERT_TRUE(xmlWriter.WriteEntity(entity2));

    std::string expectedOutput = "<element1><element2>";
    ASSERT_EQ(sink->String(), expectedOutput);
}

TEST(XMLWriter, WriteEmptyEntity) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CXMLWriter xmlWriter(sink);
    SXMLEntity emptyEntity;
    emptyEntity.DType = SXMLEntity::EType::StartElement;
    emptyEntity.DNameData = "";
    bool success = xmlWriter.WriteEntity(emptyEntity);
    ASSERT_TRUE(success);
    ASSERT_EQ(sink->String(), "<>");
}
