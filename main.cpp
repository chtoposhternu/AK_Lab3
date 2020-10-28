#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "V:L:hv";

	const struct option long_options[] = {
		{"Value",required_argument,NULL,'V'},
		{"List",required_argument,NULL,'L'},
		{"help",no_argument,NULL,'h'},
		{"version",no_argument,NULL,'v'},
		{NULL,0,NULL, 0}
	};

	int parse, option_index = -1;
	
	int repeats[4] = {0, 0, 0, 0};

	while ((parse=getopt_long(argc, argv, short_options, long_options, &option_index))!=-1){
		switch(parse){
			
			case 'V': {
				if (repeats[0] == 0){ 					
					printf("Value = %s\n",optarg);
				}
				repeats[0] = 1;
				break;
			}

			case 'L': {
				if (repeats[1] == 0){
					printf("List = %s\n",optarg);
				}
				repeats[1] = 1;	
				break;
			}
			
			case 'h': {
				if (repeats[2] == 0){
					printf("Allowed commands:\n\t-V / --Value\n\t-L / --List\n\t-h / --help\n\t-v / --version\n");
				}
				repeats[2] = 1;	
				break;
			}
			
			case 'v': {			
				if (repeats[3] == 0){	
					printf("Version 1.0\n");
				}
				repeats[3] = 1;	
				break;
			}
			
			case '?': default: {
				printf("Unknown option! Try again.\n");
				break;
			}
		}
		option_index = -1;
	}
	return 0;
}

