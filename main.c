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
