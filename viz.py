#!/usr/bin/env python

import numpy as np
import sys
import fileinput
import os
from collections import deque
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import time
import random


matplotlib.rcParams['font.sans-serif'] = ['Source Han Sans TW', 'sans-serif']
clist = [(0, "red"), (0.125, "red"), (0.25, "orange"), (0.5, "green"),
		(0.7, "green"), (0.75, "blue"), (1, "blue")]
rvb = mcolors.LinearSegmentedColormap.from_list("", clist)
def help():
	print("usage: ./[script_name].py [number_digits]\n-h for help\n-p to print the output\n-s [number] for sleep in ms\n-m for manual mode")

stackA = deque()
padd = deque()
ops = []
sleep = 0
manual = False
verbose = False
labels=False

if (len(sys.argv) < 2):
	help()
	exit()
iterArgv = iter(sys.argv)
next(iterArgv)
numDigits = next(iterArgv)
params = list(numDigits)
if ('-' in params):
	numDigits = next(iterArgv)
	if ('h' in params):
		help()
		exit()
	if ('m' in params):
		manual = True
	if ('s' in params):
		sleep = float(numDigits)
		numDigits = next(iterArgv)
	if ('v' in params):
		verbose = True

if (int(numDigits) < 30):
	labels = True
digitsToSort = random.sample(list(range(1, int(numDigits) + 1)), int(numDigits))
digitsToSortStr = ' '. join(map(str, digitsToSort))
command = "./push_swap " + digitsToSortStr
opsStr = os.popen(command).read()

# operations type: str => list
ops = opsStr.splitlines()

# digits to sort type: list => deque
stackA = deque(digitsToSort)
if (verbose == True):
	print ("input digits to sort: ", stackA)
	print ("sorted stack: ", stackA)
print("Number of ops", len(ops))
stackB = deque([], maxlen=len(stackA))

def sa(a, b):
	a[0], a[1] = a[1], a[0]

def sb(a, b):
	b[0], b[1] = b[1], b[0]

def ss(a, b):
	sa(a, b)
	sb(a, b)

def ra(a, b):
	a.rotate(-1)

def rb(a, b):
	b.rotate(-1)

def rr(a, b):
	ra(a, b)
	rb(a, b)

def rreva(a, b):
	a.rotate(1)

def rrevb(a, b):
	b.rotate(1)

def rrrev(a, b):
	rreva(a, b)
	rrevb(a, b)

def pa(a, b):
	a.appendleft(b.popleft())

def pb(a, b):
	b.appendleft(a.popleft())

def sort(a, b, op):
	opsDic = {
	"sa": sa,
	"sb": sb,
	"ss": ss,
	"ra": ra,
	"rb": rb,
	"rr": rr,
	"rra": rreva,
	"rrb": rrevb,
	"rrr": rrrev,
	"pa": pa,
	"pb": pb
	}
	func = opsDic.get(op)
	func(a, b)

plt.rcdefaults()
def drawPlotsFormated(maxStk, maxX, stackA, stackB, op=None):
	y_posA = np.arange(maxStk)
	y_posB = np.arange(maxStk)
	axA.set_xlim(right=maxX*1.1, auto=False, left=0)
	axB.set_xlim(right=maxX*1.1, auto=False, left=0)
	dataA = stackA + deque([0] * len(stackB))
	dataB = stackB + deque([0] * len(stackA))
	rectsA = axA.barh(y_posA, dataA, height=1, tick_label=(dataA), color=rvb(len(stackA)/maxStk), edgecolor='white', align='center')
	rectsB = axB.barh(y_posB, dataB, height=1, tick_label=(dataB), color=rvb(len(stackB)/maxStk), edgecolor='white', align='center')
	axA.tick_params(
		axis='x',
		which='both',
		bottom=False,
		top=False,
		labelbottom=False)
	axB.tick_params(
		axis='x',
		which='both',
		bottom=False,
		top=False,
		labelbottom=False)
	axA.tick_params(
		axis='y',
		which='both',
		pad=-15,
		labelcolor='white',
		length=0,
		labelright=False,
		labelleft=labels
)
	axB.tick_params(
		axis='y',
		which='both',
		pad=-15,
		labelcolor='white',
		length=0,
		labelright=False,
		labelleft=labels
)
	axA.invert_yaxis()
	axB.invert_yaxis()
	axA.set_title("Stack A")
	axB.set_title("Stack B")
	if (op != None):
		axA.text(maxX / 2, maxStk, op, size=18,
			horizontalalignment='center',
			verticalalignment='bottom',
			ha="right", va="top",
			bbox=dict(boxstyle="square",
			bounds=(0,0, 20,150),
			ec=(1., 0.5, 0.5),
			fc=(1., 0.8, 0.8),
			)
	)
fig = plt.figure()
axA = fig.add_subplot(1,2,1)
axB = fig.add_subplot(1,2,2)
maxStk = len(stackA)
maxX = max(stackA)
plt.ion()
plt.show()
for op in ops:
	drawPlotsFormated(maxStk, maxX, stackA, stackB, op)
	fig.canvas.flush_events()
	time.sleep(sleep)
	if (verbose == True):
		print(op)
	if (manual == True):
		input("press Enter to continue...")
	axA.cla()
	axB.cla()
	sort(stackA, stackB, op)	
drawPlotsFormated(maxStk, maxX, stackA, stackB)
fig.canvas.flush_events()
input("press Enter to exit")