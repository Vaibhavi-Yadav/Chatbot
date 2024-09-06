#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, string> memory;

    string user_input;
    // turning user_input into lowercase
    transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

    // welcome message for the bot
    cout << "Welcome user, i am a chatbot" << endl;

    // our chat functionality
    while (true)
    {
        // getting user input
        getline(cin, user_input);

        // turning user_input into lowercase
        transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

        if (user_input == "hi" || user_input == "hello" || user_input == "hey")
        {
            cout << "Hello user, how can I help you?" << endl;
        }
        else if (user_input == "how are you" || user_input == "are you ok")
        {
            cout << "As a chatbot I have no emotional states" << endl;
        }
        else if (user_input == "what's my name")
        {
            if (memory.find("name") != memory.end())
            {
                cout << "Your name is " << memory["name"] << endl;
            }
            else
            {
                cout << "Sorry you didn't tell me your name yet. Tell me your name" << endl;
            }
        }
        else if (user_input.find("my name is") != string::npos)
        {
            size_t pos = user_input.find("my name is");
            string name = user_input.substr(pos + 11);
            memory["name"] = name;
            cout << "Nice to meet you " << name << endl;
        }
        else if (user_input == "bye" || user_input == "see you later" || user_input == "later")
        {
            cout << "Bye";
            break;
        }
        else
        {
            // default message
            cout << "I didn't get that, sorry" << endl;
        }
    }
    return 0;
}


// Welcome user, i am a chatbot
// hi
// Hello user, how can I help you?
// how are you
// As a chatbot I have no emotional states
// what is your name
// I didn't get that, sorry
// what's my name
// Sorry you didn't tell me your name yet. Tell me your name
// my name is Vaibhavi
// Nice to meet you vaibhavi
// what's my name
// Your name is vaibhavi
// bye
// Bye