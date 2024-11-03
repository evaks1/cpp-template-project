#ifndef ZIPFS_H
#define ZIPFS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>
#include <functional>

namespace Session17 {
    std::vector<char> readBook(const std::string& fileName) {
        std::vector<char> result;
        std::ifstream file(fileName);

        if (!file) {
            std::cerr << "Unable to open file " << fileName << std::endl;
            return result;
        }

        char ch;
        while (file.get(ch)) {
            if (std::isalpha(ch)) {
                result.push_back(std::tolower(ch));
            } else {
                result.push_back(' ');
            }
        }

        file.close();
        return result;
    }

    
    std::map<std::string, int> computeWordFrequency(const std::vector<char>& book) {
        std::map<std::string, int> wordFrequency;
        std::stringstream stream(std::string(book.begin(), book.end()));
        std::string word;

        while (stream >> word) {
            wordFrequency[word]++;
        }

        return wordFrequency;
    }

    
    void outputFrequenciesToFile(const std::map<std::string, int>& wordFrequency, const std::string& outputFileName) {
        std::vector<std::pair<std::string, int>> sortedFrequencies(wordFrequency.begin(), wordFrequency.end());
        std::sort(sortedFrequencies.begin(), sortedFrequencies.end(), [](const auto& a, const auto& b) {
            return b.second < a.second;
        });

        std::ofstream outputFile(outputFileName);
        if (!outputFile) {
            std::cerr << "Unable to open file " << outputFileName << std::endl;
            return;
        }

        int rank = 1;
        for (const auto& [word, freq] : sortedFrequencies) {
            outputFile << rank << " " << freq << " " << word << "\n";
            rank++;
        }

        outputFile.close();
    }
}

namespace Session19 {
    std::vector<std::string> splitIntoWords(const std::vector<char>& book) {
        std::string content(book.begin(), book.end());
        std::stringstream ss(content);
        std::string word;
        std::vector<std::string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        return words;
    }

    std::vector<std::pair<std::string, int>> countWordFrequencies(const std::vector<std::string>& words) {
        std::vector<std::pair<std::string, int>> wordCounts;

        for (const auto& word : words) {
            auto it = std::find_if(wordCounts.begin(), wordCounts.end(),
                [&word](const std::pair<std::string, int>& element) { return element.first == word; });

            if (it != wordCounts.end()) {
                it->second++;
            } else {
                wordCounts.emplace_back(word, 1);
            }
        }

        return wordCounts;
    }

    
    void outputFrequenciesToFile(const std::vector<std::pair<std::string, int>>& sortedFrequencies, const std::string& outputFileName) {
        std::vector<std::pair<std::string, int>> sortedFreqs = sortedFrequencies;
        std::sort(sortedFreqs.begin(), sortedFreqs.end(), [](const auto& a, const auto& b) {
            return b.second < a.second;
        });

        std::ofstream outputFile(outputFileName);
        if (!outputFile) {
            std::cerr << "Unable to open file " << outputFileName << std::endl;
            return;
        }

        int rank = 1;
        for (const auto& [word, freq] : sortedFreqs) {
            outputFile << rank << " " << freq << " " << word << "\n";
            rank++;
        }

        outputFile.close();
    }
}

#endif 