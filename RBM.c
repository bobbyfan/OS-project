#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct appointment
{
    char service[10]; /* "Mee" for meeting, "Pre" for presentation, "Con" for conference, "Dev" for device */
    char room[5]; /* "A" or "B", represent room A, room B, can be empty*/
    char date[20]; /* YYYY-MM-DD*/
    char time[10]; /* hh:mm*/
    double duration; /* Duration of the appointment in hours, e.g. 2.0*/
	char caller[10]; /* three tenants: "tenant_A", "tenant_B" and "tenant_C"*/
	char fac1[20]; /* specific facility, can be "webcam_720p" or "webcam_1080p" or "projector_fhd" or "projector_xga"*/
	char fac2[20]; /* specific facility, can be "monitor_50" or "monitor_75" or "screen_100" or "screen_150".*/
	
};

struct appointment input(char array []){
	/* not yet finished*/
	struct appointment ap;
	int i=0, j=0, k=0;
	char temp[] = "MPCDB";
	char *p;
	
	if (array[3] == temp[0] || array[3] == temp[1] || array[3] == temp[2]){
		p = strtok (array, " ");
		while (p != NULL){
			if(i == 0){
				for ( j = 0; j < 3; j++){
					ap.service[j] = p[j+3];
				}
				ap.service[j] = 0;
			}
			if(i == 1){
				for ( j = 0; j < sizeof(ap.room); j++){
					ap.room[j] = p[j+6];
				}
				ap.room[j] = 0;
			}
			if(i == 2){
				for ( j = 0; j <= sizeof(ap.date); j++){
					ap.date[j] = p[j];
				}
				ap.date[j] = 0;
			}
			if(i == 3){
				for ( j = 0; j <= sizeof(ap.time); j++){
					ap.time[j] = p[j];
				}
				ap.time[j] = 0;
			}
			if(i == 4){
				ap.duration = atof(p);
			}
			if(i == 5){
				for ( j = 0; j <= sizeof(ap.caller); j++){
					ap.caller[j] = p[j];
				}
				ap.caller[j] = 0;
			}
			if(i == 6){
				for ( j = 0; j <= sizeof(ap.fac1); j++){
					ap.fac1[j] = p[j];
				}
				ap.fac1[j] = 0;
			}
			if(i == 7){
				for ( j = 0; j < sizeof(ap.fac2); j++){
					if (p[j] == temp[4]) break;
					ap.fac2[j] = p[j];
				}
				ap.fac2[j] = 0;
			}
			i++;
			p = strtok (NULL, " ");
		}
		printf("\n");

	}
	
	if (array[3] == temp[0]){
		p = strtok (array, " ");
		while (p != NULL){
			if(i == 0){
				for ( j = 0; j < 3; j++){
					ap.service[j] = p[j+3];
				}
				ap.service[j] = 0;
			}
			if(i == 1){
				for ( j = 0; j < sizeof(ap.fac1); j++){
					ap.fac1[j] = p[j+1];
				}
				ap.fac1[j] = 0;
			}
			if(i == 2){
				for ( j = 0; j <= sizeof(ap.date); j++){
					ap.date[j] = p[j];
				}
				ap.date[j] = 0;
			}
			if(i == 3){
				for ( j = 0; j <= sizeof(ap.time); j++){
					ap.time[j] = p[j];
				}
				ap.time[j] = 0;
			}
			if(i == 4){
				ap.duration = atof(p);
			}
			if(i == 5){
				for ( j = 0; j <= sizeof(ap.caller); j++){
					ap.caller[j] = p[j];
				}
				ap.caller[j] = 0;
			}
			i++;
			p = strtok (NULL, " ");
		}
	}
	
	return ap;


}

void interface(){
	int job=0;
	char in[200];
	char firstchar[4] = "apeA", methodchar[3] = "fpo";
	struct appointment ap[100];/*Array of struct, The max number of appoinment is 100*/
	
	printf("~~ WELCOME TO PolySME ~~\n");
	while(1){
		
		printf("Please enter booking: \n");
		fgets ( in, sizeof (in), stdin);
		
		if (in[0] == firstchar[1]/*p*/ ){
			if(in[17] == methodchar[0]/*f*/ ){
				/* Use the fcfs*/
			}
			if(in[17] == methodchar[1]/*p*/ ){
				/* Use the prio*/
			}
			if(in[17] == methodchar[2]/*o*/ ){
				/* Use the opti*/
			}
		}
		
		if (in[0] == firstchar[2]/*e*/ ) break;
		
		if (in[0] == firstchar[0]/*a*/ ){
			/* recevice the appointment and put into the appointment array*/
			ap[job] = input(in);
			printf("%s %s %s %lf %s %s %s %s", ap[job].service, ap[job].date, ap[job].time, ap[job].duration, ap[job].room, ap[job].caller, ap[job].fac1, ap[job].fac2);
			job++;
			
		}
	}
}

int main(){
	interface();
}
