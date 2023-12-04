// CSV Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program uses the CSV Library. See csv.hpp.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include <sstream>
#include "csv.hpp"
using namespace std;
using namespace chrono;
using namespace csv;




struct game {
    string appID;
    string name;
    string releaseDate;
    string estimatedPlayers;
    string price;
    string description;
    vector<string> supportedLanguages;
    string windowsCompatible;
    string macCompatible;
    string linuxCompatible;
    string positiveReviews;
    string negativeReviews;
    string achievements;
    string recommendations;
    vector<string> developers;
    vector<string> genres;
    vector<string> tags;
    game* leftChild = nullptr;
    game* rightChild = nullptr;
    game* parent = nullptr;
    bool red = true;

    game(string _appID, string _name, string _releaseDate, string _estimatedPlayers, string _price, string _description, string _windowsCompaitble, string _macCompatible, string _linuxCompatible, string _positiveReviews, string _negativeReviews, string _achievements, string _recommendations, vector<string> _supportedLanguages, vector<string> _developers, vector<string> _genres, vector<string> _tags) {
        appID = _appID; //Initialize all Variables on Creation
        name = _name;
        releaseDate = _releaseDate;
        estimatedPlayers = _estimatedPlayers;
        price = _price;
        description = _description;
        windowsCompatible = _windowsCompaitble;
        macCompatible = _macCompatible;
        linuxCompatible = _linuxCompatible;
        positiveReviews = _positiveReviews;
        negativeReviews = _negativeReviews;
        achievements = _achievements;
        recommendations = _recommendations;
        supportedLanguages = _supportedLanguages;
        developers = _developers;
        genres = _genres;
        tags = _tags;
    }

    game() { //Default Constructor just in case
        appID = -1;
        name = "Not Provided";
    }

    void display() {
        cout << "Steam App ID: " << appID << endl << "Name: " << name << endl << "Released: " << releaseDate << endl;   //Display all facts about the game
        cout << "Estimated Players: " << estimatedPlayers << endl << "Price: " << price << endl;
        cout << "Description: " << description << endl;
        cout << "Compatibilities: " << "Windows: " << windowsCompatible << " Mac: " << macCompatible << " Linux: " << linuxCompatible << endl;
        cout << "Reviews: Positive " << positiveReviews << ", Negative " << negativeReviews << endl;
        cout << "Total Achievements: " << achievements << endl << "Recommendations: " << recommendations << endl;
        cout << "Supported Languages: ";
        for (int i = 0; i < supportedLanguages.size(); i++) {   //Print Supported Languages
            if (i != supportedLanguages.size() - 1) {
                cout << supportedLanguages.at(i) << ", ";
            }
            else {
                cout << supportedLanguages.at(i) << endl;
            }
        }

        cout << "Developers: ";
        for (int i = 0; i < developers.size(); i++) {   //Print Developers
            if (i != developers.size() - 1) {
                cout << developers.at(i) << ", ";
            }
            else {
                cout << developers.at(i) << endl;
            }
        }

        cout << "Genres: ";
        for (int i = 0; i < genres.size(); i++) {   //Print Genres
            if (i != genres.size() - 1) {
                cout << genres.at(i) << ", ";
            }
            else {
                cout << genres.at(i) << endl;
            }
        }

        cout << "Tags: ";
        for (int i = 0; i < tags.size(); i++) {   //Print Tags
            if (i != tags.size() - 1) {
                cout << tags.at(i) << ", ";
            }
            else {
                cout << tags.at(i) << endl;
            }
        }

    }




};

game* insertGame(game* root, game* lastRoot, string _appID, string _name, string _releaseDate, string _estimatedPlayers, string _price, string _description, string _windowsCompaitble, string _macCompatible, string _linuxCompatible, string _positiveReviews, string _negativeReviews, string _achievements, string _recommendations, vector<string> _supportedLanguages, vector<string> _developers, vector<string> _genres, vector<string> _tags) {

    if (root == nullptr) {
        root = new game(_appID, _name, _releaseDate, _estimatedPlayers, _price, _description, _windowsCompaitble, _macCompatible, _linuxCompatible, _positiveReviews, _negativeReviews, _achievements, _recommendations, _supportedLanguages, _developers, _genres, _tags);
        root->parent = lastRoot;
    }
    else if (_appID <= root->appID) {
        root->leftChild = insertGame(root->leftChild, root, _appID, _name, _releaseDate, _estimatedPlayers, _price, _description, _windowsCompaitble, _macCompatible, _linuxCompatible, _positiveReviews, _negativeReviews, _achievements, _recommendations, _supportedLanguages, _developers, _genres, _tags);
    }
    else if (_appID > root->appID) {
        root->rightChild = insertGame(root->rightChild, root, _appID, _name, _releaseDate, _estimatedPlayers, _price, _description, _windowsCompaitble, _macCompatible, _linuxCompatible, _positiveReviews, _negativeReviews, _achievements, _recommendations, _supportedLanguages, _developers, _genres, _tags);
    }

    //Balancing

    if (root->parent == nullptr) {//New root
        root->red = false;
        return root;
    }
    else if (root->parent->red == false) {
        //Do nothing, its already balanced.
        return root;
    }
    else { //Every other Case
        game* child = root;
        game* parent = root->parent;
        game* grandparent;
        game* uncle;

        if (parent == nullptr) {
            return root;
        }

        if (parent->parent == nullptr) {
            grandparent == nullptr;
            uncle == nullptr;
            return root;
        }
        else {
            grandparent = parent->parent;
            if (grandparent == nullptr) {
                uncle = nullptr;
            }
            else { //Assign Uncle
                if (grandparent->leftChild == parent) {
                    uncle = grandparent->rightChild;
                }
                else {
                    uncle = grandparent->leftChild;
                }
            }


            //Modify



        }
    }


    return root;

}

void inOrderTraversal(game* root) {
    if (root != nullptr) {
        inOrderTraversal(root->leftChild);
        cout << root->appID << endl;
        inOrderTraversal(root->rightChild);
    }
}

void createVector(string input, vector<string>* vect) {
    for (int i = 0; i < 5; i++) {
        if (i == 0 && input != "") {
            string temp;
            for (int j = 0; j < input.size(); j++) {
                if (input.at(j) != ',') {
                    temp += input.at(j);
                }
                else {
                    vect->push_back(temp);
                    temp.clear();
                    if (input.at(j + 1) == ' ') {
                        j++; // ignore the following space
                    }
                }
            }
        }
    }
}

int main()
{
    high_resolution_clock::time_point start = high_resolution_clock::now(); //Start Timer

    //CSVReader reader("../CSV_FILES/TestProjectBook.csv"); //Shortened Dataset
    CSVReader reader("../CSV_FILES/games2.csv"); //Full Dataset

    vector<string> vectorOfAppIDs; //Initialize all vectors that will be used for datapoints
    vector<string> vectorOfNames;
    vector<string> vectorOfReleaseDates;
    vector<string> vectorOfEstimatedPlayers;
    vector<string> vectorOfPrices;
    vector<string> vectorOfDescriptions;
    vector<string> vectorOfWindowsCompatibility;
    vector<string> vectorOfMacCompatibility;
    vector<string> vectorOfLinuxCompatibility;
    vector<string> vectorOfPositiveReviews;
    vector<string> vectorOfNegativeReviews;
    vector<string> vectorOfAchievements;
    vector<string> vectorOfRecommendations;
    vector<string> vectorOfSupportedLanguagesUnparsed;
    vector<string> vectorOfDevelopersUnparsed;
    vector<string> vectorOfGenresUnparsed;
    vector<string> vectorOfTagsUnparsed;


    vector<vector<string>> vectorOfSupportedLanguages;
    vector<vector<string>> vectorOfDevelopers;
    vector<vector<string>> vectorOfGenres;
    vector<vector<string>> vectorOfTags;


    vector<game*> games;

    for (auto& row : reader) {
        vectorOfAppIDs.push_back(row["AppID"].get<string>());
        vectorOfNames.push_back(row["Name"].get<string>());
        vectorOfReleaseDates.push_back(row["Release date"].get<string>());
        vectorOfEstimatedPlayers.push_back(row["Estimated owners"].get<string>());
        vectorOfPrices.push_back(row["Price"].get<string>());
        vectorOfDescriptions.push_back(row["About the game"].get<string>());
        vectorOfWindowsCompatibility.push_back(row["Windows"].get<string>());
        vectorOfMacCompatibility.push_back(row["Mac"].get<string>());
        vectorOfLinuxCompatibility.push_back(row["Linux"].get<string>());
        vectorOfPositiveReviews.push_back(row["Positive"].get<string>());
        vectorOfNegativeReviews.push_back(row["Negative"].get<string>());
        vectorOfAchievements.push_back(row["Achievements"].get<string>());
        vectorOfRecommendations.push_back(row["Recommendations"].get<string>());
        vectorOfSupportedLanguagesUnparsed.push_back(row["Supported languages"].get<string>()); //Unparsed
        vectorOfDevelopersUnparsed.push_back(row["Developers"].get<string>()); //Unparsed
        vectorOfGenresUnparsed.push_back(row["Genres"].get<string>()); //Unparsed
        vectorOfTagsUnparsed.push_back(row["Tags"].get<string>()); //Unparsed
    }

    vector<vector<string>> allLanguagesParsed;

    for (int i = 0; i < vectorOfSupportedLanguagesUnparsed.size(); i++) { //Parse Supported Languages
        vector<string> stringSeperator;
        stringstream newString(vectorOfSupportedLanguagesUnparsed.at(i));
        string line;
        while (getline(newString, line, ',')) {
            stringSeperator.push_back(line);
        }
        allLanguagesParsed.push_back(stringSeperator);
    }

    for (int i = 0; i < allLanguagesParsed.size(); i++) {
        for (int j = 0; j < allLanguagesParsed.at(i).size(); j++) {
            if (allLanguagesParsed.at(i).at(j).at(0) == ' ') {
                allLanguagesParsed.at(i).at(j).erase(allLanguagesParsed.at(i).at(j).begin()); //Delete spaces in the first character
            }
            for (int k = 0; k < allLanguagesParsed.at(i).at(j).size(); k++) {
                if (allLanguagesParsed.at(i).at(j).at(k) == '[' || allLanguagesParsed.at(i).at(j).at(k) == ']' || allLanguagesParsed.at(i).at(j).at(k) == '\'') { //Delete other characters
                    allLanguagesParsed.at(i).at(j).erase(allLanguagesParsed.at(i).at(j).begin() + k);
                    k--;
                }
            }
        }
    }

    vector<vector<string>> allDevelopersParsed;
    vector<vector<string>> allGenresParsed;
    vector<vector<string>> allTagsParsed;


    for (int i = 0; i < vectorOfDevelopersUnparsed.size(); i++) { //Parse Supported Developers
        vector<string> stringSeperator;
        stringstream newString(vectorOfDevelopersUnparsed.at(i));
        string line;
        while (getline(newString, line, ',')) {
            stringSeperator.push_back(line);
        }
        allDevelopersParsed.push_back(stringSeperator);
    }

    for (int i = 0; i < vectorOfGenresUnparsed.size(); i++) { //Parse Supported Genres
        vector<string> stringSeperator;
        stringstream newString(vectorOfGenresUnparsed.at(i));
        string line;
        while (getline(newString, line, ',')) {
            stringSeperator.push_back(line);
        }
        allGenresParsed.push_back(stringSeperator);
    }

    for (int i = 0; i < vectorOfTagsUnparsed.size(); i++) { //Parse Supported Tags
        vector<string> stringSeperator;
        stringstream newString(vectorOfTagsUnparsed.at(i));
        string line;
        while (getline(newString, line, ',')) {
            stringSeperator.push_back(line);
        }
        allTagsParsed.push_back(stringSeperator);
    }




    game* root = nullptr;
    game* headPointer = new game();

    for (int i = 0; i < vectorOfAppIDs.size(); i++) { //Create all new game nodes
        //game* newGame = new game(vectorOfAppIDs.at(i), vectorOfNames.at(i), vectorOfReleaseDates.at(i), vectorOfEstimatedPlayers.at(i), vectorOfPrices.at(i), vectorOfDescriptions.at(i), vectorOfWindowsCompatibility.at(i), vectorOfMacCompatibility.at(i), vectorOfLinuxCompatibility.at(i), vectorOfPositiveReviews.at(i), vectorOfNegativeReviews.at(i), vectorOfAchievements.at(i), vectorOfRecommendations.at(i), allLanguagesParsed.at(i), allDevelopersParsed.at(i), allGenresParsed.at(i), allTagsParsed.at(i));

        root = insertGame(root, headPointer, vectorOfAppIDs.at(i), vectorOfNames.at(i), vectorOfReleaseDates.at(i), vectorOfEstimatedPlayers.at(i), vectorOfPrices.at(i), vectorOfDescriptions.at(i), vectorOfWindowsCompatibility.at(i), vectorOfMacCompatibility.at(i), vectorOfLinuxCompatibility.at(i), vectorOfPositiveReviews.at(i), vectorOfNegativeReviews.at(i), vectorOfAchievements.at(i), vectorOfRecommendations.at(i), allLanguagesParsed.at(i), allDevelopersParsed.at(i), allGenresParsed.at(i), allTagsParsed.at(i));
    }

    inOrderTraversal(root);
    /*
    for (int i = 0; i < games.size(); i++) { //Display all games (for testing)
        games.at(i)->display();
        cout << endl << endl;
    }
    */

    // Input and display

    vector<string> vLang, vSys, vGenre, vTag;
    vector<game*> currGames; // Vector of currently displayed games for splay tree(?)

    string language, achievement, system, genre, tag, input;
    bool hasAchievements = true;

    cout << "Welcome to Retro Recommend! Please respond to the following filter inquiries. Separate listed elements with a comma. (Ex.\"English, Spanish, French \") " << endl;

    bool gameSearch = true;

    while (gameSearch) {

        cout << "Supported language(s)?: " << endl;
        cin >> language;

        cout << "Operating System(s)?: " << endl;
        cin >> system;

        cout << "Are there achievements in this game? Please enter (y) or yes, (n) or no: " << endl;
        cin >> achievement;

        if (achievement == "y" || "Y" || "yes" || "Yes") {
            hasAchievements = true;
        }
        else if (achievement == "n" || "N" || "no" || "No")
        {
            hasAchievements = false;
        }

        cout << "Genre(s)?: " << endl;
        cin >> genre;

        cout << "Tag(s)?: " << endl;
        cin >> tag;

        createVector(language, &vLang);
        createVector(system, &vSys);
        createVector(genre, &vGenre);
        createVector(tag, &vTag);

        // TOD0 : Tree based functions


        for (int i = 0; i < currGames.size(); i++) {
            games.at(i)->display();
            cout << endl << endl;
        }

        cout << "Would you like to continue? Please enter (y) or yes, (n) or no: " << endl;
        cin >> input;

        if (input == "n" || "no" || "No") {
            gameSearch = false;
            break;
        }

    }

    high_resolution_clock::time_point stop = high_resolution_clock::now(); //End timer and display run time
    duration<float> totalTime = duration_cast<duration<float>>(stop - start);
    cout << totalTime.count() << " seconds." << endl;





    //Beginning the AVL Tree











}