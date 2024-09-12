   #include <gtest/gtest.h>
   #include "Context.h"
   #include "StrategyA.h"
   #include "StrategyB.h"

   TEST(StrategyTest, TestStrategyA) {
       StrategyA strategy;
       Context context(&strategy);
       EXPECT_EQ(context.ExecuteStrategy(), expectedValueA); // замените expectedValueA на ожидаемое значение
   }

   TEST(StrategyTest, TestStrategyB) {
       StrategyB strategy;
       Context context(&strategy);
       EXPECT_EQ(context.ExecuteStrategy(), expectedValueB); // замените expectedValueB на ожидаемое значение
   }

   TEST(StrategyTest, ChangeStrategy) {
       // Check changing strategy at runtime
       Context context(new StrategyA());
       EXPECT_EQ(context.ExecuteStrategy(), expectedValueA); // замените expectedValueA

       context.SetStrategy(new StrategyB());
       EXPECT_EQ(context.ExecuteStrategy(), expectedValueB); // замените expectedValueB
   }