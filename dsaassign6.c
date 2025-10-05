
//(1)

// #include <stdio.h>
// #include <stdlib.h>

// struct vehicle {
//     int vehicleID;
//     int vehicleType;  // 1: Emergency, 2: VIP, 3: Regular
//     char driverName[20];
//     struct vehicle *next;
// };

// int IsEmpty(struct vehicle *front) {
//     return front == NULL;
// }

// void addVehicle(struct vehicle **ffront, struct vehicle **frear1, struct vehicle **frear2, struct vehicle **frear3) {
//     struct vehicle *newvehicle = NULL;
//     char ch;

//     do {
//         newvehicle = (struct vehicle*)calloc(1, sizeof(struct vehicle));
        
//         printf("\nEnter driver name: ");
//         scanf("%s", newvehicle->driverName);
//         printf("Enter vehicle ID: ");
//         scanf("%d", &newvehicle->vehicleID);
//         printf("Enter vehicle type (1-Emergency, 2-VIP, 3-Regular): ");
//         scanf("%d", &newvehicle->vehicleType);
        
//         newvehicle->next = NULL;

//         if (IsEmpty(*ffront)) {
//             // First vehicle in queue
//             *ffront = newvehicle;
//             switch(newvehicle->vehicleType) {
//                 case 1: *frear1 = newvehicle; break;
//                 case 2: *frear2 = newvehicle; break;
//                 case 3: *frear3 = newvehicle; break;
//             }
//         } else {
//             // Insert based on priority
//             struct vehicle *current = *ffront;
//             struct vehicle *prev = NULL;
            
//             // Find insertion point - maintain priority order
//             while (current != NULL && current->vehicleType <= newvehicle->vehicleType) {
//                 prev = current;
//                 current = current->next;
//             }
            
//             if (prev == NULL) {
//                 // Insert at front (highest priority)
//                 newvehicle->next = *ffront;
//                 *ffront = newvehicle;
//             } else {
//                 // Insert after prev
//                 newvehicle->next = prev->next;
//                 prev->next = newvehicle;
//             }
            
//             // Update rear pointers
//             switch(newvehicle->vehicleType) {
//                 case 1: 
//                     *frear1 = newvehicle;
//                     break;
//                 case 2: 
//                     *frear2 = newvehicle;
//                     break;
//                 case 3: 
//                     *frear3 = newvehicle;
//                     break;
//             }
//         }

//         printf("\nDo you want to add one more vehicle? (y/n): ");
//         scanf(" %c", &ch);

//     } while (ch == 'y' || ch == 'Y');
// }

// // Function to process next vehicle
// void processVehicle(struct vehicle **ffront, struct vehicle **frear1, struct vehicle **frear2, struct vehicle **frear3) {
//     if (IsEmpty(*ffront)) {
//         printf("\nNo vehicles in queue!\n");
//         return;
//     }

//     struct vehicle *temp = *ffront;
//     *ffront = (*ffront)->next;
    
//     printf("\nProcessing vehicle:\n");
//     printf("Vehicle ID: %d, Driver: %s, Type: ", temp->vehicleID, temp->driverName);
//     switch(temp->vehicleType) {
//         case 1: printf("EMERGENCY\n"); break;
//         case 2: printf("VIP\n"); break;
//         case 3: printf("REGULAR\n"); break;
//     }
    
//     // Update rear pointers if the processed vehicle was a rear
//     if (temp == *frear1) {
//         // Find new emergency rear
//         *frear1 = NULL;
//         struct vehicle *current = *ffront;
//         while (current != NULL) {
//             if (current->vehicleType == 1) {
//                 *frear1 = current;
//             }
//             current = current->next;
//         }
//     }
//     if (temp == *frear2) {
//         // Find new VIP rear
//         *frear2 = NULL;
//         struct vehicle *current = *ffront;
//         while (current != NULL) {
//             if (current->vehicleType == 2) {
//                 *frear2 = current;
//             }
//             current = current->next;
//         }
//     }
//     if (temp == *frear3) {
//         // Find new regular rear
//         *frear3 = NULL;
//         struct vehicle *current = *ffront;
//         while (current != NULL) {
//             if (current->vehicleType == 3) {
//                 *frear3 = current;
//             }
//             current = current->next;
//         }
//     }
    
//     free(temp);
// }

// void displayQueue(struct vehicle *front, struct vehicle *rear1, struct vehicle *rear2, struct vehicle *rear3) {
//     struct vehicle *temp = front;

//     if (IsEmpty(front)) {
//         printf("\nQueue is empty!\n");
//         return;
//     }

//     printf("\nToll Plaza Vehicle Queue:\n");
//     printf("==========================\n");
    
//     int position = 1;
//     while (temp != NULL) {
//         printf("%d. Vehicle ID: %d, Driver: %s, Type: ", position, temp->vehicleID, temp->driverName);
//         switch(temp->vehicleType) {
//             case 1: printf("EMERGENCY"); break;
//             case 2: printf("VIP"); break;
//             case 3: printf("REGULAR"); break;
//             default: printf("UNKNOWN"); break;
//         }
        
//         // Show if this is a rear node
//         if (temp == rear1) {
//             printf(" [REAR-EMERGENCY]");
//         } else if (temp == rear2) {
//             printf(" [REAR-VIP]");
//         } else if (temp == rear3) {
//             printf(" [REAR-REGULAR]");
//         }
        
//         printf("\n");
//         temp = temp->next;
//         position++;
//     }
// }

// // Function to free all memory
// void freeQueue(struct vehicle **ffront, struct vehicle **frear1, struct vehicle **frear2, struct vehicle **frear3) {
//     struct vehicle *temp = *ffront;
//     while (temp != NULL) {
//         struct vehicle *toDelete = temp;
//         temp = temp->next;
//         free(toDelete);
//     }
//     *ffront = NULL;
//     *frear1 = NULL;
//     *frear2 = NULL;
//     *frear3 = NULL;
// }

// int main() {
//     struct vehicle *front = NULL;
//     struct vehicle *rear1 = NULL;  // Emergency rear
//     struct vehicle *rear2 = NULL;  // VIP rear
//     struct vehicle *rear3 = NULL;  // Regular rear
//     int choice;

//     printf("=== VEHICLE TRAFFIC MANAGEMENT AT TOLL PLAZA ===\n");

//     do {
//         printf("\n1. Add Vehicle\n");
//         printf("2. Process Next Vehicle\n");
//         printf("3. Display Vehicle Queue\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 addVehicle(&front, &rear1, &rear2, &rear3);
//                 break;
//             case 2:
//                 processVehicle(&front, &rear1, &rear2, &rear3);
//                 break;
//             case 3:
//                 displayQueue(front, rear1, rear2, rear3);
//                 break;
//             case 4:
//                 freeQueue(&front, &rear1, &rear2, &rear3);
//                 printf("Exiting Toll Plaza Management System.\n");
//                 break;
//             default:
//                 printf("Invalid choice! Please try again.\n");
//         }
//     } while (choice != 4);

//     return 0;
// }

//(2)

#include <stdio.h>
#include <stdlib.h>

struct q {
    int ID;
    int priority;
    char name[20];
    struct q *next;
};

int IsEmpty(struct q *front) {
    return front == NULL;
}

void append(struct q **ffront, struct q **frear1, struct q **frear2, struct q **frear3) {
    struct q *newnode = NULL;
    char ch;

    do {
        newnode = (struct q*)calloc(1, sizeof(struct q));
        
        printf("\nEnter patient name: ");
        scanf("%s", newnode->name);
        printf("Enter patient ID: ");
        scanf("%d", &newnode->ID);
        printf("Enter priority (1-Emergency, 2-Medium, 3-Low): ");
        scanf("%d", &newnode->priority);
        
        newnode->next = NULL;

        if (IsEmpty(*ffront)) {
            // First patient in queue
            *ffront = newnode;
            switch(newnode->priority) {
                case 1: *frear1 = newnode; break;
                case 2: *frear2 = newnode; break;
                case 3: *frear3 = newnode; break;
            }
        } else {
            // Insert based on priority
            struct q *current = *ffront;
            struct q *prev = NULL;
            
            // Find insertion point - maintain priority order
            while (current != NULL && current->priority <= newnode->priority) {
                prev = current;
                current = current->next;
            }
            
            if (prev == NULL) {
                // Insert at front (highest priority)
                newnode->next = *ffront;
                *ffront = newnode;
            } else {
                // Insert after prev
                newnode->next = prev->next;
                prev->next = newnode;
            }
            
            // Update rear pointers
            switch(newnode->priority) {
                case 1: 
                    *frear1 = newnode;
                    break;
                case 2: 
                    *frear2 = newnode;
                    break;
                case 3: 
                    *frear3 = newnode;
                    break;
            }
        }

        printf("\nDo you want to add one more patient? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}

// Function to serve highest priority patient
void servePatient(struct q **ffront, struct q **frear1, struct q **frear2, struct q **frear3) {
    if (IsEmpty(*ffront)) {
        printf("\nNo patients in queue!\n");
        return;
    }

    struct q *temp = *ffront;
    *ffront = (*ffront)->next;
    
    printf("\nServing patient:\n");
    printf("ID: %d, Name: %s, Priority: ", temp->ID, temp->name);
    switch(temp->priority) {
        case 1: printf("EMERGENCY\n"); break;
        case 2: printf("MEDIUM\n"); break;
        case 3: printf("LOW\n"); break;
    }
    
    // Update rear pointers if the served patient was a rear
    if (temp == *frear1) {
        // Find new emergency rear
        *frear1 = NULL;
        struct q *current = *ffront;
        while (current != NULL) {
            if (current->priority == 1) {
                *frear1 = current;
            }
            current = current->next;
        }
    }
    if (temp == *frear2) {
        // Find new medium rear
        *frear2 = NULL;
        struct q *current = *ffront;
        while (current != NULL) {
            if (current->priority == 2) {
                *frear2 = current;
            }
            current = current->next;
        }
    }
    if (temp == *frear3) {
        // Find new low rear
        *frear3 = NULL;
        struct q *current = *ffront;
        while (current != NULL) {
            if (current->priority == 3) {
                *frear3 = current;
            }
            current = current->next;
        }
    }
    
    free(temp);
}

void display(struct q *front, struct q *rear1, struct q *rear2, struct q *rear3) {
    struct q *temp = front;

    if (IsEmpty(front)) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nHospital Patient Queue:\n");
    printf("=======================\n");
    
    int position = 1;
    while (temp != NULL) {
        printf("%d. ID: %d, Name: %s, Priority: ", position, temp->ID, temp->name);
        switch(temp->priority) {
            case 1: printf("EMERGENCY"); break;
            case 2: printf("MEDIUM"); break;
            case 3: printf("LOW"); break;
            default: printf("UNKNOWN"); break;
        }
        
        // Show if this is a rear node
        if (temp == rear1) {
            printf(" [REAR-EMERGENCY]");
        } else if (temp == rear2) {
            printf(" [REAR-MEDIUM]");
        } else if (temp == rear3) {
            printf(" [REAR-LOW]");
        }
        
        printf("\n");
        temp = temp->next;
        position++;
    }
}

// Function to free all memory
void freeQueue(struct q **ffront, struct q **frear1, struct q **frear2, struct q **frear3) {
    struct q *temp = *ffront;
    while (temp != NULL) {
        struct q *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    *ffront = NULL;
    *frear1 = NULL;
    *frear2 = NULL;
    *frear3 = NULL;
}

int main() {
    struct q *front = NULL;
    struct q *rear1 = NULL;  // Emergency rear
    struct q *rear2 = NULL;  // Medium rear
    struct q *rear3 = NULL;  // Low rear
    int choice;

    printf("=== HOSPITAL MANAGEMENT SYSTEM ===\n");

    do {
        printf("\n1. Add Patients\n");
        printf("2. Serve Next Patient\n");
        printf("3. Display All Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                append(&front, &rear1, &rear2, &rear3);
                break;
            case 2:
                servePatient(&front, &rear1, &rear2, &rear3);
                break;
            case 3:
                display(front, rear1, rear2, rear3);
                break;
            case 4:
                freeQueue(&front, &rear1, &rear2, &rear3);
                printf("Exiting Hospital Management System.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}