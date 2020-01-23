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
