#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_teams(char** teams, int teams_length) {
    for(int i = 0; i < teams_length; i++) {
        int j = rand() % teams_length;
        char* temp = teams[i];
        teams[i] = teams[j];
        teams[j] = temp;
    }
}

void generate_schedule(char** teams, int teams_length) {
    int teams_wins[teams_length];
    int teams_losses[teams_length];

    for(int i = 0; i < teams_length; i++) {
        teams_wins[i] = 0;
        teams_losses[i] = 0;
    }

    for(int game = 1; game <= 162; game++) {
        printf("Game %d:\n", game);
        shuffle_teams(teams, teams_length);
        int teams_scheduled[teams_length];

        for(int i = 0; i < teams_length; i++) {
            teams_scheduled[i] = 0;
        }

        for(int i = 0; i < teams_length; i++) {
            int j = rand() % teams_length;

            if(teams_scheduled[i]) {
                continue;
            }

            while(i == j || teams_scheduled[j]) {
                j = rand() % teams_length;
            }

            int winner_index = rand() % 2;

            if(winner_index == 0) {
                printf("%s(W) vs. %s(L)\n", teams[i], teams[j]);
                teams_wins[i]++;
                teams_losses[j]++;
            } else {
                printf("%s(L) vs. %s(W)\n", teams[i], teams[j]);
                teams_wins[j]++;
                teams_losses[i]++;
            }

            teams_scheduled[i] = 1;
            teams_scheduled[j] = 1;
        }
    }

    printf("\n");
    printf("Standings:\n");

    for(int i = 0; i < teams_length; i++) {
        printf("%s: %d - %d\n", teams[i], teams_wins[i], teams_losses[i]);
    }
}

int main() {
    char* teams[] = {
        "Los Angeles Angels",
        "Houston Astros",
        "Oakland Athletics",
        "Toronto Blue Jays",
        "Atlanta Braves",
        "Milwaukee Brewers",
        "St. Louis Cardinals",
        "Chicago Cubs",
        "Arizona Diamondbacks",
        "Los Angeles Dodgers",
        "San Francisco Giants",
        "Cleveland Guardians",
        "Seattle Mariners",
        "Miami Marlins",
        "New York Mets",
        "Washington Nationals",
        "Baltimore Orioles",
        "San Diego Padres",
        "Philadelphia Phillies",
        "Pittsburgh Pirates",
        "Tampa Bay Rays",
        "Cincinnati Reds",
        "Boston Red Sox",
        "Texas Rangers",
        "Colorado Rockies",
        "Kansas City Royals",
        "Detroit Tigers",
        "Minnesota Twins",
        "Chicago White Sox",
        "New York Yankees",
    };

    srand(time(NULL));
    int teams_length = sizeof(teams) / sizeof(teams[0]);
    generate_schedule(teams, teams_length);

    return 0;
}
