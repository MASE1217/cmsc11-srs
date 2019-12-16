//BAJAO, EGAY, DY
//CMSC11-A1
#include <stdio.h>
#include <string.h>
#include <math.h>


struct subjectSystem{
    int subIDNumber;
    char subCode[50];
    char title[100];
} out = {0, "none", " "}, out1 = {0, " ", " "};

struct studentSystem{
    int idNumber;
    char lastName[20];
    char firstName[20];
    char lecSection[5];
    int hex1Score;
    int hex2Score;
    int hex3Score;
    struct subjectSystem *subject1;
    struct subjectSystem *subject2;
    struct subjectSystem *subject3;
    int hex;
    char grade[3];
 } outo, outro = {0, " ", " ", " ", 0, 0, 0, &out1, &out1, &out1, 0, " "};

struct statisticSystem{
    int lowest;
    int highest;
    float avg;
    float sd;
} studStat[4];
//Struct STAT
struct statisticSystem exam1(struct statisticSystem stats);
struct statisticSystem exam2(struct statisticSystem stats);
struct statisticSystem exam3(struct statisticSystem stats);
struct statisticSystem hex(struct statisticSystem stats);

struct studentSystem inpt(struct studentSystem inpStud);
struct studentSystem updateRecords(struct studentSystem inpStud);
struct subjectSystem updateSubjects(struct subjectSystem *subinp);

void gradeGet(int s1, int s2, int s3);
void enlist(struct studentSystem *st);
void search(char str[15]);
void order(int ord);
void printStud(int number);
void printSub(struct subjectSystem *subs);
void subImp();
void studImp(struct studentSystem *students);
void enroll(int id, char no[30]);
void printInfo(int st);
void writes(char file[15]);
void deleteRecord(int ord);
void deleteSubs(char str[]);
void drop(int ord);
void subjexp(struct subjectSystem *Units);
int find(char str[10]);
int strcompare(char s1[], char s2[]);
int toLower(char x);
int toUpper(char x);
int ToInteger(char st[]);

int numOfStuds = 0;
int numberOfSubs = 1;


struct studentSystem students[70];
struct subjectSystem subs[20];

int main(void) {
    printf("\t\t\t\t\t\t ____________________________________________________________________________\n ");
    printf("\t\t\t\t\t\t|                                                                            |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||||||||||||||       ||||||||||||          |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||          ||     ||                      |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||          ||     ||                      |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||          ||     ||                      |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||          ||     ||                      |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||||||||||||||     ||                      |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||                 ||                      |\n ");
    printf("\t\t\t\t\t\t|           ||            ||      ||                 ||                      |\n ");
    printf("\t\t\t\t\t\t|            ||          ||       ||                 ||                      |\n ");
    printf("\t\t\t\t\t\t|             ||||||||||||        ||                   ||||||||||||          |\n ");
    printf("\t\t\t\t\t\t|                                                                            |\n ");
    printf("\t\t\t\t\t\t|                   COMPUTER SCIENCE STUDENT RECORD SYSTEM                   |\n ");
    printf("\t\t\t\t\t\t|____________________________________________________________________________|\n\n ");


	int c=1;
	int ord;

	for(int i = 0; i < 70; i++){
        students[i].subject1 = &out;
        students[i].subject2 = &out;
        students[i].subject3 = &out;
	}
    subs[0] = (struct subjectSystem){11, "CMSC11", "Introduction to Computer Science"};

		while (c >= 1 && c <= 14) {
            printf("\t\t\t\t\t\t\t\t    --------------  SRS MENU --------------\n\n");
            printf("\t\t\t\t\t\t\t\t  *****************************************\n");
            printf("\t\t\t\t\t\t\t\t  *  1. Create Student Record System      *\n");
            printf("\t\t\t\t\t\t\t\t  *  2. Import Student Records            *\n");
            printf("\t\t\t\t\t\t\t\t  *  3. Update Student Record System      *\n");
            printf("\t\t\t\t\t\t\t\t  *  4. Enroll to a Subject               *\n");
            printf("\t\t\t\t\t\t\t\t  *  5. Drop Subject                      *\n");
            printf("\t\t\t\t\t\t\t\t  *  6. Display All Student Record System *\n");
            printf("\t\t\t\t\t\t\t\t  *  7. Search Record System              *\n");
            printf("\t\t\t\t\t\t\t\t  *  8. Delete Student Record             *\n");
            printf("\t\t\t\t\t\t\t\t  *  9. Create Subject Record             *\n");
            printf("\t\t\t\t\t\t\t\t  *  10. Import Subject Record            *\n");
            printf("\t\t\t\t\t\t\t\t  *  11. Update Subject Record            *\n");
            printf("\t\t\t\t\t\t\t\t  *  12. Display All Subject Records      *\n");
            printf("\t\t\t\t\t\t\t\t  *  13. Delete Subject Record            *\n");
            printf("\t\t\t\t\t\t\t\t  *  14. Export Record System             *\n");
            printf("\t\t\t\t\t\t\t\t  *  0. Exit Program                      *\n");
            printf("\t\t\t\t\t\t\t\t  *****************************************\n");
            printf("\n\t\t\t\t\t\t\t\t\t   Enter choice: ");
            scanf("%d",&c);
            printf("\n************************************************************************************************************************************************************************\n");

            switch(c){

				case 1:
					students[numOfStuds] = inpt(students[numOfStuds]);
					enlist(&students[numOfStuds]);
					++numOfStuds;
					break;
					char str[15];

                case 2:
					studImp(students);
					break;

				case 3:
					printf("Student ID Number: \n");
					scanf("%d", &ord);
                    fflush(stdin);
					int i;
					for(i=0; students[i].idNumber != ord; i++){
                        ord = i;
                        students[ord] = updateRecords(students[ord]);
					}
                    break;
                case 4:
					printf("Enter Student ID number: \n");
					scanf("%d", &ord);
                    fflush(stdin);
					printf("Enter Subject Code: \n");
					scanf("%s", &str);
                    fflush(stdin);
					enroll(ord, str);
					break;

				case 5:
					printf("Student ID Number: \n");
					scanf("%d", &ord);
                    fflush(stdin);
					drop(ord);
					break;

				case 6:
					printInfo(numOfStuds);
					break;

				case 7:
					printf("Student's Last Name: \n");
					scanf(" %s", str);
                    fflush(stdin);
					search(str);
					break;

				case 8:
                    printf("Enter Student ID Number to be deleted: ");
                    scanf("%d", &ord);
                    fflush(stdin);
                    deleteRecord(ord);
                    break;

                case 9:
                    subs[numberOfSubs] = updateSubjects(&subs[numberOfSubs]);
                    ++numberOfSubs;
                    break;

                case 10:
                    printf("Input Record System file name: ");
                    scanf(" %100[^\n]s", &str);
                    fflush(stdin);
                    subinp(subs,str);
                    break;
                int capture = 0;
                case 11:
					printf("Enter Subject Code: \n");
					scanf("%s", str);
                    fflush(stdin);
					for(ord = 0; ord < numberOfSubs; ord++){
                        if(strcompare(subs[ord].subCode, str) == 0){
                            capture = 1;
                            break;
                        }
					}
					 if(capture == 1){
                        updateSubjects(&subs[ord]);
                    }else{
                        printf("NO RECORDS");
                    }
                    break;

                case 12:
                    printSub(subs);
                    break;

                case 13:
                    printf("Enter Subject code to be Deleted: \n");
                    fflush(stdin);
                    scanf("%s",str);
                    deleteSubs(str);
                    break;


                case 14:
                      printf("Enter File Name of Record System: ");
                      scanf("%s", &str);
                        fflush(stdin);
                        writes(str);
                        break;

                case 15:
                    printf("Enter File Name of Record System: ");
                    scanf("%s", &str);
                        fflush(stdin);
                        writes(str);

				default:
                    printf("END OF PROGRAM...");
                    break;
				}
				printf("\n");



    order(numOfStuds);
    //Exam Statistcs
    studStat[0] = exam1(studStat[0]);
    studStat[1] = exam2(studStat[1]);
    studStat[2] = exam3(studStat[2]);
    studStat[3] = hex(studStat[3]);
    }
}



struct studentSystem inpt(struct studentSystem inpStud){
	char str[10];
    int k = 1, cnt = 0;

    while(k == 1){
        int l;
        printf("\n\tInput another Student ID Number   : ");
        scanf("%d", &l);
        for(int i = 0; i < numOfStuds + 1; i++){
            if (students[i].idNumber == l)
            {
                printf("\t\tINVALID INPUT");
                break;
            }else{
                ++cnt;
            }
        }
        if(cnt == numOfStuds + 1){
            inpStud.idNumber = l;
            k = 0;
        }

    }
    printf("\tInput Last Name\t\t\t  : ");
    scanf(" %14[^\n]s", inpStud.lastName);
    fflush(stdin);
    printf("\tInput First Name\t\t  : ");
    scanf(" %14[^\n]s", inpStud.firstName);
    fflush(stdin);
    printf("\tInput CMSC11 Lecture Section\t  : ");
    scanf(" %4[^\n]s", inpStud.lecSection);
     fflush(stdin);
    printf("\tInput First Hands on Exam Score   : ");
    scanf("%d", &inpStud.hex1Score);
     fflush(stdin);
    printf("\tInput Second Hands on Exam Score  : ");
    scanf("%d", &inpStud.hex2Score);
     fflush(stdin);
    printf("\tInput Third Hands on Exam Score   : ");
    scanf("%d", &inpStud.hex3Score);
    fflush(stdin);
    printf("\tStudent is in the masterlist.");
    return inpStud;
}

int find(char str[10]){
    int ord, capture = -1;
    for (ord = 0; ord <= numberOfSubs; ord++){
    if(strcompare(subs[ord].subCode, str) == 0){
        capture = 1;
        break;
        }
    }
    if(capture == -1){
        return -1;
    }else{
        return ord;
    }
}


void subinp(struct subjectSystem *subs, char file[]){
    FILE *info;
    int numberOfSubs=0;
    char temp[10];
    info = fopen(file, "r");
    while(!feof(info)){
    fscanf(info, "\n%[^,], %[^,], %[^\n]", &temp, &subs[numberOfSubs].subCode, &subs[numberOfSubs].title);
    subs[numberOfSubs].subIDNumber=ToInteger(temp);
    numberOfSubs++;
    }
    fclose(info);
};

struct studentSystem updateRecords(struct studentSystem inpStud){

    printf("Another student ID number.");
    scanf(" %d", &inpStud.idNumber);
    printf("Last Name of student: ");
    scanf(" %14[^\n]s", inpStud.lastName);
    printf("First Name of student: ");
    scanf(" %14[^\n]s", inpStud.firstName);
    printf("Lecture Section: ");
    scanf(" %4[^\n]s", inpStud.lecSection);
    printf("Hands-On Exam 1 Score: ");
    scanf("%d", &inpStud.hex1Score);
    printf("Hands-On Exam 2 Score: ");
    scanf("%d", &inpStud.hex2Score);
    printf("Hands-On Exam 3 Score: ");
    scanf("%d", &inpStud.hex3Score);
    return inpStud;
}

void drop(int ord){
    int m;
    char ch[50];
    for(m = 0; students[m].idNumber != ord; m++);
    printf("\nSubjects: %s, %s, %s\n\n", students[m].subject1->subCode, students[m].subject2->subCode, students[m].subject3->subCode);
    printf("Subject Code to be dropped: ");
    scanf(" %s", ch);
    printf("\n");
    if(strcompare(ch, subs[0].subCode) == 0){
        printf("INVALID.\n");
    }else if(strcompare(students[m].subject2->subCode, ch) == 0){
        printf("%s DROPPED.\n", students[m].subject2->subCode);
        students[m].subject2 = students[m].subject3;
        students[m].subject3 = &out;
    }else if(strcompare(students[m].subject3->subCode, ch) == 0){
        printf("%s DROPPED.\n", students[m].subject3->subCode);
        students[m].subject3 = &out;
    }else{
        printf("Subject code doesn't exist.\n");
    }

}

void enroll(int id, char no[20]){
    int captured = 0;
    int seek = 0;
    for(int i = 0; i <= numOfStuds; i++){
        if(students[i].idNumber == id){
            captured = 1;
            if(strcompare(no, students[i].subject1->subCode) == 0 || strcompare(no, students[i].subject2->subCode) == 0 || strcompare(no, students[i].subject3->subCode) == 0){
                printf("ALREADY ENROLLED IN THIS SUBJECT.\n");
                break;
            }
            for(int j = 1; j <= numberOfSubs; j++){
                if(strcompare(no, subs[j].subCode) == 0){
                    if(students[i].subject2->subIDNumber == 0){
                        students[i].subject2 = &subs[j];
                        seek = 1;
                        printf("ENROLLED.\n");
                        break;
                    }else if (students[i].subject3->subIDNumber == 0){
                        students[i].subject3 = &subs[j];
                        seek = 1;
                        printf("ENROLLED.\n");
                        break;
                    }else{
                        printf("Student is already enrolled to 3 subjects.\n");
                        seek = 1;
                        break;
                    }

                }
            }
            if(seek == 0){
                    printf("Subject code doesn't exist\n");}

            break;
        }
    }if(captured == 0){
        printf("Student ID number doesn't exist\n");}
}

struct subjectSystem updateSubjects(struct subjectSystem *subinp){
    int l = 1, cnt = 0;
    while(l == 1){
        int h;
        printf("Enter Subject ID number: ");
        scanf("%d", &h);
        fflush(stdin);
        for(int i = 0; i < 20; i++){
            if (subs[i].subIDNumber == h)
            {
                printf("ID Number Already Exist. Input another ID number.\n");
                break;
            }else{
                ++cnt;
            }
        }
        if(cnt == 20){
            subinp->subIDNumber = h;
            l = 0;
        }
    }
    printf("Enter Subject Code: ");
    scanf(" %9[^\n]s", subinp->subCode);
    fflush(stdin);
    printf("Enter Subject Title: ");
    scanf(" %49[^\n]s", subinp->title);
    fflush(stdin);
    return *subinp;
}

int strcompare(char s1[], char s2[]) {
int m;
	for(m=0;s1[m]!='\0';m++) {
		if(m==0){
			s1[m] = toUpper(s1[m]);
			s2[m] = toUpper(s2[m]);
		}

		if(m!=0){
			s1[m] = toLower(s1[m]);
			s2[m] = toLower(s2[m]);
		}
	}

    m = 0;
	while(s1[m]==s2[m] && s1[m]!='\0' && s2[m]!='\0'){
		m++;
	}
	if (s1[m]>s2[m]) {
		return 1;
	} else if (s1[m]<s2[m]) {
		return -1;
	} else if (s1[m]==s2[m]) {
		return 0;
	}
}
int toUpper(char x) {
	if(x >= 'a' && x <= 'z') {
		x = x - 32;
	}
	return x;
}

int toLower(char x) {
	if(x >= 'A' && x <= 'Z') {
		x = x + 32;
	}
	return x;
}


void printSub(struct subjectSystem *subs){
    int numberOfSubs;
    printf("Subject ID\t\tSubject Code\t\tSubject Title\n");
        for(numberOfSubs=0;subs[numberOfSubs].subIDNumber!=0; numberOfSubs++){
            printf("%d\t\t\t", subs[numberOfSubs].subIDNumber);
            printf("%s\t\t\t",subs[numberOfSubs].subCode);
            printf("%s\n", subs[numberOfSubs].title);
        }
}

void printInfo(int st){
    printf("ID No.\tLast Name\tFirst Name\tLecture Section\tSubjects\t\tHex1 Score\tHex2 Score\tHex3 Score\tTotal\tGrade\n");
    for (int i = 0; i < st; i++)
    {
        int idx1, idx2,idx3, idx4;
        printf("\n%d\t%s", students[i].idNumber, students[i].lastName);
        idx1 = strcspn(students[i].lastName, ",");

        printf("\t%s\t\t", students[i].firstName);
        idx1 = strcspn(students[i].firstName, "\n");

        printf("%s\t", students[i].lecSection);
        idx1 = strcspn(students[i].lecSection, "\n");

        printf("%s,", students[i].subject1->subCode);
        idx1 = strcspn(students[i].subject1->subCode, "\n");
        printf("%s,", students[i].subject2->subCode);
        idx2 = strcspn(students[i].subject2->subCode, "\n");
        printf("%s", students[i].subject3->subCode);
        idx3 = strcspn(students[i].subject3->subCode, "\n");

        printf("\t\t\t%d\t\t", students[i].hex1Score);

        printf("%d\t\t", students[i].hex2Score);

        printf("%d\t\t", students[i].hex3Score);

        printf("%d", students[i].hex1Score+students[i].hex2Score+students[i].hex1Score);

        students[i].hex = students[i].hex1Score+students[i].hex2Score+students[i].hex3Score;

        printf("\t");

        gradeGet(students[i].hex1Score, students[i].hex2Score, students[i].hex3Score);



    }
    printf("\t\t\t\t\t\t\t\t\t\t\t    Lowest: %d\t%d\t%d\t%d\n",studStat[0].lowest, studStat[1].lowest ,studStat[2].lowest,studStat[3].lowest);
    printf("\t\t\t\t\t\t\t\t\t       Highest: %d\t%d\t%d\t%d\n",studStat[0].highest, studStat[1].highest ,studStat[2].highest,studStat[3].highest);
    printf("\t\t\t\t\t\t\t\t\t       Average: %.3f\t%.3f\t%.3f\t%.3f\n",studStat[0].avg, studStat[1].avg ,studStat[2].avg,studStat[3].avg);
    printf("\t\t\t\t\t\t\t\t\t     Std. Dev.: %.3f\t%.3f\t%.3f\t%.3f\n",studStat[0].sd, studStat[1].sd ,studStat[2].sd,studStat[3].sd);

    printf("\n");

}

void gradeGet(int s1, int s2, int s3){
    int score = s1 + s2 + s3;
    if(score >= 135){
        printf("HD");
    }else if (score>= 120)
    {
        printf("D");
    }else if (score>= 100)
    {
        printf("P");
    }else if (score>= 75)
    {
        printf("C");
    }else{
        printf("F");
    }
}
//
//Stats for Exam 1
struct statisticSystem exam1(struct statisticSystem stats){
    int scoregr[numOfStuds], min = students[0].hex1Score, max = students[0].hex1Score;
    float avg = 0,std = 0;
    for (int i = 0; i < numOfStuds; i++){
        scoregr[i] = students[i].hex1Score;
        avg += scoregr[i];
        if(scoregr[i] > max){
            max = scoregr[i];
        }
        if(scoregr[i] < min){
            min = scoregr[i];
        }
    }
    avg = avg / numOfStuds;
    for (int i = 0; i < numOfStuds; i++){
        std += pow(students[i].hex1Score - avg, 2);
    }
    stats.sd = sqrt(std/numOfStuds);
    stats.avg = avg;
    stats.highest = max;
    stats.lowest = min;
    return stats;
}

//Stats for Exam 2
struct statisticSystem exam2(struct statisticSystem stats){
   int scoregr[numOfStuds], min = students[0].hex2Score, max = students[0].hex2Score;
    float avg = 0,std = 0;
    for (int i = 0; i < numOfStuds; i++){
        scoregr[i] = students[i].hex2Score;
        avg += scoregr[i];
        if(scoregr[i] > max){
            max = scoregr[i];
        }
        if(scoregr[i] < min){
            min = scoregr[i];
        }
    }
    avg = avg / numOfStuds;
    for (int i = 0; i < numOfStuds; i++){
        std += pow(students[i].hex2Score - avg, 2);
    }
    stats.sd = sqrt(std/numOfStuds);
    stats.avg = avg;
    stats.highest = max;
    stats.lowest = min;
    return stats;
}

//Stats for Exam 3
struct statisticSystem exam3(struct statisticSystem stats){
   int scoregr[numOfStuds], min = students[0].hex1Score, max = students[0].hex3Score;
    float avg = 0,std = 0;
    for (int i = 0; i < numOfStuds; i++){
        scoregr[i] = students[i].hex3Score;
        avg += scoregr[i];
        if(scoregr[i] > max){
            max = scoregr[i];
        }
        if(scoregr[i] < min){
            min = scoregr[i];
        }
    }
    avg = avg / numOfStuds;
    for (int i = 0; i < numOfStuds; i++){
        std += pow(students[i].hex3Score - avg, 2);
    }
    stats.sd = sqrt(std/numOfStuds);
    stats.avg = avg;
    stats.highest = max;
    stats.lowest = min;
    return stats;
}

//Stats for Exams
struct statisticSystem hex(struct statisticSystem stats){
    int scoregr[numOfStuds], min = students[1].hex, max = students[1].hex;
    float ave = 0,sdv = 0;
    for (int i = 0; i < numOfStuds; i++){
        scoregr[i] = students[i].hex;
        ave += scoregr[i];
        if(scoregr[i] > max){
            max = scoregr[i];
        }
        if(scoregr[i] < min){
            min = scoregr[i];
        }
    }
    ave= ave / numOfStuds;
    for (int i = 0; i < numOfStuds; i++){
        sdv += pow(students[i].hex - ave, 2);
    }
    stats.sd = sqrt(sdv/numOfStuds);
    stats.avg = ave;
    stats.highest = max;
    stats.lowest = min;
    return stats;
}

void order(int ord){//Sort
    for (int i = 0; i < ord - 1; i++){
        for (int j = i; j <ord - 1; j++){
            if (strcompare(students[j].lastName,students[j+1].lastName) == 1){
                outo = students[j + 1];
                students[j + 1] = students[j];
                students[j] = outo;
            }
        }
    }
}

//Search student by last name
void search(char str[15]){
    int count = 0;
    for(int i = 0; i < numOfStuds; i++){
        if(strcompare(str,students[i].lastName) == 0){
            printStud(i);
            break;
        }else{
            ++count;
        }
        if(count == numOfStuds){
            printf("STUDENT DOESN'T EXIST.\n\n");
        }
    }
}

void printStud(int number){
    printf("ID number: %d\n", students[number].idNumber);
    printf("Last Name: %s\n", students[number].lastName);
    printf("First Name: %s\n", students[number].firstName);
    printf("Lecture Section: %s\n", students[number].lecSection);
    printf("HEX 1 Score: %d\n", students[number].hex1Score);
    printf("HEX 2 Score: %d\n",students[number].hex2Score);
    printf("HEX 3 Score: %d\n", students[number].hex3Score);
    printf("Subject 1: %s\n",students[number].subject1->subCode);
    printf("Subject 2: %s\n",students[number].subject2->subCode);
    printf("Subject 3: %s\n",students[number].subject3->subCode);
    printf("Total Hex Score: %d\n", students[number].hex);
    printf("Grade: %s\n", students[number].grade);
    printf("\n");
}

void studImp(struct studentSystem *students){
    FILE *info;
    int numOfStuds = 0;
    char temp[10], s1[10], s2[10], s3[10];
    info = fopen("student.txt","r");
    if(info==NULL){
    printf("Invalid Directory");
    }
    printf("%d" ,students[0].idNumber);
    while(!feof(info)){
        fscanf(info, "\n%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", &temp, &students[numOfStuds].firstName, &students[numOfStuds].lastName, &students[numOfStuds].lecSection, &s1, &s2, &s3);
        students[numOfStuds].idNumber = ToInteger(temp);
        printf(" %d  %s  %s  %s   %s  %s  %s\n", students[numOfStuds].idNumber, students[numOfStuds].lastName, students[numOfStuds].firstName, students[numOfStuds].lecSection, s1, s2, s3);
        numOfStuds++;
    }
    fclose(info);

}

void enlist(struct studentSystem *st){
    st->subject1 = &subs[0];
}

void writes(char file[15]){
    FILE * info;
    info = fopen(file, "w");
    for (int i = 0; i < numOfStuds; i++){
        fprintf(info, "%d, %s, %s, %s, %d, %d, %d, %s, %s, %s, %d, %s\n", students[i].idNumber, students[i].firstName, students[i].lastName, students[i].lecSection, students[i].hex1Score, students[i].hex2Score, students[i].hex3Score, students[i].subject1->subCode, students[i].subject2->subCode, students[i].subject3->subCode, students[i].hex, students[i].grade);
    }
    fclose(info);
}

void deleteSubs(char str[]){
    int c;
    for(int i = 0; i <= numberOfSubs; i++){
        if (strcompare(subs[i].subCode, str)==0){
            subs[i] = out;
            break;
        }
    }
}

void deleteRecord(int ord){
    int i,j;
    for(i = 0; i <= numOfStuds; i++){
        if (students[i].idNumber == ord)
            break;
    }
    for(j = i; j < numOfStuds; j++)
        students[j] = students[j + 1];
    --numOfStuds;
}

void subjexp(struct subjectSystem *Units){
    FILE *exprt;
    exprt = fopen(Units, "w");
    int page2_5, index;
    fprintf(exprt,"SUBJECT ID, SUBJECT CODE, SUBJECT TITLE\n");
    for (index = 0; Units[index].subIDNumber!= 0; index++){
        fprintf(exprt,"%d,%s,%s\n", Units[index].subIDNumber, Units[index].subCode, Units[index].title);
    }
    fclose(exprt);
};
int ToInteger(char st[]){
    int i = 0, integer = 0, sign = 1;
    if (st[0] == '-'){
        i = 1;
        sign = -1;
    }
    for (i = i; st[i] != 00; i++){
        integer = integer * 10 + st[i] - 48;
    }
    return(integer*sign);
};





