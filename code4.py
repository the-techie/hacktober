# This is a file that contains code to convert from decimal to binary

def to_binary(n):
	binary = ""
	while n > 0:
		r = n%2
		n = n // 2
		binary = str(r) + binary

	return(binary)

print(to_binary(10))