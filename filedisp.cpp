#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "version.h"

using namespace std;

static double version =1.2;
double *versionPtr = &version;

int main(int argc, char* argv[])
{
	displayVersion();
	string result;
	int option;
	if(strcmp("-d", argv[1])==0) {
		option =1;
	} else if (strcmp("-b", argv[1])==0) {
		option =2;
	} else if (strcmp("-f", argv[1]) ==0) {
		option =3;
	} else {
		cout<<"Invalid option."<<endl;
		return -1;
	}

	while(getline(cin, result)) {
		
		if (option ==3 && result.find("files")!= -1) {
			cout<<result<<endl;
		} else if (option ==2 && result.find("bytes")!= -1) {
			cout<<result<<endl;
		}else if (option ==1 && result.find("directories")!= -1) {
			cout<<result<<endl;
		}  

	}

}
