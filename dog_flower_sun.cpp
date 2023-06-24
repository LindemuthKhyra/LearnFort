#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

//Enum for the different levels of difficulty
enum Level {
  Beginner = 1,
  Intermediate,
  Advanced
};

//A class that contains the information about a specific level
class LevelInfo {
public:
  Level level;
  int numQuestions;
  int totalScore;

  LevelInfo(Level l, int numQuest, int totalScor) {
    level = l;
    numQuestions = numQuest;
    totalScore = totalScor;
  }
};

//A struct that contains the information about a specific user
struct User {
  string name;
  Level currentLevel;
  int totalScore;
};

//A class that represents an online education platform that gamifies learning
class EduPlatform {
private:
  unordered_map<string, User*> users;
  map<Level, LevelInfo*> levels;

public:
  //Constructor
  EduPlatform()  {
    //Set up levels
    levels[Beginner] = new LevelInfo(Beginner, 10, 1000);
    levels[Intermediate] = new LevelInfo(Intermediate, 20, 2000);
    levels[Advanced] = new LevelInfo(Advanced, 30, 3000);
  }

  //Function to add a new user to the platform
  void addUser(string name) {
    User* user = new User();
    user->name = name;
    user->currentLevel = Beginner;
    user->totalScore = 0;

    users[name] = user;
  }

  //Function to get the level info for a specific level
  LevelInfo* getLevelInfo(Level l) {
    return levels[l];
  }

  //Function to update the user's current level and total score
  void updateUser(string name, Level newLevel, int newScore) {
    User* user = users[name];
    user->currentLevel = newLevel;
    user->totalScore = newScore;
  }

  //Function to get the current user's total score
  int getUserScore(string name) {
    return users[name]->totalScore;
  }

  //Function to get all of the users in the platform
  vector<User*> getAllUsers() {
    vector<User*> userList;
    for (auto it = users.begin(); it != users.end(); ++it) {
      userList.push_back(it->second);
    }
    return userList;
  }
};

int main() {
  EduPlatform platform;
  platform.addUser("John");
  platform.addUser("Mary");
  platform.addUser("Alice");

  LevelInfo* beginner = platform.getLevelInfo(Beginner);
  cout << "Beginner level has " << beginner->numQuestions << " questions and " << beginner->totalScore << " points" << endl;

  platform.updateUser("John", Intermediate, 1500);
  cout << "John's current total score is: " << platform.getUserScore("John") << endl;

  vector<User*> users = platform.getAllUsers();
  for (auto user : users) {
    cout << user->name << " is at Level: " << user->currentLevel << endl;
  }
  return 0;
}