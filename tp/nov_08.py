import math, random
# import factorial_definition as fact_lib
import os
import platform
from oct_25 import Iterable
from time import sleep

def factorial(num):
    out = 1
    if num < 0:
        print("Sorry, factorial does not exist for negative number")
    elif num == 0:
        print("The factorial of 0 is 1")
    else:
        for i in range(1, num + 1):
            out = out * i
    return out

def load_properties_file(file_name):
    if platform.system() == 'Windows':
        monitor_properties_path = os.path.join(os.environ.get('APPDATA'), 'mycompany', file_name)
    elif platform.system() == 'Linux':
        monitor_properties_path = os.path.join(os.environ.get('HOME'), '.mycompany', file_name) or \
                                  os.path.join('/etc', file_name)
    else:
        raise BaseException('Platform not supported: %s' % platform)

    return monitor_properties_path

Pi = 3.14

print(math.sqrt(625))
print(math.factorial(10))
print(math.pi)
print(random.randint(1, 20))
print(dir(math))

result = factorial(5)
print("factorail : ", result)
print("Pi : ", Pi)

path = load_properties_file("test.properties")
print("path: ", path)

it = Iterable(5)

for i in it.generator():
    sleep(0.05)
    print(i)