#include <gtest/gtest.h>
#include "DSVWriter.h"
#include "StringDataSink.h"

TEST(DSVWriter, WriteRow){
    std::shared_ptr < CStringDataSink > Sink = std::make_shared< CStringDataSink >();
    CDSVWriter Write(Sink, '*');
    std::vector<std::string> input = {"Hi", "buddy"};
    EXPECT_TRUE(Write.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hi*buddy");
}