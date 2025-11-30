#include<stdio.h>
#include<string.h>

struct flight_information {
    int flight_number;
    char departure_city[50];
    char destination_city[50];
    char date[11];
    int total_seats;
    int available_seats;
};

void book_a_seat(struct flight_information *f1);

void flight_details(struct flight_information f);

int main() {
    int choice;
    struct flight_information f1;

    f1.flight_number = 1;
    strcpy(f1.departure_city, "Karachi");
    strcpy(f1.destination_city, "Lahore");
    strcpy(f1.date, "01-11-2025");
    f1.total_seats = 5;
    f1.available_seats = f1.total_seats - 1;

    while (1) {
        printf("\n===== [Flight Management System] =====\n");
        printf("1.Book a Seat \n");
        printf("2.Flight Details \n");
        printf("3.Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                book_a_seat(&f1);
                break;
            case 2:
                flight_details(f1);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid Choice! Enter Choice between (1-3)");
        }
    }
}

void book_a_seat(struct flight_information *f1) {
    if (f1->available_seats > 0) {
        f1->available_seats--;
        printf("Seat Booked! Ticket Confirmed.\n");
        printf("Remaining Seats: %d", f1->available_seats);
    }
    else {
        printf("Booking Failed! No Seat is Available.");
    }
}

void flight_details(struct flight_information f1) {
    printf("\n--- Flight Details ---\n");
    printf("Flight Number:        %d\n", f1.flight_number);
    printf("Departure City:       %s\n", f1.departure_city);
    printf("Destination City:     %s\n", f1.destination_city);
    printf("Date:                 %s\n", f1.date);
    printf("Available Seats:      %d\n", f1.available_seats);
    printf("----------------------\n");
}