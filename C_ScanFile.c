#include <stdio.h>
#include <stdlib.h>
void sort_requests(int requests[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
}
void c_scan_disk_scheduling(int requests[], int n, int head, int disk_size) {
    int total_head_movement = 0;
    int current_position = head;
    sort_requests(requests, n);
    printf("Seek sequence is:\n");
    for (int i = 0; i < n; i++) {
        if (requests[i] >= head) {
            printf("%d -> ", requests[i]);
            total_head_movement += abs(requests[i] - current_position);
            current_position = requests[i];
        }
    }
    if (current_position != disk_size - 1) {
        printf("%d -> ", disk_size - 1);
        total_head_movement += abs(disk_size - 1 - current_position);
        current_position = disk_size - 1;
    }
    printf("0 -> ");
    total_head_movement += current_position;
    current_position = 0;
    for (int i = 0; i < n; i++) {
        if (requests[i] < head) {
            printf("%d -> ", requests[i]);
            total_head_movement += abs(requests[i] - current_position);
            current_position = requests[i];
        }
    }
    printf("End\n");
    printf("Total head movement: %d\n", total_head_movement);
}
int main() {
    int n, head, disk_size;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the requests sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);
    c_scan_disk_scheduling(requests, n, head, disk_size);
    return 0;
}
