//Work in progress, will add in the ability to translateback from pig lattin
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*The idea of this program is to create a translator for the made up language of pig latin*/

class Language{
  private:
  string words,t_Words;
  public:
//gets input from user
  void i_Words(string input){words=input;};
//returns the translated word
  string o_Twords(){return t_Words;};
//translate the words
  void translate();
};

void Language::translate(){
//stores the amount of spaces between words/characters, the string length and word length
  int length,word_Length;
//stores the first letter of each word
  string temp,temp_Word;
  char f_Word;
  bool got_Word=false,upper=false;
  length = words.length();
//For loop to go through every single letter
  for(int i=0;i<length;i++){
//Checks if this letter is a letter
    if((words[i]!=' ')&&(words[i]!='.')&&(words[i]!=',')&&(words[i]!='?')&&(words[i]!='!')){
//if it is a letter, then collect the word
      do{
//a word ends with a space or period or comma etc
//checks if the word is ended by a comma or question mark to see if the first letter of the word needs to be capitalized
        if((words[i]=='.')||(words[i]==',')||(words[i]=='?')||(words[i]=='!')){
          upper=true;
          got_Word=true;
        }
        else if((words[i]==' ')||(i>=length)){
          got_Word=true;
        }
        else{
          temp+=words[i];
        }
        i++;
      }while(got_Word==false);
//gets the word length
      word_Length=temp.length();
//resets the bool variable so it can be used for other words
      got_Word=false;
//gets the first letter of the word
      f_Word=temp[0];
//copies the word except of the first word
      for(int k=1;k<word_Length;k++){
        temp_Word+=temp[k];
      }
//checks if the first letter is capitalized, if it is, capitalized the first letter of the new word
      if(isupper(f_Word)){
        temp_Word[0]=toupper(temp_Word[0]);
        f_Word=tolower(f_Word);
      }
//checks if it is needed to capitalized the first letter based on the stuff after the word from the previous loop
      if(upper==true){
        temp_Word[0]=toupper(temp_Word[0]);
        upper =false;
      }
//Adds the original first letter to the end of the word
      temp_Word+=f_Word;
//Adds 'ay' after the original first letter
      temp_Word+="ay";
//Adds the new word to the translated sentence
      t_Words+=temp_Word;
//resets all the varaibles
      temp.clear();
      temp_Word.clear();
//takes one off the iteration due to the process of creating the new word
      i--;
    }
//copies the next item to the new string
    t_Words+=words[i];
  }
//Make sures that the first letter is capitalized
  t_Words[0]=toupper(t_Words[0]);
}

//function prototype
//gets english input to be translated
void get_Eng(Language &eng);
//outputs translated pig lattin
void o_Pig(Language &eng);

int main(){
  Language eng;
  cout<<"This program is a translator for translating the English language to the made up language of Pig Lattin.\n";
  get_Eng(eng);
  eng.translate();
   o_Pig(eng);
}

//gets english input to be translated
void get_Eng(Language &eng){
  string input;
  cout<<"Please enter the sentence/word that you would like to be translated.\n";
  getline(cin,input);
  //cout<<"input: "<<input<<endl;
  eng.i_Words(input);
}

//outputs translated pig lattin
void o_Pig(Language &eng){
  cout<<"Translation:\n"
  <<"=============================================================\n";
  cout<<eng.o_Twords()<<endl;
}
