# Import collections module:
import collections
from collections import deque

d = deque(maxlen=10)

for x in range(0, 20):
    d.appendleft(x)

print(d)
