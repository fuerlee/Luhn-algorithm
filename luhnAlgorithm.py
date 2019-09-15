from functools import reduce

def luhn(code):
    # Pre-calculated multiplication results by 2 minus 9 for large digits
    # The index number is equal to the number on which the operation is performed
    LOOKUP = (0, 2, 4, 6, 8, 1, 3, 5, 7, 9)
    code = reduce(str.__add__, filter(str.isdigit, code))
    evens = sum(int(i) for i in code[-1::-2])
    odds = sum(LOOKUP[int(i)] for i in code[-2::-2])
    return ((evens + odds) % 10 == 0)

print("Tested: ", luhn('4561 2612 1234 5467'))
print("Failed validation: ", luhn('4561 2612 1234 5464'))