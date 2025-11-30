#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct movies {
    char title[30];
    char genre[30];
    char director[30];
    int release_year;
    float rating;
};

void add_movie(struct movies *M[20]);
void movie_details(struct movies *M[20]);

int main() {
    int choice;
    struct movies *M[20];

    for (int i = 0; i < 20; i++) {
        M[i] = NULL;
    }

    while (1) {
        printf("\n===== [Movies] =====\n");
        printf("1. Add Movies\n");
        printf("2. Search Movie by Genre\n");
        printf("3. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_movie(M);
                break;
            case 2:
                movie_details(M);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid Choice! Enter Number between (1-3).\n");
        }
    }
}

void add_movie(struct movies *M[20]) {
    int i;
    for (i = 0; i < 20; i++) {
        if (M[i] == NULL) {

            M[i] = (struct movies*) malloc(sizeof(struct movies));

            printf("\nEnter the Name of Movie: ");
            while(getchar() != '\n');

            fgets(M[i]->title, 30, stdin);
            M[i]->title[strcspn(M[i]->title, "\n")] = 0;

            printf("Enter the Genre of Movie: ");
            fgets(M[i]->genre, 30, stdin);
            M[i]->genre[strcspn(M[i]->genre, "\n")] = 0;

            printf("Enter Director Name: ");
            fgets(M[i]->director, 30, stdin);
            M[i]->director[strcspn(M[i]->director, "\n")] = 0;

            printf("Enter the Release Year: ");
            scanf("%d", &M[i]->release_year);

            printf("Enter the Rating of Movie: ");
            scanf("%f", &M[i]->rating);

            printf("Movie Added Successfully at Index %d!\n", i);
            return;
        }
    }
    printf("No more Space to add Movies!\n");
}

void movie_details(struct movies *M[20]) {
    char search_movie[30];
    int found = 0;

    printf("Enter the Genre to Search a Movie: ");
    while(getchar() != '\n');
    fgets(search_movie, 30, stdin);
    search_movie[strcspn(search_movie, "\n")] = 0;

    printf("\n--- Search Results ---\n");

    for (int i = 0; i < 20; i++) {
        if (M[i] != NULL) {
            if (strcasecmp(M[i]->genre, search_movie) == 0) {
                printf("\nTitle: %s\n", M[i]->title);
                printf("Genre: %s\n", M[i]->genre);
                printf("Director: %s\n", M[i]->director);
                printf("Release Year: %d\n", M[i]->release_year);
                printf("Rating: %.1f\n", M[i]->rating);
                found = 1;
            }
        }
    }

    if (found == 0) {
        printf("No Movie found with genre '%s'!\n", search_movie);
    }
}