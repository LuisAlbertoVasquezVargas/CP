hrs = raw_input("Enter Hours:")
rate = raw_input("Enter rate:")
h = float(hrs)
r = float(rate)

if h <= 40 :
	ans = h * r;
else :
	ans = 40 * r + (h - 40) * r * 1.5;

print(ans);