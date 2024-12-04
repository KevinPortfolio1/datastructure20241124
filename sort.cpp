/*
Sorting algorithm

1.泡沫排序

	它重複地走訪過要排序的數列，一次比較兩個元素，如果它們的順序錯誤就把它們交換過來

2.選擇

	首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
	然後，再從剩餘未排序元素中繼續尋找最小（大）元素，然後放到已排序序列的末尾。
	以此類推，直到所有元素均排序完畢。 
	
3.插入

    從第一個元素開始，該元素可以認為已經被排序
    取出下一個元素，在已經排序的元素序列中從後向前掃描
    如果該元素（已排序）大於新元素，將該元素移到下一位置
    重複步驟3，直到找到已排序的元素小於或者等於新元素的位置
    將新元素插入到該位置後
    重複步驟2~5

4.快速

	分割區交換排序
	挑選基準值：從數列中挑出一個元素，稱為「基準」（pivot），
    分割：重新排序數列，所有比基準值小的元素擺放在基準前面，
	所有比基準值大的元素擺在基準後面（與基準值相等的數可以到任何一邊）。
	在這個分割結束之後，對基準值的排序就已經完成，
    遞迴排序子序列：遞迴地將小於基準值元素的子序列和大於基準值元素的子序列排序。

5.堆積

	最大堆積調整（Max Heapify）：將堆積的末端子節點作調整，使得子節點永遠小於父節點
    建立最大堆積（Build Max Heap）：將堆積中的所有數據重新排序
    堆積排序（HeapSort）：移除位在第一個數據的根節點，並做最大堆積調整的遞迴運算

6.謝耳

	遞減增量排序演算法，是插入排序的一種更高效的改進版本。希爾排序是非穩定排序演算法。
	希爾排序是基於插入排序的以下兩點性質而提出改進方法的：
    插入排序在對幾乎已經排好序的數據操作時，效率高，即可以達到線性排序的效率
    但插入排序一般來說是低效的，因為插入排序每次只能將數據移動一位

7.合併

    採用分治法:
    分割：遞迴地把當前序列平均分割成兩半。
    整合：在保持元素順序的同時將上一步得到的子序列整合到一起（合併）。

8.基數

   原理是將整數按位元數切割成不同的數字，然後按每個位數分別比較。
   由於整數也可以表達字串（比如名字或日期）和特定格式的浮點數，所以基數排序也不是只能使用於整數。 
   

*/


//1.

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


//2.

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

//3.

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


//4.

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


//5.

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


//6.

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


//7.

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}


