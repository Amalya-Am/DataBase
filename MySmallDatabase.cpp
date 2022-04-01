#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

class CreateDatabase
{
public:
    void createDatabase(std::vector<std::string> args);
private:
    fstream myfile1;
};
class Command: public CreateDatabase
{ 
public:
    void executeAddCommand(std::vector<std::string> args);
    void executeGetCommand();
private:
    fstream myfile;
};

void
CreateDatabase::createDatabase(std::vector<std::string> line)
{
	
    myfile1.open(line[2], ios::out);
	if (!myfile1) {
		std::cout << "Database is not created!";
	}
	else {
		std::cout << "Database is created successfully!";
		myfile1.close(); 
	}
    
}

void
Command::executeAddCommand(std::vector<std::string> line)
{
    	
    stringstream myDir;
    stringstream myTextFile;
    string tmpName1 = line[2]; 
    stringstream myTextDir; 
    string myfilename;
    string tmpName2 = line[5]; 
  
  
    myDir << myfilename << tmpName1; 
    myTextFile << myfilename << tmpName2 << ".txt"; 
    myTextDir << myfilename << myDir.str() << "/" << myTextFile.str(); 
 
    fs::create_directory(myDir.str());
    
    myfile.open(myTextDir.str(), ios::out);
    if (!myfile) {
		std::cout << "File is not created!";
	}
	else {
		std::cout << "File is created successfully!";
		myfile.close(); 
	}
    
    myfile.open(myTextDir.str()); 
    myfile << "A weapon, arm or armament is any implement or device that can be used with the intent to inflict physical damage or harm. "; 
    myfile.close();
}

void
Command::executeGetCommand()
{
    
}


int main()
{
    std::string str;
   
    Command command;
    
    while(true) 
    {
        std::getline(std::cin, str);

        std::vector<std::string> list = split(str, ' ');

        if(list[0] == "q")
            break;
        
        if(list[0] == "create")
        {
            if(list[1] == "DB")
            {
                if(list[3] == "add")
                    {
                        if(list[4] == "line")
                            {
                                command.executeAddCommand(list);
                            }
                    }

            }
        }
        
        str = "";
    }
    cout << "Error.";

    return 0;
}