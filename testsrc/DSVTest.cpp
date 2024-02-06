#include <gtest/gtest.h>
#include "DSVWriter.h"
#include "DSVReader.h"
#include "StringDataSource.h"
#include "StringDataSink.h"

TEST(DSVWriter, WriteRow) {
    std::shared_ptr<CStringDataSink> sink = std::make_shared<CStringDataSink>();
    CDSVWriter writer(sink, '*');

    std::vector<std::string> input1 = {"Hey", "there"};
    std::vector<std::string> input2 = {"Hello", "world"};

    EXPECT_TRUE(writer.WriteRow(input1));
    EXPECT_TRUE(writer.WriteRow(input2));
    EXPECT_EQ(sink->String(), "Hey*there\nHello*world");
}
