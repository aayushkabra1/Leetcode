import time

def multiply(num1, num2):
    if len(num1) or len(num2) == 1:
        return str(int(num1) * int(num2))

    n = len(num1)//2

    a = num1[0:n]
    b = num1[n:]

    c = num2[0:n]
    d = num2[n:]

    ac = multiply(a, c)
    bd = multiply(b, d)

    ad_plus_bc = multiply(a + b, c + d) - ac - bd

    return str(float(ac + "0"*n) + float(ad_plus_bc + "0"*n/2) + float(bd))

if __name__ == "__main__":
    
    num1 = "3141592653589793238462643383279502884197169399375105820974944592"
    num2 = "2718281828459045235360287471352662497757247093699959574966967627"

    tic = time.time()
    print(multiply(num1, num2))
    tac = time.time()
    print("Time taken = ", tac - tic)
