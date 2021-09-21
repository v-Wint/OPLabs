from math import sqrt

def get_length(x1, x2, y1, y2):
	"""return the length of the line based on coords"""
	length = sqrt((x2-x1)**2 + (y2-y1)**2)
	return length

def main():
	try:
		x1, y1 = float(input("x1= ")), float(input("y1= "))
		x2, y2 = float(input("x2= ")), float(input("y2= "))
		x3, y3 = float(input("x3= ")), float(input("x3= "))
	except:
		print("Invalid data")
		return

	a, b, c = get_length(x1, x2, y1, y2), get_length(x2, x3, y2, y3), get_length(x3, x1, y3, y1)

	per = a + b + c
	half_per = per/2

	#using Heron's formula
	area = sqrt(half_per*(half_per-a)*(half_per-b)*(half_per-c))

	print(f"Perimeter = {per}\nArea = {area}")

main()


