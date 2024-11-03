#include <gtest/gtest.h>
#include "../include/zipfs.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

TEST(Session17Tests, ComputeWordFrequency) {
    std::vector<char> testContent = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', ' ', 'h', 'e', 'l', 'l', 'o'};
    auto frequencies = Session17::computeWordFrequency(testContent);
    EXPECT_EQ(frequencies["hello"], 2);
    EXPECT_EQ(frequencies["world"], 1);
    EXPECT_EQ(frequencies.size(), 2) << "Unexpected number of unique words";
}

TEST(Session17Tests, OutputFrequenciesToFile) {
    std::map<std::string, int> wordFrequency = {{"hello", 2}, {"world", 1}};
    std::string outputFilePath = "../files/output_test.txt";
    Session17::outputFrequenciesToFile(wordFrequency, outputFilePath);
    std::ifstream infile(outputFilePath);
    ASSERT_TRUE(infile.good()) << "Output file should exist";
    std::string line;
    ASSERT_TRUE(std::getline(infile, line)) << "Output file should not be empty";
    infile.close();
    fs::remove(outputFilePath);
}

TEST(Session19Tests, SplitIntoWords) {
    std::vector<char> testContent = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
    auto words = Session19::splitIntoWords(testContent);
    ASSERT_EQ(words.size(), 2) << "Expected 2 words";
    EXPECT_EQ(words[0], "hello");
    EXPECT_EQ(words[1], "world");
}

TEST(Session19Tests, CountWordFrequencies) {
    std::vector<std::string> words = {"hello", "world", "hello"};
    auto wordCounts = Session19::countWordFrequencies(words);
    ASSERT_EQ(wordCounts.size(), 2) << "Expected 2 unique words";
    EXPECT_EQ(wordCounts[0].first, "hello");
    EXPECT_EQ(wordCounts[0].second, 2);
    EXPECT_EQ(wordCounts[1].first, "world");
    EXPECT_EQ(wordCounts[1].second, 1);
}

TEST(Session19Tests, OutputFrequenciesToFile) {
    std::vector<std::pair<std::string, int>> wordCounts = {{"hello", 2}, {"world", 1}};
    std::string outputFilePath = "../files/output_test_algo.txt";
    Session19::outputFrequenciesToFile(wordCounts, outputFilePath);
    std::ifstream infile(outputFilePath);
    ASSERT_TRUE(infile.good()) << "Output file should exist";
    std::string line;
    ASSERT_TRUE(std::getline(infile, line)) << "Output file should not be empty";
    infile.close();
    fs::remove(outputFilePath);
}