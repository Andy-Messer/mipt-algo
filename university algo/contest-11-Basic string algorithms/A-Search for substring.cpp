#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string text;
	std::string word;
	
	std::cin >> text >> word;
	
	text = word + "-" + text;
    std::vector<int> data(text.length());
    
	for (int i = 1; i < text.length(); ++i) {
		int j = data[i - 1];
        while (text[i] != text[j] && j > 0) {
            j = data[j - 1];
        }
        if (text[j] == text[i]) {
            data[i] = j + 1;
        }
    }

    for (int i = word.length(); i < text.length(); i++) {
        int j = word.length();
        if (data[i] == j) {
	    std::cout << i - word.length() - word.length()<<' ';
        }
    }
 
    return 0;
}