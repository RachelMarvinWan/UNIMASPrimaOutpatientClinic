//UNIMAS PRIMA Outpatient Clinic
//81010 and 109675

#include <stdio.h>

int main()
{
    //Declaration of variables for billing
    char patientName[50], c;
    int consultType;
    float consultFee = 0.00, medCost, totalFee = 0.00, serviceCharge = 0.00;

    //Declaration of variables for daily summary
    int totalPatients = 0;
    float totalMedcost = 0.00, totalRevenue = 0.00;

    //For input validation
    int ch;

    do{
        //To reset value for new patient to avoid previous patient fee and charge are being carried over
        consultFee = 0.00;
        serviceCharge = 0.00;

        printf("\n---------Welcome To UNIMAS PRIMA Patient Billing System---------\n");

        //Input patient name
        printf("Enter Patient Name: ");
        scanf("%49s", patientName);

        //Select consultation type
        printf("Select Consultation Type (1=General, 2=Specialist, 3=Emergency): ");
        scanf("%d", &consultType);
        while (consultType<1 || consultType>3){
            printf("Invalid format of consultation type. Please enter enter either 1, 2 or 3 only: ");
            while (getchar() != '\n' && ch!=EOF);
            scanf("%d", &consultType);
        }

        //Check consultation charge based on type
        switch (consultType){

            case 1:
            consultFee = 10.00;
            break;

            case 2:
            consultFee = 45.00;
            break;

            case 3:
            consultFee = 30.00;
            break;
        }

        //Enter medication cost
        printf("Enter medication cost (RM): ");
        scanf("%f", &medCost);
        while(medCost<0 || scanf("%f", &medCost) != 1){
            printf("Invalid format of medication cost. Enter positive value only: ");
            while (getchar() != '\n' && ch!=EOF);
            scanf("%f", &medCost);
        }

        //Medication service charge
        if (medCost<=50){
            serviceCharge = 0.00;
        } else if (medCost<=99.99){
            serviceCharge = 5.00;
        } else {
            serviceCharge = 10.00;
        }

        //Calculate total fee
        totalFee = consultFee + serviceCharge + medCost;

        //Daily summary update
        totalPatients++;
        totalMedcost += medCost;
        totalRevenue += totalFee;

        //Display bill
        printf("\n---------Patient Bill---------\n");
        printf("Patient name: %s\n", patientName);
        printf("Service charge (RM): %.2f\n", serviceCharge);
        printf("Total Fee (RM): RM%.2f\n", totalFee);
        printf("------------------------------\n");

        //Sentinel check
        printf("\nContinue for another patient? (Y/N): ");
        scanf(" %c", &c);
        while (getchar() !='\n' && ch!=EOF);
        while (c!='N' && c!='n' && c!='Y' && c!='y'){
            printf("Invalid input! Please enter Y/N only!: ");
            scanf(" %c", &c);
            while (getchar() !='\n' && ch!=EOF);
        }

    } while (c!='N' && c!='n');

    //Display daily summary
    printf("\n---------Daily Summary------------\n");
    printf("Total patients: %d\n", totalPatients);
    printf("Total Medication Cost: %.2f\n", totalMedcost);
    printf("Total Revenue: %.2f\n", totalRevenue);
    printf("\----------------------------------");

    return 0;
}
