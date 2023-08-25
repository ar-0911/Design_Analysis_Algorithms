#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

// Returns the orientation of the triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

// Finds the convex hull of a set of n points using the Jarvis March algorithm
void convex_hull(Point points[], int n) {
    // There must be at least 3 points to form a convex hull
    if (n < 3)
        return;
    
    // Initialize an empty hull
    Point hull[n];
    for (int i = 0; i < n; i++)
        hull[i] = (Point) {-1, -1};
    
    // Find the leftmost point and add it to the hull
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x)
            leftmost = i;
    }
    hull[0] = points[leftmost];
    
    // Find the remaining points on the hull
    int p = leftmost, q;
    do {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        hull[q] = points[q];
        p = q;
    } while (p != leftmost);
    
    // Print the convex hull
    printf("The convex hull is:\n");
    for (int i = 0; i < n; i++) {
        if (hull[i].x != -1 && hull[i].y != -1)
            printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

// Driver program to test the function
int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convex_hull(points, n);
    return 0;
}
