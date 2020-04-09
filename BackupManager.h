#ifndef ENEMY_H_INCLUDES
#define ENEMY_H_INCLUDES
#include <vector>
#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <filesystem>
#include <ctime>
#include <sstream>



class MyFileObject{
  public:

    //Constructor
    MyFileObject(std::string);

    //Class Methods
    std::string toString();

    //Getters and Setters
    void setTimeCreated(double);
    double getTimeCreated();
    void setOrigPath(std::string);
    void getOrigPath();
  private:

    //Class Variables
    double        time_created;
    std::string   orig_path;
    std::string   extension;
};

class FileCollection{
  public:
    //Constructor
    FileCollection(std::string);

    //Getters and Setters
  private:
    //Class Variables


};

std::vector<std::string> mapDir(std::string);

#endif
