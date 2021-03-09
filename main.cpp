/*
    Name  : Tran Thanh Son - 20021432
    Major : Infomation Systems
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

void printHangman(int chance)
{
    switch (chance)
    {
    case 6:
    {
        cout << "_____________   " << endl;
        cout << "|     }         " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|============   " << endl;
        break;
    }
    case 5:
    {
        cout << "_____________   " << endl;
        cout << "|     }         " << endl;
        cout << "|     o         " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|============   " << endl;
        break;
    }
    case 4:
    {
        cout << "_____________   " << endl;
        cout << "|     }         " << endl;
        cout << "|     o         " << endl;
        cout << "|     |         " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|============   " << endl;
        break;
    }
    case 3:
    {
        cout << "_____________   " << endl;
        cout << "|     }         " << endl;
        cout << "|     o         " << endl;
        cout << "|     |         " << endl;
        cout << "|   / |         " << endl;
        cout << "|  /  |         " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|============   " << endl;
        break;
    }
    case 2:
    {
        cout << "_____________   " << endl;
        cout << "|     }         " << endl;
        cout << "|     o         " << endl;
        cout << "|     |         " << endl;
        cout << "|   / | \\      " << endl;
        cout << "|  /  |  \\     " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|               " << endl;
        cout << "|============   " << endl;
        break;
    }
    case 1:
    {
        cout << "_____________   " << endl;
        cout << "|     }         " << endl;
        cout << "|     o         " << endl;
        cout << "|     |         " << endl;
        cout << "|   / | \\      " << endl;
        cout << "|  /  |  \\     " << endl;
        cout << "|     |         " << endl;
        cout << "|    /          " << endl;
        cout << "|   /           " << endl;
        cout << "|============   " << endl;
        break;
    }
    case 0:
    {
        cout << "_____________   " << endl;
        cout << "|     }         " << endl;
        cout << "|     o         " << endl;
        cout << "|     |         " << endl;
        cout << "|   / | \\      " << endl;
        cout << "|  /  |  \\     " << endl;
        cout << "|     |         " << endl;
        cout << "|    / \\       " << endl;
        cout << "|   /   \\      " << endl;
        cout << "|============   " << endl;
        break;
    }
    default:
    {
        break;
    }
    }
}

void getWordToDataBase(string *wordDataBase, int n)
{
    string s;
    ifstream file("word.txt");
    file >> n;
    getline(file, s);
    while (!file.eof())
    {
        for (int i = 0; i < n; i++)
        {
            getline(file, wordDataBase[i]);
        }
    }
}

int generateRandomNumder(int n)
{
    srand(time(0));
    int randomNum = 0;
    randomNum = rand() % n;
    return randomNum;
}

int getNumderOfWord()
{
    int count = 0;
    ifstream file("word.txt");
    file >> count;
    return count;
}

int countCharacterInWord(string word)
{
    return word.size();
}

bool checkAppear(string word, char c, int stringSize)
{
    for (int i = 0; i < stringSize; i++)
        if (word[i] == c)
            return true;
    return false;
}

void convertHiddenStringToAppear(string &temp, string word, char c, int stringSize, int &countCorrect)
{
    for (int i = 0; i < stringSize; i++)
        if (word[i] == c)
        {
            temp[i] = c;
            countCorrect++;
        }
}

void getHiddenString(string &temp, int stringSize)
{
    for (int i = 0; i < stringSize; i++)
        temp[i] = '_';
}

void printHiddenString(string &temp, int stringSize)
{
    for (int i = 0; i < stringSize; i++)
    {
        cout << temp[i];
    }
    cout << endl;
}

int main()
{
    char c;
    int chance = 6;
    int n = getNumderOfWord();
    int randomNum = generateRandomNumder(n);
    int countCorrect = 0;
    string start, word, temp;
    string wordDataBase[n];
    getWordToDataBase(wordDataBase, n);
    word = wordDataBase[randomNum];
    int stringSize = countCharacterInWord(word);
    getHiddenString(temp, stringSize);

    cout << "Hang Man Game " << endl;
    cout << "Press any key and press enter to start: " << endl;
    cin >> start;
    cout << "You have 6 chances" << endl;
    
    while (chance >= 0 && countCorrect < stringSize)
    {
        cout << "Word: ";
        printHiddenString(temp, stringSize);
        cin >> c;
        if (checkAppear(word, c, stringSize) == true)
        {
            printHangman(chance);
            convertHiddenStringToAppear(temp, word, c, stringSize, countCorrect);
            cout << "You have " << chance << " chances left" << endl;
            printHiddenString(temp, stringSize);
        }
        else
        {
            printHangman(chance - 1);
            chance--;
            if (chance < 0)
                break;
            cout << "You were wrong " << endl;
            cout << "You have " << chance << "chances left" << endl;
        }
    }

    if (countCorrect == stringSize && chance >= 0)
        cout << "Congratulations !!";
    if (chance < 0)
    {
        cout << "You was losed !!" << endl;
        cout << "The hidden word is " << word;
    }
    return 0;
}
