#include<bits/stdc++.h>						//Includes all Standard C++ Headers
#ifdef unix									//If Compilation Environment is UNIX
#include <math.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>							//For usleep() function
#define delay(x) usleep(x*1000)				//For Windows delay function
#define CLS() cout<<"\033[2J\033[1;1H"		//ANSI Escape sequence for clearing screen
int login();
void gotoxy(int x,int y){					//gotoxy function for UNIX
 	printf("%c[%d;%df",0x1B,y,x);			//ANSI Escape Seqeuence  for gotoxy
 }
#endif
#ifndef unix								//If Compilation Environment is not UNIX
#define CLS() system("cls")					//Windows clearscreen function
#include<windows.h>

#define CANDIDATE_COUNT
#define CANDIDATE1 "Emerson Munangagwa"
#define CANDIDATE2 "Nelson Chamisa"
#define CANDIDATE3 "Jean Mujuru"
#define CANDIDATE4 "Emannuel Mawarire"

int votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, spoiledtvotes = 0; //DEFINE VARIABLES TO STORE VOTE COUNTS FOR EACH CANDIDATE

void gotoxy(int x,int y){
	y--;
	static HANDLE h=NULL;
	if(!h){
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = {x,y};
	SetConsoleCursorPosition(h,c);
}
void delay(unsigned int secs){
	clock_t goal = secs +  clock();
	while(goal>clock());
}

#endif
#define FLBTECH "teacher.txt"
#define FLBSTUD "student.txt"
#define FLBCLAS "class.txt"
#define RULE(x) cout<<'\n'; for(int _=0;_<80;_++) cout<<x; cout<<'\n'
#define CL(cl,x) cl==0?1:cl==x
using namespace std;

int strcmpi(const char * s1, const char* s2){
	return strcasecmp(s1,s2);
}

bool strcmpis(pair <string, int> s1, pair <string,int> s2){
	return (strcasecmp(s1.first.c_str(),s2.first.c_str()))<0;
}

void load(){
	CLS();
	cout<<"\n\n\n\n\t\t\t\t  Please Wait!!\n\n";
	for (int i=0;i<80;i++){
		cout<<"*";
		gotoxy(i,3);
		cout<<"*";
		cout.flush();
		gotoxy(i+1,7);
		delay((rand()%80) + 20);
	}
	cout.flush();
	delay(200);
}

int scan(){
	string ch;
	int i,v;
	do{
		v=1;
		cin>>ch;
		for(i=0;i<ch.size();i++){
			if(!isdigit(ch[i])){
				v=0;
				break;
			}
		}
	}while(!v);
	return atoi(ch.c_str());
}

char bGs[8][4] = {"A+","B+", "AB+", "O+", "A-", "B-", "AB-", "O-"};
int fee[12] = {
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000
};

char * strTitle(int x){
	static char title[8] = " ";
	if(x==1)
		strcpy(title,"Mr");
	else if(x==2)
		strcpy(title,"Mrs");
	else
		strcpy(title,"Miss");
	return title;
}

class Register{
  public:
    string username, password;
};

class Login{
  public:
    string inpUsername, inpPassword;
};

class Student {
	int title;
	char studentName[30];
	int rollNo;
	char fatherName[30];
	char motherName[30];
	char address[80];
	char bloodGroup[4];
	public:
	void getDetails(void);
	void printDetails(void){
		cout<<"Student Name  : "<<strTitle(title)<<' '<<studentName<<endl;
		cout<<"Roll No.      : "<<rollNo<<endl;
		cout<<"Father's Name : "<<fatherName<<endl;
		cout<<"Mother's Name : "<<motherName<<endl;
		cout<<"Address       : "<<address<<endl;
		cout<<"Blood Group   : "<<bloodGroup<<endl;
	}
	int retRollNo(){				//Return Roll No
		return rollNo;
	}
	char * retString(char x){		//Return all strings avaialable from the Student Class
		if(x=='T')
			return strTitle(title);
		if(x=='N')
			return studentName;
		if(x=='F')
			return fatherName;
		if(x=='M')
			return motherName;
		if(x=='A')
			return address;
		if(x=='B')
			return bloodGroup;
	}
	char * retStudentName(){		//Returns Student Name
		return retString('N');
	}
	void modDetail(char ch);		//Modify Details for Student
};

class Teacher {						//Teacher class for storing Records in the teacher file
	int title;  //Mr  = 1, Mrs = 2, Miss = 3
	char teacherName[30];
	int employeeNo;
	char nextOfKin[30];
	char address[80];
	char bloodGroup[4];
	public:
	void getDetails(void);			//Get Teacher Details from user
	void printDetails(void){		//Printing the details of Teacher
		cout<<"Teacher Name  : "<<strTitle(title)<<' '<<teacherName<<endl;
		cout<<"Employee No.      : "<<employeeNo<<endl;
		cout<<"Next of Kin : "<<nextOfKin<<endl;
		cout<<"Address       : "<<address<<endl;
		cout<<"Blood Group   : "<<bloodGroup<<endl;
	}
	int retEmployeeNo(){				//Return Employee No
		return employeeNo;
	}
	char * retString(char x){		//Return all strings avaialable from the Teacher Class
		if(x=='T')
			return strTitle(title);
		if(x=='N')
			return teacherName;
		if(x=='F')
			return nextOfKin;
		if(x=='A')
			return address;
		if(x=='B')
			return bloodGroup;
	}
	char * retTeacherName(){		//Returns teacher Name
		return retString('N');
	}
	void modDetail(char ch);		//Modify Details for teacher
};

void Student::getDetails(){			//Get Student Details from user
system("CLS");
	cout<<"Enter Title \n(Mr = 1, Mrs = 2, Miss = 3)  : ";
	do{
		title = scan();
	}while(title!=1 && title!=2 && title!=3);
	cout<<"Enter Student Name    : ";
	do{
		gets(studentName);
	}while(strlen(studentName)==0);
	cout<<"Enter Roll No.        : ";
	do{
		rollNo=scan();
	}while(rollNo<1);
	cout<<"Enter Father Name     : ";
	do{
		gets(fatherName);
	}while(strlen(fatherName)==0);
	cout<<"Enter Mother Name     : ";
	do{
		gets(motherName);
	}while(strlen(motherName)==0);
	cout<<"Enter Address         : ";
	do{
		gets(address);
	}while(strlen(address)==0);
	cout<<"Enter Blood Group     : ";
	int v = 0,i;
	do{
		gets(bloodGroup);
		for (i=0;i<strlen(bloodGroup);i++) bloodGroup[i] = toupper(bloodGroup[i]);
		for(i=0;i<8;i++)
			if(!strcmp(bloodGroup,bGs[i])){
				v=1;
				break;
			}
	}while(!v);
}

void Teacher::getDetails(){			//Get Teacher Details from user
system("CLS");
	cout<<"Enter Title \n(Mr = 1, Mrs = 2, Miss = 3)  : ";
	do{
		title = scan();
	}while(title!=1 && title!=2 && title!=3);
	cout<<"Enter Teacher Name    : ";
	do{
		gets(teacherName);
	}while(strlen(teacherName)==0);
	cout<<"Enter Employee No.        : ";
	do{
		employeeNo=scan();
	}while(employeeNo<1);
	cout<<"Enter Next of Kin     : ";
	do{
		gets(nextOfKin);
	}while(strlen(nextOfKin)==0);
	cout<<"Enter Address         : ";
	do{
		gets(address);
	}while(strlen(address)==0);
	cout<<"Enter Blood Group     : ";
	int v = 0,i;
	do{
		gets(bloodGroup);
		for (i=0;i<strlen(bloodGroup);i++) bloodGroup[i] = toupper(bloodGroup[i]);
		for(i=0;i<8;i++)
			if(!strcmp(bloodGroup,bGs[i])){
				v=1;
				break;
			}
	}while(!v);
}

void Student::modDetail(char ch){	//Modify Details for Student
system("CLS");
	if(ch=='T'){					//Argument will tell which detail to modify
		cout<<"Enter Title \n(Mr = 1, Mrs = 2, Miss = 3)  : ";
		do{
			title=scan();
		}while(title!=1 && title!=2 && title!=3);
	}
	else if(ch=='N'){
		cout<<"Enter Student Name    : ";
		do{
			gets(studentName);
		}while(strlen(studentName)==0);
	}
	else if(ch=='R'){
		int r=rollNo;					//Save current Roll No.
		cout<<"Enter Roll No.        : ";
		fstream fl(FLBSTUD,ios::in|ios::binary);
		Student obj;
		do{
			rollNo = scan();
			fl.close();
			fl.open(FLBSTUD,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retRollNo()==rollNo && r!=rollNo){	//Check if the new rollNo already exists
					cout<<"\nSame Roll No. Already Exists !\n";
					cout<<"Enter Roll No.        : ";
					rollNo = -1;
				}
			}
		}while(rollNo<1);
		fl.close();
	}
	else if(ch=='F'){
		cout<<"Enter Father Name     : ";
		do{
			gets(fatherName);
		}while(strlen(fatherName)==0);
	}
	else if(ch=='M'){
		cout<<"Enter Mother Name     : ";
		do{
			gets(motherName);
		}while(strlen(motherName)==0);
	}
	else if(ch=='A'){
		cout<<"Enter Address         : ";
		do{
			gets(address);
		}while(strlen(address)==0);
	}
	else {
		cout<<"Enter Blood Group     : ";
		int v = 0,i;
		do{
			gets(bloodGroup);					//Loop for checking valid Blood Groups
			for (i=0;i<strlen(bloodGroup);i++) bloodGroup[i] = toupper(bloodGroup[i]);
			for(i=0;i<8;i++)
				if(!strcmp(bloodGroup,bGs[i])){
					v=1;
					break;
				}
		}while(!v);
	}
}

void Teacher::modDetail(char ch){	//Modify Details for Student
system("CLS");
	if(ch=='T'){					//Argument will tell which detail to modify
		cout<<"Enter Title \n(Mr = 1, Mrs = 2, Miss = 3)  : ";
		do{
			title=scan();
		}while(title!=1 && title!=2 && title!=3);
	}
	else if(ch=='N'){
		cout<<"Enter Teacher Name    : ";
		do{
			gets(teacherName);
		}while(strlen(teacherName)==0);
	}
	else if(ch=='R'){
		int r=employeeNo;					//Save current Roll No.
		cout<<"Enter Employee No.        : ";
		fstream fl(FLBTECH,ios::in|ios::binary);
		Teacher obj;
		do{
			employeeNo = scan();
			fl.close();
			fl.open(FLBTECH,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retEmployeeNo()==employeeNo && r!=employeeNo){	//Check if the new rollNo already exists
					cout<<"\nSame Employee No. Already Exists !\n";
					cout<<"Enter Employee No.        : ";
					employeeNo = -1;
				}
			}
		}while(employeeNo<1);
		fl.close();
	}
	else if(ch=='F'){
		cout<<"Enter Next of Kin     : ";
		do{
			gets(nextOfKin);
		}while(strlen(nextOfKin)==0);
	}
	else if(ch=='A'){
		cout<<"Enter Address         : ";
		do{
			gets(address);
		}while(strlen(address)==0);
	}
	else {
		cout<<"Enter Blood Group     : ";
		int v = 0,i;
		do{
			gets(bloodGroup);					//Loop for checking valid Blood Groups
			for (i=0;i<strlen(bloodGroup);i++) bloodGroup[i] = toupper(bloodGroup[i]);
			for(i=0;i<8;i++)
				if(!strcmp(bloodGroup,bGs[i])){
					v=1;
					break;
				}
		}while(!v);
	}
}

class Class {						//Class class for storing Records in class file
	int class_standard;
	char studentName[30];
	int rollNo;
	char Subject[30];
	public:
	void getDetails();				//Get Class Record Detail from user
	void printDetails(int i=1){		//Print Class Record Details

		cout<<"Student Name   : "<<studentName<<endl;
		if(i)
			cout<<"Class Standard : "<<class_standard<<endl;
		cout<<"Roll No.       : "<<rollNo<<endl;
		cout<<"Subject        : "<<Subject<<endl;
	}
	int retClass(){					//Return Class Standard
		return class_standard;
	}
	int retRollNo(){				//Return Roll No
		return rollNo;
	}
	char * retString(char x){		//Return all strings avaialable from the Class class
		if(x=='N')
			return studentName;
		if(x=='S')
			return Subject;
	}
	char * retStudentName(){		//Return Student Name
		return retString('N');
	}
	void modDetail(char ch);
};

void Class::getDetails(){			//Get Class Record Details from user
system("CLS");
	cout<<"Enter Class Standard : ";
	do{
		class_standard = scan();
	}while(class_standard>12 || class_standard<1);
	cout<<"Enter Student Name   : ";
	do{
		gets(studentName);
	}while(strlen(studentName)==0);
	cout<<"Enter Roll No.       : ";
	do{
		rollNo = scan();
	}while(rollNo<1);
	cout<<"Enter Subject        : ";
	do{
		gets(Subject);
	}while(strlen(Subject)==0);
}

void Class::modDetail(char ch){		//Modify Class Record
system("CLS");
	if(ch=='C'){
		cout<<"Enter Class Standard            : ";
		do{
			class_standard = scan();
		}while(class_standard>12 || class_standard<1);
	}
	else if(ch=='N'){
		cout<<"Enter Student Name              : ";
		do{
			gets(studentName);
		}while(strlen(studentName)==0);
	}
	else if(ch=='R'){
		fstream fl(FLBCLAS,ios::in|ios::binary);
		Class obj;
		int r = rollNo;				//Save Current Roll No.
		cout<<"Enter Roll No.                  : ";
		do{
			rollNo = scan();
			fl.close();
			fl.open(FLBCLAS,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;				//Check if new Roll No. Already Exists
				if(obj.retRollNo()==rollNo && r!=rollNo){
					cout<<"\nSame Roll No. Already Exists !\n";
					cout<<"Enter Roll No.        : ";
					rollNo=-1;
				}
			}
		}while(rollNo<1);
		fl.close();
	}
	else {
		cout<<"Subject                         : ";
		int v = 0,i;
		do{
			gets(Subject);
		}while(strlen(Subject)==0);
	}
}

void castVote(){ //FUNCTION TO ALLOW USERS TO VOTE FOR THEIR FAVOURITE CANDIDATE

    int choice; // DEFINE CHOICE VARIABLE USED TO STORE THE USERS SELECTION FOR A CANDIDATE

    printf("\n\n!!!!!!!!!!Please Vote For Your Favorite Candidate!!!!!!!!!!\n");
    printf("\n 1. %s", CANDIDATE1);
    printf("\n 2. %s", CANDIDATE2);
    printf("\n 3. %s", CANDIDATE3);
    printf("\n 4. %s", CANDIDATE4);
    printf("\n 5. %s", "None of These");

    printf("\n\n Select Your Favorite Candidate (1 - 4):\t ");
    scanf("%d", &choice);

    switch(choice){ //USE A SWITCH STATEMENT TO INSTANTIATE THE LIST AND INCREMENT THE VOTE COUNT FOR EACH CANDIDATE
        case 1: votesCount1++; break;
        case 2: votesCount2++; break;
        case 3: votesCount3++; break;
        case 4: votesCount4++; break;
        case 5: spoiledtvotes++; break;

        default: printf("\n Error: Wrong Choice !! Please retry"); //RETURN THE SCREEN
        getchar();
    }
    printf("\n Thank You For Voting !!");
    printf("\n\n!!!!!!!!!!END OF VOTING!!!!!!!!!!\n\n");
}

void votesCount(){ //FUNCTION TO ALLOW USERS TO VIEW THE CURRENT VOTING STATS/VOTE COUNT FOR THEIR FAVOURITE CANDIDATE
    printf("\n\n !!!!!!!!!!STATISTICS!!!!!!!!!!");
    printf("\n %s \t- %d ", CANDIDATE1, votesCount1);
    printf("\n %s \t- %d ", CANDIDATE2, votesCount2);
    printf("\n %s \t\t- %d ", CANDIDATE3, votesCount3);
    printf("\n %s \t- %d ", CANDIDATE4, votesCount4);
    printf("\n %s \t\t- %d ", "Spoiled Votes", spoiledtvotes);
    printf("\n\n!!!!!!!!!!END OF THE LIST!!!!!!!!!!");
}

void getLeadingCandidate(){ //FUNCTION TO ALLOW USERS TO VIEW THE LEADING CANDIDATE IN TERMS OF VOTE COUNT
    printf("\n\n!!!!!!!!!!RESULTS!!!!!!!!!!\n\n");

    //DEFINE CONDITIONS THAT HANDLE THE FUNCTION

    if(votesCount1>=votesCount2 && votesCount1>=votesCount3 && votesCount1>=votesCount4)
    printf("Leading Candidate: [%s]", CANDIDATE1); //IF CANDIDATE 1 HAS THE MOST VOTES DISPLAY AS THE LEADING CANDIDATE

    else if (votesCount2>=votesCount3 && votesCount2>=votesCount4 && votesCount2>=votesCount1)
    printf("Leading Candidate: [%s]", CANDIDATE2); //IF CANDIDATE 2 HAS THE MOST VOTES DISPLAY AS THE LEADING CANDIDATE

    else if(votesCount3>=votesCount4 && votesCount3>=votesCount2 && votesCount3>=votesCount1)
    printf("Leading Candidate: [%s]", CANDIDATE3); //IF CANDIDATE 3 HAS THE MOST VOTES DISPLAY AS THE LEADING CANDIDATE

    else if(votesCount4>=votesCount1 && votesCount4>=votesCount2 && votesCount4>=votesCount3)
    printf("Leading Candidate: [%s]", CANDIDATE4); //IF CANDIDATE 4 HAS THE MOST VOTES DISPLAY AS THE LEADING CANDIDATE

    else
    printf("----- Warning !!! No-win situation----");

    printf("\n\n!!!!!!!!!!END OF LIST!!!!!!!!!!");
}

void insertStudent(){			//Insert Student Record in File
system("CLS");
	Student obj,obj2;
	char ch;
	int v=0;
	cout<<"Enter Details for new Student :\n";
	obj.getDetails();
	fstream fl1(FLBSTUD, ios::in|ios::binary);
	ofstream fl2;
	if(!fl1){					//If file does not exist, create new file
		fl2.open(FLBSTUD,ios::out|ios::binary);
		fl2.write((char*)&obj, sizeof(obj));
		fl2.close();
		cout<<"Record successfully inserted !\n";
		return;
	}
	while(!fl1.eof()){
		fl1.read((char*)&obj2,sizeof(obj));
		if(fl1.eof()){
			break;
		}
		if(obj.retRollNo()==obj2.retRollNo()){		//If record with same Roll No. exists, then abort insertion
			cout<<"Record with same Roll No. with following details already exists : \n";
			obj2.printDetails();
			cout<<"Insertion Aborted !\n";
			return;
		}
		else if(strcmpi(obj.retStudentName(),obj2.retStudentName())==0){
			if (!v)							//Warns user that Record with same name exists
				cout<<"Warning : Record with same name exists with follwing details : \n";
			obj2.printDetails();
			cout<<'\n';
			v=1;
		}
	}
	if(v){
		cout<<"Do you still wish to insert record (Y/N) ? ";
		do{									//Asks for user confirmation after warning
			cin>>ch;
			ch = toupper(ch);
		}while(ch!= 'Y' && ch!='N');
		if(ch=='N'){
			cout<<"Insertion Aborted !\n";
			return;
		}
	}
	fl2.open(FLBSTUD,ios::out|ios::app|ios::binary);
	fl2.seekp(0,ios::end);
	fl2.write((char*)&obj, sizeof(obj));
	fl2.close();
	cout<<"\n Record Inserted successfully. Press 1 and enter for Main Menu! \n";
}

void insertTeacher(){			//Insert Student Record in File
system("CLS");
	Teacher obj,obj2;
	char ch;
	int v=0;
	cout<<"Enter Details for new Teacher :\n";
	obj.getDetails();
	fstream fl1(FLBTECH, ios::in|ios::binary);
	ofstream fl2;
	if(!fl1){					//If file does not exist, create new file
		fl2.open(FLBTECH,ios::out|ios::binary);
		fl2.write((char*)&obj, sizeof(obj));
		fl2.close();
		cout<<"Record successfully inserted !\n";
		return;
	}
	while(!fl1.eof()){
		fl1.read((char*)&obj2,sizeof(obj));
		if(fl1.eof()){
			break;
		}
		if(obj.retEmployeeNo()==obj2.retEmployeeNo()){		//If record with same Roll No. exists, then abort insertion
			cout<<"Record with same Employee No. with following details already exists : \n";
			obj2.printDetails();
			cout<<"Insertion Aborted !\n";
			return;
		}
		else if(strcmpi(obj.retTeacherName(),obj2.retTeacherName())==0){
			if (!v)							//Warns user that Record with same name exists
				cout<<"Warning : Record with same name exists with follwing details : \n";
			obj2.printDetails();
			cout<<'\n';
			v=1;
		}
	}
	if(v){
		cout<<"Do you still wish to insert record (Y/N) ? ";
		do{									//Asks for user confirmation after warning
			cin>>ch;
			ch = toupper(ch);
		}while(ch!= 'Y' && ch!='N');
		if(ch=='N'){
			cout<<"Insertion Aborted !\n";
			return;
		}
	}
	fl2.open(FLBTECH,ios::out|ios::app|ios::binary);
	fl2.seekp(0,ios::end);
	fl2.write((char*)&obj, sizeof(obj));
	fl2.close();
	cout<<"\n Record Inserted successfully. Press 1 and enter for Main Menu! \n";
}

void insertClass(){							//Insert Class Record in File
system("CLS");
	Class obj,obj2;
	char ch;
	int v=0;
	cout<<"Enter Class Details :\n";
	obj.getDetails();
	fstream fl1(FLBCLAS, ios::in|ios::binary);
	ofstream fl2;
	if(!fl1){								//Create new file if it does not exist
		fl2.open(FLBCLAS,ios::out|ios::binary);
		fl2.write((char*)&obj, sizeof(obj));
		fl2.close();
		cout<<"Record Inserted successfully !\n";
		return;
	}
	while(!fl1.eof()){
		fl1.read((char*)&obj2,sizeof(obj));
		if(fl1.eof()){
			break;
		}
		if(obj.retRollNo()==obj2.retRollNo()){		//Abort if same Roll No already exists
			cout<<"Record with same Roll No. with following details already exists : \n";
			obj2.printDetails();
			cout<<"Insertion Aborted !\n";
			return;
		}
		else if(strcmpi(obj.retStudentName(),obj2.retStudentName())==0){
			if (!v)									//Warns user if record with same Roll No. Already Exists
				cout<<"Warning : Record with same name exists with follwing details : \n";
			obj2.printDetails();
			cout<<'\n';
			v=1;
		}
	}
	if(v){									//Asks for confirmation after warning
		cout<<"Do you still wish to insert record (Y/N) ? ";
		do{
			cin>>ch;
			ch = toupper(ch);
		}while(ch!= 'Y' && ch!='N');
		if(ch=='N'){
			cout<<"Insertion Aborted !\n";
			return;
		}
	}
	fl2.open(FLBCLAS,ios::out|ios::app|ios::binary);
	fl2.seekp(0,ios::end);
	fl2.write((char*)&obj, sizeof(obj));
	fl2.close();
	cout<<"Record Inserted successfully !\n";
}

int dispClassRecord(){			//Display all Class Records

	Class obj;
	int v=0;
	fstream fl(FLBCLAS, ios::in|ios::binary);
	if(!fl){					//If file does not exist
		cout<<"Empty Records !\n";
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		v=1;
		obj.printDetails();
		RULE('-');
	}
	fl.close();
	if(!v)
		cout<<"Empty Records !\n";
	return v;
}

int dispStudentRecord(){		//Display all Student Records
system("CLS");
	Student obj;
	int v=0;
	fstream fl(FLBSTUD, ios::in|ios::binary);
	if(!fl){					//If file does not exist
		cout<<"Empty Records !\n";
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		v=1;
		obj.printDetails();
		RULE('-');
	}
	fl.close();
	if(!v)
		cout<<"Empty Records !\n";
	return v;
}

int dispTeacherRecord(){		//Display all Student Records
system("CLS");
	Teacher obj;
	int v=0;
	fstream fl(FLBTECH, ios::in|ios::binary);
	if(!fl){					//If file does not exist
		cout<<"Empty Records !\n";
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		v=1;
		obj.printDetails();
		RULE('-');
	}
	fl.close();
	if(!v)
		cout<<"Empty Records !\n";
	return v;
}

int searchClassID(const string str = "search"){		//Searching Class Record by different Attributes
	fstream fl(FLBCLAS,ios::in|ios::ate|ios::binary);
	if((!fl)||fl.tellg()==0){						//If file is empty or zero size
		cout<<"No Records Found !\n";
		return 0;
	}
	fl.close();
	fl.open(FLBCLAS,ios::in|ios::binary);
	cout<<"Enter class to "<<str<<" (0 to disable) : "; //0 to search independent of class
	int cl;
	char ch;
	char query[30];
	Class obj;
	int found = 0;
	do{
		cin>>cl;
	}while(cl>12 || cl<0);
	cout<<"Enter Attribute to search :\n";
	cout<<"  (N)ame of Student.\n";
	cout<<"  (S)ubject.\n";
	cout<<"Enter your choice : ";
	do{
		cin>>ch;
		ch = toupper(ch);
	}while(ch!='N' && ch!='S');
	cout<<"Enter Query : ";
	do{
		gets(query);
	}while(strlen(query)==0);


	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		if(CL(cl,obj.retClass())){			//Check class using the defined Macro
			if((strcmpi(query,obj.retString(ch))==0)){
				if(!found)
					cout<<"\nSearch Results : \n\n";
				obj.printDetails();
				RULE('-');
				found = 1;
			}
		}
	}
	if(!found)
		cout<<"No Records Found !\n";
	fl.close();
	return found;
}

int searchStudentID(const string str = "search"){	//Search Student by Attributes
system("CLS");
	fstream fl(FLBSTUD,ios::in|ios::ate|ios::binary);
	if((!fl)||fl.tellg()==0){						//If file is empty or zero size
		cout<<" No Records Found !\n";
		return 0;
	}
	fl.close();
	fl.open(FLBSTUD,ios::in|ios::binary);
	char ch;
	char query[30];
	Student obj;
	int found = 0;
	cout<<"Enter Attribute to "<<str<<" :\n";
	cout<<"  (T)itle.\n";
	cout<<"  (N)ame of Student.\n";
	cout<<"  (F)ather's Name.\n";
	cout<<"  (M)other's Name.\n";
	cout<<"  (A)ddress.\n";
	cout<<"  (B)lood Group.\n";
	cout<<"Enter your choice : ";
	do{
		cin>>ch;
		ch = toupper(ch);
	}while(ch!='T' && ch!='N' && ch!='F' && ch!='M' && ch!='A' && ch!='B');
	cout<<"\nEnter Query : ";
	do{
		gets(query);
	}while(strlen(query)==0);
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		if((strcmpi(query,obj.retString(ch))==0)){
			if(!found)
				cout<<"\nSearch Results : \n\n";
			obj.printDetails();
			RULE('-');
			found = 1;
		}
	}
	if(!found)
		cout<<"No Records Found !\n";
	fl.close();
	return found;
}

int searchTeacherID(const string str = "search"){	//Search Student by Attributes
system("CLS");
	fstream fl(FLBTECH,ios::in|ios::ate|ios::binary);
	if((!fl)||fl.tellg()==0){						//If file is empty or zero size
		cout<<" No Records Found !\n";
		return 0;
	}
	fl.close();
	fl.open(FLBTECH,ios::in|ios::binary);
	char ch;
	char query[30];
	Teacher obj;
	int found = 0;
	cout<<"Enter Attribute to "<<str<<" :\n";
	cout<<"  (T)itle.\n";
	cout<<"  (N)ame of Teacher.\n";
	cout<<"  (F)for Next of Kin.\n";
	cout<<"  (A)ddress.\n";
	cout<<"  (B)lood Group.\n";
	cout<<"Enter your choice : ";
	do{
		cin>>ch;
		ch = toupper(ch);
	}while(ch!='T' && ch!='N' && ch!='F' && ch!='M' && ch!='A' && ch!='B');
	cout<<"\nEnter Query : ";
	do{
		gets(query);
	}while(strlen(query)==0);
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		if((strcmpi(query,obj.retString(ch))==0)){
			if(!found)
				cout<<"\nSearch Results : \n\n";
			obj.printDetails();
			RULE('-');
			found = 1;
		}
	}
	if(!found)
		cout<<"No Records Found !\n";
	fl.close();
	return found;
}

int searchByRollNo(int i){			//Search Record by Roll No., 1 for Class, 2 for Student
system("CLS");
	int r;
	if(i==1){
		Class obj;
		int found = 0;
		int cl;
		cout<<"Enter class to search in (0 to disable) : ";	//0 to search independent of class
		do{
			cin>>cl;
		}while(cl>12 || cl<0);
		cout<<"Enter Roll No. to search for : ";
		cin>>r;
		fstream fl(FLBCLAS,ios::in|ios::binary);
		if(!fl){							//No file exists
			cout<<"No Records Found !\n";
			return 0;
		}
		while(!fl.eof()){
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof()){
				break;
			}
			if(CL(cl,obj.retClass())){
				if(r==obj.retRollNo()){				//Match attribute for each Record
					if(!found)
						cout<<"\nSearch Results : \n\n";
					obj.printDetails();
					RULE('-');
					found = 1;
				}
			}
		}
		if(!found)
			cout<<"No Records Found !\n";
		fl.close();
		return found;
	}
	else{
		int found=0;
		Student obj;
		cout<<"Enter Roll No. to search for : ";
		cin>>r;
		fstream fl(FLBSTUD,ios::in|ios::binary);
		if(!fl){					//No file exists
			cout<<"No Records Found !\n";
			return 0;
		}
		while(!fl.eof()){
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof()){
				break;
			}
			if(r==obj.retRollNo()){
				if(!found)
					cout<<"\nSearch Results : \n\n";
				obj.printDetails();
				RULE('-');
				found = 1;
			}
		}
        cout<<"\nPress 1 and enter to return to Main Menu!\n";
		if(!found)
			cout<<"No Records Found !\n";
		fl.close();
		return found;
	}
}

int searchByEmployeeNo(int i){			//Search Record by Roll No., 1 for Class, 2 for Student, 3 for techer
system("CLS");
	int r;
	if(i==3){
		Teacher obj;
		int found = 0;
		cout<<"Enter Employee No. to search for : ";
		cin>>r;
		fstream fl(FLBTECH,ios::in|ios::binary);
		if(!fl){					//No file exists
			cout<<"No Records Found !\n";
			return 0;
		}
		while(!fl.eof()){
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof()){
				break;
			}
			if(r==obj.retEmployeeNo()){
				if(!found)
					cout<<"\nSearch Results : \n\n";
				obj.printDetails();
				RULE('-');
				found = 1;
			}
		}
        cout<<"\nPress 1 and enter to return to Main Menu!\n";
		if(!found)
			cout<<"No Records Found !\n";
		fl.close();
		return found;
	}
}

void sortByStudents(char ch){			//Sort Records
	vector <pair<string,int> > lst;		//Make vector of pairs of string to sort by and Roll No.
	int i;
	if(ch=='C'){						//Sort Class Records
		Class obj;
		int v=0;
		fstream fl(FLBCLAS, ios::in|ios::binary);
		if(!fl){
			cout<<"Empty Records !\n";
			return;
		}
		while(!fl.eof()){
			fl.read((char*)&obj, sizeof(obj));
			if(fl.eof())
				break;
			v=1;
			lst.push_back(make_pair(obj.retString('N'),obj.retRollNo())); //Push each pair in the vector
		}
		fl.close();
		if(v==0){
			cout<<"Empty Records !\n";
			return;
		}
		sort(lst.begin(),lst.end(),strcmpis);	//Sort using <algorithm> sort and Custom Comparison
		fstream tmp("temp.txt",ios::out|ios::binary);
		fl.open(FLBCLAS,ios::in|ios::binary);
		fl.seekg(0,ios::beg);
		for(i=0;i<lst.size();i++){
			fl.close();
			fl.open(FLBCLAS,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retRollNo()==lst[i].second){		//Check each Roll No. from each pair and write record to new file
					tmp.write((char*)&obj,sizeof(obj));
				}
			}
		}
		fl.close();
		tmp.close();
		remove(FLBCLAS);
		rename("temp.txt",FLBCLAS);
		cout<<"\nThe Records have been successfully sorted. Press 1 and enter to return to Main menu!\n\n";
		dispClassRecord();
	}
	else{					//Sort Student Records
		Student obj;
		int v=0;
		char c;
		fstream fl(FLBSTUD, ios::in|ios::binary);
		system("CLS");
		cout<<"Enter criteria to sort :\n";
		cout<<"  (N)ame of Student.\n";
		cout<<"  (T)itle.\n";
		cout<<"Enter your choice : \n";
		do{
			cin>>c;
			c=toupper(c);
		}while(c!='N' && c!='T');
		if(!fl){
			cout<<"Empty Records !\n";
			return;
		}
		while(!fl.eof()){
			fl.read((char*)&obj, sizeof(obj));
			if(fl.eof())
				break;
			v=1;
			lst.push_back(make_pair(obj.retString(c),obj.retRollNo()));	//Push each pair in the vector
		}
		fl.close();
		if(v==0){
			cout<<"Empty Records !\n";
			return;
		}
		sort(lst.begin(),lst.end(),strcmpis);	//Sort using <algorithm> sort and Custom Comparison
		fstream tmp("temp.txt",ios::out|ios::binary);
		fl.open(FLBSTUD,ios::in|ios::binary);
		fl.seekg(0,ios::beg);
		for(i=0;i<lst.size();i++){
			fl.close();
			fl.open(FLBSTUD,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retRollNo()==lst[i].second){		//Check each Roll No. from each pair and write record to new file
					tmp.write((char*)&obj,sizeof(obj));
				}
			}
		}
		fl.close();
		tmp.close();
		remove(FLBSTUD);
		rename("temp.txt",FLBSTUD);
		cout<<"\nThe Records have been successfully sorted !\n\n";
		dispStudentRecord();
	}
}

void sortByTeachers(char ch){			//Sort Records
	vector <pair<string,int> > lst;		//Make vector of pairs of string to sort by and Roll No.
	int i;
	if(ch=='C'){						//Sort Class Records
		Class obj;
		int v=0;
		fstream fl(FLBTECH, ios::in|ios::binary);
		if(!fl){
			cout<<"Empty Records !\n";
			return;
		}
		while(!fl.eof()){
			fl.read((char*)&obj, sizeof(obj));
			if(fl.eof())
				break;
			v=1;
			lst.push_back(make_pair(obj.retString('N'),obj.retRollNo())); //Push each pair in the vector
		}
		fl.close();
		if(v==0){
			cout<<"Empty Records !\n";
			return;
		}
		sort(lst.begin(),lst.end(),strcmpis);	//Sort using <algorithm> sort and Custom Comparison
		fstream tmp("temp.txt",ios::out|ios::binary);
		fl.open(FLBTECH,ios::in|ios::binary);
		fl.seekg(0,ios::beg);
		for(i=0;i<lst.size();i++){
			fl.close();
			fl.open(FLBTECH,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retRollNo()==lst[i].second){		//Check each Roll No. from each pair and write record to new file
					tmp.write((char*)&obj,sizeof(obj));
				}
			}
		}
		fl.close();
		tmp.close();
		remove(FLBTECH);
		rename("temp.txt",FLBTECH);
		cout<<"\nThe Records have been successfully sorted. Press 1 and enter to return to Main menu!\n\n";
		dispClassRecord();
	}
	else{					//Sort Student Records
		Teacher obj;
		int v=0;
		char c;
		fstream fl(FLBTECH, ios::in|ios::binary);
		system("CLS");
		cout<<"Enter criteria to sort :\n";
		cout<<"  (N)ame of Teacher.\n";
		cout<<"  (T)itle.\n";
		cout<<"Enter your choice : \n";
		do{
			cin>>c;
			c=toupper(c);
		}while(c!='N' && c!='T');
		if(!fl){
			cout<<"Empty Records !\n";
			return;
		}
		while(!fl.eof()){
			fl.read((char*)&obj, sizeof(obj));
			if(fl.eof())
				break;
			v=1;
			lst.push_back(make_pair(obj.retString(c),obj.retEmployeeNo()));	//Push each pair in the vector
		}
		fl.close();
		if(v==0){
			cout<<"Empty Records !\n";
			return;
		}
		sort(lst.begin(),lst.end(),strcmpis);	//Sort using <algorithm> sort and Custom Comparison
		fstream tmp("temp.txt",ios::out|ios::binary);
		fl.open(FLBTECH,ios::in|ios::binary);
		fl.seekg(0,ios::beg);
		for(i=0;i<lst.size();i++){
			fl.close();
			fl.open(FLBTECH,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retEmployeeNo()==lst[i].second){		//Check each Roll No. from each pair and write record to new file
					tmp.write((char*)&obj,sizeof(obj));
				}
			}
		}
		fl.close();
		tmp.close();
		remove(FLBTECH);
		rename("temp.txt",FLBTECH);
		cout<<"\nThe Records have been successfully sorted !\n\n";
		dispTeacherRecord();
	}
}

void delClassRecord(){			//Delete Class Records
system("CLS");
	Class obj;					//Writes to new file except record to be deleted
	int f=0;
	if(!searchClassID("delete from"))
		return;
	cout<<"\nEnter Roll No. to delete : ";
	int r;
	char ch;
	cin>>r;
	fstream fl(FLBCLAS, ios::in|ios::binary);
	fstream fo("temp.dat", ios::out|ios::binary);
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		if (r==obj.retRollNo()){
			cout<<"Record with following info will be deleted :\n\n";
			obj.printDetails();
			cout<<"Do you wish to continue ? (Y/N) : ";
			do{
				cin>>ch;
				ch = toupper(ch);
			}while(ch!='N' && ch!='Y');
			if(ch=='N'){
				cout<<"Deletion Aborted !\n";
				fl.close();
				fo.close();
				remove("temp.dat");
				return;
			}
			f=1;
			continue;
		}
		fo.write((char*)&obj,sizeof(obj));
	}
	fl.close();
	fo.close();
	remove(FLBCLAS);
	rename("temp.dat",FLBCLAS);
	if(f)
		cout<<"Record Successfully Deleted !\n";
	else
		cout<<"No Such Record Exists !\n";
}

void delStudentRecord(){			//Delete Student Records
system("CLS");
	Student obj;					//Writes to new file except record to be deleted
	int f=0;
	if(!searchStudentID("delete using"))
		return;
	cout<<"\nEnter Roll No. to delete : ";
	int r;
	char ch;
	cin>>r;
	fstream fl(FLBSTUD, ios::in|ios::binary);
	fstream fo("temp.dat", ios::out|ios::binary);
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		if (r==obj.retRollNo()){
			cout<<"Record with following info will be deleted :\n\n";
			obj.printDetails();
			cout<<"Do you wish to continue ? (Y/N) : ";
			do{
				cin>>ch;
				ch = toupper(ch);
			}while(ch!='N' && ch!='Y');
			if(ch=='N'){
				cout<<"Deletion Aborted !\n";

				fl.close();
				fo.close();
				remove("temp.dat");
				return;
			}
			f=1;
			continue;
		}
		fo.write((char*)&obj,sizeof(obj));
	}
	fl.close();
	fo.close();
	remove(FLBSTUD);
	rename("temp.dat",FLBSTUD);
	if(f)
		cout<<"Record Successfully Deleted. Press 1 and enter to return to Main Menu!\n";
	else
		cout<<"No Such Record Exists !\n";
}

void delTeacherRecord(){			//Delete Student Records
system("CLS");
	Teacher obj;					//Writes to new file except record to be deleted
	int f=0;
	if(!searchTeacherID("delete using"))
		return;
	cout<<"\nEnter Employee No. to delete : ";
	int r;
	char ch;
	cin>>r;
	fstream fl(FLBTECH, ios::in|ios::binary);
	fstream fo("temp.dat", ios::out|ios::binary);
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		if (r==obj.retEmployeeNo()){
			cout<<"Record with following info will be deleted :\n\n";
			obj.printDetails();
			cout<<"Do you wish to continue ? (Y/N) : ";
			do{
				cin>>ch;
				ch = toupper(ch);
			}while(ch!='N' && ch!='Y');
			if(ch=='N'){
				cout<<"Deletion Aborted !\n";

				fl.close();
				fo.close();
				remove("temp.dat");
				return;
			}
			f=1;
			continue;
		}
		fo.write((char*)&obj,sizeof(obj));
	}
	fl.close();
	fo.close();
	remove(FLBTECH);
	rename("temp.dat",FLBTECH);
	if(f)
		cout<<"Record Successfully Deleted. Press 1 and enter to return to Main Menu!\n";
	else
		cout<<"No Such Record Exists !\n";
}

int checkNoInClass(){				//Prints total number of students in each class
system("CLS");
	int cl[12]={0,0,0,0,0,0,0,0,0,0,0,0},i,found =0;
	Class obj;
	int cnt=0;
	fstream fl(FLBCLAS,ios::in|ios::binary);
	if(!fl){
		cout<<"No Records Found !\n";
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		found=1;
		cl[obj.retClass()-1]++;			//Gets each record from file and stores count of each class [c-p cp]
	}
	if(!found)
		cout<<"No Records Found !\n";
	fl.close();
	cout<<"\tNumber of Students in :\n";
	for(i=0;i<12;i++){
		cout<<"\t\tClass "<<i+1<<((i>8)?" ":"  ")<<"    :\t";
		printf("%3d",cl[i]);
		cout<<'\n';
		cnt+=cl[i];
	}
	cout<<"\t\t-------------------\n";
	cout<<"\t\tTotal Number :\t";
	printf("%3d", cnt);
	cout<<"\n\t\t-------------------\n";
	return found;
}
int dispByStandard(){					//Display each Class record by Standard
	Class obj;
	int v=0,cl=1,cnt;
	fstream fl(FLBCLAS, ios::in|ios::binary);
	if(!fl){
		cout<<"No Records Found !\n";
		return 0;
	}
	for(cl=1;cl<=12;cl++){
		cnt=0;
		fl.close();
		fl.open(FLBCLAS, ios::in|ios::binary);		//Starts with Class 1 to 12 and checks each class
		while(!fl.eof()){
			fl.read((char*)&obj, sizeof(obj));
			if(fl.eof())
				break;
			v=1;
			if(obj.retClass()==cl){
				if(cnt==0){
					RULE('*');
					cout<<"\t\t\t\t  Class "<<cl;
					RULE('*');
					cnt=1;
				}
				obj.printDetails(0);
				RULE('-');
			}
		}
	}
	fl.close();
	if(!v)
		cout<<"No Records Found !\n";
	return v;
}
int totalRevenueGenerated(){			//Calculates total fee based on Total=Sum(Fee for Each class  * Total students in that class)
system("CLS");
	int i,found =0;
	Class obj;
	int total = 0;
	fstream fl(FLBCLAS,ios::in|ios::binary);
	if(!fl){
	cout<<" \n\n   Total Fee Revenue Generated  : \t"<<total<<".00"<<'\n';
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		total += ::fee[obj.retClass()-1];
	}
	fl.close();
	cout<<" \n\n   Total Fee Revenue Generated  : \t"<<total<<".00"<<'\n';
	return found;
}

void modEntry(char c){				//Modify Record Entry
system("CLS");
	if(c=='C'){
		Class obj;
		if(!searchClassID("search for"))
			return;					//Searches for Records and Modifies using Roll No. based on attribute
		fstream fl(FLBCLAS,ios::in|ios::binary);
		int r,pos;
		char ch;
		int found = 0;
		cout<<"Enter Roll No. of Record to modify : ";
		do{
			cin>>r;
		}while(r<1);
		while(!fl.eof()){
			pos=fl.tellg();
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof())
				break;
			if(r==obj.retRollNo()){
				cout<<'\n';
				fl.close();
				fl.open(FLBCLAS,ios::out|ios::in|ios::binary);
				while(pos--) fl.get();
				cout<<"Enter Attribute to modify :\n";
				cout<<"  (N)ame of Student.\n";
				cout<<"  (C)lass Standard.\n";
				cout<<"  (R)oll No.\n";
				cout<<"  (S)ubject.\n";
				cout<<"Enter your choice : ";
				do{
					cin>>ch;
					ch = toupper(ch);
				}while(ch!='N' && ch!='C' && ch!='R' && ch!='S');
				obj.modDetail(ch);
				obj.printDetails();
				fl.write((char*)&obj,sizeof(obj));
				RULE('-');
				break;
			}
		}
		return;
	}
		Student obj;
		if(!searchStudentID("search for"))
			return;				//Searches for Records and Modifies using Roll No. based on attribute
		fstream fl(FLBSTUD,ios::in|ios::binary);
		int r,pos;
		char ch;
		int found = 0;
		cout<<"Enter Roll No. of Record to modify : ";
		do{
			cin>>r;
		}while(r<1);
		while(!fl.eof()){
			pos=fl.tellg();
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof())
				break;
			if(r==obj.retRollNo()){
				cout<<'\n';
				fl.close();
				fl.open(FLBSTUD,ios::out|ios::in|ios::binary);
				while(pos--) fl.get();
				cout<<"Enter Attribute to modify :\n";
				cout<<"  (T)itle.\n";
				cout<<"  (N)ame of Student.\n";
				cout<<"  (R)oll No.\n";
				cout<<"  (F)ather's Name.\n";
				cout<<"  (M)other's Name.\n";
				cout<<"  (A)ddress.\n";
				cout<<"  (B)lood Group.\n";
				cout<<"Enter your choice : ";
				do{
					cin>>ch;
					ch = toupper(ch);
				}while(ch!='T' && ch!='N' &&ch!='R' && ch!='F' && ch!='M' && ch!='A' && ch!='B');
				obj.modDetail(ch);
				obj.printDetails();
				fl.write((char*)&obj, sizeof(obj));
				RULE('-');
				break;
			}
            cout<<"\nPress 1 and enter to return to Main Menu!\n";
		}
}

void modEntrys(char c){				//Modify Record Entry
system("CLS");
	if(c=='C'){
		Class obj;
		if(!searchClassID("search for"))
			return;					//Searches for Records and Modifies using Roll No. based on attribute
		fstream fl(FLBCLAS,ios::in|ios::binary);
		int r,pos;
		char ch;
		int found = 0;
		cout<<"Enter Employee No. of Record to modify : ";
		do{
			cin>>r;
		}while(r<1);
		while(!fl.eof()){
			pos=fl.tellg();
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof())
				break;
			if(r==obj.retRollNo()){
				cout<<'\n';
				fl.close();
				fl.open(FLBTECH,ios::out|ios::in|ios::binary);
				while(pos--) fl.get();
				cout<<"Enter Attribute to modify :\n";
				cout<<"  (N)ame of Teacher.\n";
				cout<<"  (C)lass Standard.\n";
				cout<<"  (E)mployee No.\n";
				cout<<"  (S)ubject.\n";
				cout<<"Enter your choice : ";
				do{
					cin>>ch;
					ch = toupper(ch);
				}while(ch!='N' && ch!='C' && ch!='E' && ch!='S');
				obj.modDetail(ch);
				obj.printDetails();
				fl.write((char*)&obj,sizeof(obj));
				RULE('-');
				break;
			}
		}
		return;
	}
		Teacher obj;
		if(!searchTeacherID("search for"))
			return;				//Searches for Records and Modifies using Roll No. based on attribute
		fstream fl(FLBTECH,ios::in|ios::binary);
		int r,pos;
		char ch;
		int found = 0;
		cout<<"Enter Employee No. of Record to modify : ";
		do{
			cin>>r;
		}while(r<1);
		while(!fl.eof()){
			pos=fl.tellg();
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof())
				break;
			if(r==obj.retEmployeeNo()){
				cout<<'\n';
				fl.close();
				fl.open(FLBTECH,ios::out|ios::in|ios::binary);
				while(pos--) fl.get();
				cout<<"Enter Attribute to modify :\n";
				cout<<"  (T)itle.\n";
				cout<<"  (N)ame of Teacher.\n";
				cout<<"  (E)mployee No.\n";
				cout<<"  (F)or Next of Kin.\n";
				cout<<"  (A)ddress.\n";
				cout<<"  (B)lood Group.\n";
				cout<<"Enter your choice : ";
				do{
					cin>>ch;
					ch = toupper(ch);
				}while(ch!='T' && ch!='N' &&ch!='E' && ch!='F' && ch!='M' && ch!='A' && ch!='B');
				obj.modDetail(ch);
				obj.printDetails();
				fl.write((char*)&obj, sizeof(obj));
				RULE('-');
				break;
			}
            cout<<"\nPress 1 and enter to return to Main Menu!\n";
		}
}

int main(){
	char ch;
	char ch1;
	int ch2;
	load();

	Register newUser;
	cout << "\n\n\nUSER REGISTRATION\n";
    cout << "\nEnter UserName: \t";
    cin >> newUser.username;
    cout << "Enter Password: \t";
    cin >> newUser.password;
    cout << "\nSuccessfully Registered your account, Please login below.\n\n";

    Login newLogin;
    cout << "\nUsername: \t";
    cin >> newLogin.inpUsername;
    cout << "Password: \t";
    cin >> newLogin.inpPassword;

    while(newLogin.inpUsername != newUser.username && newLogin.inpPassword != newUser.password);
        cout << "\nLogin Failed Please try again!\n\n";

        cout << "\nUsername: \t";
        cin >> newLogin.inpUsername;
        cout << "Password: \t";
        cin >> newLogin.inpPassword;

    if(newLogin.inpUsername == newUser.username && newLogin.inpPassword == newUser.password){
        cout << "\nSuccessfully logged in, loading your dashboard...";
    }
    else {
        cout << "Login Failed Please try again later!";
        getchar();
        return 0;
    }

	do{
		CLS();
		RULE("*");
		cout<<"\t\t\t    CUZ Management System";
		RULE("*");
		cout<<"\t1. School President Elections.\n";
		cout<<"\t2. Student Database Management.\n";
		cout<<"\t3. Class Database Management.\n";
		cout<<"\t4. Teacher Database Management.\n";
		cout<<"\t0. Exit.\n\n";
		cout<<"Enter your choice : ";
		fflush(stdin);
		cin>>ch1;

		if(ch1=='1'){
			fflush(stdin);
			load();
			do{
				CLS();
				RULE("*");
				cout<<"\t\t\t    CUZ Management System";
				RULE("*");
				cout<<"\t\t\tSchool President Election's 2022";
				RULE('-');
				cout<<"\t1.  Cast Your Vote.\n";
				cout<<"\t2.  View Candidate Vote Count.\n";
				cout<<"\t3.  View Leading Candidate.\n";
				cout<<"\t0.  Exit.\n";
				cout<<"\nEnter your choice : ";
				ch2 = scan();
				switch(ch2){
					case 1:
						castVote();
						break;
					case 2:
						votesCount();
						cout<<"\nPress 1 and enter to return to Main Menu!\n";
						break;
					case 3:
						getLeadingCandidate();
						break;
				}
				fflush(stdin);
				if(ch2)
					cin>>ch;
				else
					load();
			}while(ch2!=0);
		}

		if(ch1=='2'){
			fflush(stdin);
			load();
			do{
				CLS();
				RULE("*");
				cout<<"\t\t\t    CUZ Management System";
				RULE("*");
				cout<<"\t\t\tStudent Database Management System";
				RULE('-');
				cout<<"\t1.  Insert Records.\n";
				cout<<"\t2.  Display all Records.\n";
				cout<<"\t3.  Search for a Record using Roll No.\n";
				cout<<"\t4.  Search for a Record using other Attributes.\n";
				cout<<"\t5.  Sort all Records.\n";
				cout<<"\t6.  Modify a Record.\n";
				cout<<"\t7.  Delete a Record.\n";
				cout<<"\t0.  Exit.\n";
				cout<<"\nEnter your choice : ";
				ch2 = scan();
				switch(ch2){
					case 1:
						insertStudent();
						break;
					case 2:
						dispStudentRecord();
						cout<<"\nPress 1 and enter to return to Main Menu!\n";
						break;
					case 3:
						searchByRollNo(2);
						break;
					case 4:
						searchStudentID();
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
					case 5:
						sortByStudents('S');
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
					case 6:
						modEntry('S');
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
					case 7:
						delStudentRecord();
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
				}
				fflush(stdin);
				if(ch2)
					cin>>ch;
				else
					load();
			}while(ch2!=0);
		}

		if(ch1=='3'){
			fflush(stdin);
			load();
			do{
				CLS();
				RULE("*");
				cout<<"\t\t\t     CUZ Management System";
				RULE("*");
				cout<<"\t\t\tClass Database Management System";
				RULE('-');
				cout<<"\t1.  Insert Records.\n";
				cout<<"\t2.  Display all Records.\n";
				cout<<"\t3.  Search for a Record using Roll No.\n";
				cout<<"\t4.  Search for a Record using other Attributes.\n";
				cout<<"\t5.  Sort all Records.\n";
				cout<<"\t6.  Modify a Record.\n";
				cout<<"\t7.  Delete a Record.\n";
				cout<<"\t8.  Display Total Number of Students in Each Class.\n";
				cout<<"\t9.  Display Students by Standard.\n";
				cout<<"\t10. Display Total Fee Revenue Generated.\n";
				cout<<"\t0.  Exit.\n";
				cout<<"\nEnter your choice : ";
				ch2 = scan();
				switch(ch2){
					case 1:
						insertClass();
						break;
					case 2:
						dispClassRecord();
						break;
					case 3:
						searchByRollNo(1);
						break;
					case 4:
						searchClassID();
						break;
					case 5:
						sortByStudents('C');
						break;
					case 6:
						modEntry('C');
						break;
					case 7:
						delClassRecord();
						break;
					case 8:
						checkNoInClass();
						break;
					case 9:
						dispByStandard();
						break;
					case 10:
						totalRevenueGenerated();
						break;
				}
				fflush(stdin);
				if(ch2)
					cin>>ch;
				else{
					load();
				}
			}while(ch2!=0);
		}

		if(ch1=='4'){
			fflush(stdin);
			load();
			do{
				CLS();
				RULE("*");
				cout<<"\t\t\t    School Management System";
				RULE("*");
				cout<<"\t\t\tTeacher Database Management System";
				RULE('-');
				cout<<"\t1.  Insert Records.\n";
				cout<<"\t2.  Display all Records.\n";
				cout<<"\t3.  Search for a Record using Employee No.\n";
				cout<<"\t4.  Search for a Record using other Attributes.\n";
				cout<<"\t5.  Sort all Records.\n";
				cout<<"\t6.  Modify a Record.\n";
				cout<<"\t7.  Delete a Record.\n";
				cout<<"\t0.  Exit.\n";
				cout<<"\nEnter your choice : ";
				ch2 = scan();
				switch(ch2){
					case 1:
						insertTeacher();
						break;
					case 2:
						dispTeacherRecord();
						cout<<"\nPress 1 and enter to return to Main Menu!\n";
						break;
					case 3:
						searchByEmployeeNo(3);
						break;
					case 4:
						searchTeacherID();
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
					case 5:
						sortByTeachers('S');
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
					case 6:
						modEntrys('S');
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
					case 7:
						delTeacherRecord();
						cout<<"\nPress 1 and enter to return to Main menu!\n";
						break;
				}
				fflush(stdin);
				if(ch2)
					cin>>ch;
				else
					load();
			}while(ch2!=0);
		}
	}while(ch1!='0');
	CLS();
	return 0;
}




