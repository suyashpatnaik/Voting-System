#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define PASSWORD "admin123"

struct Voter {
    int id;
    int hasVoted;
};

struct Voter voters[MAX_VOTERS];
int totalVoters = 0;
int votes[3] = {0, 0, 0}; 

void adminMenu();
void voterMenu();
void castVote(int voterId);
void viewResults();
void registerVoters();
int authenticateAdmin();
int isValidVoter(int voterId);

int main() {
    int choice;
    
    while(1) {
        printf("\n--- Secure Voting System ---\n");
        printf("1. Admin Login\n");
        printf("2. Voter Login\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (authenticateAdmin()) {
                    adminMenu();
                } else {
                    printf("Incorrect password!\n");
                }
                break;
            case 2:
                voterMenu();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

int authenticateAdmin() {
    char input[20];
    printf("Enter Admin Password: ");
    scanf("%s", input);
    return strcmp(input, PASSWORD) == 0;
}

void adminMenu() {
    int choice;
    while(1) {
        printf("\n--- Admin Menu ---\n");
        printf("1. Register Voters\n");
        printf("2. View Results\n");
        printf("3. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerVoters();
                break;
            case 2:
                viewResults();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

void registerVoters() {
    printf("Enter number of voters to register (Max %d): ", MAX_VOTERS);
    scanf("%d", &totalVoters);
    
    if (totalVoters > MAX_VOTERS || totalVoters <= 0) {
        printf("Invalid number of voters.\n");
        totalVoters = 0;
        return;
    }

    for (int i = 0; i < totalVoters; i++) {
        printf("Enter Voter ID for Voter #%d: ", i+1);
        scanf("%d", &voters[i].id);
        voters[i].hasVoted = 0;
    }
    printf("Voters registered successfully.\n");
}

void voterMenu() {
    if (totalVoters == 0) {
        printf("No voters registered yet.\n");
        return;
    }

    int voterId;
    printf("Enter your Voter ID: ");
    scanf("%d", &voterId);

    if (isValidVoter(voterId)) {
        castVote(voterId);
    } else {
        printf("Invalid or already used Voter ID.\n");
    }
}

int isValidVoter(int voterId) {
    for (int i = 0; i < totalVoters; i++) {
        if (voters[i].id == voterId && voters[i].hasVoted == 0) {
            voters[i].hasVoted = 1; // Mark as voted
            return 1;
        }
    }
    return 0;
}

void castVote(int voterId) {
    int choice;
    printf("\nCandidates:\n");
    printf("1. Alice\n");
    printf("2. Bob\n");
    printf("3. Charlie\n");
    printf("Enter your vote (1-3): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        votes[choice - 1]++;
        printf("Vote cast successfully!\n");
    } else {
        printf("Invalid candidate number.\n");
    }
}

void viewResults() {
    printf("\n--- Voting Results ---\n");
    printf("Alice: %d votes\n", votes[0]);
    printf("Bob: %d votes\n", votes[1]);
    printf("Charlie: %d votes\n", votes[2]);
}