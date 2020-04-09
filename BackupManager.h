#ifndef ENEMY_H_INCLUDES
#define ENEMY_H_INCLUDES
#include <vector>
#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>
#include <filesystem>


class MyFileObject{
  public:

    //Constructor
    MyFileObject(std::string);

    //Getters and Setters
    void setTimeCreated(double);
    double getTimeCreated();
    void setOrigPath(std::string);
    std::string getOrigPath();
  private:
    //Class Methods

    //Class Variables
    double        time_created;
    std::string   orig_path;
};

std::vector<std::string> mapDir(std::string);

#endif
