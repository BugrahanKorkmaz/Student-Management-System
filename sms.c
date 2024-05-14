#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct ogrenci {
    char ad[50];
    int no;
    int vize;
    int final;
    struct ogrenci* next ;
};
struct ogrenci* yeniogrenci(char ad[], int no, int vize, int final) {
    struct ogrenci* ogrenci = (struct ogrenci*)malloc(sizeof(struct ogrenci));
    strcpy(ogrenci->ad, ad);
    ogrenci->no = no;
    ogrenci->vize = vize;
    ogrenci->final = final;
    ogrenci->next = NULL;
    return ogrenci;
}

void kayit(struct ogrenci** head, char ad[], int no, int vize, int final){
    struct ogrenci* yeni_ogrenci = yeniogrenci(ad, no, vize, final);
    yeni_ogrenci->next = *head;
    *head = yeni_ogrenci;
}

void listele(struct ogrenci* head) {
    struct ogrenci* temp = head;
    while (temp != NULL) {
        printf("Name: %s, No: %d, Midterm: %d, Final: %d\n", temp->ad, temp->no, temp->vize, temp->final);
        temp = temp->next;
    }
}

void numarayaGoreListele(struct ogrenci* head) {
    struct ogrenci* temp = head;
    struct ogrenci* ogrenciListesi[100];
    int sayac = 0;

    while (temp != NULL) {
        ogrenciListesi[sayac++] = temp;
        temp = temp->next;
    }

    for (int i = 0; i < sayac - 1; i++) {
        for (int j = 0; j < sayac - i - 1; j++) {
            if (ogrenciListesi[j]->no > ogrenciListesi[j + 1]->no) {
                struct ogrenci* gecici = ogrenciListesi[j];
                ogrenciListesi[j] = ogrenciListesi[j + 1];
                ogrenciListesi[j + 1] = gecici;
            }
        }
    }

    for (int i = 0; i < sayac; i++) {
        printf("Name: %s, No: %d, Midterm: %d, Final: %d\n", ogrenciListesi[i]->ad, ogrenciListesi[i]->no, ogrenciListesi[i]->vize, ogrenciListesi[i]->final);
    }
}

void notaGoreListele(struct ogrenci* head, int altLimit, int ustLimit, char notTuru) {
    struct ogrenci* temp = head;
    while (temp != NULL) {
        int notDegeri = (notTuru == 'm') ? temp->vize : temp->final;
        if (notDegeri >= altLimit && notDegeri <= ustLimit) {
            printf("Name: %s, No: %d, Midterm: %d, Final: %d\n", temp->ad, temp->no, temp->vize, temp->final);
        }
        temp = temp->next;
    }
}

void kayitGuncelle(struct ogrenci* head, int no) {
    struct ogrenci* temp = head;
    while (temp != NULL) {
        if (temp->no == no) {
            printf("New Name: ");
            getchar(); 
            fgets(temp->ad, sizeof(temp->ad), stdin);
            temp->ad[strcspn(temp->ad, "\n")] = '\0'; 
            printf("New Midterm: ");
            scanf("%d", &temp->vize);
            printf("New Final: ");
            scanf("%d", &temp->final);
            printf("Record Updated.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}

void sinifOrtalamasi(struct ogrenci* head) {
    struct ogrenci* temp = head;
    int toplam = 0, sayi = 0;
    while (temp != NULL) {
        toplam += temp->vize * 0.4 + temp->final * 0.6;
        sayi++;
        temp = temp->next;
    }
    if (sayi == 0) {
        printf("Class average could not be calculated, no registration.\n");
    } else {
        printf("Class average: %.2f\n", (float)toplam / sayi);
    }
}

void enBasariliOgrenci(struct ogrenci* head) {
    struct ogrenci* temp = head;
    struct ogrenci* enBasarili = NULL;
    float maxOrtalama = 0.0;
    while (temp != NULL) {
        float ortalama = temp->vize * 0.4 + temp->final * 0.6;
        if (ortalama > maxOrtalama) {
            maxOrtalama = ortalama;
            enBasarili = temp;
        }
        temp = temp->next;
    }
    if (enBasarili != NULL) {
        printf("Most successful student: %s, No: %d, Average: %.2f\n", enBasarili->ad, enBasarili->no, maxOrtalama);
    } else {
        printf("No record.\n");
    }
}

int main() {
    struct ogrenci* head = NULL;
    char ad[50];
    int no, vize, final, secim;
    int altLimit, ustLimit;
    char notTuru;

    while (1) {
        printf("1-Adding New Record\n2-Record Listing\n3-Calculate Class Average\n4-Show Most Successful Student Information According to Average\n5-Registry Update\n0-Finish\n");
        printf("Enter your choice: ");
        scanf("%d", &secim);
        getchar(); 

        switch (secim) {
            case 1:
                printf("Name: ");
                fgets(ad, sizeof(ad), stdin);
                ad[strcspn(ad, "\n")] = '\0'; 
                printf("No: ");
                scanf("%d", &no);
                printf("Midterm: ");
                scanf("%d", &vize);
                printf("Final: ");
                scanf("%d", &final);
                kayit(&head, ad, no, vize, final);
                break;
            case 2:
                printf("1-List by Number\n2-List by Notes\nEnter your choice: ");
                scanf("%d", &secim);
                if (secim == 1) {
                    numarayaGoreListele(head);
                } else if (secim == 2) {
                    printf("Note Type (m-Midterm, f-final): ");
                    getchar(); 
                    scanf("%c", &notTuru);
                    printf("Lower Limit: ");
                    scanf("%d", &altLimit);
                    printf("Upper Limit: ");
                    scanf("%d", &ustLimit);
                    notaGoreListele(head, altLimit, ustLimit, notTuru);
                } else {
                    printf("Invalid Election.\n");
                }
                break;
            case 3:
                sinifOrtalamasi(head);
                break;
            case 4:
                enBasariliOgrenci(head);
                break;
            case 5:
                printf("Enter the student number to be updated: ");
                scanf("%d", &no);
                kayitGuncelle(head, no);
                break;
            case 0:
                printf("Program is being terminated...\n");
                exit(0);
                break;
            default:
                printf("Invalid election. Try again.\n");
        }
    }

    return 0;
}