#include "global.h"

using namespace std;

void welcome(){
  cout << "\nWelcome to the Ant Colony Algorithm pathfinder\n";
  cout << "Copyright (C) 2017 Raphaël Duque\n";
  cout << "License: GNU GPLv3 <http://gnu.org/licenses/gpl.html>\n";
  cout << "This is free software: you are free to change and "
       <<"redistribute it.\n";
  cout << "There is NO WARRANTY, to the extent permitted by law.\n";
  cout << "For more information, please see the README file.\n";


}

string chooseFile(){
  int ask = 1;
  string file = ""; //to return
  string ans; //anser to new or map
  cout << "You currently have these maps stored:\n";
  system("ls *.map");

  while (ask == 1){
    cout << "\nWould you like to find the optimal path with a map already"
         << " stored"
         << " [map] or would you like to enter a new map [new]?\n";

    cin >> ans;

    if (ans.compare("new") == 0){
      cout << "\nStarting procedure to make a new map...\n";
      cout << "Enter name of new map, the resulting file will be called"
           << " [what you enter].map\n";
      cout << "Remember to not use spaces\n";

      cin >> file;
      mapToFile(file);//make a new file called file.map
      ask = 0;
    }
    else if(ans.compare("map") == 0){
      cout << "\nChoosing from existing maps...\n";
      cout << "Please enter a file name (without the '.map'), you can choose"
           << " from the maps listed above";

      cin >> file;
      ask = 0;
    }
    else{
      cout << "That's not a valid answer (answer 'new' or 'map').\n";
      ask = 1;
    }

  }
  return file + ".map";
}


void mapToFile(string file){ //make file.map

}

void sorry(){

  cout << "Sorry, looks like the world of which you want to find the shortest"
       << " path has a problem. Either : \n";

  cout << " 1. The start or end position are not accessible (inside"
       << "walls),\n";
  cout << " 2. The start and end positions are at the same place (not"
       << " authorized),\n";
  cout << " 3. The world is not entirely sourrounded by a wall (the ants can "
       << "randomly walk out of the world!),\n";
  cout << " 4. There is no path between the start and end positions (good "
       << "luck with finding one!).\n";

  cout << "Please try another .map file.\n";

}

int askExit(){
  int xit = 0;
  string yn;
  int ask = 1;
  while (ask ==1 ){
    cout << "Would you like to exit ants [y or n]?";
    cin >> yn;
    if (yn.compare("y") == 0){
      xit = 1;
      ask =0;
    }
    else if (yn.compare("n")){
      xit = 0;
      ask = 0;
    }
  }
  return xit;
}
