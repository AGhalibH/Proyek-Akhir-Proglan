#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define ARRMAX 100

int kotak[100]={0};
int arr[ARRMAX] = {0};
int sizemax=0;
int n=9;
int i, c, dadu, strip, jumlah=0, turn, score_dadu=0, choice, dchoice, dc, highscore1, highscore2, highscore3, temp1, temp2, temp3;
char answer;
char name[100];

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;

void display() {
   struct node *ptr = head;

   //printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {
      //printf("%d\n",ptr->data);
      arr[sizemax] = ptr->data;
      sizemax++;
      ptr = ptr->next;
   }
   
   //printf(" [null]\n");
}

//MATERI LINKED LIST
void push(int highscore)
{
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = highscore;
   if(head == NULL)
      newNode->next = NULL;
   else
      newNode->next = head;
   head = newNode;
   //printf("\nInsertion is Success!!! %d has been push\n", value);
}

//MATERI POINTER
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] < arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void printArr(int arr[], int size) 
{ 
	int i; 
	for (i=0; i<size; i++)
    {
        printf("\t%d\n", arr[i]); 
	}
}

void logo() {
    FILE *ptr_file;
    char buf[1000];
    ptr_file =fopen("Judul.txt","r");
    if (!ptr_file)
	{
    	printf("error");
	}
    while (fgets(buf,1000, ptr_file)!=NULL)
	{
        printf("%s",buf);
	}
	fclose(ptr_file);
}

void mainmenu() {
	fullscreen();
	logo();
	printf("\n\n\n\n");
	printf("	---------------------------\n");
	printf("	1. Start Game\n");
	printf("	2. Leaderboard\n");
	printf("	3. Help\n");
	printf("	4. Exit\n");
	printf("	---------------------------\n");
	printf("	Select the number of menu : ");
	inputmenu(choice);
}

int inputmenu(int choice) {
	scanf("%d", &choice);
	if(choice==1){
		system("CLS");
		difficulty();
	} else if(choice==2) {
		system("CLS");
		leaderboard();
	} else if(choice==3) {
		system("CLS");
		help();
	} else if(choice==4) {
		close();
	} else {
		printf("\n	Masukkan input lain!\n\n	");
		system("pause");
		system("cls");
		while( ( choice = getchar() ) != '\n' && choice != EOF );
		fullscreen();
		mainmenu();
	}
}

int leaderboard() {
	logo();
	printf("\n\n\n\n");
	printf("	---------LEADERBOARD-------\n");
	printf("	---------------------------\n");
	printf("	1. Highscore Easy\n");
	printf("	2. Highscore Normal\n");
	printf("	3. Highscore Hard\n");
	printf("	---------------------------\n");
	printf("	Select tab highscore : ");
	inputleaderboard();	
}

int inputleaderboard(int lc){
	scanf("%d", &lc);
	if(lc==1){
		system("CLS");
		logo();
		printf("\n\n\n\n");
		printf("	---------LEADERBOARD-------\n");
		printf("	------------EASY-----------\n");
		//push(highscore1);
		printf("	 %s	 ", name);
		display();
		bubbleSort(arr, sizemax);
		printArr(arr,sizemax);
		getch();
		system("cls");
		fullscreen();
		mainmenu();
	} else if(lc==2) {
		system("CLS");
		logo();
		printf("\n\n\n\n");
		printf("	---------LEADERBOARD-------\n");
		printf("	-----------NORMAL----------\n");
		//push(highscore2);
		display();
		bubbleSort(arr, sizemax);
		printArr(arr,sizemax);
		getch();
		system("cls");
		fullscreen();
		mainmenu();
	} else if(lc==3) {
		system("CLS");
		logo();
		printf("\n\n\n\n");
		printf("	---------LEADERBOARD-------\n");
		printf("	------------HARD-----------\n");
		//push(highscore3);
		display();
		bubbleSort(arr, sizemax);
		printArr(arr,sizemax);
		getch();
		system("cls");
		fullscreen();
		mainmenu();
	} else {
		printf("\n	Masukkan input lain!\n\n	");
		system("pause");
		system("cls");
		while( ( choice = getchar() ) != '\n' && choice != EOF );
		fullscreen();
		leaderboard();
	}
}

int help(){
	system("cls");
	logo();
	printf("\n\n\n\n");
	printf("				SNAKE AND LADDERS GAME RULES\n");
	printf("	--------------------------------------------------------------------\n");
	printf("	* Game terdiri dari 100 kotak (10x10)\n");
	printf("	* Start pion dimulai dari angka 1 dan berakhir di angka 100\n");
	printf("	* Terdapat 1 buah dadu dengan 6 mata dadu\n");
	printf("	* Terdapat jumlah Turn dengan tingkat kesulitan yang berbeda (Easy, Normal, Hard)\n");
	printf("	* Pemain hanya perlu menekan tombol keyboard untuk mengocok dadu\n");
	printf("	* Setiap mengocok dadu akan mengurangi jumlah Turn\n");
	printf("	* Pemain akan menang jika pion berhasil berada dikotak ke 100 dengan jumlah Turn > 0\n");
	printf("	* Pemain akan kalah jika kehabisan jumlah Turn dan pion belum berada di kotak ke 100\n");
	printf("	* Terdapat Highscore pada Leaderboard jika pemain menang\n");
	printf("	* Jumlah highscore bergantung pada sisa jumlah turn dikali dengan bobot difficultynya\n");
	printf("	* Easy = turn*50 ; Normal = turn*150 ; Hard = turn*450\n\n");
    printf("	Press any key to go back to the main menu...");
    getch();
    system("cls");
    fullscreen();
    mainmenu();	
}

int close(){
	system("CLS");
	int i=0;
	for(i=0;i<=10;i++){
		printf("\n");
	}
	printf("					Good Bye\n");
	Sleep(1000);
	system("cls");
	exit(0);	
}

int welcome(){
	int i=0;
	for(i=0;i<=10;i++){
		printf("\n");
	}
	printf("					WELCOME");
	Sleep(1000);
	system("CLS");

	mainmenu();
}

int difficulty(int dchoice) {
	logo();
	printf("\n\n\n\n");
	printf("	---------------------------\n");
	printf("	Difficulty :\n");
	printf("	1. Easy   (Turn = 90)\n");
	printf("	2. Normal (Turn = 60)\n");
	printf("	3. Hard   (Turn = 30)\n");
	printf("	---------------------------\n");
	printf("	Select Difficulty : ");
	scanf("%d", &dchoice);
	if(dchoice==1) {
		turn = 90;
		dc = 1;
	} else if(dchoice==2) {
		turn = 60;
		dc = 2;
	} else if(dchoice==3) {
		turn = 30;
		dc = 3;
	}
	system("cls");
	game();
}

void clrscr(){
    system("@cls||clear");
}

int fullscreen(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void display_notes(){
	printf("\t   CATATAN :\n");
	printf("\t	Tangga (Naik ke) :     | Ular (Turun ke) :\n");
	printf("\t	   1 => 38   28 => 76  | 32 => 10   88 => 24\n");
	printf("\t	   4 => 14   50 => 67  | 36 => 6    \n");
	printf("\t	   8 => 30   71 => 92  | 48 => 26   \n");
	printf("\t	  21 => 42   80 => 99  | 62 => 18\n");
}

void submit(){
	printf("\t   Submit Nama\t= ");
	scanf(" %[^\n]s", &name);
}

void display_winsolution(){
	printf("\t\t      +-----------------+\n");
	printf("\t\t      | !!! YOU WIN !!! |\n");
	printf("\t\t      +-----------------+\n\n");
	if(dc == 1) {
		highscore1 = turn*50;
		temp1 = highscore1;
		push(highscore1);
		printf("\t   Highscore\t= %d\n", highscore1);
		submit();
	} else if(dc == 2) {
		highscore2 = turn*150;
		temp2 = highscore2;
		push(highscore1);
		printf("\t   Highscore\t= %d\n", highscore2);
		submit();
	} else if(dc == 3) {
		highscore3 = turn*450;
		temp3 = highscore3;
		push(highscore1);
		printf("\t   Highscore\t= %d\n", highscore3);
		submit();
	}
	display_choice();
}

void display_losesolution(){
	printf("\t\t      +------------------+\n");
	printf("\t\t      |     YOU LOSE     |\n");
	printf("\t\t      |  YOUR TURN IS 0  |\n");
	printf("\t\t      +------------------+\n");
	display_choice();
}

int display_choice(){
	while(1){
		getch();
		system("cls");
		logo();
		printf("\n\t   You want try this game again (Y/N) = ");
		char answer = getche();
		if(answer == 'y' || answer == 'Y'){
			kotak[jumlah-1]=0;
       		score_dadu=jumlah=0;
       		if(dc==1){
       			turn=90;
			} else if(dc==2){
				turn=60;
			} else if(dc==3){
				turn=30;
			}
       		system("cls");
       		fullscreen();
           	mainmenu();
		} else if(answer == 'n' || answer == 'N'){
			system("cls");
       		fullscreen();
           	mainmenu();
		}
	}
}


void display_game(int kotak[100]){
	int i;
	printf("\n\t");
	printf("   -----------------------------------------\n\t100");
	for(i=99; i>=90; i--){
		printf("| %d ", kotak[i]);
	} printf("|91\n\t");
	printf("   -----------------------------------------\n\t 81");
	for(i=80; i<=89; i++){
		printf("| %d ", kotak[i]);
	} printf("|90\n\t");
	printf("   -----------------------------------------\n\t 80");
	for(i=79; i>=70; i--){
		printf("| %d ", kotak[i]);
	} printf("|71\n\t");
	printf("   -----------------------------------------\n\t 61");
	for(i=60; i<=69; i++){
		printf("| %d ", kotak[i]);
	} printf("|70\n\t");
	printf("   -----------------------------------------\n\t 60");
	for(i=59; i>=50; i--){
		printf("| %d ", kotak[i]);
	} printf("|51\n\t");
	printf("   -----------------------------------------\n\t 41");
	for(i=40; i<=49; i++){
		printf("| %d ", kotak[i]);
	} printf("|50\n\t");
	printf("   -----------------------------------------\n\t 40");
	for(i=39; i>=30; i--){
		printf("| %d ", kotak[i]);
	} printf("|31\n\t");
	printf("   -----------------------------------------\n\t 21");
	for(i=20; i<=29; i++){
		printf("| %d ", kotak[i]);
	} printf("|30\n\t");
	printf("   -----------------------------------------\n\t 20");
	for(i=19; i>=10; i--){
		printf("| %d ", kotak[i]);
	} printf("|11\n\t");
	printf("   -----------------------------------------\n\t  1");
	for(i=0; i<=9; i++){
		printf("| %d ", kotak[i]);
	} printf("|10\n\t");
	printf("   -----------------------------------------\n\t");
	printf("   ==^==\n\t   START\n\n");
}

void resultwin(){
	system("cls");
	logo();
	display_game(kotak);
	display_winsolution();
}

void resultlose(){
	system("cls");
	logo();
	display_game(kotak);
	display_losesolution();
}

int game() {
	while(jumlah != 100)
	{
		logo();
		time_t t;
		srand((unsigned) time(&t));
		display_game(kotak);
		display_notes();
		printf("\n\t   Posisi Pion = [%d] | Turn = [%d] | Difficulty = [%d]\n", jumlah, turn, dc);
		printf("\n\t   [Tekan tombol keyboard untuk mengocok dadu]\n");
		kotak[jumlah-1]=0; 
		//system("pause");
		getch();
		dadu=(rand()%6+1);
		jumlah+=dadu;
		score_dadu+=dadu;
		turn-=1;
		printf("\n\t   Dadu = [%d]\n", dadu);
		if(jumlah>100){
			jumlah=100-(jumlah-100);
		}
		
		//Rules Tangga
		if(jumlah==1){jumlah=38;}
		if(jumlah==4){jumlah=14;}
		if(jumlah==8){jumlah=30;}
		if(jumlah==21){jumlah=42;}
		if(jumlah==28){jumlah=76;}
		if(jumlah==50){jumlah=67;}
		if(jumlah==71){jumlah=92;}
		if(jumlah==80){jumlah=99;}
		//Rules Ular
		if(jumlah==32){jumlah=10;}
		if(jumlah==36){jumlah=6;}
		if(jumlah==48){jumlah=26;}
		if(jumlah==62){jumlah=18;}
		if(jumlah==88){jumlah=24;}
		//if(jumlah==95){jumlah=56;}
		//if(jumlah==97){jumlah=78;}
			
		//system("pause");
		getch();
		system("cls");
		kotak[jumlah-1]=1;
		if(turn==0){
			resultlose();
			return 0;
		}
		if(kotak[100-1]==1 || turn==0){
			resultwin();
		}
	}
}

int main() {
	system("color 02");
	welcome();
	mainmenu();
	return 0;
}
