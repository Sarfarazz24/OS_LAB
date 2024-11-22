#include <stdio.h>
#include <stdlib.h>
void sort_requests(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void scan_disk_scheduling(int requests[], int n, int head, int disk_size, int direction) {
    int total_movement = 0;
    int current_position = head;
    int sequence[n + 2];
    int sequence_count = 0;
    sort_requests(requests, n);
    if (direction == 1) {
        sequence[sequence_count++] = disk_size - 1;
    } else {
        sequence[sequence_count++] = 0;
    }
    for (int i = 0; i < n; i++) {
        if ((direction == 1 && requests[i] >= head) || (direction == 0 && requests[i] <= head)) {
            sequence[sequence_count++] = requests[i];
        }
    }
    if (direction == 1) {
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] < head) {
                sequence[sequence_count++] = requests[i];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (requests[i] > head) {
                sequence[sequence_count++] = requests[i];
            }
        }
    }
    printf("Request sequence is:\n");
    for (int i = 0; i < sequence_count; i++) {
        printf("%d -> ", sequence[i]);
        total_movement += abs(sequence[i] - current_position);
        current_position = sequence[i];
    }
    printf("Total head movement: %d\n", total_movement);
}
int main() {
    int n, head, disk_size, direction;
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
    printf("Enter the head movement direction (1 for right, 0 for left): ");
    scanf("%d", &direction);
    scan_disk_scheduling(requests, n, head, disk_size, direction);
    return 0;
}
