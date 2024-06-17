#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char name[20];
    double exam1, exam2;
    struct node *nextNode;
} node;

int main() {
    // Declare nodes and allocate memory 

    node *a = (node *)malloc(sizeof(node));
    node *b = (node *)malloc(sizeof(node));
    node *c = (node *)malloc(sizeof(node));

    //update data for node a
    strcpy(a->name, "Jameson");
    a->exam1 = 69;
    a->exam2 = 2;
    a->nextNode = b;

    //update data for node b
    strcpy(b->name, "Peter");
    b->exam1 = 59;
    b->exam2 = 69;
    b->nextNode = c;

    //update data for node c
    strcpy(c->name, "Gwen");
    c->exam1 = 666;
    c->exam2 = 33;
    c->nextNode = NULL;

    //printing the linked list 
    node *currentNode = a;
    double exam1_total = 0, exam2_total = 0;
    double max = currentNode->exam1;
    double max2 = currentNode->exam2;

    FILE *fp = fopen("linked_list_output.txt", "w");

    while (currentNode != NULL) {
        fprintf(fp, "Name: %s\n", currentNode->name);
        fprintf(fp, "Exam 1: %.2f\n", currentNode->exam1);
        fprintf(fp, "Exam 2: %.2f\n", currentNode->exam2);
        fprintf(fp, "Average score: %.2f\n", (currentNode->exam1 + currentNode->exam2) / 2.0);
        exam1_total += currentNode->exam1;
        exam2_total += currentNode->exam2;
        if (currentNode->exam1 > max) {
            max = currentNode->exam1;
        }
        if (currentNode->exam2 > max2) {
            max2 = currentNode->exam2;
        }
        currentNode = currentNode->nextNode;
    }

    fprintf(fp, "Average score for exam 1: %.2f\n", exam1_total / 3.0);
    fprintf(fp, "Average score for exam 2: %.2f\n", exam2_total / 3.0);

    fprintf(fp, "Highest score for exam 1: %.2f\n", max);
    fprintf(fp, "Highest score for exam 2: %.2f\n", max2);
    fclose(fp);
}