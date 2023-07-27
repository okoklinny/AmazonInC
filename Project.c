//ID:99691
#include <stdio.h>
#include <string.h>
#define book 200
#define skincare 700
#define watch 1000
#define desk 4000
#define laptop 6000
int signup(int N, int C, char user[N][C]);
int login(int N, int C, char user[N][C]);
int main()
{
	int N = 3, C = 200;
	int choice;
	char user[N][C];
	printf("\n**********************************************");
	printf("\n                   AMAZON                    ");
	printf("\n**********************************************");
	printf("\n1.LOGIN");
	printf("\n2.SIGN UP");
	printf("\n**********************************************");
	printf("\nPlease enter your option< 1 / 2 >:\n");
	scanf("%d", &choice);
	if (choice == 1)
	{
		login(N, C, user);
	}
	else
	{
		N = N + 1;
		signup(N, C, user);
	}
	return 0;
}

int login(int N, int C, char user[N][C])
{
	int i, a, j, result1, result2, result3, c, x, ch = 1, choice, v, quantity, count = 0, w = 0, res = 1;
	double sum = 0, total;
	int n, an = 1;
	char ans[200];
	char email[N][100], fname[N][100], lname[N][100], pw[N][100], baccount[N][100], balance[N][100], question[N][100], answer[N][100], e[200], fn[200], ln[200], p[200], ba[200], blnc[200], q[200], answr[200];
	FILE *input, *out;

	input = fopen("database.txt", "r");
	out = fopen("output.txt", "w");
	for (i = 0; i < 3; i++)
	{
		fgets(user[i], 200, input);
	}

	for (i = 0; i < N; i++)
	{
		sscanf(user[i], "%s %s %s %s %s %s %s %s", email[i], fname[i], lname[i], pw[i], baccount[i], balance[i], question[i], answer[i]);
	}
	fclose(input);
	printf("\nplease enter your email: \n");
	scanf("%s", e);
	for (i = 0; i < N; i++)
	{
		result1 = strcmp(e, email[i]);
		if (result1 == 0)
		{
			printf("please enter your password \n");
			scanf("%s", p);
			result2 = strcmp(p, pw[i]);
			a = strlen(p);
			if (result2 == 0)
			{
				printf("you logged in successfully!\n");
				v = i;
			}
			else
			{
				printf("WRONG PASSWORD\n");
				for (j = 0; j < a; j++)
				{
					if (p[j] == p[j + 1])
					{
						printf("\n %s \n", question[i]);
						scanf("%s", ans);
						result3 = strcmp(ans, answer[i]);
						if (result3 == 0)
						{
							printf("you logged in successfully!\n");
							v = i;
						}
						else
						{
							c = 0;
						}
						break;
					}
				}
			}
		}
		else
		{
			c = 0;
		}
	}
	while (res == 1)
	{
		if (c = !0)
		{
			sscanf(balance[v], "%d", &x);
			printf("Welcome!\n");
			printf("1-Change Information\n2-Make Order\n3-Logout\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("please enter your password \n");
				scanf("%s", p);
				for (i = 0; i < N; i++)
				{
					result2 = strcmp(p, pw[i]);
					if (result2 == 0)
					{
						break;
					}
				}
				if (result2 == 0)
				{
					printf("What do you want to change?\n1-Email\n2-First Name\n3-Last Name\n4-Password\n5-Bank Account\n6-Balance\n7-Question\n8-Answer\n");
					scanf("%d", &ch);
					if (ch == 1)
					{
						printf("\nplease enter an email:");
						scanf("%s", e);
						sprintf(email[v], "%s", e);
					}
					else if (ch == 2)
					{
						printf("\nplease enter first name:");
						scanf("%s", fn);
						sprintf(fname[v], "%s", fn);
					}
					else if (ch == 3)
					{
						printf("\nplease enter last name:");
						scanf("%s", ln);
						sprintf(lname[v], "%s", ln);
					}
					else if (ch == 4)
					{
						printf("\nplease enter password:");
						scanf("%s", p);
						sprintf(pw[v], "%s", p);
					}
					else if (ch == 5)
					{
						printf("\nplease enter bank account:");
						scanf("%s", ba);
						sprintf(baccount[v], "%s", ba);
					}
					else if (ch == 6)
					{
						printf("\nplease enter balance:");
						scanf("%s", blnc);
						sprintf(balance[v], "%s", blnc);
					}
					else if (ch == 7)
					{
						printf("\nplease enter question:");
						scanf("%s", q);
						sprintf(question[v], "%s", q);
					}
					else
					{
						printf("\nplease enter an answer:");
						scanf("%s", answr);
						sprintf(answer[v], "%s", answr);
					}
				}
				else
				{
					printf("WRONG PASSWORD!");
				}
			}
			else if (choice == 2)
			{
				printf("\nthe balance is %d \n", x);
				while (sum < x && an == 1)
				{
					printf("please choose an item:\n1-Book\n2-Skin Care\n2-Watch\n3-Desk\n4-Laptop\n");
					scanf("%d", &choice);
					if (choice == 1)
					{
						printf("please enter quantity:\n");
						scanf("%d", &quantity);
						sum = sum + (quantity * book);
					}
					else if (choice == 2)
					{
						printf("please enter quantity:\n");
						scanf("%d", &quantity);
						sum = sum + (quantity * skincare);
					}
					else if (choice == 3)
					{
						printf("please enter quantity:\n");
						scanf("%d", &quantity);
						sum = sum + (quantity * watch);
					}
					else if (choice == 4)
					{
						printf("please enter quantity:");
						scanf("%d", &quantity);
						sum = sum + (quantity * desk);
					}
					else
					{
						printf("please enter quantity:\n");
						scanf("%d", &quantity);
						sum = sum + (quantity * laptop);
					}
					if (sum > x)
					{
						printf("balance insufficient \nEnter a new bank account:\n");
						scanf("%s", baccount[v]);
						printf("enter balance:\n");
						scanf("%d", &x);
						while (count < 3){
							if (sum > x){
								printf("BALANCE INSUFFICIENT\n");
								printf("please enter a new bank account\n");
								scanf("%s", baccount[v]);
								printf("please enter balance:\n");
								scanf("%d", &x);
								count++;
								sprintf(balance[v], "%d", x);
							}
							else{
								x = x - sum;
								sprintf(balance[v], "%d", x);
								printf("\n NEW BANK ACCOUNT APPROVED \n");
								printf("do you want to keep purchasing?\n1-Yes\n2-No\n");
								scanf("%d", &an);
								if (an == 1)
								{
									n = 1;
								}
								else
								{
									printf("The total is:%f\n", sum);
									printf("Your new balance is %s \n", balance[v]);
									c = 1;
									break;
								}
							}
							if (count == 2)
							{
								printf("Your order have been dropped!");
								break;
							}
						}
					}
					else
					{
						printf("do you want to keep purchasing?\n1-Yes\n2-No\n");
						scanf("%d", &an);
						if (an == 1)
						{
							n = 1;
						}
						else
						{
							x = x - sum;
							sprintf(balance[v], "%d", x);
							printf("The total is:%f\n", sum);
							printf("Your new balance is %s \n", balance[v]);
							c = 1;
							break;
						}
					}
				}
			}
			else if (choice == 3)
			{
			    for (i = 0; i < N; i++){
					if (i == v)
					{
						sprintf(user[v], "%s %s %s %s %s %s %s %s", email[v], fname[v], lname[v], pw[v], baccount[v], balance[v], question[v], answer[v]);
					}
					fprintf(out, "%s\n", user[i]);
				}
				break;
			}
			printf("do you want to do something else?\n1-Yes\n2-No\n");
			scanf("%d", &res);
			if (res == 2)
			{
				for (i = 0; i < N; i++)
				{
					if (i == v)
					{
						sprintf(user[v], "%s %s %s %s %s %s %s %s", email[v], fname[v], lname[v], pw[v], baccount[v], balance[v], question[v], answer[v]);
					}
					fprintf(out, "%s\n", user[i]);
				}
			}
		}
		else
		{
			printf("WRONG PASSWORD!\nDo you want to sign up?\n1-Yes\n2-No\n");
			scanf("%d", &ch);
			if (ch == 1)
			{
				signup(N, C, user);
			}
			else
			{
				fclose(out);
				break;
			}
		}
	}
	fclose(out);
}

int signup(int N,int C,char user[N][C]){
	int i,a,j,result1,result2,result3,c;
	char ans[200];
	char email[N][100],fname[N][100],lname[N][100],pw[N][100],baccount[N][100],balance[N][100],question[N][100],answer[N][100],e[200],p[200];
	FILE *input;
    input=fopen("database.txt","r");
    for(i=0;i<3;i++){
	  fgets(user[i],200,input);
    }
	for(i=0;i<3;i++){
		sscanf(user[i],"%s %s %s %s %s %s %s %s",email[i],fname[i],lname[i],pw[i],baccount[i],balance[i],question[i],answer[i]);
    }
    fclose(input);
	for(i=0;i<N-2;i++){
		printf("\nplease enter an email:");
		scanf("%s",email[N-1]);
		printf("\nplease enter first name:");
		scanf("%s",fname[N-1]);
		printf("\nplease enter last name:");
		scanf("%s",lname[N-1]);
		printf("\nplease enter password:");
		scanf("%s",pw[N-1]);
		printf("\nplease enter bank account:");
		scanf("%s",baccount[N-1]);
		printf("\nplease enter balance:");
		scanf("%s",balance[N-1]);
		printf("\nplease enter question:");
		scanf("%s",question[N-1]);
		printf("\nplease enter an answer:");
		scanf("%s",answer[N-1]);
		result1=strcmp(email[i],email[N-1]);
		result2=strcmp(baccount[i],baccount[N-1]);
	   	if(result1==0 || result2==0){
		    printf("\nACCOUNT ALREADY EXISTS");
		    if(result1==0){
		    	while(result1==0){
			   		printf("Enter new email:\n");
		       		scanf("%s",email[N-1]);
		   	   		result1=strcmp(email[i],email[N-1]);
				}
		    }
			if(result2==0){
		    	while(result1==0){
			   		printf("Enter new bank account:\n");
		       		scanf("%s",baccount[N-1]);
		   	   		result2=strcmp(baccount[i],baccount[N-1]);
				}
		    }
		}
	   	else{
		   sprintf(user[N-1], "%s %s %s %s %s %s %s %s",email[N-1],fname[N-1],lname[N-1],pw[N-1],baccount[N-1],balance[N-1],question[N-1],answer[N-1]);
		   login(N,C,user);
		   break;
	   	}
	}	
} 