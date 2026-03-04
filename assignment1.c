//UNIMAS PRIMA Outpatient Clinic Assignment
//81010 &

#include <stdio.h>

int main()
{
    // declare variables for consultation type, consultation fee, medication cost
    int consultationType;
    float medicationCost, consultationFee = 0.0, serviceCharge = 0.0, totalFee;

    // declare variables for Patient Identity
    char patientName[50];

    // daily summary variables
    int totalPatients = 0;
    float totalMedication = 0.0, totalRevenue = 0.0;

    // sentinel to continue or stop
    char again;

    // for input validation
    int validInput;
    int ch;

    printf("\n-----------------Welcome to UNIMAS Prima Outpatient Clinic Billing System-----------------------\n");

    // loop for multiple patients
    do {

        printf("\nEnter patient name: ");
        scanf("%49s", patientName);

        // consultation type with validation (handles non-integer input)
        do {
            printf("Consultation type (1=General, 2=Specialist, 3=Emergency): ");
            validInput = scanf("%d", &consultationType);

            if (validInput != 1) {
                printf("Invalid input. Please enter numbers only (1, 2, or 3).\n");
                // clear invalid characters from buffer
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }

            if (consultationType < 1 || consultationType > 3) {
                printf("Invalid consultation type. Please enter 1, 2, or 3 only.\n");
            }

        } while (validInput != 1 || consultationType < 1 || consultationType > 3);

        // set consultation fee
        switch(consultationType) {
            case 1:
                consultationFee = 10.00;
                break;
            case 2:
                consultationFee = 45.00;
                break;
            case 3:
                consultationFee = 30.00;
                break;
        }

        // medication cost with validation (handles non-numeric and negative)
        do {
            printf("Enter the medication cost: ");
            validInput = scanf("%f", &medicationCost);

            if (validInput != 1) {
                printf("Invalid input. Please enter a numeric value for medication cost.\n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }

            if (medicationCost < 0) {
                printf("Medication cost cannot be negative. Please enter again.\n");
            }

        } while (validInput != 1 || medicationCost < 0);

        // conditions for medication service charge
        if (medicationCost < 50.00) {
            serviceCharge = 0.00;
        } else if (medicationCost <= 99.99) {
            serviceCharge = 5.00;
        } else {
            serviceCharge = 10.00;
        }

        // calculate total fee
        totalFee = medicationCost + consultationFee + serviceCharge;

        // display per-patient bill
        printf("\n---- Patient Bill ----\n");
        printf("Patient Name: %s\n", patientName);
        printf("Consultation Fee: RM%.2f\n", consultationFee);
        printf("Service Charge: RM%.2f\n", serviceCharge);
        printf("Medication Cost: RM%.2f\n", medicationCost);
        printf("Total Fee: RM%.2f\n", totalFee);

        // update daily summary
        totalPatients++;
        totalMedication += medicationCost;
        totalRevenue += totalFee;

        // ask whether to process next patient
        printf("\nProcess next? (Y/N): ");
        scanf(" %c", &again);

        // clear any extra characters after Y/N
        while ((ch = getchar()) != '\n' && ch != EOF);

    } while (again == 'Y' || again == 'y');

    // print daily summary
    printf("\n==== Daily Summary ====\n");
    printf("Total Patients: %d\n", totalPatients);
    printf("Total Medication Cost: RM%.2f\n", totalMedication);
    printf("Total Revenue: RM%.2f\n", totalRevenue);

    return 0;
}

