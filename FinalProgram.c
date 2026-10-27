#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#pragma warning(disable:4996)

#define MAX_STAFF 100
#define MAX_SIZE 50
#define MAX_SIZE 50
#define MAX_TRAINS 50
#define MAX_BOOKINGS 100



// Staff Structure
typedef struct {
	int staff_id;
	char name[MAX_SIZE];
	char password[MAX_SIZE];
	char position[MAX_SIZE];
	char email[MAX_SIZE];
	char ph_NO[MAX_SIZE];
	char address[MAX_SIZE];
	char department[MAX_SIZE];
	int reset_password_flag;
}Staff;


// Structure for staff leave
typedef struct {
	int staff_id;
	char start_date[11];
	char end_date[11];
}Leave;





// Member structure
typedef struct {
	char memberID[6];
	char name[100];
	char memberPassword[5];
	char gender;
	char ic[15];
	char phoneNO[12];
	char securityQuestion[100];
	char recoveryAnswer[50];
}MemberInfo;





//Train structure
typedef struct {
	char train_id[6];
	char departure_station[22], arrival_station[22];
	double price;
	int departure_hour;
	int departure_minutes;
	int arrival_hour;
	int arrival_minutes;
	int available;
	int seat;
}Train;


Train modify[MAX_TRAINS];
Train deleteTrains[MAX_TRAINS];
Train search;
Train display[MAX_TRAINS];
Train generate[MAX_TRAINS];



// Booking structure
typedef struct {
	char arrival_Station[22], departure_Station[22];
	char train_id[7], booking_id, member_id;
	char  date[15], pMethod[20];
	int departure_hour, departure_minutes, arrival_hour, arrival_minutes, ticket_status, seat;
	double price;
} BookingInfo;

BookingInfo booking[MAX_BOOKINGS];



//Function Declaration for Staff Mode
void staffMenu();
int login_staff(Staff staffList[], int* staffCount);
void register_staff(Staff staffList[], int* staffCount);
void password_recovery(Staff staffList[], int staffCount);
void display_profile(const Staff* staff);
void leave_management(int staff_id, Leave leaves[], int* leaveCount);
int reset_password(Staff* staff);
int valid_email(const char* email);


//Function Declaration for Member Mode
void memberModule();
void registerMember();
void loginMember();
void displayMemberProfile(MemberInfo loggedInMember);
void clearInputBuffer();
void memberAccountMenu(MemberInfo loggedInMember);
void recoverPassword();
void editMemberProfile(MemberInfo loggedInMember);
void resetPassword(MemberInfo* loggedInMember);
void generateMemberReport();
void cancelMembership(MemberInfo loggedInMember);
void memberMenu(MemberInfo loggedInMember);


//Function Declaration for Train Schedule
void trainMenu();
int isRegistered(int staffID);
void manageSchedule(int* numTrains);
void trainScheduleMenu(int* numTrains);
void addTrain(int* numTrains);
void modifyTrain(Train* train, int numTrains);
void deleteTrain(Train* train, int numTrains);
void searchTrain(Train* train, int numTrains);
void displaySchedule(Train* train, int numTrains);
void generateReport(Train* train, int numTrains);
void convertToUpper(char* str);
int validTimeInput(const char* timeInput, int* Hour, int* Minutes);
int validSeatInput(const char* seatInput);


//Function Declaration for Ticket Booking
void ticketModule(BookingInfo booking[], int* count);
void bookingInterface(BookingInfo booking[], int count);
void ticketStatus(BookingInfo booking[], int count);
void paymentProcess(BookingInfo booking[], int count);
void searchTicket(BookingInfo booking[], int* count);
void bookTicket(BookingInfo booking[], int* count);
void changeTicket(BookingInfo booking[], int* count);
void deleteTicket(BookingInfo booking[], int* count);
void displayAvailableTickets(BookingInfo booking[], int count);
void bookedStatus(BookingInfo booking[], int count);




// Main page , allow user to choose staff mode , member mode , train schedule and ticket booking
main() {
	int choice;

	system("cls");

	printf("\n\n");

	printf("\t\t\t\t\t\t\tWW    WW EEEEEEEE LL        CCCCCCC  OOOOOO  M      M  EEEEEEEE        TTTTTTTT  OOOOOO \n");
	printf("\t\t\t\t\t\t\tWW    WW EE       LL       CC       OO    OO MMM  MMM  EE                 TT    OO    OO\n");
	printf("\t\t\t\t\t\t\tWW WW WW EEEEEEE  LL       CC       OO    OO MM MM MM  EEEEEEE            TT    OO    OO\n");
	printf("\t\t\t\t\t\t\tWWW  WWW EE       LL       CC       OO    OO MM    MM  EE                 TT    OO    OO\n");
	printf("\t\t\t\t\t\t\tWW    WW EEEEEEEE LLLLLLLL  CCCCCCC  OOOOOO  MM    MM  EEEEEEEE           TT     OOOOOO \n");
	printf("\n\n");

	printf("\t\t\t\tTTTTTTTT RRRRRRR      AA     IIIIIIII NN    NN       TTTTTTTT IIIIIIII  CCCCCCC KK   K  EEEEEEEE TTTTTTTT IIIIIIII NN    NN GGGGGGGG\n");
	printf("\t\t\t\t   TT    RR     R    A  A       II    NNN   NN          TT       II    CC       KK K    E           TT       II    NNN   NN GG\n");
	printf("\t\t\t\t   TT    RRRRRRR    AAAAAA      II    NN  N NN          TT       II    CC       KKK     EEEEEEE     TT       II    NN N  NN GG   GGGG\n");
	printf("\t\t\t\t   TT    RR RR     AA    AA     II    NN   NNN          TT       II    CC       KK K    E           TT       II    NN   NNN GG     G\n");
	printf("\t\t\t\t   TT    RR   RRR AA      AA IIIIIIII NN    NN          TT    IIIIIIII  CCCCCCC KK   K  EEEEEEEE    TT    IIIIIIII NN    NN GGGGGGGG\n");
	printf("\n\n");

	printf("\t\t\t\t\t\t\t\t\t     SSSSSS  YY    YY  SSSSSS  TTTTTTTT EEEEEEEE  M      M\n");
	printf("\t\t\t\t\t\t\t\t\t    SS        YY  YY  SS          TT    EE        MMM  MMM\n");
	printf("\t\t\t\t\t\t\t\t\t     SSSSSS     YY     SSSSSS     TT    EEEEEEE   MM MM MM\n");
	printf("\t\t\t\t\t\t\t\t\t          SS    YY          SS    TT    EE        MM    MM\n");
	printf("\t\t\t\t\t\t\t\t\t     SSSSSS     YY     SSSSSS     TT    EEEEEEEE  MM    MM\n");
	printf("\n\n\n");

	printf("\t\t\t\t\t+ - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +\n");
	printf("\t\t\t\t\t-  Selection :                                              -\n");
	printf("\t\t\t\t\t+                                                           +\n");
	printf("\t\t\t\t\t-       1. Staff Administrator Mode                         -\n");
	printf("\t\t\t\t\t+       2. Member Mode                                      +\n");
	printf("\t\t\t\t\t+       3. Exit                                             -\n");
	printf("\t\t\t\t\t+                                                           +\n");
	printf("\t\t\t\t\t- + - + - + - + - + - + - + - + - + - + - + - + - + - + - + -\n");

	do {
		printf("\n");
		printf("\t\t\t\t\tEnter choice (1-3): ");
		while (scanf("%d", &choice) != 1) {
			clearInputBuffer();
			printf("\t\t\t\t\t\t** Invalid choice! Please enter a valid choice. **\n\n");
			printf("\t\t\t\t\tEnter choice (1-3): ");

		}
		if (choice < 1 || choice > 3) {
			clearInputBuffer();
			printf("\t\t\t\t\t\t** Invalid choice! Please enter a valid choice. **\n");
		}
	} while (choice < 1 || choice > 3);


	switch (choice) {
	case 1:
		system("cls");
		staffMenu();
		break;
	case 2:
		system("cls");
		memberModule();
		break;
	case 3:
		break;
	default:
		printf("\t\t\t\t\t\tInvalid choice. Please try again.\n");
	}

	system("pause");
}




int login_staff(int* loggedInStaff, Staff staffList[], int staffCount) {
	int staff_id;
	char password[MAX_SIZE];
	Staff staff;

	printf("\n\t\t\tEnter Staff ID: ");
	scanf("%d", &staff_id);
	printf("\n\t\t\tEnter password: ");
	scanf("%s", password);

	FILE* file = fopen("staff.txt", "r");
	if (file == NULL) {
		printf("Error opening file for reading.\n");
		return -1;
	}

	int i; // Declaration of i
	while (fscanf(file, "%d | %s | %s | %s | %s | %s | %s | %s",
		&staff.staff_id, staff.name, staff.password,
		staff.position, staff.email, staff.ph_NO,
		staff.address, staff.department) != EOF) {
		if (staff.staff_id == staff_id && strcmp(staff.password, password) == 0) {
			printf("Login successful. Welcome %s.\n", staff.name);
			for (i = 0; i < staffCount; i++) {
				if (staffList[i].staff_id == staff_id) {
					staffList[i].reset_password_flag = 1; // Set reset password flag
					break;
				}
			}
			fclose(file);
			*loggedInStaff = staff.staff_id;
			return 1; // Successful login
		}
	}

	printf("Invalid staff ID or password. Please try again.\n");
	fclose(file);
	return -1; // Unsuccessful login
}



void register_staff(Staff staffList[], int* staffCount) {
	Staff newStaff;

	FILE* file = fopen("staff.txt", "a");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}
	printf("\t\t\tYou are not able to have space for every data. Sorry for any inconvinience.\n");
	printf("\t\t\t***You can use ',' or uppercase instead of using space.***\n\n");

	printf("\n\t\t\tEnter staff ID (Exp: 12345): ");
	scanf("%5d", &newStaff.staff_id);
	rewind(stdin);
	printf("\n\t\t\tEnter name: ");
	scanf("%[^\n]", &newStaff.name);
	rewind(stdin);
	printf("\n\t\t\tEnter password: ");
	scanf("%s", &newStaff.password);
	rewind(stdin);
	printf("\n\t\t\tEnter position: ");
	scanf("%[^\n]", &newStaff.position);
	rewind(stdin);

	printf("\n\t\t\tEnter email (xxx@gmail.com): ");
	scanf("%s", &newStaff.email);
	rewind(stdin);
	if (!valid_email(newStaff.email)) {
		do {
			printf("\t\t\tInvalid email format. Please try again.\n");
			printf("\t\t\tEnter email (MUST include '@' and '.'): ");
			scanf("%s", &newStaff.email);
			rewind(stdin);
		} while (!valid_email(newStaff.email));
	}

	printf("\n\t\t\tEnter phone number: ");
	scanf("%s", &newStaff.ph_NO);
	rewind(stdin);
	printf("\n\t\t\tEnter address: ");
	scanf("%[^\n]", &newStaff.address);
	rewind(stdin);
	printf("\n\t\t\tEnter department: ");
	scanf("%[^\n]i", &newStaff.department);
	rewind(stdin);


	fprintf(file, "%.5d | %s | %s | %s | %s | %s | %s | %s\n",
		newStaff.staff_id, newStaff.name, newStaff.password,
		newStaff.position, newStaff.email, newStaff.ph_NO,
		newStaff.address, newStaff.department);

	fclose(file);
	printf("\n\t\t\tRegistration successfully! Welcome, %s\n", newStaff.name);
}



void password_recovery(Staff staffList[], int staffCount) {

	int found = 0;
	char email[MAX_SIZE];
	Staff staff;

	FILE* file = fopen("staff.txt", "w");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}

	printf("\t\t\tEnter your email: ");
	scanf("%s", &staff.email);
	rewind(stdin);


	if (!valid_email(staff.email)) {
		printf("\t\t\tInvalid email format. Please try again.\n");
		printf("\t\t\tEnter email: ");
		scanf("%s", &staff.email);
		rewind(stdin);
	}

	while (fscanf(file, "%s| %s", staff.email, staff.password) != EOF)

		for (int i = 0; i < staffCount; i++) {
			if (strcmp(staffList[i].email, email) == 0) {
				printf("\t\t\tYour password is: %s\n", staffList[i].password);
				found = 1;
				break;
			}
		}
	if (!found) {
		printf("\n\t\t\tNo account found with the provided Email...\n");
	}
	fclose(file);
}


void display_profile(const Staff* staff) {
	FILE* file = fopen("staff.txt", "r");
	if (file == NULL) {
		printf("Error opening file.\n");
		return;
	}
	while (fscanf(file, "%d | %s | %s | %s | %s | %s | %s | %s",
		&staff->staff_id, staff->name, staff->password,
		staff->position, staff->email, staff->ph_NO,
		staff->address, staff->department) != EOF) {

		printf("\t\t\t\t---------------------------------------------------------------\n");
		printf("\t\t\t\t==                                                           ==\n");
		printf("\t\t\t\t==     Staff ID      : %.5d                                 ==\n", staff->staff_id);
		printf("\t\t\t\t==     Name          : %-15s                       ==\n", staff->name);
		printf("\t\t\t\t==     Position      : %-15s                       ==\n", staff->position);
		printf("\t\t\t\t==     Email         : %-15s                       ==\n", staff->email);
		printf("\t\t\t\t==     Phone Number  : %-15s                       ==\n", staff->ph_NO);
		printf("\t\t\t\t==     Address       : %-15s                  ==\n", staff->address);
		printf("\t\t\t\t==     Department    : %-15s                       ==\n", staff->department);
		printf("\t\t\t\t==                                                           ==\n");
		printf("\t\t\t\t---------------------------------------------------------------\n");

		fclose(file);
		return -1;
	}
}


void leave_management(int staff_id, Leave leaves[], int* leaveCount) {
	if (*leaveCount >= MAX_SIZE) {
		printf("\n\t\t\tMaximum leave application reached.\n");
		return 0;
	}

	printf("\n\t\t\tEnter the start date of your leave(YYYY-MM-DD): ");
	scanf("%10s", &leaves[*leaveCount].start_date);
	rewind(stdin);
	printf("\n\t\t\tEnter the end date of you leave(YYYY-MM-DD): ");
	scanf("%10s", &leaves[*leaveCount].end_date);

	if (strcmp(leaves[*leaveCount].start_date, leaves[*leaveCount].end_date) > 0) {
		printf("\n\t\t\tInvalid date range. Start date must before the end date.\n");
		return 0;
	}

	leaves[*leaveCount].staff_id = staff_id;
	(*leaveCount)++;
	printf("\n\t\t\tLeave applied from %s to %s successfully.\n", leaves[*leaveCount - 1].start_date, leaves[*leaveCount - 1].end_date);
	return 1;
}

int reset_password(Staff staffList[], int staffCount, int targetStaffID) {

	// Open the file for reading
	FILE* file = fopen("staff.txt", "r+");
	if (file == NULL) {
		printf("Error opening file.\n");
		return 0;// Return 0 to indicate failure
	}

	char newPassword[MAX_SIZE];
	int index = -1;

	if (staffList[index].reset_password_flag == 0) {
		printf("\t\t\tPassword doesn't need to be reset.\n");
		return 0;
	}

	printf("\t\t\tEnter new password: ");
	scanf("%s", &newPassword);
	rewind(stdin);
	strcpy(staffList[index].password, newPassword);//change the new password
	staffList[index].reset_password_flag = 0;
	printf("\t\t\tPassword changed successfully.\n");

	return -1;
}


int valid_email(const char* email) {
	int i, at_count = 0;
	int dot_count = 0;

	for (int i = 0; email[i] != '\0'; i++) {
		if (email[i] == '@') {
			at_count++;
		}
		else if (email[i] == '.') {
			dot_count++;
		}
	}
	return (at_count == 1 && dot_count > 0);
}

void welcomepage() {
	printf("\t\t==================================================================================\n");
	printf("\t\t==================================================================================\n");
	printf("\t\tW     W  EEEEEEE  L        CCCCCCC  OOOOOOO  M     M  EEEEEEE     TTTTTTT  OOOOOOO\n");
	printf("\t\tW  W  W  E        L        C        O     O  M M M M  E              T     O     O\n");
	printf("\t\tW W W W  EEEEEEE  L        C        O     O  M  M  M  EEEEEEE        T     O     O\n");
	printf("\t\tW W W W  E        L        C        O     O  M     M  E              T     O     O\n");
	printf("\t\t W   W   EEEEEEE  LLLLLLL  CCCCCCC  OOOOOOO  M     M  EEEEEEE        T     OOOOOOO\n\n");
	printf("\t\tSSSSSSS  TTTTTTT    AAA    FFFFFFF  FFFFFFF     M     M  OOOOOOO  DDDDDD   EEEEEEE\n");
	printf("\t\tS           T      A   A   F        F           M M M M  O     O  D    DD  E      \n");
	printf("\t\tSSSSSSS     T     AAAAAAA  FFFFF    FFFFF       M  M  M  O     O  D    DD  EEEEEEE\n");
	printf("\t\t      S     T     AA   AA  F        F           M     M  O     O  D    DD  E      \n");
	printf("\t\tSSSSSSS     T     AA   AA  F        F           M     M  OOOOOOO  DDDDDD   EEEEEEE\n");
	printf("\t\t==================================================================================\n");
	printf("\t\t==================================================================================\n\n");
}

void staffMenu() {
	Staff staffList[MAX_STAFF];
	Staff staff[MAX_STAFF];
	Leave leaveArray[MAX_SIZE];
	int staffCount = 0;
	int leaveCount = 0;
	int loggedInStaff = -1;
	int choice, staff_id;
	int loggedInChoice;
	char password[MAX_SIZE];

	welcomepage();

	do {

		printf("\n\n\t\tPlease select an option: \n");
		printf("\t\t1. Login\n");
		printf("\t\t2. Register\n");
		printf("\t\t3. Password Recovery\n");
		printf("\t\t4. Exit\n");
		printf("\t\tEnter your choice(1 - 4): ");
		scanf("%d", &choice);
		rewind(stdin);
		system("cls");

		switch (choice) {
		case 1:
			loggedInStaff = login_staff(&staff_id, staffList, staffCount);


			if (loggedInStaff != -1) {
				do {
					printf("\n----------------------------------\n");
					printf("|   Staff menu:                    |\n");
					printf("|        1. Display Profile        |\n");
					printf("|        2. Reset Password         |\n");
					printf("|        3. Leave Management       |\n");
					printf("|        4. Manage Train           |\n");
					printf("|        5. Generate Member Report |\n");
					printf("|        6. Logout                 |\n");
					printf("------------------------------------\n");
					printf("Enter your choice: ");
					scanf(" %d", &loggedInChoice);

					switch (loggedInChoice) {
					case 1:
						display_profile(&staff);
						break;
					case 2:
						reset_password(staffList, staffCount, loggedInStaff);
						break;

					case 3:
						leave_management(&staff_id, leaveArray, &leaveCount);
						break;

					case 4:
						trainMenu(loggedInStaff);
						break;

					case 5:
						generateMemberReport();
						break;
					case 6:
						main();
						break;

					default:
						printf("Invalid choice. please try again.\n");
					}
					if (choice == '4') {
						break;
					}
				} while (loggedInChoice != 4);
			}
			break;

		case 2:
			register_staff(staffList, &staffCount);
			break;

		case 3:
			password_recovery(staffList, &staffCount);
			break;

		case 4:
			main();
			break;

		default:
			printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 4);
	return 0;
}












// To clean the input buffer
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// Allow user choose to register or login 
void memberModule() {
	int choice;

	system("cls");
	printf("\n\n\n");
	printf("\t\t\t\t\t\t MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RRRRRRR           AA     CCCCCCCC CCCCCCCC EEEEEEEE  SSSSSS   SSSSSS  \n");
	printf("\t\t\t\t\t\t MMM  MMM EE       MMM  MMM BB     B EE       RR    RR         A  A    CC       CC       EE       SS       SS       \n");
	printf("\t\t\t\t\t\t MM MM MM EEEEEEE  MM MM MM BBBBBBB  EEEEEEE  RRRRRRR         AAAAAA   CC       CC       EEEEEEE   SSSSSS   SSSSSS  \n");
	printf("\t\t\t\t\t\t MM    MM EE       MM    MM BB     B EE       RR RR          AA    AA  CC       CC       EE             SS       SS \n");
	printf("\t\t\t\t\t\t MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RR  RRR       AA      AA CCCCCCCC CCCCCCCC EEEEEEEE  SSSSSS   SSSSSS  \n\n");
	printf("\t\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\t\t         .  .  .            .  .  .           .  .  .  \n");
	printf("\t\t\t\t\t\t\t\t\t       .         .        .         .       .         .\n");
	printf("\t\t\t\t\t\t\t\t\t      .   0   0   .      .   0   0   .     .   0   0   .\n");
	printf("\t\t\t\t\t\t\t\t\t      .           .      .           .     .           .\n");
	printf("\t\t\t\t\t\t\t\t\t       .    U    .        .    U    .       .    U    .\n");
	printf("\t\t\t\t\t\t\t\t\t         .  .  .            .  .  .           .  .  .\n");
	printf("\n\n\n");
	printf("\t\t\t =========================================================\n");
	printf("\t\t\t == SELECTION :                                         ==\n");
	printf("\t\t\t =========================================================\n");
	printf("\t\t\t ==                                                     ==\n");
	printf("\t\t\t ==     1. Register As A Member.                        ==\n");
	printf("\t\t\t ==     2. Login To Your Account.                       ==\n");
	printf("\t\t\t ==     3. Back                                         ==\n");
	printf("\t\t\t =========================================================\n");
	printf("\n");


	do {
		printf("\n");
		printf("\t\t\tEnter choice (1-3): ");
		while (scanf("%d", &choice) != 1) {
			printf("\t\t\t\t** Invalid choice! Please enter a valid choice. **\n\n");
			printf("\t\t\tEnter choice (1-3): ");
			clearInputBuffer();
		}
		clearInputBuffer();
		if (choice < 1 || choice > 3) {
			printf("\t\t\t\t** Invalid choice! Please enter a valid choice. **\n");
		}
	} while (choice < 1 || choice > 3);



	switch (choice) {
	case 1:
		system("cls");
		registerMember();
		break;
	case 2:
		system("cls");
		loginMember();
		break;
	case 3:
		main();
		break;
	default:
		printf("Invalid choice. Please try again.\n\n");
		break;
	}

}

// Let user to register as a member 
void registerMember() {
	int choice;
	int validPassword = 0;
	int validGender = 0;
	int validIC = 0;
	int validPhone = 0;

	FILE* mfptr = fopen("member_info.txt", "a");
	if (mfptr == NULL) {
		printf("Error in opening the file!");
		exit(-1);
	}

	MemberInfo newMember;

	// Read the last generated member ID
	char lastMemberID[6] = "M0000";
	FILE* idFile = fopen("lastMemberID.txt", "r");
	if (idFile != NULL) {
		fscanf(idFile, "%s", lastMemberID);
		fclose(idFile);
	}

	// Extract the numeric part of the member ID
	int idNumber = atoi(lastMemberID + 1); // Convert "0000" to integer

	// Increment the ID number for the next member
	idNumber++;
	sprintf(newMember.memberID, "M%04d", idNumber); // Format the new ID

	// Save the new last member ID to the file
	idFile = fopen("lastMemberID.txt", "w");
	if (idFile != NULL) {
		fprintf(idFile, "%s", newMember.memberID);
		fclose(idFile);
	}

	printf("\n\n");
	printf("\t\t\t  MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RRRRRRR        RRRRRRR  EEEEEEEE GGGGGGGG IIIIIIII  SSSSSS  TTTTTTTT RRRRRRR      AA     TTTTTTTT IIIIIIII  OOOOOO  NN   NN\n");
	printf("\t\t\t  MMM  MMM EE       MMM  MMM BB     B EE       RR    RR       RR     R EE       GG          II    SS          TT    RR    RR    A  A       TT       II    OO    OO NNN  NN\n");
	printf("\t\t\t  MM MM MM EEEEEEE  MM MM MM BBBBBBB  EEEEEEE  RRRRRRR        RRRRRRR  EEEEEEE  GG  GGGG    II     SSSSSS     TT    RRRRRRR    AAAAAA      TT       II    OO    OO NN N NN\n");
	printf("\t\t\t  MM    MM EE       MM    MM BB     B EE       RR RR          RR RR    EE       GG    G     II          SS    TT    RR RR     AA    AA     TT       II    OO    OO NN  NNN\n");
	printf("\t\t\t  MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RR  RRR        RR  RRR  EEEEEEEE GGGGGGG  IIIIIIII  SSSSSS     TT    RR  RRR  AA      AA    TT    IIIIIIII  OOOOOO  NN   NN\n");
	printf("\t\t\t __________________________________________________________________________________________________________________________________________________________________________\n\n");

	printf("\n\t\t\t\t\tWelcome to register as a member of our Train Ticket System!!!\n\n");
	printf("\t\t\t\t\t\t***********************************************************************************************************\n");

	printf("\t\t\t\t\t\t| Member ID                         : %s                                                               |\n", newMember.memberID);
	printf("\t\t\t\t\t\t|                                                                                                         |\n");

	printf("\t\t\t\t\t\t| Enter Name                        : ");
	scanf("%[^\n]", &newMember.name);
	clearInputBuffer();
	printf("\t\t\t\t\t\t|                                                                                                         |\n");

	printf("\t\t\t\t\t\t| Enter Password (4 Digits Only)    : ");


	//For password validation , user only can enter 4 digit password
	do {

		scanf("%s", newMember.memberPassword);
		while (getchar() != '\n');

		if (strlen(newMember.memberPassword) == 4 && isdigit(newMember.memberPassword[0])
			&& isdigit(newMember.memberPassword[1]) && isdigit(newMember.memberPassword[2])
			&& isdigit(newMember.memberPassword[3])) {
			validPassword = 1;
		}
		else {
			printf("\t\t\t\t\t\t|                                                                                                         |\n");
			printf("\t\t\t\t\t\t|       ** Please Enter Valid Password (4 Digits Only)! **                                                |\n");
			printf("\t\t\t\t\t\t|       ** Re-enter Password        : ");

		}
	} while (!validPassword);




	printf("\t\t\t\t\t\t|                                                                                                         |\n");
	printf("\t\t\t\t\t\t| Enter Gender (M/F)                : ");


	// For gender validation , user only can enter 'M' or 'F'
	do {
		scanf(" %c", &newMember.gender);
		newMember.gender = toupper(newMember.gender);
		clearInputBuffer();

		if (newMember.gender == 'M' || newMember.gender == 'F') {
			validGender = 1;
		}
		else {
			validGender = 0;
			printf("\t\t\t\t\t\t|                                                                                                         |\n");
			printf("\t\t\t\t\t\t|       ** Please Enter Valid Gender (M/F)! **                                                            |\n");
			printf("\t\t\t\t\t\t|       ** Re-enter Gender          : ");
		}

	} while (!validGender);


	printf("\t\t\t\t\t\t|                                                                                                         |\n");
	printf("\t\t\t\t\t\t| Enter IC No. (XXXXXX-XX-XXXX)     : ");



	// ic number validation , user nned to enter ic with the format of (XXXXXX-XX-XXXX) 
	do {
		scanf("%s", newMember.ic);
		clearInputBuffer();

		if (strlen(newMember.ic) == 14 &&
			isdigit(newMember.ic[0]) && isdigit(newMember.ic[1]) &&
			isdigit(newMember.ic[2]) && isdigit(newMember.ic[3]) &&
			isdigit(newMember.ic[4]) && isdigit(newMember.ic[5]) &&
			newMember.ic[6] == '-' &&
			isdigit(newMember.ic[7]) && isdigit(newMember.ic[8]) &&
			newMember.ic[9] == '-' &&
			isdigit(newMember.ic[10]) && isdigit(newMember.ic[11]) &&
			isdigit(newMember.ic[12]) && isdigit(newMember.ic[13])) {
			validIC = 1;
		}
		else {
			validIC = 0;
			printf("\t\t\t\t\t\t|                                                                                                         |\n");
			printf("\t\t\t\t\t\t|       ** Please Enter Valid IC Number! **                                                               |\n");
			printf("\t\t\t\t\t\t|       ** Re-enter IC No.           : ");
		}
	} while (!validIC);


	printf("\t\t\t\t\t\t|                                                                                                         |\n");

	printf("\t\t\t\t\t\t| Enter Phone No. (Eg:012-3456789)  : ");


	//phone number validation , user must enter phone number with correct format (Eg:012-3456789) 
	do {
		scanf("%s", newMember.phoneNO);
		clearInputBuffer();

		if (strlen(newMember.phoneNO) == 11 &&
			isdigit(newMember.phoneNO[0]) && isdigit(newMember.phoneNO[1]) &&
			isdigit(newMember.phoneNO[2]) &&
			newMember.phoneNO[3] == '-' &&
			isdigit(newMember.phoneNO[4]) && isdigit(newMember.phoneNO[5]) &&
			isdigit(newMember.phoneNO[6]) && isdigit(newMember.phoneNO[7]) &&
			isdigit(newMember.phoneNO[8]) && isdigit(newMember.phoneNO[9]) &&
			isdigit(newMember.phoneNO[10])) {
			validPhone = 1;
		}
		else {
			printf("\t\t\t\t\t\t|                                                                                                         |\n");
			printf("\t\t\t\t\t\t|       ** Please Enter Valid Phone Number! **                                                            |\n");
			printf("\t\t\t\t\t\t|       ** Re-enter Phone No.           : ");
		}
	} while (!validPhone);

	printf("\t\t\t\t\t\t|                                                                                                         |\n");
	printf("\t\t\t\t\t\t| Security Question                 : ");
	fgets(newMember.securityQuestion, sizeof(newMember.securityQuestion), stdin);
	newMember.securityQuestion[strcspn(newMember.securityQuestion, "\n")] = 0;

	printf("\t\t\t\t\t\t|                                                                                                         |\n");
	printf("\t\t\t\t\t\t| Answer                            : ");
	fgets(newMember.recoveryAnswer, sizeof(newMember.recoveryAnswer), stdin);
	newMember.recoveryAnswer[strcspn(newMember.recoveryAnswer, "\n")] = 0;



	printf("\t\t\t\t\t\t                                                                                                          |\n");
	printf("\t\t\t\t\t\t***********************************************************************************************************\n\n");



	// Welcome message display with the register member's name
	printf("\n\t\t\t\t\t\t\tRegistration Successful! \n\n\t\t\t\t\t\t\tWelcome, %s !\n\n\n", newMember.name);





	// Save member data to file
	fprintf(mfptr, "%s|%s|%s|%c|%s|%s|%s|%s\n",
		newMember.memberID,
		newMember.name,
		newMember.memberPassword,
		newMember.gender,
		newMember.ic,
		newMember.phoneNO,
		newMember.securityQuestion,
		newMember.recoveryAnswer);

	fclose(mfptr);


	// Let user to choose to back to member access or main page
	printf("\n\n");
	printf("\t\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t *  Choice :                                   *\n");
	printf("\t\t\t\t\t *                                             *\n");
	printf("\t\t\t\t\t *              1. Member Access               *\n");
	printf("\t\t\t\t\t *              2. Main Menu                   *\n");
	printf("\t\t\t\t\t *                                             *\n");
	printf("\t\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t    Selection (1-2) : ");
	scanf("%d", &choice);


	while (choice < 1 || choice > 2) {
		clearInputBuffer();
		printf("\n\t\t\t\t\t\t** Please enter (1-2)  :");
		scanf("%d", &choice);
	}

	switch (choice) {
	case 1:
		system("cls");
		memberModule();
		break;
	case 2:
		system("cls");
		main();
		break;
	default:
		clearInputBuffer();
		printf("\n\t\t\t\t\t\t** Please enter (1-2)  :");
		scanf("%d", &choice);
	}

}


// Let member to login
void loginMember() {
	char inputID[6];
	char inputPassword[5];
	int found = 0;
	int pswdChoice = 0;
	int validPassword = 0;
	int validID = 0;

	MemberInfo member[100];

	// Read member information from file
	FILE* mfptr = fopen("member_info.txt", "r");
	if (mfptr == NULL) {
		printf("Error in opening the file!\n");
		exit(-1);
	}

	// Save the member info into the member structure
	int count = 0;
	while (fscanf(mfptr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^\n]\n",
		member[count].memberID,
		member[count].name,
		member[count].memberPassword,
		&member[count].gender,
		member[count].ic,
		member[count].phoneNO,
		member[count].securityQuestion,
		member[count].recoveryAnswer) == 8) {
		count++;
	}



	printf("\n\n\n");
	printf("\t\t\t\t\t MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RRRRRRR       LL         OOOO   GGGGGGG  IIIIIIII NN   NN\n");
	printf("\t\t\t\t\t MMM  MMM EE       MMM  MMM BB     B EE       RR    RR      LL       OO    OO GG          II    NNN  NN\n");
	printf("\t\t\t\t\t MM MM MM EEEEEEE  MM MM MM BBBBBBB  EEEEEEE  RRRRRRR       LL       OO    OO GG  GGGG    II    NN N NN\n");
	printf("\t\t\t\t\t MM    MM EE       MM    MM BB     B EE       RR RR         LL       OO    OO GG    G     II    NN  NNN\n");
	printf("\t\t\t\t\t MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RR  RRR       LLLLLLLL   OOOO   GGGGGGG  IIIIIIII NN   NN\n\n");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------\n\n");

	printf("\t\t\t\t\tEnter Member ID (Eg M0001)   : ");

	// member id validation , user need to enter correct format of id , otherwise will keep re-enter
	do {
		scanf("%s", &inputID);
		clearInputBuffer();

		if (strlen(inputID) != 5 || !(isalpha(inputID[0]) && isdigit(inputID[1]) && isdigit(inputID[2]) && isdigit(inputID[3]) && isdigit(inputID[4]))) {
			printf("\n");
			printf("\t\t\t\t\t\t** Invalid ID! Please Enter Valid ID **\n");
			printf("\t\t\t\t\t\t** Re-enter ID (Eg M0001)        : ");
		}
		else {
			validID = 1;
		}

	} while (!validID);

	printf("\n\n");
	printf("\t\t\t\t\tEnter Password (4 digit)     : ");


	// password validation , user must enter password with 4 digit , otherwise will keep re-enter
	do {

		scanf("%s", &inputPassword);
		while (getchar() != '\n');


		if (strlen(inputPassword) == 4 && isdigit(inputPassword[0])
			&& isdigit(inputPassword[1]) && isdigit(inputPassword[2])
			&& isdigit(inputPassword[3])) {
			validPassword = 1;
		}
		else {
			printf("\n");
			printf("\t\t\t\t\t\t** Invalid Password! Please Enter Valid Password **\n");
			printf("\t\t\t\t\t\t** Re-enter Password (4 digit)   : ");


		}
	} while (!validPassword);



	// Find the id and password in the structure array ,that is match

	for (int i = 0; i < count; i++) {
		if (strcmp(member[i].memberID, inputID) == 0 && strcmp(member[i].memberPassword, inputPassword) == 0) {
			found = 1;
			system("cls");
			printf("\n\n\n\t\t\t\t\tWelcome, %s!\n", member[i].name);

			memberMenu(member[i]);

		}
	}


	// If not match , user can choose to re-enter id and password or go to password recovery
	if (!found) {
		printf("\n\n\n\t\t\t\t\t\t\t------  Invalid Member ID or Password! Please try again. ------\n\n\n");

		printf("\t\t\t\t\t------------------------------------------------------\n");
		printf("\t\t\t\t\t| Choose :                                           |\n");
		printf("\t\t\t\t\t|      1. Re-enter ID and Password.                  |\n");
		printf("\t\t\t\t\t|      2. Forgot Password.                           |\n");
		printf("\t\t\t\t\t------------------------------------------------------\n");
		printf("\t\t\t\t\t\tEnter your choice      : ");


		do {
			if (scanf("%d", &pswdChoice) != 1 || pswdChoice < 1 || pswdChoice > 2) {
				printf("\t\t\t\t\t\t\t ** Invalid choice! Please enter a valid choice. **\n\n");
				printf("\t\t\t\t\t\tRe-enter Choice (1-2)  : ");
				clearInputBuffer();
				continue; // Skip to the next iteration of the loop
			}


			switch (pswdChoice) {
			case 1:
				system("cls");
				loginMember();
				break;
			case 2:
				recoverPassword(); // Forgot Password
				break;
			default:
				printf("\t\t\t\t\t\t\t Invalid choice. Please try again.\n\n");
			}

		} while (pswdChoice < 1 || pswdChoice > 2);

	}

	fclose(mfptr);

}

// For members who have forgotten their password, they will need to answer the security question (set during registration). If the recovery answer is correct, the password will be displayed.
void recoverPassword() {

	char memberIDInput[6];
	char recoveryAnswerInput[50];
	int found = 0;
	int choice;
	int foundAns = 0;
	int validID = 0;
	int attemptCount = 0;

	MemberInfo recover[100];



	FILE* mfptr;
	mfptr = fopen("member_info.txt", "r");
	if (mfptr == NULL) {
		printf("Error opening file\n\n");
		return;
	}


	int count = 0;
	while (fscanf(mfptr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^\n]\n",
		recover[count].memberID,
		recover[count].name,
		recover[count].memberPassword,
		&recover[count].gender,
		recover[count].ic,
		recover[count].phoneNO,
		recover[count].securityQuestion,
		recover[count].recoveryAnswer) != EOF) {
		count++;
	}


	system("cls");
	printf("\n\n\n");
	printf("\t\t\t\t\t---------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t|                                              RECOVERY PASSWORD                                              |\n");
	printf("\t\t\t\t\t---------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t|                                                                                                             |\n");
	printf("\t\t\t\t\t|                                                                                                             |\n");

	printf("\t\t\t\t\t|  1. Enter Your ID (Eg M0001)   : ");
	do {
		scanf("%5s", memberIDInput);
		clearInputBuffer();

		found = 0; // Assume valid ID, if not found later, user will be prompted to re-enter 
		for (int i = 0; i < count; i++) {
			if (strcmp(recover[i].memberID, memberIDInput) == 0) {
				validID = 1;
				found = 1;
				printf("\t\t\t\t\t|                                                                                                             |\n");
				printf("\t\t\t\t\t|                                                                                                             |\n");
				printf("\t\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
				printf("\t\t\t\t\t|                                                                                                             |\n");
				printf("\t\t\t\t\t|                                                                                                             |\n");
				printf("\t\t\t\t\t|  2. Security Question          : %-45s                              |\n", recover[i].securityQuestion);
				printf("\t\t\t\t\t|                                                                                                             |\n");
				printf("\t\t\t\t\t|                                                                                                             |\n");
				printf("\t\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
				printf("\t\t\t\t\t|                                                                                                             |\n");

				printf("\t\t\t\t\t|                                                                                                             |\n");
				printf("\t\t\t\t\t|  3. Enter Your Answer          : ");

				do {
					scanf("%[^\n]", recoveryAnswerInput);
					clearInputBuffer();




					if (strcmp(recover[i].recoveryAnswer, recoveryAnswerInput) == 0) {
						printf("\t\t\t\t\t|                                                                                                             |\n");
						printf("\t\t\t\t\t|                                                                                                             |\n");
						printf("\t\t\t\t\t- + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +\n");
						printf("\t\t\t\t\t+                                                                                                             -\n");
						printf("\t\t\t\t\t-                                                                                                             +\n");
						printf("\t\t\t\t\t+     Your password is           : %s                                                                       -\n", recover[i].memberPassword);
						printf("\t\t\t\t\t-                                                                                                             +\n");
						printf("\t\t\t\t\t+                                                                                                             -\n");
						printf("\t\t\t\t\t- + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +\n");
						foundAns = 1;
					}
					else {

						attemptCount++; // Increment the attempt count on each failed attempt 
						if (attemptCount == 3) {
							printf("\t\t\t\t\t|\t\t                                                                                              |\n");
							printf("\t\t\t\t\t|\t\t                                                                                              |\n");
							printf("\t\t\t\t\t|\t\t                                                                                              |\n");
							printf("\t\t\t\t\t|\t\t                  YOUR RECOVERY PASSWORD FAILED TOO MANY TIMES!!!                             |\n");
							printf("\t\t\t\t\t|\t\t              -----------------------------------------------------                           |\n");
							printf("\t\t\t\t\t|\t\t                . . . . . . . . . . . . . . . . . . . . . . . . .                             |\n");
							printf("\t\t\t\t\t|\t\t                . Choice :                                      .                             |\n");
							printf("\t\t\t\t\t|\t\t                .            1. Continue Recovery               .                             |\n");
							printf("\t\t\t\t\t|\t\t                .            2. Back To Member Access           .                             |\n");
							printf("\t\t\t\t\t|\t\t                . . . . . . . . . . . . . . . . . . . . . . . . .                             |\n");
							printf("\t\t\t\t\t|\t\t                Enter Your Choice (1-2)  : ");


							// If fail for 3 times , member can choose to continue re-enter or back to member access
							do {
								if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {

									printf("\t\t\t\t\t|\t\t                     ** Invalid choice! Please enter (1-2). **\n");
									printf("\t\t\t\t\t|\t\t                                                                                              |\n");
									printf("\t\t\t\t\t|\t\t                     ** Re-enter Your Choice: ");
									clearInputBuffer();
									continue;
								}

								switch (choice) {
								case 1: // Continue recovery
									attemptCount = 0;
									printf("\t\t\t\t\t|                                                                                                             |\n");
									printf("\t\t\t\t\t|                                                                                                             |\n");
									printf("\t\t\t\t\t|                                                                                                             |\n");
									break;
								case 2: // Go back to member access
									system("cls");
									memberModule();
									break;
								default:
									break;
								}
							} while (choice != 1 && choice != 2);
						}
						else {
							printf("\t\t\t\t\t|                                                                                                             |\n");
							printf("\t\t\t\t\t|\t\t** Your recovery password failed! Please try again.                                           |\n");
							printf("\t\t\t\t\t|\t\t** Re-enter Your Answer      : ");
						}
					}
				} while (!foundAns);


				// Reset attempt count after successful recovery
				attemptCount = 0;



				printf("\n\n\n");
				printf("\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
				printf("\t\t\t\t\t *  Choice :                                     *\n");
				printf("\t\t\t\t\t  * -------                                     *\n");
				printf("\t\t\t\t\t *               1. Member Access                *\n");
				printf("\t\t\t\t\t  *              2. Main Menu                   *\n");
				printf("\t\t\t\t\t *                                               *\n");
				printf("\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * *\n");
				printf("\t\t\t\t\t    Selection (1-2)  : ");

				do {
					if (scanf("%d", &choice) != 1 || choice < 1 || choice > 2) {
						printf("\t\t\t\t\t\t  ** Invalid choice! Please enter a valid choice. **\n\n");
						printf("\t\t\t\t\t    Re-enter Selection (1-2)  : ");
						clearInputBuffer();
						continue; // Skip to the next iteration of the loop
					}


					switch (choice) {
					case 1:
						system("cls");
						memberModule();
						break;
					case 2:
						system("cls");
						main();
						break;
					default:
						break;
					}
				} while (choice < 1 || choice > 2);
			}
		}


		if (!found && !validID) {
			printf("\t\t\t\t\t|                                                                                                             |\n");
			printf("\t\t\t\t\t|\t\t** ID not found! Please Try Again **                                                          |\n");
			printf("\t\t\t\t\t|\t\t** Re-enter ID (Eg M0001)    : ");
		}

	} while (!found || !validID);

}

void memberMenu(MemberInfo loggedInMember) {

	int select;
	int count;


	// Member Mode Menu
	printf("\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t        =================================================================================\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                                   MEMBER MENU                                 |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |...............................................................................|\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                                1. My Account                                  |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                                2. Booking Ticket                              |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                                3. Exit                                        |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        =================================================================================\n");
	printf("\n");
	printf("\t\t\t\t\t\t\tEnter Your choice (1-3)    : ");

	do {

		if (scanf("%d", &select) != 1 || select < 1 || select > 4) {
			printf("\t\t\t\t\t\t\t\t  ** Invalid choice! Please enter a valid choice. **\n\n");
			printf("\t\t\t\t\t\t\t     Re-enter choice (1-3)  : ");
			clearInputBuffer();
			continue; // Skip to the next iteration of the loop
		}



		switch (select) {
		case 1:
			system("cls");
			memberAccountMenu(loggedInMember);
			break;
		case 2:
			system("cls");
			ticketModule(booking, &count);
			break;
		case 3:
			memberModule();
			break;
		default:
			printf("Invalid choice. Please try again.\n\n");
			break;
		}

	} while (select < 1 || select > 3);
}

// This menu will be displayed after the member successfully logs in
void memberAccountMenu(MemberInfo loggedInMember) {

	int memberChoice;

	// Member Mode Menu
	printf("\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t        =================================================================================\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                                 MEMBER ACCOUNT                                |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |...............................................................................|\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                            1. My Profile                                      |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                            2. Edit My Profile                                 |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                            3. Reset Password                                  |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                            4. Cancel Membership                               |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        |                            5. Exit                                            |\n");
	printf("\t\t\t\t\t\t        |                                                                               |\n");
	printf("\t\t\t\t\t\t        =================================================================================\n");
	printf("\n");
	printf("\t\t\t\t\t\t\tEnter Your choice (1-5)    : ");

	do {

		if (scanf("%d", &memberChoice) != 1 || memberChoice < 1 || memberChoice > 6) {
			printf("\t\t\t\t\t\t\t\t  ** Invalid choice! Please enter a valid choice. **\n\n");
			printf("\t\t\t\t\t\t\t     Re-enter choice (1-5)  : ");
			clearInputBuffer();
			continue; // Skip to the next iteration of the loop
		}



		switch (memberChoice) {
		case 1:
			system("cls");
			displayMemberProfile(loggedInMember);
			break;
		case 2:
			system("cls");
			editMemberProfile(loggedInMember);
			break;
		case 3:
			system("cls");
			resetPassword(&loggedInMember);
			break;
		case 4:
			system("cls");
			cancelMembership(loggedInMember);
			break;
		case 5:
			system("cls");
			memberMenu(loggedInMember);
			break;
		default:
			printf("Invalid choice. Please try again.\n\n");
			break;
		}

	} while (memberChoice < 1 || memberChoice > 5);
}

// The details of the logged in member will be displayed
void displayMemberProfile(MemberInfo loggedInMember) {

	int count = 0;
	int found = 0;
	char yesno;

	FILE* mfptr;
	mfptr = fopen("member_info.txt", "r");
	if (mfptr == NULL) {
		printf("Error in opening the file!\n");
		return;
	}


	MemberInfo display[100];


	while (fscanf(mfptr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^\n]\n",
		display[count].memberID,
		display[count].name,
		display[count].memberPassword,
		&display[count].gender,
		display[count].ic,
		display[count].phoneNO,
		display[count].securityQuestion,
		display[count].recoveryAnswer) != EOF) {
		count++;
	}

	fclose(mfptr);


	// Find and modify the details of the logged-in member
	for (int i = 0; i < count; i++) {
		if (strcmp(display[i].memberID, loggedInMember.memberID) == 0 &&
			strcmp(display[i].memberPassword, loggedInMember.memberPassword) == 0) {
			found = 1;



			printf("\n\n\n");
			printf("\t\t\t\t\t MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RRRRRRR       PPPPPPP  RRRRRRR   0OOOO0  FFFFFFFF IIIIIIII LL       EEEEEEEE \n");
			printf("\t\t\t\t\t MMM  MMM EE       MMM  MMM BB     B EE       RR    RR      PP     P RR    RR OO    OO FF          II    LL       EE     \n");
			printf("\t\t\t\t\t MM MM MM EEEEEEE  MM MM MM BBBBBBB  EEEEEEE  RRRRRRR       PPPPPPP  RRRRRRR  OO    OO FFFFFFF     II    LL       EEEEEEE  \n");
			printf("\t\t\t\t\t MM    MM EE       MM    MM BB     B EE       RR RR         PP       RR RR    OO    OO FF          II    LL       EE     \n");
			printf("\t\t\t\t\t MM    MM EEEEEEEE MM    MM BBBBBBB  EEEEEEEE RR  RRR       PP       RR  RRR   0OOOO0  FF       IIIIIIII LLLLLLLL EEEEEEEE\n\n");
			printf("\t\t\t\t\t----------------------------------------------------------------------------------------------------------------------------\n\n");


			// Display details of the logged-in member
			printf("\t\t\t\t\t\t\t===============================================================================================\n");
			printf("\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| ID                 :  %-6s", display[i].memberID);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| NAME               :  %-12s", display[i].name);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| PASSWORD           :  %-4s", display[i].memberPassword);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| GENDER             :  %-2c", display[i].gender);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| IC                 :  %-12s", display[i].ic);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| PHONE NO.          :  %-13s", display[i].phoneNO);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| SECURITY QUESTION  :  %-20s", display[i].securityQuestion);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| ANSWER             :  %-10s", display[i].recoveryAnswer);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t===============================================================================================\n\n\n");





			printf("\t\t\t\t\t\tBack To Member Menu? (Y): ");
			scanf(" %c", &yesno);
			yesno = toupper(yesno);



			while (yesno != 'Y') {
				while (getchar() != '\n'); // Clear input buffer   
				printf("\n");
				printf("\t\t\t\t\t\t\t** Invalid response! **\n");
				printf("\t\t\t\t\t\t\t** Please enter (Y) : ");
				scanf(" %c", &yesno);
				yesno = toupper(yesno);
			}


			while (getchar() != '\n');

			if (yesno == 'Y') {
				system("cls");
				memberAccountMenu(loggedInMember);
			}


			getchar();


		}
	}
	if (!found) {
		printf("Member not found!\n");
		// Ensure that the program remains in the member menu
		system("cls");
		memberAccountMenu(loggedInMember);
	}
}

// Allow member to modify their profile
void editMemberProfile(MemberInfo loggedInMember) {
	FILE* mfptr;
	mfptr = fopen("member_info.txt", "r+");
	if (mfptr == NULL) {
		printf("Error in opening the file!\n");
		return;
	}


	MemberInfo modify[100];
	int option;
	int found = 0;
	int count = 0;



	char updName[100];
	char updMemberPassword[20];
	char updGender;
	char updIc[20];
	char updPhoneNO[20];
	char updSecurityQuestion[100];
	char updRecoveryAnswer[50];


	while (fscanf(mfptr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^\n]\n",
		modify[count].memberID,
		modify[count].name,
		modify[count].memberPassword,
		&modify[count].gender,
		modify[count].ic,
		modify[count].phoneNO,
		modify[count].securityQuestion,
		modify[count].recoveryAnswer) != EOF) {
		count++;
	}

	fclose(mfptr);


	// Find and modify the details of the logged-in member
	for (int i = 0; i < count; i++) {
		if (strcmp(modify[i].memberID, loggedInMember.memberID) == 0 &&
			strcmp(modify[i].memberPassword, loggedInMember.memberPassword) == 0) {
			found = 1;


			// The profile will be displayed first, allowing the member to review the details and decide which ones to modify
			printf("\n");
			printf("\t\t\t\t\t\t\t===============================================================================================\n");
			printf("\t\t\t\t\t\t\t|                                       MEMBER PROFILE                                        |\n");
			printf("\t\t\t\t\t\t\t===============================================================================================\n");
			printf("\t\t\t\t\t\t\t| ID                 :  %-6s", modify[i].memberID);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| NAME               :  %-12s", modify[i].name);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| GENDER             :  %-2c", modify[i].gender);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| IC                 :  %-12s", modify[i].ic);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| PHONE NO.          :  %-13s", modify[i].phoneNO);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| SECURITY QUESTION  :  %-20s", modify[i].securityQuestion);
			printf("\n\t\t\t\t\t\t\t|                                                                                             |\n");
			printf("\t\t\t\t\t\t\t| ANSWER             :  %-10s", modify[i].recoveryAnswer);
			printf("\n\t\t\t\t\t\t\t===============================================================================================\n\n\n");



			// Menu for modify selection
			printf("\t\t\t\t\t+ - + - + - + - + - + - + - + - + - + - + - + - + - + -\n");
			printf("\t\t\t\t\t-  Which One Do You Want To Modify?                   +\n");
			printf("\t\t\t\t\t+ - - - - - - - - - - - - - - - - - - - - - - - -     -\n");
			printf("\t\t\t\t\t-       1. Name            5. Security Question       +\n");
			printf("\t\t\t\t\t+       2. Gender          6. Recovery Answer         -\n");
			printf("\t\t\t\t\t-       3. No.Ic           7. Exit                    +\n");
			printf("\t\t\t\t\t+       4. Phone no.                                  -\n");
			printf("\t\t\t\t\t- + - + - + - + - + - + - + - + - + - + - + - + - + - +\n");
			printf("\n\t\t\t\t\t   Enter Your Choice (1-7)  : ");

			int validGender = 0;
			int validIC = 0;
			int validPhone = 0;

			do {
				if (scanf("%d", &option) != 1 || option < 1 || option > 7) {
					printf("\n\t\t\t\t\t\t** Invalid option!\n");
					clearInputBuffer();
					printf("\t\t\t\t\t\t** Enter Your Choice (1-7)  : ");
					continue;
				}


				switch (option) {
				case 1:
					printf("\n\t\t\t\t\t\t   Enter New Name                           : ");
					scanf(" %[^\n]", updName);
					strcpy(modify[i].name, updName);
					printf("\t\t\t\t\t\t\t\t** Name Updated Successfully! **\n\n");
					break;

				case 2:
					printf("\n\t\t\t\t\t\t   Enter New Gender (M/F)                   : ");

					// Gender validation
					do {
						scanf(" %c", &modify[i].gender);
						modify[i].gender = toupper(modify[i].gender);
						clearInputBuffer();

						if (modify[i].gender == 'M' || modify[i].gender == 'F') {
							validGender = 1;
							printf("\t\t\t\t\t\t\t\t** Gender Updated Successfully!\n\n");
						}
						else {
							validGender = 0;
							printf("\n\t\t\t\t\t\t\t** Please Enter Valid Gender (M/F): ");
						}
					} while (!validGender);
					break;

				case 3:
					printf("\n\t\t\t\t\t\t   Enter New IC Number (XXXXXX-XX-XXXX)     : ");


					// ic number validation
					do {
						scanf("%s", updIc);
						strcpy(modify[i].ic, updIc);
						clearInputBuffer();

						if ((strlen(modify[i].ic) == 14 && isdigit(modify[i].ic[0]) && isdigit(modify[i].ic[1]) &&
							isdigit(modify[i].ic[2]) && isdigit(modify[i].ic[3]) && isdigit(modify[i].ic[4]) &&
							isdigit(modify[i].ic[5]) && modify[i].ic[6] == '-' &&
							isdigit(modify[i].ic[7]) && isdigit(modify[i].ic[8]) &&
							modify[i].ic[9] == '-' && isdigit(modify[i].ic[10]) &&
							isdigit(modify[i].ic[11]) && isdigit(modify[i].ic[12]) &&
							isdigit(modify[i].ic[13]))) {
							validIC = 1;
							printf("\t\t\t\t\t\t\t\t** IC Number Updated Successfully!\n\n");
						}
						else {
							validIC = 0;
							printf("\n\t\t\t\t\t\t\t** Please Enter Valid IC: ");
						}
					} while (!validIC);
					break;

				case 4:
					printf("\n\t\t\t\t\t\t   Enter New Phone Number (Eg: 012-3456789) : ");


					//phone number validation
					do {
						scanf("%s", updPhoneNO);
						strcpy(modify[i].phoneNO, updPhoneNO);
						clearInputBuffer();

						if (strlen(modify[i].phoneNO) == 11 &&
							isdigit(modify[i].phoneNO[0]) && isdigit(modify[i].phoneNO[1]) &&
							isdigit(modify[i].phoneNO[2]) &&
							modify[i].phoneNO[3] == '-' &&
							isdigit(modify[i].phoneNO[4]) && isdigit(modify[i].phoneNO[5]) &&
							isdigit(modify[i].phoneNO[6]) && isdigit(modify[i].phoneNO[7]) &&
							isdigit(modify[i].phoneNO[8]) && isdigit(modify[i].phoneNO[9]) &&
							isdigit(modify[i].phoneNO[10])) {
							validPhone = 1;
							printf("\t\t\t\t\t\t\t\t** Phone Number Updated Successfully!\n\n");
						}
						else {
							validPhone = 0;
							printf("\n\t\t\t\t\t\t\t** Please Enter Valid Phone No: ");
						}
					} while (!validPhone);
					break;


				case 5:
					printf("\n\t\t\t\t\t\t   Enter New Security Question           : ");
					scanf(" %[^\n]", updSecurityQuestion);
					strcpy(modify[i].securityQuestion, updSecurityQuestion);
					printf("\t\t\t\t\t\t\t\t** Security Question Updated Successfully!\n\n");
					break;
				case 6:
					printf("\n\t\t\t\t\t\t   Enter New Recovery Answer             : ");
					scanf(" %[^\n]", updRecoveryAnswer);
					strcpy(modify[i].recoveryAnswer, updRecoveryAnswer);
					printf("\t\t\t\t\t\t\t\t** Recovery Answer Updated Successfully!\n\n");
					break;
				case 7:
					// Write the modified details back to the file
					mfptr = fopen("member_info.txt", "w");
					if (mfptr == NULL) {
						printf("Error in opening the file for writing!\n");
						return;
					}

					for (int j = 0; j < count; j++) {
						fprintf(mfptr, "%s|%s|%s|%c|%s|%s|%s|%s\n",
							modify[j].memberID,
							modify[j].name,
							modify[j].memberPassword,
							modify[j].gender,
							modify[j].ic,
							modify[j].phoneNO,
							modify[j].securityQuestion,
							modify[j].recoveryAnswer);
					}

					fclose(mfptr);
					system("cls");
					memberAccountMenu(loggedInMember);
					break;
				default:
					printf("\t\t\t\t\t\t** Invalid option!\n\n");
					break;
				}

				printf("\n\t\t\t\t\t   Enter Your Choice (1-7)  : ");

			} while (option != 7);
		}

	}

}

// Let member to reset their password , they need to enter the current password , if the password match , then enter the new password and confirm password. If both passwords match, the password reset is successful.
void resetPassword(MemberInfo* loggedInMember) {

	int count;
	int found = 0;
	char yesno;

	char oldPswd[6];
	char newPswd[6];
	char confirmPswd[6];
	int validPassword1 = 0;
	int validPassword2 = 0;
	int validPassword3 = 0;


	FILE* mfptr;
	mfptr = fopen("member_info.txt", "r");
	if (mfptr == NULL) {
		printf("Error in opening the file!\n");
		return;
	}


	MemberInfo changePswd[100];
	count = 0;

	while (fscanf(mfptr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^\n]\n",
		changePswd[count].memberID,
		changePswd[count].name,
		changePswd[count].memberPassword,
		&changePswd[count].gender,
		changePswd[count].ic,
		changePswd[count].phoneNO,
		changePswd[count].securityQuestion,
		changePswd[count].recoveryAnswer) != EOF) {
		count++;
	}

	fclose(mfptr);



	// Find and modify the details of the logged-in member
	for (int i = 0; i < count; i++) {
		if (strcmp(changePswd[i].memberID, loggedInMember->memberID) == 0 &&
			strcmp(changePswd[i].memberPassword, loggedInMember->memberPassword) == 0) {
			found = 1;
			printf("\n\n\n");
			printf("\t\t\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
			printf("\t\t\t\t\t\t|                                    RESET PASSWORD                                     |\n");
			printf("\t\t\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
			printf("\t\t\t\t\t\t  |   Are You Sure To Reset Password? (Y/N)                                           |\n");
			printf("\t\t\t\t\t\t  |   :  ");
			scanf(" %1c", &yesno);
			yesno = toupper(yesno);


			while (yesno != 'Y' && yesno != 'N') {
				while (getchar() != '\n');
				printf("\t\t\t\t\t\t  |          ** Invalid response! **                                                  |\n");
				printf("\t\t\t\t\t\t  |                                                                                   |\n");
				printf("\t\t\t\t\t\t  |                                                                                   |\n");
				printf("\t\t\t\t\t\t  |   Please enter (Y/N) : ");
				scanf(" %1c", &yesno);
				yesno = toupper(yesno);

			}

			while (getchar() != '\n');

			if (yesno == 'Y') {
				printf("\t\t\t\t\t\t  |                                                                                   |\n");
				printf("\t\t\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
				printf("\t\t\t\t\t\t  |   Enter Current Password (4 digit) : ");

				do {

					scanf("%s", oldPswd); // Limiting input to 4 characters to prevent buffer overflow
					while (getchar() != '\n');
					printf("\t\t\t\t\t\t  |                                                                                   |\n");

					// Password validation
					if (strlen(oldPswd) == 4 && isdigit(oldPswd[0])
						&& isdigit(oldPswd[1]) && isdigit(oldPswd[2])
						&& isdigit(oldPswd[3])) {
						// Check the current passowrd is match with the password save in structure array
						if (strcmp(loggedInMember->memberPassword, oldPswd) != 0) {
							printf("\t\t\t\t\t\t  |          ** Password Not Match! **                                                |\n ");
							printf("\t\t\t\t\t\t  |                                                                                   |\n");
							printf("\t\t\t\t\t\t  |                                                                                   |\n");
							printf("\t\t\t\t\t\t  |   Enter Current Password : ");
						}
						else {
							// Password matches, proceed to entering new password
							validPassword1 = 1;

							printf("\t\t\t\t\t\t  |          ** Password Match!!!  Continue Enter New Password **                     |\n");
							printf("\t\t\t\t\t\t  |                                                                                   |\n");
							printf("\t\t\t\t\t\t  |                                                                                   |\n");
							printf("\t\t\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");



							do {
								printf("\t\t\t\t\t\t  |   Enter New Password     : ");
								scanf("%s", newPswd);
								while (getchar() != '\n');


								// Check if the entered password meets the criteria 
								if (strlen(newPswd) == 4 && isdigit(newPswd[0])
									&& isdigit(newPswd[1]) && isdigit(newPswd[2])
									&& isdigit(newPswd[3])) {
									validPassword2 = 1;
								}

								else {
									printf("\t\t\t\t\t\t  |                                                                                   |\n");
									printf("\t\t\t\t\t\t  |          ** Please Enter Valid Password (4 Digits Only)! **                       |\n");
									printf("\t\t\t\t\t\t  |                                                                                   |\n");
									printf("\t\t\t\t\t\t  |                                                                                   |\n");

								}
							} while (!validPassword2);

							// Prompt for confirming new password

							printf("\t\t\t\t\t\t  |                                                                                   |\n");
							printf("\t\t\t\t\t\t  |                                                                                   |\n");



							printf("\t\t\t\t\t\t  |                                                                                   |\n");
							printf("\t\t\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");



							do {
								printf("\t\t\t\t\t\t  |   Confirm New Password   : ");
								scanf("%s", confirmPswd);
								while (getchar() != '\n');
								printf("\t\t\t\t\t\t  |                                                                                   |\n");

								if (strlen(confirmPswd) != 4 || !isdigit(confirmPswd[0])
									|| !isdigit(confirmPswd[1]) || !isdigit(confirmPswd[2])
									|| !isdigit(confirmPswd[3])) {
									printf("\t\t\t\t\t\t  |          ** Please Enter Valid Password (4 Digits Only)! **                       |\n");
									printf("\t\t\t\t\t\t  |                                                                                   |\n");
									printf("\t\t\t\t\t\t  |                                                                                   |\n");
								}
								else {
									// Check if new password and confirmation match

									if (strcmp(newPswd, confirmPswd) == 0) {
										validPassword3 = 1;
										printf("\t\t\t\t\t\t  |                                                                                   |\n");
										printf("\t\t\t\t\t\t  |          ** Password Reset Successful **                                          |\n");
										printf("\t\t\t\t\t\t  |                                                                                   |\n");
										printf("\t\t\t\t\t\t  |                                                                                   |\n");
										printf("\t\t\t\t\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
										strcpy(loggedInMember->memberPassword, confirmPswd);
										strcpy(changePswd[i].memberPassword, confirmPswd);



										// Write the updated member information back to the file
										mfptr = fopen("member_info.txt", "w");
										if (mfptr == NULL) {
											printf("Error in opening the file for writing!\n");
											return;
										}

										for (int j = 0; j < count; j++) {
											fprintf(mfptr, "%s|%s|%s|%c|%s|%s|%s|%s\n",
												changePswd[j].memberID,
												changePswd[j].name,
												changePswd[j].memberPassword,
												changePswd[j].gender,
												changePswd[j].ic,
												changePswd[j].phoneNO,
												changePswd[j].securityQuestion,
												changePswd[j].recoveryAnswer);
										}

										fclose(mfptr);

									}
									else {
										validPassword3 = 0;
										printf("\t\t\t\t\t\t  |          ** Passwords do not match! Please try again. **                          |\n");
										printf("\t\t\t\t\t\t  |                                                                                   |\n");
										printf("\t\t\t\t\t\t  |                                                                                   |\n");

									}

								}
							} while (!validPassword3);



						}

					}
					else {
						printf("\t\t\t\t\t\t  |          ** Please Enter Valid Password (4 Digits Only)! **                       |\n");
						printf("\t\t\t\t\t\t  |                                                                                   |\n");
						printf("\t\t\t\t\t\t  |                                                                                   |\n");
						printf("\t\t\t\t\t\t  |   Enter Current Password : ");
					}
				} while (!validPassword1);
			}
			else {
				system("cls");
				memberAccountMenu(*loggedInMember);  // Go back to the member menu 
			}

			if (!found) {
				printf("\t\t\t\t\t\t  |          ** Member not found! **                                                  |\n");
				printf("\t\t\t\t\t\t  |                                                                                   |\n");
			}
		}
	}

	printf("\t\t\t\t\t\tBack To Member Account? (Y): ");
	scanf(" %1c", &yesno);
	yesno = toupper(yesno);



	while (yesno != 'Y') {
		while (getchar() != '\n');
		printf("\n");
		printf("\t\t\t\t\t\t\t** Invalid response! **\n");
		printf("\t\t\t\t\t\t\t** Please enter (Y) : ");
		scanf(" %c", &yesno);
		yesno = toupper(yesno);
	}

	while (getchar() != '\n');
	if (yesno == 'Y') {
		system("cls");
		memberAccountMenu(*loggedInMember);
	}

}


// Let member to cancel their membership , then the member detail will be delete also in the txt file
void cancelMembership(MemberInfo loggedInMember) {
	int count;
	int found = 0;
	char confirm;
	char yesno;

	FILE* mfptr;
	mfptr = fopen("member_info.txt", "r");
	if (mfptr == NULL) {
		printf("Error in opening the file!\n");
		return;
	}

	MemberInfo cancel[100];
	count = 0;

	while (fscanf(mfptr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^\n]\n",
		cancel[count].memberID,
		cancel[count].name,
		cancel[count].memberPassword,
		&cancel[count].gender,
		cancel[count].ic,
		cancel[count].phoneNO,
		cancel[count].securityQuestion,
		cancel[count].recoveryAnswer) != EOF) {
		count++;
	}

	fclose(mfptr);


	printf("\n\n\n");
	printf("\n\n\t\t\t\t\t\t\t===============================================================================================\n");
	printf("\t\t\t\t\t\t\t|                                     MEMBERSHIP CANCELLATION                                 |\n");
	printf("\t\t\t\t\t\t\t===============================================================================================\n");
	printf("\t\t\t\t\t\t\t|                                                                                             |\n");

	// Find the logged-in member detail in the array , if match ,then can cancel for membership
	for (int i = 0; i < count; i++) {
		if (strcmp(cancel[i].memberID, loggedInMember.memberID) == 0 &&
			strcmp(cancel[i].memberPassword, loggedInMember.memberPassword) == 0) {
			found = 1;

			// Confirm the membership cancellation
			printf("\t\t\t\t\t\t\t|  Are you sure you want to cancel your membership? (Y/N)                                     |\n");
			printf("\t\t\t\t\t\t\t|  : ");
			scanf(" %c", &confirm);
			confirm = toupper(confirm);



			while (confirm != 'Y' && confirm != 'N') {
				while (getchar() != '\n');
				printf("\t\t\t\t\t\t\t|                                                                                             |\n");
				printf("\t\t\t\t\t\t\t|  Invalid response! Please enter Y/N: ");
				scanf(" %c", &confirm);
				confirm = toupper(confirm);
			}

			while (getchar() != '\n');

			if (confirm == 'Y') {
				// Shift array elements to overwrite the cancelled member's data
				for (int j = i; j < count - 1; j++) {
					strcpy(cancel[j].memberID, cancel[j + 1].memberID);
					strcpy(cancel[j].name, cancel[j + 1].name);
					strcpy(cancel[j].memberPassword, cancel[j + 1].memberPassword);
					cancel[j].gender = cancel[j + 1].gender;
					strcpy(cancel[j].ic, cancel[j + 1].ic);
					strcpy(cancel[j].phoneNO, cancel[j + 1].phoneNO);
					strcpy(cancel[j].securityQuestion, cancel[j + 1].securityQuestion);
					strcpy(cancel[j].recoveryAnswer, cancel[j + 1].recoveryAnswer);
				}

				// Decrement count to reflect the removal of the cancelled member
				count--;

				// Write the updated member information back to the file
				mfptr = fopen("member_info.txt", "w");
				if (mfptr == NULL) {
					printf("Error in opening the file for writing!\n");
					return;
				}

				for (int k = 0; k < count; k++) {
					fprintf(mfptr, "%s|%s|%s|%c|%s|%s|%s|%s\n",
						cancel[k].memberID,
						cancel[k].name,
						cancel[k].memberPassword,
						cancel[k].gender,
						cancel[k].ic,
						cancel[k].phoneNO,
						cancel[k].securityQuestion,
						cancel[k].recoveryAnswer);
				}

				fclose(mfptr);
				printf("\t\t\t\t\t\t\t|                                                                                             |\n");
				printf("\t\t\t\t\t\t\t|                                                                                             |\n");
				printf("\t\t\t\t\t\t\t|  Membership cancelled successfully.                                                         |\n");
				printf("\t\t\t\t\t\t\t===============================================================================================\n");

			}
			else {
				printf("\t\t\t\t\t\t\t|                                                                                             |\n");
				printf("\t\t\t\t\t\t\t|                                                                                             |\n");
				printf("\t\t\t\t\t\t\t|  Membership cancellation aborted.                                                           |\n");
				printf("\t\t\t\t\t\t\t===============================================================================================\n");
			}
		}

	}
	// If logged-in member not found
	if (!found) {
		printf("\t\t\t\t\t\t\t|                                                                                             |\n");
		printf("\t\t\t\t\t\t\t|  Member not found!                                                                          |\n");
		printf("\t\t\t\t\t\t\t===============================================================================================\n");
	}



	printf("\n\n\t\t\t\t\t Back To Member Access ?  (Y) :");
	scanf(" %c", &yesno);
	yesno = toupper(yesno);


	while (yesno != 'Y') {
		while (getchar() != '\n');
		printf("\n\t\t\t\t\t\t** Invalid response! **\n");
		printf("\t\t\t\t\t\t** Please enter (Y)   :");
		scanf(" %c", &yesno);
		yesno = toupper(yesno);

	}

	while (getchar() != '\n');

	if (yesno == 'Y') {

		system("cls");
		memberModule();
	}

}




// This function is for staff only , only staff can view the member report
void generateMemberReport() {

	system("cls");
	int count = 0;
	char yesno;

	FILE* mfptr;
	mfptr = fopen("member_info.txt", "r");
	if (mfptr == NULL) {
		printf("Error in opening the file!\n");
		return;
	}


	MemberInfo report[100];


	while (fscanf(mfptr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^\n]\n",
		report[count].memberID,
		report[count].name,
		report[count].memberPassword,
		&report[count].gender,
		report[count].ic,
		report[count].phoneNO,
		report[count].securityQuestion,
		report[count].recoveryAnswer) != EOF) {
		count++;
	}

	fclose(mfptr);

	printf("\n\n\n");
	printf("\t\t\t\t\t\t===============================================================================================================\n");
	printf("\t\t\t\t\t\t|                                               MEMBER REPORT                                                 |\n");
	printf("\t\t\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
	printf("\t\t\t\t\t\t|     ID     |             Name              |   GENDER   |           No.IC           |       Phone.No        |\n");
	printf("\t\t\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");
	printf("\t\t\t\t\t\t|            |                               |            |                           |                       |\n");

	for (int c = 0; c < count; c++) {

		printf("\t\t\t\t\t\t|    %-8s|         %-15s       |      %c     |       %-18s  |      %-17s|\n", report[c].memberID, report[c].name, report[c].gender, report[c].ic, report[c].phoneNO);
		printf("\t\t\t\t\t\t|            |                               |            |                           |                       |\n");

	}

	printf("\t\t\t\t\t\t| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n");

	printf("\n");
	printf("\t\t\t\t\t\t    Display details for %d customers ", count);


	printf("\n\n\t\t\t\t\t Back To Main Menu (Y)    : ");
	scanf(" %c", &yesno);
	yesno = toupper(yesno);

	while (yesno != 'Y') {
		while (getchar() != '\n');
		printf("     Invalid response!\n");
		printf("     Please enter Y >");
		scanf(" %c", &yesno);
		yesno = toupper(yesno);
	}

	while (getchar() != '\n');

	if (yesno == 'Y') {
		system("cls");
		return;
	}

}






// Train Schedule 
void trainMenu() {
	int choice;
	int numTrains = 0;
	int loggedInStaffID;

	// Prompt for staff ID
	printf("\n\n\t\t\t\t       Enter your staff ID: ");
	scanf("%d", &loggedInStaffID);
	rewind(stdin);

	// Check if the staff ID is registered
	if (!isRegistered(loggedInStaffID)) {
		printf("\t\t\t\t       You are not a  staff. Access denied.\n");
		return;
	}

	system("cls");
	printf("\n\n");

	printf("\t\t     TTTTTTTTT RRRRRRR    AAAAAA   IIIIIIIII NN    NN     MM     MM   AAAAAA   NN    NN   AAAAAA   GGGGGGGG  EEEEEEEE  MM     MM  EEEEEEEE  NN    NN  TTTTTTTT \n");
	printf("\t\t        TT     RR    RR  AA    AA     II     NNN   NN     MMM   MMM  AA    AA  NNN   NN  AA    AA  GG        EE        MMM   MMM  EE        NNN   NN     TT    \n");
	printf("\t\t        TT     RRRRRRR   AAAAAAAA     II     NN NN NN     MM MMM MM  AAAAAAAA  NN NN NN  AAAAAAAA  GG   GGG  EEEEEEE   MM MMM MM  EEEEEEEE  NN NN NN     TT    \n");
	printf("\t\t        TT     RR  RR    AA    AA     II     NN   NNN     MM  M  MM  AA    AA  NN   NNN  AA    AA  GG    GG  EE        MM  M  MM  EE        NN   NNN     TT    \n");
	printf("\t\t        TT     RR    RR  AA    AA  IIIIIIIII NN    NN     MM     MM  AA    AA  NN    NN  AA    AA  GGGGGGGG  EEEEEEEE  MM     MM  EEEEEEEE  NN    NN     TT    \n");
	printf("\t\t     ------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	do {
		// Display menu options
		printf("\n\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==   TRAIN MENU :                                      ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ==     1. Display Schedule                             ==\n");
		printf("\t\t\t\t       ==     2. Schedule Menu                                ==\n");
		printf("\t\t\t\t       ==     3. Exit                                         ==\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       Enter your choice: ");


		// Input validation for menu choice
		while (scanf("%d", &choice) != 1) {
			printf("\n\n\t\t Invalid input. Please enter a number: ");
			while (getchar() != '\n');
		}

		system("cls");
		// Menu option selection
		switch (choice) {
		case 1:
			displaySchedule(&display[numTrains], numTrains);

			break;
		case 2:
			trainScheduleMenu(&numTrains);
			break;

		case 3:
			main();
			break;
		default:
			printf("\n\n\t\t ! ! ! Invalid Choice. Please Enter Number Between 1 and 7 ! ! !\n");
		}
	} while (choice != 3);


	return 0;
}

int isRegistered(int staffID) {
	FILE* file = fopen("staff.txt", "r");
	if (file == NULL) {
		printf("Error opening file.\n");
		return 0; // Assume not registered if unable to open file
	}

	int id;
	char name[100];
	char password[100];
	char position[100];
	char email[100];
	char phone[100];
	char address[100];
	char department[100];

	// Read each line and check for matching ID
	while (fscanf(file, "%d | %[^\n] | %[^\n] | %[^\n] | %[^\n] | %[^\n] | %[^\n] | %[^\n]", &id, name, password, position, email, phone, address, department) != EOF) {
		if (id == staffID) {
			fclose(file);
			return 1; // Staff ID found, return true
		}
	}

	fclose(file);
	return 0; // Staff ID not found, return false
}

void manageSchedule(int* numTrains) {
	int choice;
	do {
		// Display menu options
		printf("\n\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==   SCHEDULE MENU :                                   ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ==     1. Add Train                                    ==\n");
		printf("\t\t\t\t       ==     2. Modify                                       ==\n");
		printf("\t\t\t\t       ==     3. Delete Train                                 ==\n");
		printf("\t\t\t\t       ==     4. Exit                                         ==\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       Enter your choice: ");


		// Input validation for menu choice
		while (scanf("%d", &choice) != 1) {
			printf("\n\n\t\t Invalid input. Please enter a number: ");
			while (getchar() != '\n');
		}

		system("cls");
		// Menu option selection
		switch (choice) {
		case 1:
			addTrain(numTrains);
			break;
		case 2:
			modifyTrain(modify, numTrains);
			break;

		case 3:
			deleteTrain(&deleteTrains[*numTrains], numTrains);
			break;
		case 4:
			trainMenu();
			break;
		default:
			printf("\n\n\t\t ! ! ! Invalid Choice. Please Enter Number Between 1 and 4 ! ! !\n");
		}
	} while (choice != 4);

}

void trainScheduleMenu(int* numTrains) {
	int choice;
	do {
		// Display menu options
		printf("\n\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==   SCHEDULE MENU :                                   ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ==     1. Manage Schedule                              ==\n");
		printf("\t\t\t\t       ==     2. Route Planning                               ==\n");
		printf("\t\t\t\t       ==     3. Exit                                         ==\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       Enter your choice: ");


		// Input validation for menu choice
		while (scanf("%d", &choice) != 1) {
			printf("\n\n\t\t Invalid input. Please enter a number: ");
			while (getchar() != '\n');
		}

		system("cls");
		// Menu option selection
		switch (choice) {
		case 1:
			manageSchedule(numTrains);
			break;
		case 2:
			generateReport(&generate[*numTrains], numTrains);
			break;

		case 3:
			trainMenu();
			break;
		default:
			printf("\n\n\t\t ! ! ! Invalid Choice. Please Enter Number Between 1 and 7 ! ! !\n");
		}
	} while (choice != 3);

}

// let staff to add train schedule
void addTrain(int* numTrains) {
	char ans;
	char seatInput[4];
	char priceInput[6];
	char departureInput[5];
	char arrivalInput[5];
	int validTime, validSeat = 0, validPrice = 0;
	int departureHour, departureMinutes, arrivalHour, arrivalMinutes;


	FILE* ptr;
	FILE* checkPtr;
	Train newTrain;
	Train existingTrain;

	checkPtr = fopen("trains.bin", "rb");
	ptr = fopen("trains.bin", "ab");
	if (ptr == NULL) {
		printf("Error opening file.\n");
		return;
	}

	printf("\n\n\n");
	printf("\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("\t\t\t\t\t\t|                                           ADD TRAIN                                                 |\n");
	printf("\t\t\t\t\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

	do {
		// Read train details from user
		if (*numTrains < MAX_TRAINS) {


			printf("\t\t\t\t\t\t|  Enter Train ID (Eg: A001)    : ");
			scanf("%s", newTrain.train_id);
			convertToUpper(newTrain.train_id);

			// Check if the train ID already exists or not
			if (checkPtr != NULL) {
				while (fread(&existingTrain, sizeof(Train), 1, checkPtr)) {
					if (strcmp(existingTrain.train_id, newTrain.train_id) == 0) {
						printf("\t\t\t\t\t\t|     !! Error !! Train ID '%s' already exists.                                                      |\n", newTrain.train_id);
						fclose(checkPtr);
						return;
					}
				}
				fclose(checkPtr);

			}


			printf("\t\t\t\t\t\t|                                                                                                     |\n");
			printf("\t\t\t\t\t\t|  Enter Departure Station      : ");
			scanf(" %[^\n]", newTrain.departure_station);
			convertToUpper(newTrain.departure_station);

			printf("\t\t\t\t\t\t|                                                                                                     |\n");
			printf("\t\t\t\t\t\t|  Enter Arrival Station        : ");
			scanf(" %[^\n]", newTrain.arrival_station);
			convertToUpper(newTrain.arrival_station);

			printf("\t\t\t\t\t\t|                                                                                                     |\n");

			// Get departure time from user and validate it
			do {
				printf("\t\t\t\t\t\t|  Enter Departure Time in 24 Hour(HH:MM) : ");
				departureMinutes = 0;
				scanf("%s", departureInput);
				validTime = validTimeInput(departureInput, &departureHour, &departureMinutes);
				if (validTime) {
					newTrain.departure_hour = departureHour;
					newTrain.departure_minutes = departureMinutes;
				}

			} while (!validTime);

			printf("\t\t\t\t\t\t|                                                                                                     |\n");

			// Get arrival time from user and validate it
			do {
				printf("\t\t\t\t\t\t|  Enter Arrival Time in 24 Hour(HH:MM)   : ");
				arrivalMinutes = 0;
				scanf("%s", arrivalInput);
				validTime = validTimeInput(arrivalInput, &arrivalHour, &arrivalMinutes);
				if (validTime) {
					newTrain.arrival_hour = arrivalHour;
					newTrain.arrival_minutes = arrivalMinutes;
				}
			} while (!validTime);

			printf("\t\t\t\t\t\t|                                                                                                     |\n");

			// Get number of available seats from user and validate it
			do {
				printf("\t\t\t\t\t\t|  Enter Seat                   : ");
				scanf("%s", seatInput);

				newTrain.seat = validSeatInput(seatInput);
				if (newTrain.seat != -1) {
					validSeat = 1;
				}
				else {
					printf("\t\t\t\t\t\t|     !! Invalid !! Seat must be a number.                                                    |\n");
					validSeat = 0;
				}

			} while (!validSeat);

			printf("\t\t\t\t\t\t|                                                                                                     |\n");

			// Get price from user and validate it
			do {
				printf("\t\t\t\t\t\t|  Enter Price (RM)             : ");
				scanf("%s", priceInput);
				validPrice = validPriceInput(priceInput);

				if (validPrice) {
					newTrain.price = atoi(priceInput);
				}
			} while (!validPrice);

			printf("\t\t\t\t\t\t|                                                                                                     |\n");
			printf("\t\t\t\t\t\t|                                                                                                     |\n");
			printf("\t\t\t\t\t\t| - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - |\n");

			// Write new train to file
			fwrite(&newTrain, sizeof(Train), 1, ptr);
			(*numTrains)++; // Increment number of trains

			printf("\n\n\t\t\t\t\t\t\tTrain added successfully.\n");
		}

		else {
			printf("\n\t\t\t\t\t\t\Train List is Maximum!!\n");
			return;
		}

		// Prompt user if they want to add another train
		printf("\n\n\t\t\t\t\tWant to add one more? (Y/N): ");
		scanf(" %c", &ans);



	} while (toupper(ans) != 'N');

	fclose(ptr);
	system("cls");



}

// Let staff to modify the train schedule
void modifyTrain(Train* modify, int numTrains) {
	FILE* ptr;
	FILE* checkPtr;
	Train existingTrain;

	char trainID[6], updDeparture[22], updArrival[22];
	char confirm;
	char departureInput[5], arrivalInput[5], priceInput[6], seatInput[4];
	int updDepatureHour, updDepatureMinutes, updArrivalHour, updArrivalMinutes;
	int i = 0, found = 0, Count, option, updSeat, validTime, validPrice, validSeat;
	double updPrice;

	FILE* dptr;
	dptr = fopen("trains.bin", "rb");

	if (dptr == NULL) {
		printf("Error opening file\n\n");
		return;
	}
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t|  %-5s  |  %-22s  |  %-22s  |  %-10s |  %-10s  |  %-5s  |    %-10s |\n",
		"Train ID", "Departure Station", "Arrival Station",
		"Departure Time", "Arrival Time", "Seat", "Price(RM)");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n");


	while (fread(modify, sizeof(Train), 1, dptr)) {
		printf("\t\t\t\t\t|    %-5s   |  %-22s  |  %-22s  |      %02d:%02d      |      %02d:%02d     |   %-5d |     %-10.2lf|\n",

			modify->train_id, modify->departure_station, modify->arrival_station,
			modify->departure_hour, modify->departure_minutes,
			modify->arrival_hour, modify->arrival_minutes,
			modify->seat, modify->price);
		printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n");

	}
	fclose(dptr);

	ptr = fopen("trains.bin", "rb+");
	checkPtr = fopen("trains.bin", "rb");

	if (ptr == NULL || checkPtr == NULL) {
		printf("Error opening file\n");
		return;
	}




	fseek(ptr, 0, SEEK_END); // Move the file pointer to the end to count records
	Count = ftell(ptr) / sizeof(Train); // Get the count of records
	rewind(ptr); // Reset file pointer to the beginning

	// Read all records from file into modify array
	while (fread(&modify[i], sizeof(Train), 1, ptr))
		i++;

	fclose(ptr);







	// Get the train ID to modify from user
	printf("\n\t\t\t\t\tEnter TRAIN ID to modify: ");
	scanf("%s", trainID);
	convertToUpper(trainID);

	for (i = 0; i < Count; i++) {
		if (strcmp(trainID, modify[i].train_id) == 0) {
			found = 1;// Flag indicating train ID found


			do {
				printf("\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
				printf("\t\t\t\t\t*                                                       *\n");
				printf("\t\t\t\t\t*         Select the option you want to change          *\n");
				printf("\t\t\t\t\t*                                                       *\n");
				printf("\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
				printf("\t\t\t\t\t*                                                       *\n");
				printf("\t\t\t\t\t*      1. Train ID              5. Departure Time       *\n");
				printf("\t\t\t\t\t*      2. Departure Station     6. Arrival Time         *\n");
				printf("\t\t\t\t\t*      3. Arrival Station       7. Price                *\n");
				printf("\t\t\t\t\t*      4. Seat                  8. Exit                 *\n");
				printf("\t\t\t\t\t*                                                       *\n");
				printf("\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
				printf("\n\t\t\t\t\t   Enter your option: ");

				while (scanf("%d", &option) != 1) {
					printf("\n\n\t\t Invalid Input. Please Enter a number: ");
					while (getchar() != '\n');
				}

				switch (option) {


				case 1:
					printf("\n\t\t\t\t\t   Enter New Train ID: ");
					rewind(stdin);
					scanf("%s", trainID);
					convertToUpper(trainID);

					// Check if new Train ID already exists
					if (checkPtr != NULL) {
						while (fread(&existingTrain, sizeof(Train), 1, checkPtr)) {
							if (strcmp(existingTrain.train_id, trainID) == 0) {
								printf("\n\t\t\t\t\t Error !! Train ID '%s' already exists.\n", trainID);
								fclose(checkPtr);
								return;
							}
						}
						fclose(checkPtr);
					}

					printf("\n\t\t\t\t\t   Confirm to modify? (Y/N): ");
					rewind(stdin);
					scanf(" %c", &confirm);

					if (toupper(confirm) == 'Y') {
						strcpy(modify[i].train_id, trainID); // Update Train ID
						printf("\n\n\n\t\t\t\t\tModifying %s to %s....", trainID, modify[i].train_id);
						strcpy(trainID, modify[i].train_id);
					}
					else if (toupper(confirm) == 'N') {
						printf("\n\n\t\t\t\t\tCancelled....\n");
						return;
					}
					break;


				case 2:
					printf("\n\t\t\t\t\t   Enter New Departure Station: ");
					scanf(" %[^\n]", updDeparture);
					convertToUpper(updDeparture);

					if (checkPtr != NULL) {
						while (fread(&existingTrain, sizeof(Train), 1, checkPtr)) {
							if (strcmp(existingTrain.departure_station, updDeparture) == 0) {
								printf("\n\t\t\t\t\t !!! Error !!! Departure station is same.\n");
								fclose(checkPtr);
								return;
							}
						}
						fclose(checkPtr);
					}

					printf("\n\t\t\t\t\t   Confirm to modify? (Y/N): ");
					rewind(stdin);
					scanf(" %c", &confirm);

					if (toupper(confirm) == 'Y') {
						system("cls");
						strcpy(modify[i].departure_station, updDeparture);
						printf("\n\n\n\t\t\t\t\tModifying TRAIN %s Departure Station %s....", trainID, modify[i].departure_station);
					}
					else if (toupper(confirm) == 'N') {
						printf("\n\n\t\t\t\t\tCancelled....\n");
						return;
					}
					break;


				case 3:

					printf("\n\t\t\t\t\t   Enter New Arrival Station: ");
					scanf(" %[^\n]", updArrival);
					convertToUpper(updArrival);

					if (checkPtr != NULL) {
						while (fread(&existingTrain, sizeof(Train), 1, checkPtr)) {
							if (strcmp(existingTrain.arrival_station, updArrival) == 0) {
								printf("\n\t\t\t\t\t !!! Error !!! Departure station is same.\n");
								fclose(checkPtr);
								return;
							}
						}
						fclose(checkPtr);
					}
					printf("\n\t\t\t\t\t   Confirm to modify? (Y/N): ");
					rewind(stdin);
					scanf(" %c", &confirm);

					if (toupper(confirm) == 'Y') {
						system("cls");
						strcpy(modify[i].arrival_station, updArrival);
						printf("\n\n\n\t\t\t\t\tModifying TRAIN %s Arrival Station %s....", trainID, modify[i].arrival_station);
					}
					else if (toupper(confirm) == 'N') {
						printf("\n\n\t\t\t\t\tCancelled....\n");
						return;
					}
					break;


				case 4:

					do {
						printf("\n\t\t\t\t\t   Enter New Seat: ");
						scanf("%s", seatInput);
						validSeat = validSeatInput(seatInput);// Validate the seat input


						if (validSeat) {

							printf("\n\t\t\t\t\t   Confirm to modify? (Y/N): ");
							rewind(stdin);
							scanf(" %c", &confirm);
							if (toupper(confirm) == 'Y') {
								system("cls");
								modify[i].seat = validSeat;
								printf("\n\n\n\t\t\t\t\tModifying TRAIN %s Seat to %s....", trainID, seatInput);
							}
							else if (toupper(confirm) == 'N') {
								printf("\n\n\t\t\t\t\tCancelled....\n");
								return;
							}

						}
						else {
							printf("\n\t\t\t\t\t   !! Invalid !! Seat must be a number.\n");
							validSeat = 0;
						}


					} while (!validSeat);
					break;


				case 5:

					do {
						printf("\n\t\t\t\t\t   Enter New Departure Time in 24 Hour (HH:MM): ");
						updDepatureMinutes = 0;
						scanf("%s", departureInput);
						validTime = validTimeInput(departureInput, &updDepatureHour, &updDepatureMinutes);


						if (validTime) {
							printf("\n\t\t\t\t\t   Confirm to modify? (Y/N): ");
							rewind(stdin);
							scanf(" %c", &confirm);

							if (toupper(confirm) == 'Y') {
								system("cls");
								modify[i].departure_hour = updDepatureHour;
								modify[i].departure_minutes = updDepatureMinutes;
								printf("\n\n\n\t\t\t\t\tModifying TRAIN %s Departure Time %s....", trainID, departureInput);
							}
							else if (toupper(confirm) == 'N') {
								printf("\n\n\t\t\t\t\tCancelled....\n");
								return;
							}


						}
					} while (!validTime);

					break;


				case 6:

					do {
						printf("\n\t\t\t\t\t   Enter New Arrival Time in 24 Hour (HH:MM): ");
						updArrivalMinutes = 0;
						scanf("%s", arrivalInput);
						validTime = validTimeInput(arrivalInput, &updArrivalHour, &updArrivalMinutes);

						if (validTime) {

							printf("\n\t\t\t\t\t   Confirm to modify? (Y/N): ");
							rewind(stdin);
							scanf(" %c", &confirm);
							if (toupper(confirm) == 'Y') {
								system("cls");

								modify[i].arrival_hour = updArrivalHour;
								modify[i].arrival_minutes = updArrivalMinutes;

								printf("\n\n\n\t\t\t\t\tModifying TRAIN %s Arrival Time %s....", trainID, arrivalInput);
							}
							else if (toupper(confirm) == 'N') {
								printf("\n\n\t\t\t\t\tCancelled....\n");
								return;
							}
						}
					} while (!validTime);

					break;


				case 7:
					do {
						printf("\n\t\t\t\t\t   Enter New Price: ");
						scanf("%s", priceInput);
						validPrice = validPriceInput(priceInput); // Validate the price input

						if (!validPrice) {
							printf("\n\t\t\t\t\t   !!Invalid !!Price must be a valid numeric value.\n");
							while (getchar() != '\n'); // Clear input buffer
						}
					} while (!validPrice);

					// Convert price input to double
					updPrice = atof(priceInput);

					printf("\n\t\t\t\t\t   Confirm to modify? (Y/N): ");
					scanf(" %c", &confirm);

					if (toupper(confirm) == 'Y') {
						system("cls");
						modify[i].price = updPrice;
						printf("\n\n\n\t\t\t\t\tModifying TRAIN %s Price to %.2lf....", modify[i].train_id, updPrice);
					}
					else if (toupper(confirm) == 'N') {
						printf("\n\n\t\t\t\t\tCancelled....\n");

					}
					break;


				case 8:
					printf("\n\n\t\t\t\t\tByebye~~");


					return;
				default:
					break;
				}

				// Display modified train information
				printf("\n\n\n\t\t\t\t\t   Train modified successfully.\n\n");
				if (option != 8) {
					printf("  ---------------------------------------------------------------------------------------------------------------------------------\n");
					printf("  |  %-5s  |  %-22s  |  %-22s  |  %-10s |  %-10s  |  %-5s  |    %-10s |\n",
						"Train ID", "Departure Station", "Arrival Station",
						"Departure Time", "Arrival Time", "Seat", "Price(RM)");
					printf("  ---------------------------------------------------------------------------------------------------------------------------------\n");
					printf("  |    %-5s   |  %-22s  |  %-22s  |      %02d:%02d      |      %02d:%02d     |   %-5d |     %-10.2lf|\n",
						modify[i].train_id, modify[i].departure_station, modify[i].arrival_station,
						modify[i].departure_hour, modify[i].departure_minutes,
						modify[i].arrival_hour, modify[i].arrival_minutes,
						modify[i].seat, modify[i].price);
					printf("  ---------------------------------------------------------------------------------------------------------------------------------\n");
				}

			} while (option != 8);


		}
	}

	if (!found) {
		printf("\n\n\t\t\t\t\t!! Error !! Train ID '%s' not found.\n\n", trainID);
	}
}

// Let staff to delete the train schedule
void deleteTrain(Train* train, int* numTrains) {
	FILE* ptr;
	char trainID[6], confirm;
	int i = 0, found = 0, Count, j, k;

	ptr = fopen("trains.bin", "rb");

	if (ptr == NULL) {
		printf("Error opening file\n");
		return;
	}

	while (fread(&deleteTrains[i], sizeof(Train), 1, ptr))
		i++;
	Count = i;

	fclose(ptr);


	printf("\n\n");
	printf("\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t\t|                                                                                                 |\n");
	printf("\t\t\t\t\t\t|                                      TRAIN CANCELLATION                                         |\n");
	printf("\t\t\t\t\t\t|                                                                                                 |\n");
	printf("\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
	printf("\t\t\t\t\t\t\tEnter Train ID to delete: ");
	scanf(" %[^\n]", trainID);
	for (k = 0; trainID[k] != '\0'; ++k) {
		trainID[k] = toupper(trainID[k]);
	}
	for (i = 0; i < Count; i++) {
		if (strcmp(trainID, deleteTrains[i].train_id) == 0) {
			found = 1;


			// Display train details for confirmation
			printf("\n\n");
			printf("\t\t\t\t\t\t\t\t===================================================================\n");
			printf("\t\t\t\t\t\t\t\t|                                                                 |\n");
			printf("\t\t\t\t\t\t\t\t|                           TRAIN DETAILS :                       |\n");
			printf("\t\t\t\t\t\t\t\t|                                                                 |\n");
			printf("\t\t\t\t\t\t\t\t|.................................................................|\n");
			printf("\t\t\t\t\t\t\t\t|                                                                 |\n");
			printf("\t\t\t\t\t\t\t\t| \tTRAIN ID           : %-6s                               |\n", deleteTrains[i].train_id);
			printf("\t\t\t\t\t\t\t\t| \tDEPARTURE STATION  : %-22s               |\n", deleteTrains[i].departure_station);
			printf("\t\t\t\t\t\t\t\t| \tARRIVAL STATION    : %-22s               |\n", deleteTrains[i].arrival_station);
			printf("\t\t\t\t\t\t\t\t| \tDEPARTURE TIME     : %02d:%02d                                |\n", deleteTrains[i].departure_hour, deleteTrains[i].departure_minutes);
			printf("\t\t\t\t\t\t\t\t| \tARRIVAL TIME       : %02d:%02d                                |\n", deleteTrains[i].arrival_hour, deleteTrains[i].arrival_minutes);
			printf("\t\t\t\t\t\t\t\t| \tSEAT               : %-5d                                |\n", deleteTrains[i].seat);
			printf("\t\t\t\t\t\t\t\t| \tPRICE (RM)         : %-10.2lf                           |\n", deleteTrains[i].price);
			printf("\t\t\t\t\t\t\t\t|                                                                 |\n");
			printf("\t\t\t\t\t\t\t\t===================================================================\n");


			// Prompt user to confirm deletion
			printf("\n\t\t\t\t\tConfirm deletion (Y/N): ");
			scanf(" %c", &confirm);


			// Shift elements to remove deleted record
			if (toupper(confirm) == 'Y') {
				for (j = i; j < Count - 1; j++) {
					deleteTrains[j] = deleteTrains[j + 1];
				}
				Count--;

				ptr = fopen("trains.bin", "wb");
				for (i = 0; i < Count; i++) {
					fwrite(&deleteTrains[i], sizeof(Train), 1, ptr);
				}
				fclose(ptr);

				printf("\n\t\t\t\t\tTrain deleted successfully.\n");
			}
			else if (toupper(confirm) == 'N') {
				printf("\t\t\t\t\tDeletion cancelled.\n");
				return;
			}
		}
	}

	// Notify user if Train ID not found
	if (!found) {
		printf("\n\n\t\t\t\t\t TRAIN ID - %s not found.\n", trainID);
		return;
	}
}


// Let user to search the train schedule by entering some keyword
void searchTrain(Train* train, int numTrains) {
	FILE* ptr;
	char keyword[22], uppercaseKeyword[22];
	int found = 0, hour, minute;
	char choice;

	ptr = fopen("trains.bin", "rb");

	if (ptr == NULL) {
		printf("Error opening file\n\n");
		return;
	}


	do {
		system("cls");
		printf("\n\n");
		printf("\t\t\t\t\t\t\t    .- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -.\n");
		printf("\t\t\t\t\t\t\t  .   .......................................................................................   .\n");
		printf("\t\t\t\t\t\t\t .  .                                                                                         .  .\n");
		printf("\t\t\t\t\t\t\t .  .                                         SEARCH                                          .  .\n");
		printf("\t\t\t\t\t\t\t .  .                                                                                         .  .\n");
		printf("\t\t\t\t\t\t\t  .   .......................................................................................   .\n");
		printf("\t\t\t\t\t\t\t    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");


		found = 0;
		printf("\n\n\t\t\t\t\tEnter the keyword to search for: ");
		rewind(stdin);
		scanf(" %[^\n]", keyword);
		strcpy(uppercaseKeyword, keyword);
		for (int i = 0; uppercaseKeyword[i]; i++) {
			uppercaseKeyword[i] = toupper(uppercaseKeyword[i]);
		}

		printf("\n\n\t\t\t\t\t   Search Results:\n\n");
		rewind(ptr);
		while (fread(train, sizeof(Train), 1, ptr)) {


			if (strcmp(uppercaseKeyword, train->train_id) == 0 ||
				strcmp(uppercaseKeyword, train->departure_station) == 0 ||
				strcmp(uppercaseKeyword, train->arrival_station) == 0) {
				printf("\t\t\t\t\t  ---------------------------------------------------------------------------------------------------------------------------------\n");
				printf("\t\t\t\t\t  |  %-5s  |  %-22s  |  %-22s  |  %-10s |  %-10s  |  %-5s  |    %-10s |\n",
					"TRAIN ID", "DEPARTURE STATION", "ARRIVAL STATION",
					"DEPARTURE TIME", "ARRIVAL TIME", "SEAT", "PRICE(RM)");
				printf("\t\t\t\t\t  ---------------------------------------------------------------------------------------------------------------------------------\n");

				printf("\t\t\t\t\t  |    %-5s   |  %-22s  |  %-22s  |      %02d:%02d      |     %02d:%02d      |   %-5d |     %-10.2lf|\n",
					train->train_id, train->departure_station, train->arrival_station,
					train->departure_hour, train->departure_minutes,
					train->arrival_hour, train->arrival_minutes,
					train->seat, train->price);
				printf("\t\t\t\t\t  ---------------------------------------------------------------------------------------------------------------------------------\n");
				found = 1;


				// Calculate and display the distance between departure and arrival times
				hour = train->arrival_hour - train->departure_hour;
				minute = train->arrival_minutes - train->departure_minutes;
				if (minute < 0) {
					minute += 60;
					hour--;
				}

				if (hour == 0) {
					printf("\t\t\t\t\t   The distance is about %d minute\n\n\n", minute);
				}
				else if (minute == 0) {
					printf("\t\t\t\t\t   The distance is about %d hour \n\n\n", hour);
				}
				else {
					printf("\t\t\t\t\t   The distance is about %d hour %d minute\n\n\n", hour, minute);
				}
			}
		}


		// Notify if no matching results found
		if (!found) {
			printf("\t\t\t\t\t            No matching results found. \n\n");
		}

		printf("\n\t\t\t\t\t  Do you want to search again? (Y/N): ");
		scanf(" %c", &choice);
		rewind(stdin);
		system("cls");
	} while (toupper(choice) == 'Y');

	fclose(ptr);
}


// Display the train schedule for member to book
void displaySchedule(Train* train, int numTrains) {
	int choice;

	FILE* ptr;
	ptr = fopen("trains.bin", "rb");

	if (ptr == NULL) {
		printf("Error opening file\n\n");
		return;
	}

	printf("\n\n");
	printf("\t\t\t\t\tTTTTTTTTT RRRRRRR    AAAAAA   IIIIIIIII NNN    NN      SSSSSS   CCCCCCC HH   HH  EEEEEEEE  DDDDDDD  UU    UU LL       EEEEEEEE \n");
	printf("\t\t\t\t\t   TT     RR    RR  AA    AA     II     NN NN  NN     SS       CC       HH   HH  EE        DD    DD UU    UU LL       EE        \n");
	printf("\t\t\t\t\t   TT     RRRRRRR   AAAAAAAA     II     NN  NN NN      SSSSSS  CC       HHHHHHH  EEEEEEE   DD    DD UU    UU LL       EEEEEEE  \n");
	printf("\t\t\t\t\t   TT     RR  RR    AA    AA     II     NN   N NN           SS CC       HH   HH  EE        DD    DD UU    UU LL       EE        \n");
	printf("\t\t\t\t\t   TT     RR    RR  AA    AA  IIIIIIIII NN    NNN      SSSSSS   CCCCCCC HH   HH  EEEEEEEE  DDDDDDD   UUUUUU  LLLLLLLL EEEEEEEE  \n");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n\n\n");

	do {
		printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\t\t\t\t\t|  %-5s  |  %-22s  |  %-22s  |  %-10s |  %-10s  |  %-5s  |    %-10s |\n",
			"Train ID", "Departure Station", "Arrival Station",
			"Departure Time", "Arrival Time", "Seat", "Price(RM)");
		printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n");


		while (fread(train, sizeof(Train), 1, ptr)) {
			printf("\t\t\t\t\t|    %-5s   |  %-22s  |  %-22s  |      %02d:%02d      |      %02d:%02d     |   %-5d |     %-10.2lf|\n",

				train->train_id, train->departure_station, train->arrival_station,
				train->departure_hour, train->departure_minutes,
				train->arrival_hour, train->arrival_minutes,
				train->seat, train->price);
			printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n");

		}
		printf("\n\n\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==   Selection :                                       ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ==     1. Seaech                                       ==\n");
		printf("\t\t\t\t       ==     2. Exit                                         ==\n");
		printf("\t\t\t\t       ==                                                     ==\n");
		printf("\t\t\t\t       ---------------------------------------------------------\n");
		printf("\t\t\t\t       Enter your choice: ");
		// Input validation for menu choice
		while (scanf("%d", &choice) != 1) {
			printf("\n\n\t\t Invalid input. Please enter a number: ");
			while (getchar() != '\n');
		}

		switch (choice) {
		case 1:
			searchTrain(&search, numTrains);
			break;
		case 2:
			trainMenu();
			break;
		default:
			printf("\n\n\t\t ! ! ! Invalid Choice. Please Enter Number Between 1 and 2 ! ! !\n");
		}

	} while (choice != 2);

	fclose(ptr);
}



// Generate train report for staff only
void generateReport(Train* train, int numTrains) {
	FILE* ptr;

	int totalTrains = 0;
	double totalRevenue = 0.0;
	double totalOccupancy = 0.0;
	int maxDepartures = 0, maxArrivals = 0;
	int peakDepartureHour = 0, peakArrivalHour = 0;
	int departureFrequency[24] = { 0 };
	int arrivalFrequency[24] = { 0 };
	int destinationFrequency[MAX_TRAINS] = { 0 };
	// Declare variables to store report data

	ptr = fopen("trains.bin", "rb");

	if (ptr == NULL) {
		printf("Error opening file\n\n");
		return;
	}

	while (fread(train, sizeof(Train), 1, ptr)) {
		totalTrains++;
		totalRevenue += train->price;
		totalOccupancy += (double)train->seat / MAX_TRAINS;

		departureFrequency[train->departure_hour]++;
		arrivalFrequency[train->arrival_hour]++;
		if (departureFrequency[train->departure_hour] > maxDepartures) {
			maxDepartures = departureFrequency[train->departure_hour];
			peakDepartureHour = train->departure_hour;
		}
		if (arrivalFrequency[train->arrival_hour] > maxArrivals) {
			maxArrivals = arrivalFrequency[train->arrival_hour];
			peakArrivalHour = train->arrival_hour;
		}
	}

	fclose(ptr);

	// Calculate average ticket price and occupancy rate
	double averageTicketPrice = totalRevenue / totalTrains;
	double averageOccupancy = totalOccupancy / totalTrains;

	// Adjust peak departure and arrival hours to 12-hour format
	const char* peakDepartureTime = (peakDepartureHour < 12) ? "AM" : "PM";
	const char* peakArrivalTime = (peakArrivalHour < 12) ? "AM" : "PM";
	if (peakDepartureHour > 12) peakDepartureHour -= 12;
	if (peakArrivalHour > 12) peakArrivalHour -= 12;

	// Print the report
	printf("\n\n");
	printf("\t\t\t\t\t\t\t=============================================================================================\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                    Train Schedule Report                                  |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|...........................................................................................|\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t| \tTotal Trains            : %-27d                               |\n", totalTrains);
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t| \tTotal Revenue           : RM %-23.2lf                                |\n", totalRevenue);
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t| \tAverage Ticket Price (RM)                       Average Occupancy Rate              |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t| \t         %-20.2lf                             %-20.2lf      |\n", averageTicketPrice, averageOccupancy * 100),
		printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|      \t  Peak Departure Hour                              Peak Arrival Hour                |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|   \t       %02d:00 %s                                         %02d:00 %s                    |\n", peakDepartureHour, peakDepartureTime, peakArrivalHour, peakArrivalTime);
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t|                                                                                           |\n");
	printf("\t\t\t\t\t\t\t=============================================================================================\n");
}


// Convert the user input details to upper case
void convertToUpper(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		str[i] = toupper(str[i]);
	}
}



// For time validation
int validTimeInput(const char* timeInput, int* Hour, int* Minutes) {
	int len = strlen(timeInput);
	if (len > 0 && len <= 5) {
		// Check if the format is HH:MM or H:MM or HH:M or H:M
		if (((isdigit(timeInput[0]) && isdigit(timeInput[1]) && timeInput[2] == ':' &&
			isdigit(timeInput[3]) && isdigit(timeInput[4])) ||
			(isdigit(timeInput[0]) && timeInput[1] == ':' && isdigit(timeInput[2])) ||
			(isdigit(timeInput[0])) || (isdigit(timeInput[0]) && isdigit(timeInput[1]))) &&
			atoi(timeInput) >= 0 && atoi(timeInput) <= 2359) {
			sscanf(timeInput, "%d:%d", Hour, Minutes);
			if (*Hour > 23 || *Minutes > 59) {
				printf("\n\t\t\t\t\t!! Invalid !! Time must be between 0 and 23 hours and 0 and 59 minutes.\n\n");
				return 0; // Invalid time input
			}
			return 1; // Valid time input
		}
		else {
			printf("\n\t\t\t\t\t!! Invalid !! Time must be in HH:MM format\n\n");
			return 0; // Invalid time input
		}
	}
	else {
		printf("\n\t\t\t\t\t!! Invalid !! Time must be between 1 and 24 Hour and 00 - 59 Minutes.\n\n");
		return 0; // Invalid time input
	}
}


// For seat number validation
int validSeatInput(const char* seatInput) {
	if (strlen(seatInput) > 0 && strlen(seatInput) <= 3) {
		if ((isdigit(seatInput[0]) && isdigit(seatInput[1]) && isdigit(seatInput[2])) ||
			(isdigit(seatInput[0]) && isdigit(seatInput[1])) ||
			(isdigit(seatInput[0]))) {
			return atoi(seatInput);
		}

		else {
			return -1; // Invalid seat input
		}
	}

}


// For ticket price validation
int validPriceInput(const char* priceInput) {
	if (strlen(priceInput) > 0 && strlen(priceInput) <= 5) {
		if ((isdigit(priceInput[0]) && isdigit(priceInput[1]) && priceInput[2] == '.' &&
			isdigit(priceInput[3]) && isdigit(priceInput[4])) ||
			(isdigit(priceInput[0]) && priceInput[1] == '.' && isdigit(priceInput[2])) ||
			(isdigit(priceInput[0])) || (isdigit(priceInput[0]) && isdigit(priceInput[1])))
		{
			return 1; // Valid price input
		}
		else {

			printf("\t\t\t\t\t\t|      !! Invalid !! Price must be a number.                                                          |\n");
			return 0; // Invalid price input
		}
	}
	else {
		printf("\t\t\t\t\t\t|    !! Invalid !! Price must be between 1 and 5 characters.                                           |\n");
		return 0; // Invalid price input
	}
}























// Ticket Booking
void ticketModule(BookingInfo booking[], int* count) {
	int a;
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t\t    BBBBBBB    OOOOOO   OOOOOO  KK    KK  IIIIIIIII NN    NN  GGGGGGG        TTTTTTTTT  IIIIIIIII  CCCCCCC  KK    KK EEEEEEEE TTTTTTTT\n");
	printf("\t\t\t\t    BB    BB  OO    OO OO    OO KK  KK       II     NNN   NN GG                 TT         II     CC        KK  KK   EE          TT  \n");
	printf("\t\t\t\t    BBBBBBB   OO    OO OO    OO KKKK         II     NN NN NN GG   GGGG          TT         II     CC        KKKK     EEEEEEE     TT  \n");
	printf("\t\t\t\t    BB    BB  OO    OO OO    OO KK  KK       II     NN   NNN GG     GG          TT         II     CC        KK  KK   EE          TT  \n");
	printf("\t\t\t\t    BBBBBBB    OOOOOO   OOOOOO  KK    KK  IIIIIIIII NN    NN  GGGGGGG           TT      IIIIIIIII  CCCCCCC  KK    KK EEEEEEEE    TT  \n");
	printf("\t\t\t\t    ---------------------------------------------------------------------------------------------------------------------------------\n");


	printf("\n\n\n");

	printf("\t\t\t\t\t========================================================\n");
	printf("\t\t\t\t\t==                                                    ==\n");
	printf("\t\t\t\t\t==   Selection                                        ==\n");
	printf("\t\t\t\t\t==                                                    ==\n");
	printf("\t\t\t\t\t========================================================\n");
	printf("\t\t\t\t\t==                                                    ==\n");
	printf("\t\t\t\t\t==        1.Booking Interface                         ==\n");
	printf("\t\t\t\t\t==                                                    ==\n");
	printf("\t\t\t\t\t==        2.View Ticket Status                        ==\n");
	printf("\t\t\t\t\t==                                                    ==\n");
	printf("\t\t\t\t\t==        3.Exit                                      ==\n");
	printf("\t\t\t\t\t==                                                    ==\n");
	printf("\t\t\t\t\t========================================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t  Please Enter your choice:");
	scanf("%d", &a);

	while (a < 1 || a > 3) {
		clearInputBuffer();
		printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice!**\n\n");
		printf("\t\t\t\t\t  Please enter your choice:");
		scanf("%d", &a);
	}

	switch (a) {
	case 1:
		system("cls");
		bookingInterface(booking, *count);
		break;
	case 2:
		system("cls");
		ticketStatus(booking, *count);
		break;
	case 3:
		main();
		break;
	default:
		printf("\t\t\t\t\t\t**Invalid Choice! Please choose again! **\n\n");
		break;
	}
}


// Allow member to choose to search , book , change , delete  and pay ticket
void bookingInterface(BookingInfo booking[], int count) {
	BookingInfo ticket;
	int a;

	printf("\n\n");

	printf("\t\t\t\t\t BBBBBBB    OOOOOO   OOOOOO  K    KK     IIIIIIIII NN    NN TTTTTTTT EEEEEEEE RRRRRRR   FFFFFFF  AAAA   CCCCCCC EEEEEEEE  \n");
	printf("\t\t\t\t\t BB    BB  OO    OO OO    OO K  KK          II     NNN   NN    TT    EE       RR    RR  FF      AA  AA  CC      EE        \n");
	printf("\t\t\t\t\t BBBBBBB   OO    OO OO    OO KKK            II     NN NN NN    TT    EEEEEEE  RRRRRRR   FFFFFF AAAAAAAA CC      EEEEEEE  \n");
	printf("\t\t\t\t\t BB    BB  OO    OO OO    OO K  KK          II     NN   NNN    TT    EE       RR  RR    FF     AA    AA CC      EE        \n");
	printf("\t\t\t\t\t BBBBBBB    OOOOOO   OOOOOO  K    KK     IIIIIIIII NN    NN    TT    EEEEEEEE RR    RR  FF     AA    AA CCCCCCC EEEEEEEE  \n");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------------\n\n\n");

	printf("\t\t\t\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t==   Selection                                         ==\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t=========================================================\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t==       1.Search Ticket                               ==\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t==       2.Book Ticket                                 ==\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t==       3.Change Ticket                               ==\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t==       4.Delete Ticket                               ==\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t==       5.Payment Process                             ==\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t==       6.Exit                                        ==\n");
	printf("\t\t\t\t\t\t\t\t==                                                     ==\n");
	printf("\t\t\t\t\t\t\t\t=========================================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t  Please Enter Your Choice:");
	scanf("%d", &a);

	while (a < 1 || a>6) {
		clearInputBuffer();
		printf("\t\t\t\t\t\t**Invalid Choice! Please Enter Valid Choice!**\n\n");
		printf("\t\t\t\t\t  Please Enter your choice:");
		scanf("%d", &a);
	}

	switch (a) {
	case 1:
		system("cls");
		searchTicket(booking, &count);
		break;
	case 2:
		system("cls");
		bookTicket(booking, &count);
		break;
	case 3:
		system("cls");
		changeTicket(booking, &count);
		break;
	case 4:
		system("cls");
		deleteTicket(booking, &count);
		break;
	case 5:
		system("cls");
		paymentProcess(booking, &count);
		break;
	case 6:
		system("cls");
		ticketModule(booking, &count);
		break;
	default:
		printf("\t\t\t\t\t\t** Invalid Choice! Please choose again! **\n\n");
		break;
	}


}










void searchTicket(BookingInfo booking[], int* count) {
	FILE* ptr;
	Train searchTic;
	char keyword[22], uppercaseKeyword[22];
	int found = 0, a;

	ptr = fopen("trains.bin", "rb");
	if (ptr == NULL) {
		printf("Error opening file\n");
		return;
	}

	found = 0;

	printf("\n\n\n");
	printf("\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t\t*                                                   SEARCH TICKET                                             *\n");
	printf("\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t\t*                                                                                                             *\n");
	printf("\t\t\t\t\t\t*  Enter departure station to search for tickets: ");
	rewind(stdin);
	scanf(" %[^\n]", keyword);

	strcpy(uppercaseKeyword, keyword);
	for (int i = 0; uppercaseKeyword[i]; i++) {
		uppercaseKeyword[i] = toupper(uppercaseKeyword[i]);
	}

	printf("\t\t\t\t\t\t*                                                                                                             *\n");
	printf("\t\t\t\t\t\t*                                                                                                             *\n");
	printf("\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n");

	// Display header if at least one matching ticket is found
	printf("\t\t\t\t\t\tSearch Results:\n");
	printf("\t\t\t\t\t\t-------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t| Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Seat | Price |\n");
	printf("\t\t\t\t\t\t-------------------------------------------------------------------------------------------------\n");
	rewind(ptr);


	while (fread(&searchTic, sizeof(Train), 1, ptr) == 1) {

		if (strcmp(uppercaseKeyword, searchTic.departure_station) == 0) {

			// Display matching ticket
			printf("\t\t\t\t\t\t| %-8s | %-16s  | %-14s  | %02d:%02d          | %02d:%02d        | %4d | %6.2lf|\n",
				searchTic.train_id, searchTic.departure_station, searchTic.arrival_station,
				searchTic.departure_hour, searchTic.departure_minutes,
				searchTic.arrival_hour, searchTic.arrival_minutes,
				searchTic.seat, searchTic.price);
			found = 1;
		}
	}

	if (!found) {
		printf("\t\t\t\t\t\tNo tickets found for the provided departure station.\n\n");

		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t\t== Selection                    ==\n");
		printf("\t\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t\t==       1. Search Again        ==\n");
		printf("\t\t\t\t\t\t==       2. Exit                ==\n");
		printf("\t\t\t\t\t\t==================================\n");
		printf("\n");
		printf("\t\t\t\t\t\t  Please enter your choice: ");
		if (scanf("%d", &a) != 1) {
			clearInputBuffer();
			printf("\t\t\t\t\t\t  Please enter your choice: ");
			scanf("%d", &a);
			fclose(ptr);
			return;
		}

		switch (a) {
		case 1:
			system("cls");
			searchTicket(booking, count);
			break;
		case 2:
			system("cls");
			ticketModule(booking, count);
			break;
		default:
			printf("\t\t\t\t\t\t**Invalid choice! Please choose again!\n\n");
			break;
		}
	}
	else {
		printf("\t\t\t\t\t\t------------------------------------------------------------------------------------------------\n\n\n");

		printf("\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t== Selection                    ==\n");
		printf("\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t==       1. Book Ticket         ==\n");
		printf("\t\t\t\t\t==       2. Search Again        ==\n");
		printf("\t\t\t\t\t==       3. Exit               ==\n");
		printf("\t\t\t\t\t==================================\n");
		printf("\n\n");
		printf("\t\t\t\t\tPlease enter your choice: ");
		if (scanf("%d", &a) != 1) {
			clearInputBuffer();
			printf("\t\t\t\t\tPlease enter your choice: ");
			scanf("%d", &a);
			fclose(ptr);

		}

		switch (a) {
		case 1:
			system("cls");
			bookTicket(booking, count);
			break;
		case 2:
			system("cls");
			searchTicket(booking, count);
			break;
		case 3:
			ticketModule(booking, count);
			break;
		default:
			printf("\t\t\t\t\t\t**Invalid choice! Please choose again!\n\n");
			break;
		}
	}

	fclose(ptr);
}


void bookTicket(BookingInfo booking[], int* count) {
	FILE* ptr;
	FILE* fptr;
	Train availableTicket;
	BookingInfo bookedTicket;
	char bookTicketDate[11]; // Changed to 11 to include null terminator
	int choice;
	BookingInfo newTicket;

	// Open the trains binary file for reading
	ptr = fopen("trains.bin", "rb");
	if (ptr == NULL) {
		printf("Error opening trains file\n");
		return;
	}

	// Display already available tickets
	printf("\n\t\t\t\t\tAlready Available Tickets:\n");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t|  %-7s | %-18s | %-18s | %-10s | %-10s | %-5s | %-8s | %-8s|\n",
		"Train ID", "Departure Station", "Arrival Station", "Departure Time", "Arrival Time", "Seat", "Price", "Status");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");

	while (fread(&availableTicket, sizeof(Train), 1, ptr)) {
		printf("\t\t\t\t\t| %-9s | %-18s | %-18s | %02d:%02d          | %02d:%02d        | %-5d | %6.2lf  | %-8s |\n",
			availableTicket.train_id, availableTicket.departure_station, availableTicket.arrival_station,
			availableTicket.departure_hour, availableTicket.departure_minutes,
			availableTicket.arrival_hour, availableTicket.arrival_minutes, availableTicket.seat,
			availableTicket.price, "Available");
		printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");
	}

	// Close the trains file
	fclose(ptr);

	// Prompt the user to input the details of the ticket they want to book
	printf("\n\t\t\t\t\tEnter the Booking Date (dd/mm/yyyy): ");
	scanf("%15s", bookTicketDate); // Changed to read max 10 characters (dd/mm/yyyy)

	char selectedTrainID[7];
	// Ask user to input Train ID of the ticket they want to book
	printf("\n\t\t\t\t\tEnter the Train ID of the ticket you want to book (e.g: A001): ");
	scanf("%6s", selectedTrainID); // Assume train ID is 6 characters long
	convertToUpper(selectedTrainID);

	// Display ticket details based on the entered train ID
	ptr = fopen("trains.bin", "rb");
	if (ptr == NULL) {
		printf("\t\t\t\t\t**Error opening trains file\n");
		return;
	}

	printf("\n\n\n\t\t\t\t\tSelected Ticket Details:\n");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t| %-5s | %-18s | %-18s | %-10s | %-10s | %-5s | %-8s | %-8s|\n",
		"Train ID", "Departure Station", "Arrival Station", "Departure Time", "Arrival Time", "Seat", "Price", "Status");
	printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");

	// Search for the selected ticket in the train schedule
	int ticketFound = 0;

	while (fread(&availableTicket, sizeof(Train), 1, ptr)) {
		if (strcmp(availableTicket.train_id, selectedTrainID) == 0) {
			printf("\t\t\t\t\t| %-9s | %-18s | %-18s | %02d:%02d          | %02d:%02d        | %-5d | %6.2lf  | %-8s |\n",
				availableTicket.train_id, availableTicket.departure_station, availableTicket.arrival_station,
				availableTicket.departure_hour, availableTicket.departure_minutes,
				availableTicket.arrival_hour, availableTicket.arrival_minutes, availableTicket.seat,
				availableTicket.price, "Available");
			printf("\t\t\t\t\t--------------------------------------------------------------------------------------------------------------------\n");

			ticketFound = 1;
			break;
		}
	}

	// Close the trains file
	fclose(ptr);

	if (!ticketFound) {
		printf("\t\t\t\t\t**Error: Ticket not found.\n");
		return;
	}


	// Confirm ticket booking
	printf("\n\t\t\t\t\tAre you sure you want to book this ticket? (1 for Yes, 0 for No): ");
	scanf("%d", &choice);

	if (choice != 1) {
		printf("\n\t\t\t\t\tTicket Booking Canceled....\n");
		return;
	}

	// Open the tickets binary file for appending
	fptr = fopen("tickets.bin", "ab");
	if (fptr == NULL) {
		printf("Error opening tickets file\n");
		return;
	}

	// Store ticket details in the tickets binary file
	strcpy(bookedTicket.date, bookTicketDate);
	strcpy(bookedTicket.train_id, selectedTrainID);
	bookedTicket.ticket_status = 1; // Assuming the ticket is booked
	strcpy(bookedTicket.departure_Station, availableTicket.departure_station);
	strcpy(bookedTicket.arrival_Station, availableTicket.arrival_station);
	bookedTicket.departure_hour = availableTicket.departure_hour;
	bookedTicket.departure_minutes = availableTicket.departure_minutes;
	bookedTicket.arrival_hour = availableTicket.arrival_hour;
	bookedTicket.arrival_minutes = availableTicket.arrival_minutes;
	bookedTicket.seat = availableTicket.seat;
	bookedTicket.price = availableTicket.price;

	// Write the booked ticket details to the ticket binary file
	fwrite(&bookedTicket, sizeof(BookingInfo), 1, fptr);

	// Close the tickets file
	fclose(fptr);

	printf("\n\t\t\t\t\tTicket booked successfully!\n");
	printf("\t\t\t\t\t==================================\n");
	printf("\t\t\t\t\t== Selection                    ==\n");
	printf("\t\t\t\t\t==================================\n");
	printf("\t\t\t\t\t== 1. Book Again                ==\n");
	printf("\t\t\t\t\t== 2. Change Ticket             ==\n");
	printf("\t\t\t\t\t== 3. Delete Ticket             ==\n");
	printf("\t\t\t\t\t== 4. Payment Process           ==\n");
	printf("\t\t\t\t\t== 5. Exit                      ==\n");
	printf("\t\t\t\t\t==================================\n");

	printf("\n\t\t\t\t\tPlease enter your choice: ");
	scanf("%d", &choice);

	while (choice < 1 || choice > 5) {
		clearInputBuffer();
		printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice: ");
		scanf("%d", &choice);
	}

	switch (choice) {
	case 1:
		system("cls");
		bookTicket(booking, count);
		break;
	case 2:
		system("cls");
		changeTicket(booking, count);
		break;
	case 3:
		system("cls");
		deleteTicket(booking, count);
		break;
	case 4:
		system("cls");
		paymentProcess(booking, count);
		break;
	case 5:
		system("cls");
		ticketModule(booking, count);
		break;
	default:
		printf("\t\t\t\t\t\t**Invalid Choice! Please choose again!\n\n");
		break;
	}
}


void changeTicket(BookingInfo booking[], int* count) {
	FILE* fptr;
	char keyword[7]; // Assuming booking ID is 6 characters long + null terminator
	int found = 0, a, choice;
	char bookingID[10];
	BookingInfo bookedTicket;

	// Open the "tickets.bin" file for reading and writing in binary mode
	fptr = fopen("tickets.bin", "rb+");
	if (fptr == NULL) {
		printf("Error opening tickets file\n");
		return;
	}

	// Display already booked tickets
	printf("\n\n\t\t\t\t\tAlready Booked Tickets:\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t| Booking ID | Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Seat | Price |\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");

	// Read booked tickets from the file and display their details
	while (fread(&bookedTicket, sizeof(BookingInfo), 1, fptr) == 1) {
		sprintf(bookingID, "B%03d", bookedTicket.booking_id);
		printf("\t\t\t\t\t| %-10s | %-8s | %-16s  | %-14s  | %02d:%02d          | %02d:%02d        | %4d |%6.2lf |\n",
			bookingID, bookedTicket.train_id, bookedTicket.departure_Station, bookedTicket.arrival_Station,
			bookedTicket.departure_hour, bookedTicket.departure_minutes,
			bookedTicket.arrival_hour, bookedTicket.arrival_minutes,
			bookedTicket.seat, bookedTicket.price);
		found = 1;
	}

	printf("\t\t\t\t\t---------------------------------------------------------------------------------------------------------------\n");

	// Prompt the user to input the booking ID of the ticket they want to change
	printf("\n\t\t\t\t\tEnter the Booking ID of the ticket you want to change: ");
	scanf("%6s", keyword); // Assuming booking ID is 6 characters long

	// Search for the selected ticket in the booked tickets
	rewind(fptr); // Move file pointer to the beginning of the file
	while (fread(&bookedTicket, sizeof(BookingInfo), 1, fptr) == 1) {
		sprintf(bookingID, "B%03d", bookedTicket.booking_id);
		if (strcmp(keyword, bookingID) == 0) {
			// Ticket found, display its details
			printf("\t\t\t\t\tSelected Ticket Details:\n");
			printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t\t| Booking ID | Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Seat | Price |\n");
			printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t\t| %-10s | %-8s | %-16s  | %-14s  | %02d:%02d          | %02d:%02d        | %4d |%6.2lf |\n",
				bookingID, bookedTicket.train_id, bookedTicket.departure_Station, bookedTicket.arrival_Station,
				bookedTicket.departure_hour, bookedTicket.departure_minutes,
				bookedTicket.arrival_hour, bookedTicket.arrival_minutes,
				bookedTicket.seat, bookedTicket.price);

			// Prompt the user to select which detail they want to change
			printf("\n\t\t\t\t\tWhat detail do you want to change?\n");
			printf("\t\t\t\t\t1. Departure Station\n");
			printf("\t\t\t\t\t2. Arrival Station\n");
			printf("\t\t\t\t\t3. Departure Time\n");
			printf("\t\t\t\t\t4. Arrival Time\n");
			printf("\t\t\t\t\tEnter your choice: ");
			scanf("%d", &choice);

			// Update the selected detail based on user's choice
			switch (choice) {
			case 1:
				printf("\t\t\t\t\tEnter new departure station: ");
				scanf("%s", bookedTicket.departure_Station);
				break;
			case 2:
				printf("\t\t\t\t\tEnter new arrival station: ");
				scanf("%s", bookedTicket.arrival_Station);
				break;
			case 3:
				printf("\t\t\t\t\tEnter new departure time (HH MM): ");
				scanf("%d %d", &bookedTicket.departure_hour, &bookedTicket.departure_minutes);
				break;
			case 4:
				printf("\t\t\t\t\tEnter new arrival time (HH MM): ");
				scanf("%d %d", &bookedTicket.arrival_hour, &bookedTicket.arrival_minutes);
				break;
			default:
				printf("\t\t\t\t\tInvalid choice!\n");
				printf("\t\t\t\t\t==================================\n");
				printf("\t\t\t\t\t== Selection                    ==\n");
				printf("\t\t\t\t\t==================================\n");
				printf("\t\t\t\t\t== 1. Try again                 ==\n");
				printf("\t\t\t\t\t== 2. Exit                      ==\n");
				printf("\t\t\t\t\t==================================\n");

				printf("\n\t\t\t\t\tPlease enter your choice: ");
				scanf("%d", &a);

				while (a < 1 || a > 2) {
					clearInputBuffer();
					printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice: ");
					scanf("%d", &a);
				}

				switch (a) {
				case 1:
					system("cls");
					changeTicket(booking, &count);
					break;
				case 2:
					system("cls");
					ticketModule(booking, &count);
					break;
				default:
					printf("\t\t\t\t\t\t**Invalid Choice! Please choose again!\n\n");
					break;
				}
				break;
			}

			// Move file pointer back to update the ticket
			fseek(fptr, -(long)sizeof(BookingInfo), SEEK_CUR);

			// Write the updated ticket to the file
			fwrite(&bookedTicket, sizeof(BookingInfo), 1, fptr);

			// Display success message
			printf("\n\t\t\t\t\tTicket updated successfully!\n");

			// Display updated ticket details
			printf("\n\t\t\t\t\tUpdated Ticket Details:\n");
			printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t\t| Booking ID | Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Seat | Price |\n");
			printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
			printf("\t\t\t\t\t| %-10s | %-8s | %-16s  | %-14s  | %02d:%02d          | %02d:%02d        | %4d |%6.2lf |\n",
				bookingID, bookedTicket.train_id, bookedTicket.departure_Station, bookedTicket.arrival_Station,
				bookedTicket.departure_hour, bookedTicket.departure_minutes,
				bookedTicket.arrival_hour, bookedTicket.arrival_minutes,
				bookedTicket.seat, bookedTicket.price);

			printf("\n\t\t\t\t\t==================================\n");
			printf("\t\t\t\t\t== Selection                    ==\n");
			printf("\t\t\t\t\t==================================\n");
			printf("\t\t\t\t\t== 1. Delete Ticket             ==\n");
			printf("\t\t\t\t\t== 2. Payment Process           ==\n");
			printf("\t\t\t\t\t== 3. Exit                      ==\n");
			printf("\t\t\t\t\t==================================\n");

			printf("\n\t\t\t\t\tPlease enter your choice: ");
			scanf("%d", &a);

			while (a < 1 || a > 3) {
				clearInputBuffer();
				printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice: ");
				scanf("%d", &a);
			}

			switch (a) {
			case 1:
				system("cls");
				deleteTicket(booking, &count);
				break;
			case 2:
				system("cls");
				paymentProcess(booking, &count);
				break;
			case 3:
				system("cls");
				ticketModule(booking, &count);
				break;
			default:
				printf("\t\t\t\t\t\t**Invalid Choice! Please choose again!\n\n");
				break;
			}

			// Close the file
			fclose(fptr);

			return;
		}
	}

	// Close the file
	fclose(fptr);

	if (!found) {
		// Ticket not found or not available for change
		printf("\t\t\t\t\t\t** Error: Ticket not found or not available for change.\n");
	}
}



void deleteTicket(BookingInfo booking[], int* count) {
	FILE* fptr;
	char keyword[10], lastMemberID[20], bookingID[10]; // Increased size to accommodate the Booking ID
	int found = 0, a;
	BookingInfo bookedTicket;

	fptr = fopen("tickets.bin", "rb+");
	if (fptr == NULL) {
		printf("Error opening tickets file\n");
		return;
	}

	// Display already booked tickets
	printf("\n\n\t\t\t\t\tAlready Booked Tickets:\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t| Booking ID | Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Seat | Price |\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");

	// Read booked tickets from the file and display their details
	while (fread(&bookedTicket, sizeof(BookingInfo), 1, fptr) == 1) {
		sprintf(bookingID, "B%03d", bookedTicket.booking_id);
		printf("\t\t\t\t\t| %-10s | %-8s | %-16s  | %-14s  | %02d:%02d          | %02d:%02d        |%4d | %6.2lf |\n",
			bookingID, bookedTicket.train_id, bookedTicket.departure_Station, bookedTicket.arrival_Station,
			bookedTicket.departure_hour, bookedTicket.departure_minutes,
			bookedTicket.arrival_hour, bookedTicket.arrival_minutes,
			bookedTicket.seat, bookedTicket.price);
		found = 1;
	}

	printf("\t\t\t\t\t---------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tBooking Date:%10s\n", bookedTicket.date);


	// Prompt the user to input the details of the ticket they want to delete
	FILE* mfptr = fopen("lastMemberID.txt", "r");
	if (mfptr == NULL) {
		printf("  Error opening member file\n");
		return;
	}

	while (fgets(lastMemberID, sizeof(lastMemberID), mfptr) != NULL) {
		lastMemberID[strcspn(lastMemberID, "\n")] = 0;
	}

	printf("\t\t\t\t\tYour Member ID:%s", lastMemberID);
	printf("\n\t\t\t\t\tEnter the Booking ID of the ticket you want to delete: ");
	scanf("%6s", keyword); // Assuming train ID is 6 characters long

	// Search for the selected ticket in the booked tickets
	while (fread(&bookedTicket, sizeof(BookingInfo), 1, fptr) == 1) {
		if (strcmp(keyword, bookingID) == 0) { // Compare train IDs
			// Ticket found, mark it as available (delete it)
			bookedTicket.booking_id = '\0';  // Clear the train ID to mark it as available
			found = 1;
			break; // Exit loop after finding the ticket
		}
	}

	if (found) {
		// Ticket deleted successfully
		printf("\t\t\t\t\tTicket deleted successfully!\n");
		bookedTicket.booking_id = 0; // Assuming 0 indicates an available booking ID

		// Move file pointer back to update the ticket
		fseek(fptr, -(long)sizeof(BookingInfo), SEEK_CUR);

		// Write the updated ticket to the file
		fwrite(&bookedTicket, sizeof(BookingInfo), 1, fptr);

		printf("\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t== Selection                    ==\n");
		printf("\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t==       1.Payment Process      ==\n");
		printf("\t\t\t\t\t==       2.Exit                 ==\n");
		printf("\t\t\t\t\t==================================\n");
		printf("\n\n");
		printf("\t\t\t\t\tPlease Enter your choice:");
		scanf("%d", &a);

		while (a < 0 || a>2) {
			clearInputBuffer();
			printf("\t\t\t\t\t\t**Invalid Choice! please enter valid choice!**\n\n");
			printf("\t\t\t\t\tPlease Enter your choice:");
			scanf("%d", &a);
		}

		switch (a) {
		case 1:
			system("cls");
			paymentProcess(booking, &count);
			break;
		case 2:
			system("cls");
			ticketModule(booking, &count);
			break;
		default:
			printf("\t\t\t\t\t\t**Invalid choice! please choose again!\n\n");
			break;
		}
	}
	else {
		// Ticket not found or not available for deletion
		printf("\t\t\t\t\t\t** Error: Ticket not found or not available for deletion.\n");

		printf("\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t== Selection                    ==\n");
		printf("\t\t\t\t\t==================================\n");
		printf("\t\t\t\t\t==       1.Delete Ticket        ==\n");
		printf("\t\t\t\t\t==       2.Payment Process      ==\n");
		printf("\t\t\t\t\t==       3.Exit                 ==\n");
		printf("\t\t\t\t\t==================================\n");
		printf("\n\n");
		printf("\t\t\t\t\tPlease Enter your choice:");
		scanf("%d", &a);

		while (a < 0 || a>3) {
			clearInputBuffer();
			printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice!**\n");
			printf("\t\t\t\t\tPlease Enter your choice:");
			scanf("%d", &a);
		}

		switch (a) {
		case 1:
			system("cls");
			deleteTicket(booking, &count);
			break;
		case 2:
			system("cls");
			paymentProcess(booking, &count);
			break;
		case 3:
			system("cls");
			ticketModule(booking, &count);
			break;
		default:
			printf("\t\t\t\t\t\t**Invalid choice! please choose again!\n\n");
			break;
		}
	}
}



void paymentProcess(BookingInfo booking[], int count) {
	FILE* fptr;
	double totalPayment = 0.0;
	BookingInfo payment, bookedTicket;
	char bookingID[10];
	int found = 0, a;

	fptr = fopen("tickets.bin", "rb");

	if (fptr == NULL) {
		printf("Error open file\n");
		return;
	}

	// Display all booked tickets and calculate total payment
	printf("\n\n\t\t\t\t\tBooked Tickets:\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t| Booking ID | Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Seat | Price |\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");

	// Read booked tickets from the file and display their details
	while (fread(&bookedTicket, sizeof(BookingInfo), 1, fptr) == 1) {
		sprintf(bookingID, "B%03d", bookedTicket.booking_id);
		printf("\t\t\t\t\t| %-10s | %-8s | %-16s  | %-14s  | %02d:%02d          | %02d:%02d        |%4d | %6.2lf |\n",
			bookingID, bookedTicket.train_id, bookedTicket.departure_Station, bookedTicket.arrival_Station,
			bookedTicket.departure_hour, bookedTicket.departure_minutes,
			bookedTicket.arrival_hour, bookedTicket.arrival_minutes,
			bookedTicket.seat, bookedTicket.price);
		totalPayment += bookedTicket.price;
		found = 1;
	}

	printf("\t\t\t\t\t---------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tBooking Date:%10s\n", bookedTicket.date);


	// Display total payment to the user
	printf("\t\t\t\t\tTotal Payment: %.2lf\n", totalPayment);
	// Prompt the user to confirm the payment
	char confirm;
	printf("\t\t\t\t\tPlease enter your payment method:");
	scanf("%s", payment.pMethod);
	printf("\t\t\t\t\tConfirm payment? (Y/N): ");
	scanf(" %c", &confirm);

	if (confirm == 'Y' || confirm == 'y') {
		// Payment confirmed, proceed with payment process
		// For demonstration purposes, just display a success message
		printf("\t\t\t\t\tPayment successful!\n");

		// Update payment status of booked tickets
		// Assuming 'booking' is an array of BookingInfo structures

		printf("\n\n");
		printf("\t\t\t\t\t====================================\n");
		printf("\t\t\t\t\t== Selection                      ==\n");
		printf("\t\t\t\t\t====================================\n");
		printf("\t\t\t\t\t==       1.Display booked ticket  ==\n");
		printf("\t\t\t\t\t==       2.Exit                   ==\n");
		printf("\t\t\t\t\t====================================\n");
		printf("\n\n");
		printf("\t\t\t\t\tPlease Enter your choice:");
		scanf("%d", &a);

		while (a < 0 || a>2) {
			clearInputBuffer();
			printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice!**\n");
			printf("\t\t\t\t\tPlease Enter your choice:");
			scanf("%d", &a);
		}

		switch (a) {
		case 1:
			system("cls");
			bookedStatus(booking, &count);
			break;
		case 2:
			system("cls");
			ticketModule(booking, &count);
			break;
		default:
			printf("\t\t\t\t\t\t**Invalid choice! please choose again!\n\n");
			break;
		}

		// Write the updated booking records back to the file or database
		// This step will depend on how you store and manage your booking data
		// For example, you may need to rewrite the entire file or update specific database records

	}
	else {
		// Payment not confirmed, return to the previous menu or take appropriate action
		printf("\t\t\t\t\t\tPayment cancelled.\n");
	}

	printf("\t\t\t\t\t==================================\n");
	printf("\t\t\t\t\t== Selection                    ==\n");
	printf("\t\t\t\t\t==================================\n");
	printf("\t\t\t\t\t==       1.Payment Process      ==\n");
	printf("\t\t\t\t\t==       2.Exit                 ==\n");
	printf("\t\t\t\t\t==================================\n");
	printf("\n\n");
	printf("\t\t\t\t\tPlease Enter your choice:");
	scanf("%d", &a);

	while (a < 0 || a>2) {
		clearInputBuffer();
		printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice!**\n");
		printf("\t\t\t\t\tPlease enter your choice:");
		scanf("%d", &a);
	}

	switch (a) {
	case 1:
		system("cls");
		paymentProcess(booking, &count);
		break;
	case 2:
		system("cls");
		ticketModule(booking, &count);
		break;
	default:
		printf("\t\t\t\t\t\t**Invalid choice! please choose again!\n\n");
		break;
	}
}

void ticketStatus(BookingInfo booking[], int count) {

	int a;

	printf("\n\n\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t== Selection                              ==\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t==       1.Display Available Ticket       ==\n");
	printf("\t\t\t\t\t==       2.Booked Ticket Status           ==\n");
	printf("\t\t\t\t\t==       3.Exit                           ==\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\n\n");
	printf("\t\t\t\t\tPlease Enter your choice:");
	scanf("%d", &a);

	while (a < 0 || a>4) {
		clearInputBuffer();
		printf("\t\t\t\t\t\t**Invalid Choice! please enter valid choice!**\n\n");
		printf("\t\t\t\t\tPlease Enter your choice:");
		scanf("%d", &a);
	}

	switch (a) {
	case 1:
		system("cls");
		displayAvailableTickets(booking, &count);
		break;
	case 2:
		system("cls");
		bookedStatus(booking, &count);
		break;
	case 3:
		system("cls");
		ticketModule(booking, &count);
		break;
	default:
		printf("\t\t\t\t\t\t**Invalid choice! please choose again!\n\n");
		break;
	}
}

void displayAvailableTickets(BookingInfo booking[], int count) {
	system("cls");
	FILE* ptr;
	Train train;
	int ticketCount = 0;

	ptr = fopen("trains.bin", "rb");

	if (ptr == NULL) {
		printf("Error opening file\n\n");
		return;
	}

	printf("\n\n\t\t\t\t\t  ---------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t  |  %-5s  |  %-22s  |  %-22s  |  %-10s |  %-10s  |  %-5s  |    %-10s |\n",
		"Train ID", "Departure Station", "Arrival Station",
		"Departure Time", "Arrival Time", "Seat", "Price(RM)");
	printf("\t\t\t\t\t  ---------------------------------------------------------------------------------------------------------------------------------\n");


	while (fread(&train, sizeof(Train), 1, ptr)) {
		printf("\t\t\t\t\t  |    %-5s   |  %-22s  |  %-22s  |      %02d:%02d      |      %02d:%02d     |   %-5d |     %-10.2lf|\n",

			train.train_id, train.departure_station, train.arrival_station,
			train.departure_hour, train.departure_minutes,
			train.arrival_hour, train.arrival_minutes,
			train.seat, train.price);
		printf("\t\t\t\t\t  ---------------------------------------------------------------------------------------------------------------------------------\n");
		ticketCount++;
	}

	fclose(ptr);


	printf("\n\t\t\t\t\t  Quantity Available Tickets: %d\n", ticketCount);

	int a;
	printf("\n\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t== Selection                              ==\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t==       1.Book Ticket                    ==\n");
	printf("\t\t\t\t\t==       2.Exit                           ==\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t Please enter your choice:");
	scanf("%d", &a);

	while (a < 0 || a>2) {
		clearInputBuffer();
		printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice!**\n\n");
		printf("\t\t\t\t\tPlease enter your choice:");
		scanf("%d", &a);
	}

	switch (a) {
	case 1:
		system("cls");
		bookTicket(booking, &count);
		break;
	case 2:
		system("cls");
		ticketStatus(booking, &count);
		break;
	default:
		printf("\t\t\t\t\t\t**Invalid choice! please choose again!\n\n");
		break;
	}

}

void bookedStatus(BookingInfo booking[], int count) {
	FILE* fptr;
	BookingInfo bookedTicket;
	int a, ticketCount = 0;
	char bookingID[10];

	// Open the tickets binary file for reading
	fptr = fopen("tickets.bin", "rb");
	if (fptr == NULL) {
		printf("\n\n No Booked Tickets record!\n\n");

		printf("\t\t\t\t\t\t============================================\n");
		printf("\t\t\t\t\t\t== Selection                              ==\n");
		printf("\t\t\t\t\t\t============================================\n");
		printf("\t\t\t\t\t\t==       1.Display Available Ticket       ==\n");
		printf("\t\t\t\t\t\t==       2.Exit                           ==\n");
		printf("\t\t\t\t\t\t============================================\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t Please Enter your choice:");
		scanf("%d", &a);

		while (a < 0 || a>2) {
			clearInputBuffer();
			printf("\t\t\t\t\t\t**Invalid Choice! Please enter valid choice!**\n\n");
			printf("\t\t\t\t\tPlease enter your choice:");
			scanf("%d", &a);
		}

		switch (a) {
		case 1:
			system("cls");
			displayAvailableTickets(booking, &count);
			break;
		case 2:
			system("cls");
			ticketStatus(booking, &count);
			break;
		default:
			printf("\t\t\t\t\t\t** Invalid Choice! please choose again!\n\n");
			break;
		}

		return;
	}

	printf("\n\n\t\t\t\tBooked Tickets:\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t| Booking ID | Train ID | Departure Station | Arrival Station | Departure Time | Arrival Time | Seat | Price |\n");
	printf("\t\t\t\t\t-------------------------------------------------------------------------------------------------------------\n");

	// Read booked tickets from the file and display their details
	while (fread(&bookedTicket, sizeof(BookingInfo), 1, fptr) == 1) {
		sprintf(bookingID, "B%03d", bookedTicket.booking_id);
		printf("\t\t\t\t\t| %-10s | %-8s | %-16s  | %-14s  | %02d:%02d          | %02d:%02d        |%4d | %6.2lf |\n",
			bookingID, bookedTicket.train_id, bookedTicket.departure_Station, bookedTicket.arrival_Station,
			bookedTicket.departure_hour, bookedTicket.departure_minutes,
			bookedTicket.arrival_hour, bookedTicket.arrival_minutes,
			bookedTicket.seat, bookedTicket.price);
		ticketCount++;
	}

	printf("\t\t\t\t\t---------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t  Quantity of Booked Tickets:%d\n", ticketCount);

	// Prompt the user for further actions
	printf("\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t== Selection                              ==\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\t\t\t\t\t==       1.Payment Process                ==\n");
	printf("\t\t\t\t\t==       2.Exit                           ==\n");
	printf("\t\t\t\t\t============================================\n");
	printf("\n\n");
	printf("\t\t\t\t\t Please Enter your choice:");
	scanf("%d", &a);

	while (a < 0 || a>2) {
		clearInputBuffer();
		printf("\t\t\t\t\t\t\t**Invalid Choice! Please enter valid choice!**\n\n");
		printf("\t\t\t\t\t\tPlease Enter your choice:");
		scanf("%d", &a);
	}

	switch (a) {
	case 1:
		system("cls");
		paymentProcess(booking, &count);
		break;
	case 2:
		system("cls");
		ticketStatus(booking, &count);
		break;
	default:
		printf("\t\t\t\t\t\t**Invalid choice! please choose again!\n\n");
		break;
	}

	// Close the file
	fclose(fptr);
}


