#include <stdio.h>

#define MAX 100

typedef struct {
    int priority;
    int index;
} Document;

Document queue[MAX];
int front = 0, rear = -1;

void enqueue(Document d) {
    queue[++rear] = d;
}

Document dequeue() {
    return queue[front++];
}

int isHigherPriority(int priority) {
    for (int i = front; i <= rear; i++) {
        if (queue[i].priority > priority)
            return 1;
    }
    return 0;
}

int printerQueue(int priorities[], int n, int location) {

    front = 0;
    rear = -1;

    for (int i = 0; i < n; i++) {
        Document d;
        d.priority = priorities[i];
        d.index = i;
        enqueue(d);
    }

    int minutes = 0;

    while (front <= rear) {

        Document current = dequeue();

        if (isHigherPriority(current.priority)) {
            enqueue(current);
        }
        else {
            minutes++;

            if (current.index == location)
                return minutes;
        }
    }

    return -1;
}

int main() {

    int priorities[] = {2, 1, 3, 2};
    int n = 4;
    int location = 2;

    printf("Minutes = %d\n", printerQueue(priorities, n, location));

    return 0;
}