#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define numSalon 4
#define numFilms 4
#define numChairs 50

typedef struct Film
{
    char *filmName;
    float length;
    char *actors;
    char *summary;
} Film;

typedef struct Sanse
{
    int numSanse;
    Film film;
    char *salonNameOwner;
    int day;
    float startTime;
    float endTime;
    int chair[10][5];
    int assigned;
} Sanse;

typedef struct Salon
{
    char *name;
    Sanse sanse[8];
    int numChair;
} Salon;
void fileReader(Salon x[],int n)
{
    int i,j;
    FILE *p;
    p=fopen("Salon.txt","r");
    for(i=0;i<n;i++)
    {
        fscanf(p,"%p",&x[i].name);
        for(j=0;j<8;j++)
        {
            fscanf(p,"%d",&x[i].sanse[j].numSanse);
            fscanf(p,"%p",&x[i].sanse[j].salonNameOwner);
            fscanf(p,"%d",&x[i].sanse[j].day);
            fscanf(p,"%f",&x[i].sanse[j].startTime);
            fscanf(p,"%f",&x[i].sanse[j].endTime);
            fscanf(p,"%d",&x[i].sanse[j].assigned);
            fscanf(p,"%p",&x[i].sanse[j].film.filmName);
            fscanf(p,"%f",&x[i].sanse[j].film.length);
            fscanf(p,"%p",&x[i].sanse[j].film.actors);
            fscanf(p,"%p",&x[i].sanse[j].film.summary);
            int k=0;
            for(k=0;k<10;k++)
            {
                int l;
                for(l=0;l<5;l++)
                    fscanf(p,"%d",&x[i].sanse[j].chair[k][l]);
            }
        }
        fscanf(p,"%p",&x[i].numChair);
    }
    fclose(p);
}
void fileWriter (Salon x[],int n)
{
    int i,j;
    FILE *p;
    p=fopen("Salon.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(p,"%p ",x[i].name);
        for(j=0;j<8;j++)
        {
            fprintf(p,"%d ",x[i].sanse[j].numSanse);
            fprintf(p,"%p ",x[i].sanse[j].salonNameOwner);
            fprintf(p,"%d ",x[i].sanse[j].day);
            fprintf(p,"%f ",x[i].sanse[j].startTime);
            fprintf(p,"%f ",x[i].sanse[j].endTime);
            fprintf(p,"%d ",x[i].sanse[j].assigned);
            fprintf(p,"%p ",x[i].sanse[j].film.filmName);
            fprintf(p,"%f ",x[i].sanse[j].film.length);
            fprintf(p,"%p ",x[i].sanse[j].film.actors);
            fprintf(p,"%p ",x[i].sanse[j].film.summary);
            int k=0;
            for(k=0;k<10;k++)
            {
                int l;
                for(l=0;l<5;l++)
                    fprintf(p,"%d ",x[i].sanse[j].chair[k][l]);
            }
        }
        fprintf(p,"%p ",x[i].numChair);
    }
    fclose(p);
}
Film addFilm(char *name, float length, char *actors, char *summary)
{
    Film film;
    film.filmName = name;
    film.length = length;
    film.actors = actors;
    film.summary = summary;
    return film;
}

Sanse sanseCreator(int numSanse, char *salonNameOwner, int startTime, int day)
{
    Sanse sanse;
    sanse.numSanse = numSanse;
    sanse.salonNameOwner = salonNameOwner;
    sanse.startTime = startTime;
    sanse.day = day;
    return sanse;
}

int emptyChirs(int chairs[10][5])
{
    int i, j, count;
    count = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (chairs[i][j] == 0)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{

    int salonChoice[32];
    int sanseChoice[32];
    int k = 0;
    int i, j, u;
    int userChoice, radif, sandali, filmNum;
    int shomareSalon, shomareSanse;
    int adminChoice;
    int adminFilmName;
    int adminSanseChoice;

    Salon salons[numSalon];
    fileReader(salons,numSalon);
    Film films[numFilms];

    films[0] = addFilm("Jodai", 1.45, "Shahab Hoseini, Peyman Moadi, Leila Hatami", "dastan Jodai Nader az simin mibahsad va etefaghati ke dar in borhe az zenfegi anan rokh midahad!...");
    films[1] = addFilm("Darbareh Eli", 1.35, "Shahab Hoseini, Peyman Moadi, Golshifteh Farahani", "khanevadehai az tabagheh motavaset ke ham daneshgahie sabegh hastand be shmal safar mikonand va etefaghati dar jarian in safar baraye anan rokh midahad...");
    films[2] = addFilm("Abad va yek Ruz", 1.48, "Navid Moahammadzadeh, Peyman Moadi, PArinaz Izadyar", "Faghr va Etiad va khanevadei ke dargire in sakhgtar az zengei hastand...");
    films[3] = addFilm("Gav", 1.30, "Ezat Entezami, Ali Nasirian", "dastan jonun, gham, faghr, delbastegi ...");

    salons[0].name = "taranhe";
    salons[1].name = "saghar";
    salons[2].name = "maryam";
    salons[3].name = "sonbol";

    salons[0].numChair = numChairs;
    salons[1].numChair = numChairs;
    salons[2].numChair = numChairs;
    salons[3].numChair = numChairs;
    int dy;
    for (i = 0; i < numSalon; i++)
    {
        for (dy = 1; dy < 4; dy++)
        {
            for (j = 0; j < 8; j++)
            {
                float strTime = 8.00 + 2.00 * j;
                salons[i].sanse[j] = sanseCreator(j, salons[i].name, strTime, dy);
            }
        }
    }

    for (i = 0; i < numSalon; i++)
    {
        for (j = 0; j < 8; j++)
        {
            memset(salons[i].sanse[j].chair, 0, sizeof(salons[i].sanse[j].chair[0][0]) * 10 * 5);
        }
    }

    int option;
    printf("\n\t-----------------------------------------");
    printf("\n\t*** Welcome to Movie Ticketing System ***\n");
    printf("\t-----------------------------------------\n");

    do
    {
        time_t rawtime = time(NULL);
        if (rawtime == -1)
        {

            puts("The time() function failed");
            return 1;
        }

        struct tm *ptm = localtime(&rawtime);

        if (ptm == NULL)
        {

            puts("The localtime() function failed");
            return 1;
        }
        printf("\n\n\t\t----<Main Menu>----\n");
        printf("\n\t 1. User options\n");
        printf("\n\t 2. Admin options\n");
        printf("\n\t 3. Quit\n");
        printf("\n\tWhat is your option (1-3)? ");
        scanf("%d", &option);
        switch (option)
        {
            // User Functionality
            case 1:

                //		printf("Enter the name of film:\n1.%s\n2.%s\n3.%s\n4.%s", );
                for (i = 0; i < numFilms; i++)
                {
                    printf("%d. '%s''-----'summary': %s----'actors': %s----'length': %f\n", i + 1, films[i].filmName, films[i].summary, films[i].actors, films[i].length);
                }
                printf("\nWhat is your option (1-4)? ");
                scanf("%d", &filmNum);

                printf("\nAll sanse for %s :\n", films[filmNum - 1].filmName);

                k = 0;
                for (i = 0; i < numSalon; i++)
                {
                    for (j = 0; j < 8; j++)
                    {

                        if (salons[i].sanse[j].film.filmName == films[filmNum - 1].filmName && salons[i].sanse[j].startTime > ptm->tm_hour && salons[i].sanse[j].assigned == 1)
                        {
                            printf("%d. %s in salon %s in sanse %d in starttime %f with length %f empty chairs: %d\n", k + 1, films[filmNum - 1].filmName, salons[i].name, salons[i].sanse[j].numSanse, salons[i].sanse[j].startTime, films[filmNum - 1].length, emptyChirs(salons[i].sanse[j].chair));
                            salonChoice[k] = i;
                            sanseChoice[k] = j;
                            k++;
                        }
                    }
                }

                // for (i = 0 ; i < nu)
                if (k != 0)
                {
                    printf("\nWhat is your option ? ");
                    scanf("%d", &userChoice);
                    shomareSalon = salonChoice[userChoice - 1];
                    shomareSanse = sanseChoice[userChoice - 1];
                    printf("empty chairs:\n");

                    for (i = 0; i < 10; i++)
                    {
                        for (j = 0; j < 5; j++)
                        {

                            if (salons[shomareSalon].sanse[shomareSanse].chair[i][j] == 0)
                            {

                                printf("radif: %d sandali: %d\t", i + 1, j + 1);
                            }
                        }
                    }

                    printf("\nEnter Radif: ");
                    scanf("%d", &radif);
                    printf("Enter Sandali: ");
                    scanf("%d", &sandali);
                    if (salons[shomareSalon].sanse[shomareSanse].chair[radif - 1][sandali - 1] == 1)
                    {
                        printf("\nthis sandali reserved!\n");
                    }
                    else
                    {
                        salons[shomareSalon].sanse[shomareSanse].chair[radif - 1][sandali - 1] = 1;
                        printf("\nsuccessful!\n");
                    }
                }
                else
                {
                    printf("\n\n !!!!!! There is no sanse for your film from now! :((");
                }

                break;

            case 2:

                do
                {
                    printf("\n\n\t\t----<Admin Menu>----\n");
                    printf("\n\t 1. Add Film Sans");
                    printf("\n\t 2. Remove Film Sans");
                    printf("\n\t 3. Quit\n");
                    printf("\n\tWhat is your option (1-3)? ");
                    scanf("%d", &adminChoice);

                    switch (adminChoice)
                    {
                        case 1:
                            k = 0;
                            for (i = 0; i < numSalon; i++)
                            {
                                for (j = 0; j < 8; j++)
                                {

                                    if (salons[i].sanse[j].assigned != 1)
                                    {
                                        printf("%d. in salon %s sanse %d is empty\n", k + 1, salons[i].name, salons[i].sanse[j].numSanse + 1);
                                        salonChoice[k] = i;
                                        sanseChoice[k] = j;
                                        k++;
                                    }
                                }
                            }

                            printf("Enter your Sanse Choice:\n");
                            scanf("%d", &adminSanseChoice);
                            printf("Enter your film:\n1. %s, 2. %s, 3. %s , 4. %s (Enter a Number between 1 - 4)?\n", films[0].filmName, films[1].filmName, films[2].filmName, films[3].filmName);
                            scanf("%d", &adminFilmName);
                            shomareSalon = salonChoice[adminSanseChoice - 1];
                            shomareSanse = sanseChoice[adminSanseChoice - 1];

                            salons[shomareSalon].sanse[shomareSanse].film = films[adminFilmName - 1];
                            salons[shomareSalon].sanse[shomareSanse].assigned = 1;

                            break;

                        case 2:

                            printf("\t\n\n--------------All sanse-------------------\n");
                            k = 0;
                            for (i = 0; i < numSalon; i++)
                            {
                                for (j = 0; j < 8; j++)
                                {

                                    if (salons[i].sanse[j].assigned == 1)
                                    {
                                        printf("%d. in salon %s sanse %d film %s\n", k + 1, salons[i].name, salons[i].sanse[j].numSanse + 1, salons[i].sanse[j].film.filmName);
                                        salonChoice[k] = i;
                                        sanseChoice[k] = j;
                                        k++;
                                    }
                                }
                            }

                            printf("Enter your Sanse Choice:\n");
                            scanf("%d", &adminSanseChoice);
                            shomareSalon = salonChoice[adminSanseChoice - 1];
                            shomareSanse = sanseChoice[adminSanseChoice - 1];

                            salons[shomareSalon].sanse[shomareSanse].assigned = 0;

                            break;
                    }
                } while (adminChoice != 3);

                break;
        }

    } while (option != 3);
    fileWriter (salons,numSalon);
    return 0;
}