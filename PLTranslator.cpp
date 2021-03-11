// This program translates English sentances into the made up language of Pig Latin
// Alexander Ng
// 03/08/2021

#include <iostream>
#include <cstring>
using namespace std;

//class for language
class Language {
private:
    //variables to store user input words and translated words
    string word;
public:
    void get_word(string sen);
    void define_Word();
    void translate(int f, int e);
};

//class function that obtains the word
void Language::get_word(string sen) {
    word = sen;
}

//class function to define what are words
/*
Gets the input from the user, then seperates what are words to plug into another function to translate it*/
void Language::define_Word() {
    //location of the sentanace that the function has read, first letter of a word, end of that word
    int sentance = 0, f, e;
    //stores length of word
    int length = word.length();
    //while loop until the input is finished translating
    while (sentance < length) {
        //obtains the location of the first letter

        //cout<<"Looking at: "<<sentance<<" word: "<<word[sentance]<<endl;

        if (isalpha(word[sentance])) {
            f = sentance;
            sentance++;
        }
        //if there are more letters afterwards, loop to find when it ends
        while (isalpha(word[sentance])) {
            sentance++;
        }
        //ending location is 1 less than resulting word
        e = sentance - 1;
        //prevents retranslating old stuff
        if (isalpha(word[sentance - 1])) {
            translate(f, e);
        }
        cout << word[sentance];
        sentance++;
    }
}

//class function to translate the found words
/*
It recieves the location of the first letter and the end of the word then takes out the first letter to add it to the end of the output word
*/
void Language::translate(int f, int e) {
    //cout<<"\nS translate:\n";
  //stores the first letter
    char first_Word = word[f];
    //Caps the new first letter of the word if it is the beginning of a sentance
    if (isupper(word[f]) || (f == 0 || word[f - 1] == '.') || ((word[f - 2] == '.') && (word[f - 1] == ' '))) {
        cout << static_cast<char>(toupper(word[f + 1]));
    }
    else {
        cout << word[f + 1];
    }
    //a for loop that starts after the beginning of the word and end at the end
    if ((e - f) > 1) {
        for (int i = f + 2; i < e + 1; i++) {
            cout << word[i];
        }
    }
    if (isupper(word[e])) {
        cout << static_cast<char>(toupper(first_Word)) << "ay";
    }
    else {
        cout << static_cast<char>(tolower(first_Word)) << "ay";
    }
    //cout<<"\nE translate:\n";
}

int main() {
    Language trans;
    string user;
    cout << "Please enter words to translate\n";
    getline(cin, user);
    cout << "Translation:\n";
    trans.get_word(user);
    trans.define_Word();
}
