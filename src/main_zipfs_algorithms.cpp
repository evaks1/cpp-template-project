#include "../include/zipfs.h"

int main() {
    std::string fileName = "../files/pg2701.txt";
    std::vector<char> bookContent = Session17::readBook(fileName); // Reuse readBook

    std::vector<std::string> words = Session19::splitIntoWords(bookContent);

    std::vector<std::pair<std::string, int>> wordCounts = Session19::countWordFrequencies(words);

    Session19::outputFrequenciesToFile(wordCounts, "moby_dick_frequencies_algorithms.txt");

    std::cout << "Word frequencies (algorithm-based) have been written to 'moby_dick_frequencies_algorithms.txt'." << std::endl;

    return 0;
}