//
// Created by DELL on 2019/4/12.
//

#ifndef DATASTRUCT_SORT_H
#define DATASTRUCT_SORT_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace Util {
    /**
     * 二分查找
     * @tparam T
     * @param array
     * @param n
     * @param target
     * @return
     */
    template<typename T>
    bool BinarySearch(T array[], int n, T target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + ((r - l) / 2);

            if (array[mid] == target) {
                return true;
            }

            if (array[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

        }
        return false;
    }

/**
 * 选择排序算法
 * @param array
 * @param n
 */
    void SelectSort(int *array, int n) {
        if (n < 2) {
            return;
        }
        for (int i = 0; i < n; i++) {
            int node = i;
            bool flag = false;
            for (int j = (i + 1); j < n; j++) {
                if (array[j] < array[node]) {
                    node = j;
                    flag = true;
                }
            }
            if (!flag) {
                continue;
            }
            swap(array[i], array[node]);
        }


    }

    /**
     * 插入排序算法
     * @param array
     * @param n
     */

    void InsertSort(int *array, int n) {
        if (n < 2) {
            return;
        }
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (array[j + 1] < array[j]) {
                    swap(array[j + 1], array[j]);
                }
            }
        }

    }

/**
 * 冒泡排序算法
 * @param array
 * @param n
 */
    void BubbleSort(int *array, int n) {
        if (n < 2) {
            return;
        }

        for (int i = n - 1; i > 0; i--) {
            int max = i;
            bool flag = false;
            for (int j = i - 1; j >= 0; j--) {
                if (array[j] > array[max]) {
                    max = j;
                    flag = true;
                }
            }

            if (!flag) {
                continue;
            }
            swap(array[max], array[i]);
        }


    }

    int partition(int * array, int l ,int r) {
        int focus = array[l];
        int j = l;
        for (int i = l + 1;i <=r ;i++) {
             if(array[i] < focus) {
                 swap(array[i],array[j+1]);
                 j++;
             }
        }
        swap(array[l],array[j]);
        return j;

    }
    void divideLR(int * array, int l, int r ) {
        if( NULL == array || l >= r) {
            return;
        }
        int index = partition(array,l,r);
        divideLR(array,l,index-1);
        divideLR(array,index+1,r);

    }



/**
 * 快速排序算法
 * @param array
 * @param n
 */
    void QuickSort(int *array, int n) {
         divideLR(array,0,n-1);

    }




    /**
     * 归并
     * @param array
     * @param start
     * @param mid
     * @param end
     */
    void merge(int *array, int start, int mid, int end) {
        int total = (end - start) + 1;
        int *temp = new int[total];
        int i = start, j = mid + 1;
        for (int t = 0; t < total; t++) {
            if (i <= mid && j > end) {
                temp[t] = array[i];
                i++;
                continue;
            }

            if (i > mid && j <= end) {
                temp[t] = array[j];
                j++;
                continue;
            }

            if (array[i] > array[j]) {
                temp[t] = array[j];
                j++;
            } else {
                temp[t] = array[i];
                i++;
            }

        }

        for (int i = 0; i < total; i++) {
            array[start + i] = temp[i];
        }

        delete[] temp;

    }

    /**
     * 自上而下归并
     * @param array
     * @param start
     * @param end
     */
    void mergeSortUpToDown(int *array, int start, int end) {
        if (NULL == array || start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSortUpToDown(array, start, mid);
        mergeSortUpToDown(array, mid + 1, end);
        merge(array, start, mid, end);

    }

    /**
 * 归并排序算法
 * @param array
 * @param n
 */
    void MergeSort(int *array, int n) {
        mergeSortUpToDown(array, 0, n - 1);
    }

    /**
     * 自下而上归并
     * @param array
     * @param start
     * @param end
     */
    void mergeSortDownToUp(int *array, int start, int end) {

    }


}

namespace TestAssistant {
    int *GetRandomArray(int n, int from, int to) {
        assert(from <= to);
        int *array = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            array[i] = rand() % (to - from + 1);
        }
        return array;
    }

    int *DupArray(int *array, int n) {
        int *data = new int[n];

        for (int i = 0; i < n; i++) {
            data[i] = array[i];
        }
        return data;

    }

    void ShowArrayElement(int *array, int n) {
        for (int i = 0; i < n; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }


}


#endif //DATASTRUCT_SORT_H
