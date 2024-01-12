

# Counting inversions below

def merge_count(left, right):
    output = []
    i, j = 0, 0

    inversions = 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            output.append(left[i])
            i += 1
        else:
            output.append(right[j])
            inversions += len(left) - i # why?
            j += 1

    # Add the rest of the list
    while i < len(left):
        output.append(left[i])
        i += 1

    while j < len(right):
        output.append(right[j])
        j += 1

    return output, inversions


def merge_sort_count(array):
    # Base Case
    if len(array) == 1:
        return array, 0
    else:
        midpoint = len(array)
        left, left_count = merge_sort_count(array[:midpoint])
        right, right_count = merge_sort_count(array[midpoint:])

        merged, m_count = merge_count(left, right)

        total = left_count + right_count + m_count
        return merged, total

def main():
    input_file = [int(line.replace('\n', '')) for line in open("/home/shankar/Shiva/prepare-cs2040/Algorithms-Design-and-Analysis-Part-1/HW1/IntegerArray.txt").readlines()]

    sorted_arr, counter = merge_sort_count(input_file)
    print(counter)


if __name__ == "__main__":
    main()
    # test()