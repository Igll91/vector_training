#include "gtest/gtest.h"
#include "vector_example.h"

class VectorTest : public ::testing::Test
{
};

TEST(VectorTest, SizeAndCapacity)
{
    etk::vector a {5, 10, 20};

    EXPECT_EQ(3, a.size());
    EXPECT_EQ(3, a.capacity());

    etk::vector b;

    EXPECT_EQ(0, b.size());
    EXPECT_EQ(2, b.capacity());

    a.push_back(30);

    EXPECT_EQ(4, a.size());
    EXPECT_EQ(6, a.capacity());

    a.push_back(45);

    EXPECT_EQ(5, a.size());
    EXPECT_EQ(6, a.capacity());

    etk::vector c(22);

    EXPECT_EQ(0, c.size());
    EXPECT_EQ(22, c.capacity());
}

TEST(VectorTest, DeepCopyVerification)
{
    etk::vector a {10, 12, 16};
    etk::vector b(a);
    etk::vector c;

    c = b;

    EXPECT_EQ(3, b.size());
    EXPECT_EQ(3, b.capacity());

    a.push_back(15);

    EXPECT_EQ(3, b.size());
    EXPECT_EQ(3, b.capacity());

    EXPECT_EQ(3, c.size());
    EXPECT_EQ(3, c.capacity());

    EXPECT_EQ(4, a.size());
    EXPECT_EQ(6, a.capacity());

    b.push_back(44);

    EXPECT_EQ(4, b.size());
    EXPECT_EQ(6, b.capacity());

    EXPECT_EQ(3, c.size());
    EXPECT_EQ(3, c.capacity());

    EXPECT_EQ(4, a.size());
    EXPECT_EQ(6, a.capacity());

    c.push_back(213);

    EXPECT_EQ(4, b.size());
    EXPECT_EQ(6, b.capacity());

    EXPECT_EQ(4, c.size());
    EXPECT_EQ(6, c.capacity());

    EXPECT_EQ(4, a.size());
    EXPECT_EQ(6, a.capacity());

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
