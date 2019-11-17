#include "palindromecheck.h"

using namespace std;
string cleanString (string str1){
    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    str1.erase(remove_if(str1.begin(), str1.end(), ispunct), str1.end());
    return str1;
}



bool palindromecheck(string palindrome){
    palindrome = cleanString(palindrome);
    if (palindrome.length() == 0  || palindrome.length() == 1){
        return true;
    }
    else if (palindrome.front() != palindrome.back()) {
        return false;
    }
    return palindromecheck(palindrome.substr(1, palindrome.length() - 2));
}

int main(){
    string str = "g  eeks   for ge  eeks  ";
    string bat = "Batman w a s made in GO th am Cit y";
    string bar = "I go TO a BaR EverYday";
    string punct = "However they choose to write, people are ALLowed   to make THEIR OWn DeC..isionS; A     s a Result, many peopLE sweAr by their writing METHODS.  ";
    string max = "MAx.XAm";
    string IQP = "A man, a plan , A canal: Panama!";
    string strin = cleanString(str);  
    string Bat = cleanString(bat);
    std::cout << strin << std::endl; 
    std::cout << Bat << std::endl;
    std::cout << cleanString(bar) << std::endl;
    std::cout << cleanString(punct) << std::endl;
    std::cout << palindromecheck(max) << std::endl;
    std::cout << palindromecheck(IQP) << std::endl;
    return 0; 
}

