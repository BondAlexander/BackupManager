#ifndef ENEMY_H_INCLUDES
#define ENEMY_H_INCLUDES
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <filesystem>
#include <sstream>


class MyFileObject{
  public:

    //Constructor
    MyFileObject(std::string);
    std::string toString();

    //Getters and Setters
    void setTimeCreated(double);
    double getTimeCreated();
    void setOrigPath(std::string);
    std::string getOrigPath();
  private:

    //Class Variables
    double        time_created;
    std::string   orig_path;
    std::string   extension;
};

std::vector<std::string> mapDir(std::string);

#endif
