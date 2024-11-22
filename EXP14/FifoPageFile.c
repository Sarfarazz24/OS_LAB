#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100
void printFrames(int frames[], int frameCount) {
    printf("Frames: ");
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] != -1)
            printf("%d ", frames[i]);
        else
            printf("- ");
    }
    printf("\n");
}
int main() {
    int frames[MAX_FRAMES];
    int pageReferenceString[MAX_PAGES];
    int pageFaults = 0, frameCount, pageCount;
    printf("Enter number of frames: ");
    scanf("%d", &frameCount);
    printf("Enter number of pages: ");
    scanf("%d", &pageCount);
    printf("Enter the page reference string (space separated): ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pageReferenceString[i]);
    }
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }
    int nextFrameToReplace = 0;
    for (int i = 0; i < pageCount; i++) {
        int currentPage = pageReferenceString[i];
        int pageFound = 0;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }
        if (!pageFound) {
            frames[nextFrameToReplace] = currentPage;
            nextFrameToReplace = (nextFrameToReplace + 1) % frameCount;
            pageFaults++;
            printFrames(frames, frameCount);
        }
    }
    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}