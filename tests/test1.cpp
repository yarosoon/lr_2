#include <gtest/gtest.h>
#include "ConcreteStratergyA.h"
#include "ConcreteStratergyB.h"
#include "Context.h"

TEST(ConcreteStratergyTest, AlgorithmAExecution) {
    ConcreteStratergyA strategyA;
    testing::internal::CaptureStdout();
    strategyA.algorithmInterface();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("ConcreteStratergyA algorithm executed.\n", output);
}

TEST(ConcreteStratergyTest, AlgorithmBExecution) {
    ConcreteStratergyB strategyB;
    testing::internal::CaptureStdout();
    strategyB.algorithmInterface();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("ConcreteStratergyB algorithm executed.\n", output);
}
TEST(ContextTest, ContextWithStrategyA) {
    ConcreteStratergyA strategyA;
    Context context(&strategyA);
    testing::internal::CaptureStdout();
    context.contextInterface();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("ConcreteStratergyA algorithm executed.\n", output);
}

TEST(ContextTest, ContextWithStrategyB) {
    ConcreteStratergyB strategyB;
    Context context(&strategyB);
    testing::internal::CaptureStdout();
    context.contextInterface();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("ConcreteStratergyB algorithm executed.\n", output);
}
TEST(ContextTest, ContextWithoutStrategy) {
    Context context(nullptr);
    testing::internal::CaptureStdout();
    context.contextInterface();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("No strategy set.\n", output);
}