#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

   
    int L[n1], R[n2];

    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        
        merge(arr, left, mid, right);
    }
}

int main() {
    int m, n;

    
    printf("Enter the number of elements in nums1: ");
    scanf("%d", &m);

    printf("Enter the number of elements in nums2: ");
    scanf("%d", &n);

    int nums1[m], nums2[n], merged[m + n];

    
    printf("Enter the elements of nums1 in non-increasing order:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    
    printf("Enter the elements of nums2 in non-increasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    
    for (int i = 0; i < m; i++) {
        merged[i] = nums1[i];
    }
    for (int i = 0; i < n; i++) {
        merged[m + i] = nums2[i];
    }

    
    mergeSort(merged, 0, m + n - 1);

    
    printf("Merged and sorted array (AB): ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
