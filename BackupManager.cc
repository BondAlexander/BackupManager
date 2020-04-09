#include "BackupManager.h"

using namespace std;

vector<string> mapDir(string target_path){
  DIR *target_dir;
  struct dirent *file;
  struct stat info_buf;
  vector<string> file_paths;

  if( (target_dir = opendir(&target_path[0])) != NULL){
    while( (file = readdir(target_dir)) != NULL){
      string file_name = target_path + "/" + file->d_name;
      if( (lstat(&file_name[0], &info_buf))  == 0 ){
        cout << file_name << " :: " << info_buf.st_size << "\n";
      }
      else{
        cerr << "Couldn\'t open " << file_name << "\n";
      }


      file_paths.push_back(file->d_name);
    }
  }
  closedir(target_dir);
  return file_paths;
}


int main(){
  vector<string> files = mapDir("/Users/bondalexander/Documents");
  for(int i = 0 ; i < files.size() ; i++){
    cout << files[i] << "\n";
  }
};
