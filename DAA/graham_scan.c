#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

// Returns the square of the Euclidean distance between points p1 and p2
int dist_squared(Point p1, Point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

// Returns the orientation of the triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

// Compares two points by polar angle with respect to a reference point
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    
    int o = orientation((Point){0,0}, *p1, *p2);
    if (o == 0)
        return (dist_squared((Point){0,0}, *p2) >= dist_squared((Point){0,0}, *p1)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

// Finds the convex hull of a set of n points using the Graham's Scan algorithm
void convex_hull(Point points[], int n) {
    // There must be at least 3 points to form a convex hull
    if (n < 3)
        return;
    
    // Find the point with the lowest y-coordinate
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
    
    // Swap the lowest point with the first point in the array
    Point temp = points[0];
    points[0] = points[min];
    points[min] = temp;
    
    // Sort the remaining points by polar angle with respect to the first point
    qsort(&points[1], n-1, sizeof(Point), compare);
    
    // Initialize an empty hull and add the first two points to it
    Point hull[n];
    hull[0] = points[0];
    hull[1] = points[1];
    int top = 1;
    
    // Find the remaining points on the hull
    for (int i = 2; i < n; i++) {
        while (top > 0 && orientation(hull[top-1], hull[top], points[i]) != 2)
            top--;
        top++;
        hull[top] = points[i];
    }
    
    // Print the convex hull
    printf("The convex hull is:\n");
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
}

// Driver program to test the function
int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convex_hull(points, n);
    return 0;
}

