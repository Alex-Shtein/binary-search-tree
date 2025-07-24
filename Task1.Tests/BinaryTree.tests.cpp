#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Task1/BinaryTree.h"

TEST(BinaryTreeIntTests, ConstructorWithoutParameterAndInsert)
{
    BinaryTree<int> tree;
    tree.Insert(20);
    tree.Insert(10);
    int arrInsert[] = {10, 20};
    for (int i = 0; i < 2; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arrInsert[i]);
    }
}

TEST(BinaryTreeIntTests, ConstructorWithParametersAndRemove)
{
    int values[] = {20, 19, 21};
    BinaryTree<int> tree(values, 3);
    int arr[] = {19, 20, 21};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arr[i]);
    }
    tree.Remove(20.);
    int arrRemove[] = {19, 21};
    for (int i = 0; i < 2; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arrRemove[i]);
    }
}

TEST(BinaryTreeIntTests, CopyConstructor)
{
    int values[] = {20, 10, 25};
    BinaryTree<int> tree(values, 3);
    BinaryTree<int> copyTree(tree);
    int arrCopy[] = {10, 20, 25};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(copyTree.RoundLrootR()[i], arrCopy[i]);
    }
}

TEST(BinaryTreeIntTests, MoveConstructor)
{
    int values[] = {20, 10, 25};
    BinaryTree<int> tree(values, 3);
    BinaryTree<int> moveTree = std::move(tree);
    int arrMove[] = {10, 20, 25};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(moveTree.RoundLrootR()[i], arrMove[i]);
    }
    ASSERT_TRUE(tree.Empty());
}

TEST(BinaryTreeIntTests, AddAndRemoveNodesTest)
{
    int values[] = {20, 10, 30};
    BinaryTree<int> tree(values, 3);
    tree.Insert(15);
    ASSERT_TRUE(tree.Contains(15));
    ASSERT_FALSE(tree.Contains(5));
    auto pkl = tree.RoundRrootL();
    int arr[] = {30, 20, 15, 10};
    for (int i = 0; i < 4; i++)
    {
        ASSERT_EQ(pkl[i], arr[i]);
    }
}

TEST(BinaryTreeIntTests, DifficultTests)
{
    int values[] = {10, 21, 15, 6, 8, 17, 4, 2, 25, 7, 5, 9, 11, 22, 30};
    BinaryTree<int> tree(values, 15);
    tree.Remove(10);
    tree.Remove(2);
    tree.Remove(4);
    tree.Remove(6);
    auto round = tree.RoundLrootR();
    std::vector<int> expect = {5, 7, 8, 9, 11, 15, 17, 21, 22, 25, 30};
    for (int i = 0; i < 11; i++)
    {
        ASSERT_EQ(round[i], expect[i]);
    }
    tree.Output();
}

TEST(BinaryTreeStringTests, ConstructorWithoutParameterAndInsert)
{
    BinaryTree<std::string> tree;
    tree.Insert("20");
    tree.Insert("10");
    std::string arrInsert[] = {"10", "20"};
    for (int i = 0; i < 2; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arrInsert[i]);
    }
}

TEST(BinaryTreeStringTests, ConstructorWithParametersAndRemove)
{
    std::string values[] = {"20", "10", "30"};
    BinaryTree<std::string> tree(values, 3);
    std::string arr[] = {"10", "20", "30"};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arr[i]);
    }
    tree.Remove("20");
    std::string arrRemove[] = {"10", "30"};
    for (int i = 0; i < 2; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arrRemove[i]);
    }
}

TEST(BinaryTreeStringTests, CopyConstructor)
{
    std::string values[] = {"20", "10", "25"};
    BinaryTree<std::string> tree(values, 3);
    BinaryTree<std::string> copyTree(tree);
    std::string arrCopy[] = {"10", "20", "25"};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(copyTree.RoundLrootR()[i], arrCopy[i]);
    }
}

TEST(BinaryTreeStringTests, MoveConstructor)
{
    std::string values[] = {"20", "10", "25"};
    BinaryTree<std::string> tree(values, 3);
    BinaryTree<std::string> moveTree = std::move(tree);
    std::string arrMove[] = {"10", "20", "25"};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(moveTree.RoundLrootR()[i], arrMove[i]);
    }
    ASSERT_TRUE(tree.Empty());
}

TEST(BinaryTreeStringTests, AddAndRemoveNodesTest)
{
    std::string values[] = {"a", "b", "c"};
    BinaryTree<std::string> tree(values, 3);
    tree.Insert("d");
    ASSERT_TRUE(tree.Contains("d"));
    ASSERT_FALSE(tree.Contains("e"));
    auto pkl = tree.RoundRrootL();
    std::string arr[] = {"d", "c", "b", "a"};
    for (int i = 0; i < 4; i++)
    {
        ASSERT_EQ(pkl[i], arr[i]);
    }
}

TEST(BinaryTreeStringTests, DifficultTests)
{
    std::string values[] = {"c", "z", "a", "f", "b", "q", "m"};
    BinaryTree<std::string> tree(values, 7);
    tree.Insert("h");
    ASSERT_TRUE(tree.Contains("h"));
    ASSERT_FALSE(tree.Contains("K"));
    tree.Output();
    auto pkl = tree.RoundRrootL();
    std::string arr[] = {"z", "q", "m", "h", "f", "c", "b", "a"};
    for (int i = 0; i < 8; i++)
    {
        ASSERT_EQ(pkl[i], arr[i]);
    }
}

TEST(BinaryTreeDoubleTests, ConstructorWithoutParameterAndInsert)
{
    BinaryTree<double> tree;
    tree.Insert(20.);
    tree.Insert(10.);
    double arrInsert[] = {10., 20.};
    for (int i = 0; i < 2; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arrInsert[i]);
    }
}

TEST(BinaryTreeDoubleTests, ConstructorWithParametersAndRemove)
{
    double values[] = {20., 19.9, 20.1};
    BinaryTree<double> tree(values, 3);
    double arr[] = {19.9, 20, 20.1};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arr[i]);
    }
    tree.Remove(20.);
    double arrRemove[] = {19.9, 20.1};
    for (int i = 0; i < 2; i++)
    {
        ASSERT_EQ(tree.RoundLrootR()[i], arrRemove[i]);
    }
}

TEST(BinaryTreeDoubleTests, CopyConstructor)
{
    double values[] = {20., 10., 25.};
    BinaryTree<double> tree(values, 3);
    BinaryTree<double> copyTree(tree);
    double arrCopy[] = {10., 20., 25.};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(copyTree.RoundLrootR()[i], arrCopy[i]);
    }
}

TEST(BinaryTreeDoubleTests, MoveConstructor)
{
    double values[] = {20., 10., 25.};
    BinaryTree<double> tree(values, 3);
    BinaryTree<double> moveTree = std::move(tree);
    double arrMove[] = {10., 20., 25.};
    for (int i = 0; i < 3; i++)
    {
        ASSERT_EQ(moveTree.RoundLrootR()[i], arrMove[i]);
    }
    ASSERT_TRUE(tree.Empty());
}

TEST(BinaryTreeDoubleTests, AddAndRemoveNodesTest)
{
    double values[] = {20., 10., 30.};
    BinaryTree<double> tree(values, 3);
    tree.Insert(15);
    ASSERT_TRUE(tree.Contains(15));
    ASSERT_FALSE(tree.Contains(5));
    auto pkl = tree.RoundRrootL();
    double arr[] = {30., 20., 15., 10.};
    for (int i = 0; i < 4; i++)
    {
        ASSERT_EQ(pkl[i], arr[i]);
    }
}
