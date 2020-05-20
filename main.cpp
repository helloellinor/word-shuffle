#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>

//-----------------------------------------------------------------------------

void get_words(std::vector<std::string>& input)
{
	std::ifstream infile("wordlist.txt");
	infile.ignore();
	std::string word;
	while (std::getline(infile, word, ','))
		input.push_back(word);
	//removes terminating newline
	input.back().pop_back();
	return;
}

//-----------------------------------------------------------------------------

void export_list(std::vector<std::string>& output)
{
	std::ofstream outfile("wordlist_shuffled.txt", std::ofstream::trunc);
	//deletes 1 char after index 0 to remove leading space
	output[0].erase(0, 1);
	for (auto i : output)
		outfile << i << ',';
}

//-----------------------------------------------------------------------------

int main()
{
	std::vector<std::string> wordlist;
	get_words(wordlist);
	std::shuffle(wordlist.begin(), wordlist.end(), std::random_device());
	export_list(wordlist);
	return 0;
} 
