// Copyright 2021 NNTU-CS
  
void SortAlgo(int* data, int lenD) {
  int j = 0;
  int tmp = 0;
  for (int i = 0; i < lenD; i++) {
    j = i;
    for (int n = i; n < lenD; n++) {
      if (data[j] > data[n]) {
        j = n;
      }
    }
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
}

int countPairs1(int* arr, int len, int value) {
  SortAlgo(arr, len);
  int n = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        n++;
      }
    }
  }
  return n;
}
 
int countPairs2(int* arr, int len, int value) {
  SortAlgo(arr, len);
  int n = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        n++;
      }
    }
  }
  return n;
}

int countPairs3(int *arr, int len, int value) {
    SortAlgo(arr, len);
int n = 0;
for (int i = 0; i < len - 1; i++) {
  int left = i, right = len;
  while (left < right - 1) {
    int mid = (left + right) / 2;
    if (arr[i] + arr[mid] == value) {
      n++;
      int j = mid + 1;
      while (arr[i] + arr[j] == value && j < right) {
        n++;
        j++;
      }
      j = mid - 1;
      while (arr[i] + arr[j] == value && j > left) {
        n++;
        j--;
      }
      break;
    }
    if (arr[i] + arr[mid] > value)
      right = mid;
    else
      left = mid;
    }
  }
return n;
}
