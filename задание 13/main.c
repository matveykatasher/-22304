#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_FORMAT ".dat"

typedef struct date{
    int day;
    int month;
    int year;
}date;

typedef struct data{
    char phone[12];
    char name[255];
    char surname[255];
    date date;
}data;

typedef struct CPeople{
    data data;
    struct CPeople* next;
}CPeople;

void add_new_record(CPeople** head, data data){
    CPeople* new = malloc(sizeof(CPeople));
    new->data = data;
    new->next = *head;
    *head = new;
}

//void delete_by_id(CPeople** head, CPeople* record_to_delete){
//    CPeople* tmp = *head;
//    if (record_to_delete == *head){
//        *head = (*head)->next;
//        free(record_to_delete);
//        return;
//    }
//    while(tmp->next != record_to_delete){
//        tmp = tmp->next;
//    }
//    tmp->next = record_to_delete->next;
//    free(record_to_delete);
//}

int delete_by_id(CPeople** head, int id){
    CPeople* tmp = *head;
    if (id <= 0)
        return -1;
    if (id == 1){
        *head = (*head)->next;
        free(tmp);
        return 0;
    }
    for(int i=1; i<(id-1); i++){
        if (tmp->next == NULL)
            return -1;
        tmp = tmp->next;
    }
    CPeople* record_to_delete = tmp->next;
    tmp->next = tmp->next->next;
    free(record_to_delete);
    return 0;
}

void free_list(CPeople** head){
    CPeople* tmp_p;
    while (*head != NULL)
    {
        tmp_p = *head;
        *head = (*head) -> next;
        free(tmp_p);
    }
    *head = NULL;
}

void print_list(CPeople* head){
    if(head == NULL)
        return;
    CPeople* pointer = head;
    printf("%2s   %11s%15s%15s%19s\n\n", "ID","PHONE","NAME","SURNAME","BIRTHDAY");
    int i = 1;
    while(pointer != NULL) {
        printf("%2d   %11s%15s%15s%15d-%02d-%02d\n", i, pointer->data.phone, pointer->data.name, \
        pointer->data.surname, pointer->data.date.year, pointer->data.date.month, \
        pointer->data.date.day);
        pointer = pointer->next;
        i++;
    }
    printf("\n");
}