void insertionSort(int arr[], int n) {
    // Функция сортировки вставками
    int i, j, cur;
    for (i = 1; i < n; i++) {
        cur = arr[i]; // Запоминаем текущий элемент
        j = i - 1;
        // Перемещаем все элементы больше текущего на одну позицию вперед
        while (j >= 0 && arr[j] > cur) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j] = cur; // Вставляем текущий элемент на правильную позицию
    }
}

void merge(int arr[], int left, int mid, int right) {
    // Функция для слияния двух подмассивов
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Копируем данные во временные массивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Слияние временных массивов обратно в arr[left..right]
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

    // Записываем оставшиеся элементы из L[] и R[], если таковые остались
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
    // Функция для сортировки слиянием
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Рекурсивно вызываем mergeSort для двух половин массива
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем две половины массива
        merge(arr, left, mid, right);
    }
}

void hybridSort(int arr[], int n) {
    // Функция гибридной сортировки
    if (n <= 10)
        mergeSort(arr, 0, n); // Если размер массива меньше или равен 10, используем сортировку слиянием
    else
        insertionSort(arr, n); // Иначе используем сортировку вставками
}

void xorSwap(int& a, int& b) {
    // Функция для обмена значений переменных с использованием XOR: 0,0=0; 0,1=1; 1,0=1; 1,1=0
    a ^= b;
    b ^= a;
    a ^= b;
}

int fibonacci(int n) {
    // Функция для вычисления n-го числа Фибоначчи
    if (n <= 1) {
        return n;
    }
    //Вызов самой себя через рекурсию
    return fibonacci(n - 1) + fibonacci(n - 2);
}