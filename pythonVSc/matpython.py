def generate(rows, cols):
    return [[0 for _ in range(cols)] for _ in range(rows)]

def matrixmul(first, second):
    if len(first[0]) != len(second):
        print("wrong size")
        return None
    result_rows = len(first)
    result_cols = len(second[0])

    result = generate(result_rows, result_cols)
    
    for i in range(result_rows):
        for j in range(result_cols):
            sum = 0
            for k in range(len(first[0])):
                sum += first[i][k] * second[k][j]
            result[i][j] = sum
    
    return result