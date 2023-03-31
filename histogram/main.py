from collections import Counter

import sys
import numpy as np
import matplotlib.pyplot as plt

def main():
    if len(sys.argv) == 2:
        try:
            f = open(sys.argv[1], 'r')
        except:
            print("No such file or directory.")
            exit()

        c = Counter(f.read())
        plt.bar(*zip(*c.most_common()), width=.8, color='g')
        plt.show()
    
    else:
        print("Too few or too many args.")
        print("Usage: python3 main.py <TEXT_FILE>")

if __name__ == '__main__':
    main()
