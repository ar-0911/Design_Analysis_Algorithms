#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100
typedef struct candidate {
    int id;
    int quality;
} Candidate;

int compare_candidates(const void *a, const void *b) {
    Candidate *ca = (Candidate *)a;
    Candidate *cb = (Candidate *)b;
    if (ca->quality > cb->quality) {
        return -1;
    } else if (ca->quality < cb->quality) {
        return 1;
    } else {
        return 0;
    }
}

int hire_assistant(Candidate *candidates, int n) {
    int best = -1;
    int hires = 0;
    for (int i = 0; i < n; i++) {
        if (candidates[i].quality > best) {
            best = candidates[i].quality;
            hires++;
        }
    }
    return hires;
}

int main() {
    int n;
    printf("Enter the number of candidates: ");
    scanf("%d", &n);
    Candidate candidates[MAX_N];
    for (int i = 0; i < n; i++) {
        printf("Enter the quality of candidate %d: ", i+1);
        scanf("%d", &candidates[i].quality);
        candidates[i].id = i+1;
    }
    qsort(candidates, n, sizeof(Candidate), compare_candidates);
    int hires = hire_assistant(candidates, n);
    printf("The number of candidates hired is: %d\n", hires);
    return 0;
}
