#include <gtest/gtest.h>
#include "DSVWriter.h"
#include "DSVReader.h"
#include "StringDataSource.h"
#include "StringDataSink.h"

TEST(DSVReader, ReadRow1) {
    std::shared_ptr<CStringDataSource> source = std::make_shared<CStringDataSource>("Hey*there\nHello*world");
    CDSVReader reader(source, '*');
    std::vector<std::string> expected1 = {"Hey", "there"};
    std::vector<std::string> row1;
    EXPECT_TRUE(reader.ReadRow(row1));
    EXPECT_EQ(row1, expected1);
}

TEST(DSVReader, Read2Rows) {
    std::shared_ptr<CStringDataSource> source = std::make_shared<CStringDataSource>("Hey*there\nHello*world");
    CDSVReader reader(source, '*');

    std::vector<std::string> expected1 = {"Hey", "there"};
    std::vector<std::string> expected2 = {"Hello", "world"};

    std::vector<std::string> row1;
    std::vector<std::string> row2;

    EXPECT_TRUE(reader.ReadRow(row1));
    EXPECT_TRUE(reader.ReadRow(row2));
}


TEST(DSVWriter, WriteRow1) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink, '*');

    std::vector<std::string> input1 = {"Hey", "there"};
    std::vector<std::string> input2 = {"Hello", "world"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink->String(), "Hey*there\nHello*world");
}

TEST(DSVWriter, WriteRow2) {
    std::shared_ptr<CStringDataSink> sink1 = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink1, '*');

    std::vector<std::string> input1 = {"This", "is"};
    std::vector<std::string> input2 = {"test", "two"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink1->String(), "This*is\ntest*two");
}

TEST(DSVWriter, WriteRow3) {
    std::shared_ptr<CStringDataSink> sink2 = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink2, '*');

    std::vector<std::string> input1 = {"This", "is"};
    std::vector<std::string> input2 = {"a", "third test"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink2->String(), "This*is\na*third test");
}

TEST(DSVWriter, WriteRow4) {
    std::shared_ptr<CStringDataSink> sink3 = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink3, '*');

    std::vector<std::string> input1 = {"This", "h@s"};
    std::vector<std::string> input2 = {"a", "spec!al"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink3->String(), "This*h@s\na*spec!al");
}

TEST(DSVReader, ReadMultipleRowsDifferentDelimiters) {
    std::shared_ptr<CStringDataSource> source = std::make_shared<CStringDataSource>("Hey,there\nHello|world\nHow|are|you");
    CDSVReader reader1(source, ',');
    CDSVReader reader2(source, '|');

    std::vector<std::string> expected1 = {"Hey", "there"};
    std::vector<std::string> expected2 = {"Hello", "world"};
    std::vector<std::string> expected3 = {"How", "are", "you"};

    std::vector<std::string> row1, row2, row3;

    EXPECT_TRUE(reader1.ReadRow(row1));
    EXPECT_TRUE(reader2.ReadRow(row2));
    EXPECT_TRUE(reader2.ReadRow(row3));
}

TEST(DSVWriter, WriteRowWithEmptyColumns) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink, ',');

    std::vector<std::string> input1 = {"Hey", "", "there"};
    std::vector<std::string> input2 = {"Hello", "", "world"};
    std::vector<std::string> input3 = {"How", "are", "", "you"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_TRUE(writer.WriteRow(input3));

    EXPECT_EQ(sink->String(), "Hey,,there\nHello,,world\nHow,are,,you");
}

