import numpy as np

def strassen(X, Y):
    X = np.array(X)
    Y = np.array(Y)

    n = len(X)
    if n == 1:
        return X*Y

    A = X[0:n//2, 0:n//2]
    B = X[0:n//2, n//2:]
    C = X[n//2:, 0:n//2]
    D = X[n//2:, n//2:]

    E = Y[0:n//2, 0:n//2]
    F = Y[0:n//2, n//2:]
    G = Y[n//2:, 0:n//2]
    H = Y[n//2:, n//2:]

    P1 = strassen(A, F - H)
    P2 = strassen(A + B, H)
    P3 = strassen(C + D, E)
    P4 = strassen(D, G - E)
    P5 = strassen(A + D, E + H)
    P6 = strassen(B - D, G + H)
    P7 = strassen(A - C, E + F)

    return np.array([
        [P5 + P4 - P2 + P6, P1 + P2],
        [P3 + P4, P1 + P5 - P7 - P3]
    ])

if __name__ == '__main__':
    X = [[1, 2], [3, 4]]
    Y = [[5, 6], [7, 8]]

    print(strassen(X, Y))