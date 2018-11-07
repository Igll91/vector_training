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

    c.push_back(423);
    c.push_back(74);
    c.push_back(99);

    EXPECT_EQ(4, b.size());
    EXPECT_EQ(6, b.capacity());

    EXPECT_EQ(7, c.size());
    EXPECT_EQ(12, c.capacity());

    EXPECT_EQ(4, a.size());
    EXPECT_EQ(6, a.capacity());
}

TEST(VectorTest, ReadingVerification)
{
    etk::vector a {10, 12, 16};

    EXPECT_EQ(10, a[0]);
    EXPECT_EQ(10, a.at(0));

    EXPECT_EQ(12, a[1]);
    EXPECT_EQ(12, a.at(1));

    EXPECT_EQ(16, a[2]);
    EXPECT_EQ(16, a.at(2));

    a.push_back(202);

    EXPECT_EQ(202, a[3]);
    EXPECT_EQ(202, a.at(3));

    try
    {
        a.at(21231);
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("received invalid index value."));
    }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
