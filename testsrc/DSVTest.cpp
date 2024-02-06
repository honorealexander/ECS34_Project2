#include <gtest/gtest.h>
#include "DSVWriter.h"
#include "DSVReader.h"
#include "StringDataSource.h"
#include "StringDataSink.h"

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
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink, '*');

    std::vector<std::string> input1 = {"This", "is"};
    std::vector<std::string> input2 = {"test", "two"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink->String(), "This*test\ntest*two");
}

TEST(DSVWriter, WriteRow3) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink, '*');

    std::vector<std::string> input1 = {"This", "is"};
    std::vector<std::string> input2 = {"a", "third test"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink->String(), "This*is\na*third test");
}

TEST(DSVWriter, WriteRow4) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink, '*');

    std::vector<std::string> input1 = {"This", "h@s"};
    std::vector<std::string> input2 = {"a", "spec!al"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink->String(), "This*h@s\na*spec!al");
}