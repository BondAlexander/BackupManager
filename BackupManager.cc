#include "BackupManager.h"

using namespace std;

//MyFileObject Class Methods
MyFileObject::MyFileObject(string file_path){
  this->orig_path = file_path;
  this->extension = "";
  struct stat file_buf;
  ifstream file(&file_path[0]);
  string file_as_string = "";

  vector<string> file_types;
  file_types.push_back("JFIF");
  file_types.push_back("PNG");
  file_types.push_back("PDF")

  char c;
  while(file.get(c)){
    file_as_string += c ;
    //Check if file is a JPEG
    for(int i = 0 ; i < file_types.size() ; i++){
      string f_type = file_types[i];
      if(file_as_string.length() < f_type.length()){
        break;
      }
      string f_end = file_as_string.substr(file_as_string.size()-f_type.size()-1, file_as_string.size()-1);
      cout << f_end << "\n\n";
    }

  }
  cout << file_as_string.substr(0, 6);

  //lstat the file into file_buf
  if(lstat(&(this->orig_path)[0], &file_buf) == -1){
    cerr <<  "Couldn\'t open " << this->orig_path << "\n";
  }

  this->time_created = file_buf.st_ctime;



}

std::string MyFileObject::toString(){
  time_t t = time_t(time_created);
  struct tm *ftime = localtime(&t);
  stringstream ss;

  ss   << "FILENAME:  " << orig_path << "\n"
       << "CREATED:   " << ftime->tm_hour<<":"<<ftime->tm_min<<":"<<ftime->tm_sec<<" "<<ftime->tm_mon<<"/"<<ftime->tm_mday<<"/"<<ftime->tm_year+1900 << "\n"
       << "EXTENSION: " << this->extension << "\n";
  return ss.str();
}

//Independent Methods
vector<string> mapDir(string target_path){
  DIR *target_dir;
  struct dirent *file;
  struct stat info_buf;
  vector<string> file_paths;

  if( (target_dir = opendir(&target_path[0])) != NULL){
    while( (file = readdir(target_dir)) != NULL){

      //Get File Path and assign
      string file_name = target_path + "/" + file->d_name;

      //Stat into "info_buf"
      if( (lstat(&file_name[0], &info_buf))  == -1 ){
        cerr << "Couldn\'t open " << file_name << "\n";
      }

      //If file is directory, recurse
      if(info_buf.st_mode & S_IFDIR){
        //Ignore . and ..
        if(!(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) ){
          vector<string> more_paths = mapDir(file_name);
          for(int i = 0 ; i < more_paths.size() ; i++){
            file_paths.push_back(more_paths[i]);
          }
        }
      }
      else{
        file_paths.push_back(file_name);
      }
    }
  }
  closedir(target_dir);
  return file_paths;
}


int main(int argc, char *argv[]){
  vector<string> files = mapDir(argv[1]);
  cout << "Contents of files:\n";
  for(int i = 0 ; i < files.size() ; i++){
    cout << files[i] << "\n";
  }
  cout << "\n\n\n";

  MyFileObject file = MyFileObject(files[files.size()-1]);

  cout << file.toString();

};
