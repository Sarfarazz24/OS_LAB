#include <stdio.h>
#include <stdlib.h>
void fcfs_disk_scheduling(int requests[], int n, int head) {
    int total_head_movement = 0;
    printf("Seek sequence is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", requests[i]);
        total_head_movement += abs(requests[i] - head);
        head = requests[i];
    }
    printf("End\n");
    printf("Total head movement: %d\n", total_head_movement);
}
int main() {
    int n, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    fcfs_disk_scheduling(requests, n, head);
    return 0;
}
