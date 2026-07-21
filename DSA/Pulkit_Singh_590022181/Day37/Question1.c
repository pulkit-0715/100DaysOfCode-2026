#include <stdio.h>

#define MAX 10000

int queue[MAX];
int front = 0, rear = -1;

int ping(int t) {

    queue[++rear] = t;

    while (front <= rear && queue[front] < t - 3000) {
        front++;
    }

    return rear - front + 1;
}

int main() {

    printf("%d\n", ping(1));
    printf("%d\n", ping(100));
    printf("%d\n", ping(3001));
    printf("%d\n", ping(3002));

    return 0;
}