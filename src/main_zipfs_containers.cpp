#include "../include/zipfs.h"

int main() {
    std::string fileName = "../files/pg2701.txt";
    std::vector<char> bookContent = Session17::readBook(fileName);

    std::map<std::string, int> wordFrequency = Session17::computeWordFrequency(bookContent);

    Session17::outputFrequenciesToFile(wordFrequency, "moby_dick_frequencies_containers.txt");

    std::cout << "Word frequencies (container-based) have been written to 'moby_dick_frequencies_containers.txt'." << std::endl;

    return 0;
}