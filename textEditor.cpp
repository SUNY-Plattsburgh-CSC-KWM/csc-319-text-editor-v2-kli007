#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int implement(string& command, vector<string>& file, string& buffer);

int main() {
    vector<string> file;
    string command;
    string buffer;

    while (command != "q"){
        cout << "> ";
        cin >> command;
        implement(command, file, buffer);
        cout << endl;
    }

    cout << "End Command" << endl;
    return 0;
}


int implement(string& command, vector<string>& file, string& buffer) {
    string line;
    string input;

    //append
    if (command == "a") {
        cin.ignore();
        getline(cin, input);
        file.push_back(input);
    }
    //change
    if (command == "c"){
        string newinput;
        cout << "Enter the old string\n> ";
        cin.ignore();
        getline(cin, input);
        cout << "Enter the new string\n> ";
        getline(cin, newinput);

        for (auto i = file.begin(); i != file.end(); ++i) {
            if (*i == input) {
                auto index = distance(file.begin(), i);
                file[index] = newinput;
            }
        }
    }
    //delete
    if (command == "d") {
        cin >> line;
        file.erase(file.begin() + stoi(line));
    }
    //find
    if (command == "f") {
        cin.ignore();
        getline(cin, input);

        for (auto i = file.begin(); i != file.end(); ++i) {
            if (*i == input) {
                auto index = distance(file.begin(), i);
                cout << "[" << index << "] " << *i << endl;
            }
        }
        return 0;
    }
    //help
    if (command == "h") {
        cout << "Command List:\n"
                "a: append input\n"
                "c: change oldInput with newInput\n"
                "d: delete line n\n"
                "f: find input\n"
                "h: help\n"
                "i: insert line n\n"
                "l: prints letter counts\n"
                "r: replace line n with input\n"
                "w: write out file\n"
                "s: sort\n"
                "p: puts \n"
                "st: summarizes the file\n"
                "q: quit\n"
                "y: yank" << endl;
        return 0;
    }
    //insert
    if (command == "i") {
        cin >> line;
        file.insert(file.begin() + stoi(line), "");
    }
    //letter
    if (command == "l") {
        for (auto i = file.begin(); i != file.end(); ++i) {
            auto index = distance(file.begin(), i);
            int count = file[index].length();
            cout << "[" << index << "]" << "[" << count << "] "<< *i << endl;
        }
        return 0;
    }
    //put
    if (command == "p") {
        cin >> line;
        file.insert(file.begin() + stoi(line), buffer);
    }
    //replace
    if (command == "r") {
        cin >> line;
        getline(cin, file[stoi(line)]);
    }
    //write
    if (command == "w") {
        cin >> input;
        ofstream outfile;

        outfile.open(input);
        if (outfile.fail()) {
            cerr << "Error opening file" << endl;
            return 1;
        }

        for (auto i = file.begin(); i != file.end(); ++i) {
            auto index = distance(file.begin(), i);
            outfile << file[index] << endl;
        }
        outfile.close();
        cout << "File written successfully" << endl;
        return 0;
    }
    //sort
    if (command == "s") {
        sort(file.begin(), file.end());
    }
    //stats
    if (command == "st") {
        int count = 0;
        for (auto i = file.begin(); i != file.end(); ++i) {
            auto index = distance(file.begin(), i);
            count += file[index].length();
        }
        cout << "Line count: " << file.size() << " Character Count: " << count << endl;
        return 0;
    }
    //yank
    if (command == "y") {
        cin >> line;
        buffer = file[stoi(line)];
        cout << "Yanked: " << buffer << endl;
        return 0;
    }

    for (auto i = file.begin(); i != file.end(); ++i) {
        auto index = distance(file.begin(), i);
        cout << "[" << index << "]"<< *i << endl;
    }
    return 0;
}