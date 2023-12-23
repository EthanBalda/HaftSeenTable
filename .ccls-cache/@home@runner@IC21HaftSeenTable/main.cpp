#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>  //stringstream
#include <string>
#include <vector>
//#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Category{HAFT_SEEN = 1, HAFT_SHEEN, OPTIONAL};

struct HaftSeenItem {
  string farsiName, englishName;
  Category category;

struct Date {
int day, month, year, hour, minute; 
};

static Date nowruzDate;
};

HaftSeenItem::Date HaftSeenItem:: nowruzDate = {19, 3, 2024, 20, 6};

vector<HaftSeenItem> loadItemsFromFile(const string &filename, Category category){
  vector<HaftSeenItem> items;
  ifstream infile;

  infile.open(filename);

  if(!infile.is_open()){
    cerr << "Error: Could not open file " << filename << endl;
  return items;
  }
  string line;
  while(getline(infile, line)){

    //stringstream class performs input.output operations on a string in the same way we do with file streams like       ifstream 

    stringstream ss(line); //good for parsing strings

    HaftSeenItem item;
    getline(ss, item.farsiName, ',');
    getline(ss, item.englishName);
    item.category = category;
    items.push_back(item);
  }
  infile.close();
  return items;
}

void displayHaftSeenTable(const vector <HaftSeenItem> &items){

  cout << "\n\t\t\tNowruz Date: "
       << HaftSeenItem::nowruzDate.month << "/" << HaftSeenItem::nowruzDate.day << "/" << HaftSeenItem::nowruzDate.year;

  int hour = HaftSeenItem::nowruzDate.hour;
  string am_pm = (hour < 12) ? "AM" : "PM";
  hour = (hour % 12 == 0) ? 12 : hour %12;
  cout << setw(2) << setfill(' ') << hour << ":"
       << setw(2) << setfill('0') << HaftSeenItem::nowruzDate.minute << " " << am_pm << " PT\n\n";
  cout << setfill(' ');

  
  
  cout << "\n\t\t\t\t🌷🌷💐💐🌺🌺🏵️🏵️ Happy"
          " Nowruz 🏵️🏵️🌺🌺💐💐🌷🌷\n\n";
  cout << "\t\t\tUnveiling the Beauty of Your Curated Haft-Seen Table\n\n";

  srand(time(0));
  for (const auto &item : items) {
    cout << left << setw(30) << item.englishName << setw(30) << "\"" + item.farsiName + "\"";

    int randomNum = rand() % 3;
    
    if (randomNum == 0) 
      cout << "🌻🌼💐";
    else if(randomNum == 1)
      cout << "💮🏵️🌸";
    else 
      cout << "🌴🌺🌾";

    cout << endl;
  }

  cout << "\n\t🌱🌱🌱🌾🌾 Enjoy the spiritual and cultural richness of Nowruz 🌾🌾🌱🌱🌱\n";
}
int main() {

  vector<HaftSeenItem> haftSeenTable;
  int choice;
  vector <pair<string, Category>> options = {{"haft_seen", HAFT_SEEN}, {"haft_sheen", HAFT_SHEEN}, {"optional", OPTIONAL}};

  for (const pair<string, Category> &option : options) {
    string fileName = option.first;
    Category category = option.second;

    cout << "Do you want to include \"" <<fileName << "\" items? Enter " << category << " for yes, 0 for no: ";
    cin >> choice;

    if (choice == category){
      vector<HaftSeenItem> categoryItems = loadItemsFromFile(fileName + ".txt", category);
      
      haftSeenTable.insert(haftSeenTable.end(), categoryItems.begin(), categoryItems.end());
    }
  }

  cout << endl;
  displayHaftSeenTable(haftSeenTable);
  cout << endl;
  return 0;
}