#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include "version.h"

//update

using namespace std;

static double version =1.2;
double *versionPtr = &version;

int count(string dirPath, int* dirNum, int* fileNum, int* byteNum)
{
	if (dirPath == "")
		return -1;

	DIR *dir = opendir(dirPath.c_str());
	string pathToNext;
	struct dirent *dirStruct;
	struct stat fileContent;

	if (! dir)
		return-1;


	while (( dirStruct=readdir(dir))!= NULL) {
		pathToNext= dirPath+"/"+ (dirStruct->d_name);

		stat(pathToNext.c_str(), &fileContent);

		if(S_ISREG(fileContent.st_mode)) {
			(*fileNum)++;
			(*byteNum)+=fileContent.st_size;
		} else if (S_ISDIR(fileContent.st_mode)) {
			if ( strcmp(dirStruct->d_name,".") != 0 &&
			     strcmp(dirStruct->d_name,"..") != 0) {

				(*dirNum)++;
				count(pathToNext, dirNum, fileNum, byteNum);
			}
		}
	}






	closedir(dir);
}


int getHome( int* dirNum, int* fileNum, int* byteNum)
{
	count(getlogin(), dirNum, fileNum, byteNum);
}
void outPutSuccess(int dirNum, int fileNum, int byteNum, const char *name)
{
	cout<<"The total number of directories in directory"<< name <<" is: " << dirNum<<endl;
	cout<<"The total number of files in directory"<< name <<" is: " << fileNum<<endl;
	cout<<"The total number of bytes in directory"<< name <<" is: " << byteNum<<endl;


}

int main(int argc, char *argv[])
{

	displayVersion();
	if (argc<2) {
		cout<< "Invalide argument"<<endl;
		return 0;
	}

	int dirNum =0, fileNum=0, byteNum=0;
	string dirPath ;

	dirPath+= argv[1];
	if(dirPath.compare("~")==0)
		getHome( &dirNum, &fileNum, &byteNum);
	else
		count(dirPath, &dirNum, &fileNum, &byteNum);


	outPutSuccess( dirNum, fileNum, byteNum, argv[1]);


}
/*
int main()
{
		int dirNum =0, fileNum=0, byteNum=0;
		string path ="/usr/share";
		count("/usr/share", &dirNum, &fileNum, &byteNum);
		outPutSuccess( dirNum, fileNum, byteNum, path.c_str());
}
*/
