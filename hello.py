import os
import time
import sys
from time import sleep

os.system('clear')

print("What is up my hammies?!?\n\n\n")

mess = "=" * 51

def print_slowly(text):
        for c in text:
            print (c, end='-')
            sys.stdout.flush()
            sleep(0.5)


print_slowly(mess)
print("\n")

