#include <gtest/gtest.h>
#include "DSVWriter.h"
#include "StringDataSink.h"

TEST(DSVWriter, WriteRow){
    std::shared_ptr < CStringDataSink > Sink = std::make_shared< CStringDataSink >();
    CDSVWriter Write(Sink, '*');
    std::vector<std::string> input = {"Hey", "there"};
    EXPECT_TRUE(Write.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hey*there");
}

TEST(DSVWriter, WriteSimpleLine) {
    std::shared_ptr < CStringDataSink > Sink = std::make_shared<CStringDataSink>();
    CDSVWriter Writer(Sink, '&');
    std::vector<std::string> input = {"Hello", "World!"};   
    EXPECT_TRUE(Writer.WriteRow(input));
    EXPECT_EQ(Sink->String(), "Hello&World!");
}