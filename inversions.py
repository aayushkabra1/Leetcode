
def sort_and_count(arr):

    sum = 0
    if len(arr) <= 1:
        return (arr, 0)
    if len(arr) == 2:
        if arr[0] > arr[1]:
            return (arr[::-1], 1)
        else:
            return (arr, 0)

    n = len(arr)//2

    left_arr = arr[0:n]
    right_arr = arr[n:]

    left_arr, temp = sort_and_count(left_arr)
    sum += temp
    right_arr, temp = sort_and_count(right_arr)
    sum += temp

    i = 0
    j = 0
    k = 0
    sorted_arr = [0]*len(arr)
    while i < len(left_arr) and j < len(right_arr):
        if left_arr[i] <= right_arr[j]:
            sorted_arr[k] = left_arr[i]
            i += 1
        else:
            sorted_arr[k] = right_arr[j]
            sum += len(left_arr) - i
            j += 1
        k += 1
    
    while i < len(left_arr):
        sorted_arr[k] = left_arr[i]
        i += 1
        k += 1

    while j < len(right_arr):
        sorted_arr[k] = right_arr[j]
        j += 1
        k += 1

    return (sorted_arr, sum)

if __name__ == "__main__":
    arr = [1, 3, 5, 2, 4, 6]
    print(arr)

    arr, sum = sort_and_count(arr)
    print(arr)
    print(sum)