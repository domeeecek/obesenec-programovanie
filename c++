#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


void drawHangman(int incorrectGuesses) {
    if (incorrectGuesses >= 1) cout << "  O" << endl;
    if (incorrectGuesses == 2) cout << "  |" << endl;
    if (incorrectGuesses == 3) cout << " /|" << endl;
    if (incorrectGuesses >= 4) cout << " /|\\" << endl;
    if (incorrectGuesses == 5) cout << " /" << endl;
    if (incorrectGuesses >= 6) cout << " / \\" << endl;
}

void displayWord(string word, vector<char> guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end())
            cout << letter << " ";
        else
            cout << "_ ";
    }
    cout << endl;
}

bool isWordGuessed(string word, vector<char> guessedLetters) {
    for (char letter : word) {
        if (find(guessedLetters.begin(), guessedLetters.end(), letter) == guessedLetters.end())
            return false;
    }
    return true;
}

int main() {
    srand(time(0));
    vector<string> words = { "jablko", "pocitac", "klavestnica", "slza", "svetlo","zem","hra","valorant","CS:GO","slovo","obesenec",
    "prst","hlava","noha","ruka","plasma","antimeter","nike","eternet" };
    string word = words[rand() % words.size()];
    int incorrectGuesses = 0;
    vector<char> guessedLetters;

    cout << "Vitaj v obesencovi hrac " << endl;

    while (incorrectGuesses < 6 && !isWordGuessed(word, guessedLetters)) {
        cout << endl;
        drawHangman(incorrectGuesses);
        displayWord(word, guessedLetters);

        cout << "Vloz pismeno (iba male pismena): ";
        char guess;
        cin >> guess;

        if (find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end()) {
            cout << "Toto pismeno si už hadal!" << endl;
            continue;
        }

        guessedLetters.push_back(guess);

        if (word.find(guess) == string::npos)
            incorrectGuesses++;
    }

    cout << endl;
    drawHangman(incorrectGuesses);
    displayWord(word, guessedLetters);

    if (isWordGuessed(word, guessedLetters))
        cout << "Gratulujem uhadol si slovo: " << word << endl;
    else
        cout << "Prehral si! Slovo bolo: " << word << endl;

    return 0;
}

