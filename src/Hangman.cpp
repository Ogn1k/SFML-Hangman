#include <iostream> //хз почему но когда удаляю всё роме иострима всё работает, так что не трогаю пока
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <stdio.h>
using namespace std;

const char* dictionary(int num) // словарь слов (порядок: лёгкий, средний, хард)
{
    switch (num)
    {
    case 1: return "балл";
    case 2: return "галера";
    case 3: return "кондитер";
    case 4: return "знак";
    case 5: return "кафель";
    case 6: return "подлодка";
    case 7: return "банк";
    case 8: return "фильтр";
    case 9: return "синоптик";
    case 10: return "омар";
    case 11: return "спичка";
    case 12: return "характер";

    }
    return "num"; //чтобы не вылезал варнинг (0 раз понадобится)

}

const char* choice(string difficult) // rand-ом выбирает слово
{
    srand(time(NULL));
    int dif = std::stoi(difficult);
    int num = dif + 3 * (rand() % 4);
    const char* word = dictionary(num);
    return word;

}

void hangman(int mist, unsigned char** Letters, bool* Answer, int length) // рисует висилицу и пропуски/слова
{
    switch (mist)
    {
    case 0: printf("  +---+\n  |   |\n      |\n      |\n      |\n      |\n============\n"); break;
    case 1: printf("  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n============\n"); break;
    case 2: printf("  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n============\n"); break;
    case 3: printf("  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n============\n"); break;
    case 4: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n============\n"); break;
    case 5: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n============\n"); break;
    case 6: printf("  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n============\n"); break;
    }
    for (int i = 0; i < length; i++)
    {
        if (Answer[i] == false) printf("_");
        else printf("%s", Letters[i]);
    }
    printf("\n");
}

int main()
{
    int i = 0;
    string symbols = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя"; // чтоб пиндоские буквы не прошли в проверке
    printf("Выберите сложность:\n1. Лёгкий\n2. Средний\n3. Тяжёлый\n");
    string difficult;
    while (difficult != "1" && difficult != "2" && difficult != "3") getline(cin, difficult);
    const int length = 2 + (2 * stoi(difficult));
    const char* Word = choice(difficult); // наше слово (слоняра)
    unsigned char* Letters[length];
    bool Answer[length]; // булька которая решает, писать букву или _
    for (const char* ptr = Word; *ptr != '\0'; ptr += 2) // хитрый механизм со стак оверфлоу чтобы 2-байтовую кириллицу поделить по базе + заполнить булевый фолсами
    {
        unsigned short ch = (static_cast<unsigned char>(*(ptr)) << 8) | static_cast<unsigned char>(*(ptr + 1));
        Answer[i] = false;
        Letters[i] = new unsigned char[3];
        Letters[i][0] = ch >> 8;
        Letters[i][1] = ch & 0xFF;
        Letters[i][2] = '\0';
        printf("%s", Letters[i]); // твоё слово (для проверки, можно удалить)
        i++;

    }
    printf("\n\n");
    int mist = 0;
    hangman(mist, Letters, Answer, length);
    while (mist < 6)
    {
        string l;
        getline(cin, l);
        if (l.find_first_of(symbols) == 0 && l.length() == 2) // проверка на вшивость
        {
            const char* q = l.c_str(); //опять тот стак оверфлоу механизм для разбивки
            const char* ptr = q;
            unsigned short ch = (static_cast<unsigned char>(*(ptr)) << 8) | static_cast<unsigned char>(*(ptr + 1));
            unsigned char* Input[1];
            Input[0] = new unsigned char[3];
            Input[0][0] = ch >> 8;
            Input[0][1] = ch & 0xFF;
            Input[0][2] = '\0';
            int err = 0;
            for (int i = 0; i < length; i++) // если угадал букву, то булька становится тру в этом месте
            {
                if (Input[0][0] == Letters[i][0] && Input[0][1] == Letters[i][1])
                {
                    Answer[i] = true;
                }
                else err++;
            }
            if (err == length) mist++; // если ни в одном цикле не было совпадений то висилица затягивается на шее

        }
        hangman(mist, Letters, Answer, length);
        int found = 0;
        for (int i = 0; i < length; i++)
        {
            if (Answer[i] == true) found++; // проверка на победу
        }
        if (found == length) mist = 7;
    }
    if (mist == 6) printf("Вы проиграли!!!");
    if (mist == 7) printf("Вы победили ГОЙДА");
    return 0;

}