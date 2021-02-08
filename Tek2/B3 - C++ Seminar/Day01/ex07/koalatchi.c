/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD01-pierre.jeannin
** File description:
** koalatchi
*/

#include <stdlib.h>
#include <stdio.h>

void get_octets(uint32_t header, unsigned char octets[4])
{
    octets[0] = header >> 0;
    octets[1] = header >> 8;
    octets[2] = header >> 16;
    octets[3] = header >> 24;
}

void display(unsigned char *octets, char *type[4], char *domain[4],
char *mess[4][4][3], const char *content)
{
    if ((octets[3] == 1 || octets[3] == 2 || octets[3] == 4) && (octets[2] == 1
    || octets[2] == 2 || octets[2] == 4) && ((int)(octets[0] + (octets[1] <<
    8)) == 1 || (int)(octets[0] + (octets[1] << 8)) == 2 || (int)(octets[0]
    + (octets[1] << 8)) == 3)) {
        printf("%s %s %s", type[octets[3] - 1],
        domain[octets[2] - 1], mess[octets[2] - 1][octets[3] - 1][((octets[0]
        + (octets[1] << 8))) - 1]);
        if (content)
            printf(" %s\n", content);
        else
            printf("\n");
    } else
        printf("Invalid message.\n");
}

int prettyprint_message(uint32_t header , const char *content)
{
    char *type[4] = { "Notification" , "Request", "" , "Error" };
    char *domain[4] = { "Nutrition" , "Entertainment" , "" , "Education" };
    char *message[4][4][3] = { { { "Eat", "Defecate",  "" } ,
    {"Hungry" , "Thirsty" , ""} , { } , { "Indigestion", "Starving" , "" } } ,
    { {"Ball", "Bite", "" } , { "NeedAffection", "WannaPlay" , "Hug" } , { } ,
    { "Bored", "", ""} } , { } , { { "TeachCoding" , "BeAwesome" , "" } , {
    "FeelStupid" , "" , "" } , { } , { "BrainDamage" , "" , "" } } };
    unsigned char octets[4];

    get_octets(header, octets);
    display(octets, type, domain, message, content);

    return (0);
}